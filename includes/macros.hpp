/**
 * @file macros.hpp
 * @version 1.1
 * @date 2025
 *
 * @brief This header file provides a set of utility macros and template
 *        metafunctions to facilitate generic programming and conditional
 *        compilation in C++.
 *
 * The main components of this file are:
 * - HALF: A macro to define a template specialization for halving types.
 * - MAX: A macro to compute the maximum of two values.
 * - bsr, bsrl: Macros to compute the bit scan reverse for 32-bit and 64-bit integers.
 * - base2_of: A macro to compute the next power of two for a given number.
 * - pow2: A macro to compute 2 raised to the power of a given number.
 * - bits_of: A macro to compute the number of bits in a given type.
 * - write_hex: A constexpr function template to write hexadecimal representation of data.
 * - OPTIONAL, MAX_OPT: Macros for optional evaluation and maximum with optional fallback.
 * - FOR_EACH: A macro to apply a given macro to each argument in a variadic list.
 *
 * @note The code is designed to be compatible with C++20 and does not include
 *       any other headers to maintain independence.
 *
 * @copyright
 * (C) 2025 Erivaldo Mate. All rights reserved.
 */

#pragma once

template <typename T> struct Half;
template <typename T> using Half_t = typename Half<T>::type;
#define HALF(TYPE)                                                             \
    template <typename T>                                                      \
        requires(sizeof(T) == sizeof(TYPE) * 2)                                \
    struct Half<T> {                                                           \
        using type = TYPE;                                                     \
    }
HALF(unsigned char);
HALF(unsigned short);
HALF(unsigned int);
HALF(unsigned long);
HALF(unsigned long long);
using size_t = decltype(sizeof(void *));
using half_t = Half<size_t>::type;

#define MAX(X, Y) (X >= Y ? X : Y)
#define bsr(N) (31 - __builtin_clz(N))
#define bsrl(N) (63 - __builtin_clzl(N))
#define base2_of(N) (size_t{1} << (bsrl(N) + !!(N & (N - 1))))
#define pow2(N) (size_t(1) << N)
#define bits_of(N) (sizeof(N) * 8)

static constexpr char Hex_list[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                                    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
template <bool revert = false, auto lookup = Hex_list, unsigned N>
static constexpr inline void write_hex(char *where, const char (&data)[N]) {
    for (int i = 0; i < N; i++) {
        where[(1 - 2 * revert) * (i * 2 + 1)] = lookup[data[i] >> 4];
        where[(1 - 2 * revert) * (i * 2 + 0)] = lookup[data[i] & 0xF];
    }
}

#ifndef OPTIONAL
#    define OPTIONAL(X, Y)                                                     \
        ([] {                                                                  \
            if constexpr (requires { X; }) return X;                           \
            else return Y;                                                     \
        }())
#    define MAX_OPT(X, Y) OPTIONAL(MAX(X, Y), Y)
#endif

#ifndef FOR_EACH

#    define THEN ;
#    define CONCATENATE(x, y) x##y
#    define FOR_EACH(WORK, ...) LOOP___(LOOP_(__VA_ARGS__), WORK, __VA_ARGS__)
#    define LOOP___(N, WORK, ...) CONCATENATE(LOOP, N)(WORK, __VA_ARGS__)
#    define LOOP_(...) LOOP_COUNT(__VA_ARGS__, LOOP_N, _0)
#    define LOOP_COUNT(...) LOOP_Num(__VA_ARGS__)

#    if __cplusplus >= 20202L // c++20 allow LOOP without a job
#        define LOOP__01(WORK, ...) __VA_OPT__(WORK(__VA_ARGS__))
#    else
#        define LOOP__01(WORK, ...) WORK(__VA_ARGS__) //  cannot be empty
#    endif

#    define LOOP__02(WORK, x, ...) WORK(x) THEN LOOP__01(WORK, __VA_ARGS__)
#    define LOOP__03(WORK, x, ...) WORK(x) THEN LOOP__02(WORK, __VA_ARGS__)
#    define LOOP__04(WORK, x, ...) WORK(x) THEN LOOP__03(WORK, __VA_ARGS__)
#    define LOOP__05(WORK, x, ...) WORK(x) THEN LOOP__04(WORK, __VA_ARGS__)
#    define LOOP__06(WORK, x, ...) WORK(x) THEN LOOP__05(WORK, __VA_ARGS__)
#    define LOOP__07(WORK, x, ...) WORK(x) THEN LOOP__06(WORK, __VA_ARGS__)
#    define LOOP__08(WORK, x, ...) WORK(x) THEN LOOP__07(WORK, __VA_ARGS__)
#    define LOOP__09(WORK, x, ...) WORK(x) THEN LOOP__08(WORK, __VA_ARGS__)
#    define LOOP__10(WORK, x, ...) WORK(x) THEN LOOP__09(WORK, __VA_ARGS__)
#    define LOOP__11(WORK, x, ...) WORK(x) THEN LOOP__10(WORK, __VA_ARGS__)
#    define LOOP__12(WORK, x, ...) WORK(x) THEN LOOP__11(WORK, __VA_ARGS__)
#    define LOOP__13(WORK, x, ...) WORK(x) THEN LOOP__12(WORK, __VA_ARGS__)
#    define LOOP__14(WORK, x, ...) WORK(x) THEN LOOP__13(WORK, __VA_ARGS__)
#    define LOOP__15(WORK, x, ...) WORK(x) THEN LOOP__14(WORK, __VA_ARGS__)
#    define LOOP__16(WORK, x, ...) WORK(x) THEN LOOP__15(WORK, __VA_ARGS__)
#    define LOOP__17(WORK, x, ...) WORK(x) THEN LOOP__16(WORK, __VA_ARGS__)
#    define LOOP__18(WORK, x, ...) WORK(x) THEN LOOP__17(WORK, __VA_ARGS__)
#    define LOOP__19(WORK, x, ...) WORK(x) THEN LOOP__18(WORK, __VA_ARGS__)
#    define LOOP__20(WORK, x, ...) WORK(x) THEN LOOP__19(WORK, __VA_ARGS__)
#    define LOOP__21(WORK, x, ...) WORK(x) THEN LOOP__20(WORK, __VA_ARGS__)
#    define LOOP__22(WORK, x, ...) WORK(x) THEN LOOP__21(WORK, __VA_ARGS__)
#    define LOOP__23(WORK, x, ...) WORK(x) THEN LOOP__22(WORK, __VA_ARGS__)
#    define LOOP__24(WORK, x, ...) WORK(x) THEN LOOP__23(WORK, __VA_ARGS__)
#    define LOOP__25(WORK, x, ...) WORK(x) THEN LOOP__24(WORK, __VA_ARGS__)
#    define LOOP__26(WORK, x, ...) WORK(x) THEN LOOP__25(WORK, __VA_ARGS__)
#    define LOOP__27(WORK, x, ...) WORK(x) THEN LOOP__26(WORK, __VA_ARGS__)
#    define LOOP__28(WORK, x, ...) WORK(x) THEN LOOP__27(WORK, __VA_ARGS__)
#    define LOOP__29(WORK, x, ...) WORK(x) THEN LOOP__28(WORK, __VA_ARGS__)
#    define LOOP__30(WORK, x, ...) WORK(x) THEN LOOP__29(WORK, __VA_ARGS__)
#    define LOOP__31(WORK, x, ...) WORK(x) THEN LOOP__30(WORK, __VA_ARGS__)
#    define LOOP__32(WORK, x, ...) WORK(x) THEN LOOP__31(WORK, __VA_ARGS__)
#    define LOOP__33(WORK, x, ...) WORK(x) THEN LOOP__32(WORK, __VA_ARGS__)
#    define LOOP__34(WORK, x, ...) WORK(x) THEN LOOP__33(WORK, __VA_ARGS__)
#    define LOOP__35(WORK, x, ...) WORK(x) THEN LOOP__34(WORK, __VA_ARGS__)
#    define LOOP__36(WORK, x, ...) WORK(x) THEN LOOP__35(WORK, __VA_ARGS__)
#    define LOOP__37(WORK, x, ...) WORK(x) THEN LOOP__36(WORK, __VA_ARGS__)
#    define LOOP__38(WORK, x, ...) WORK(x) THEN LOOP__37(WORK, __VA_ARGS__)
#    define LOOP__39(WORK, x, ...) WORK(x) THEN LOOP__38(WORK, __VA_ARGS__)
#    define LOOP__40(WORK, x, ...) WORK(x) THEN LOOP__39(WORK, __VA_ARGS__)
#    define LOOP__41(WORK, x, ...) WORK(x) THEN LOOP__40(WORK, __VA_ARGS__)
#    define LOOP__42(WORK, x, ...) WORK(x) THEN LOOP__41(WORK, __VA_ARGS__)
#    define LOOP__43(WORK, x, ...) WORK(x) THEN LOOP__42(WORK, __VA_ARGS__)
#    define LOOP__44(WORK, x, ...) WORK(x) THEN LOOP__43(WORK, __VA_ARGS__)
#    define LOOP__45(WORK, x, ...) WORK(x) THEN LOOP__44(WORK, __VA_ARGS__)
#    define LOOP__46(WORK, x, ...) WORK(x) THEN LOOP__45(WORK, __VA_ARGS__)
#    define LOOP__47(WORK, x, ...) WORK(x) THEN LOOP__46(WORK, __VA_ARGS__)
#    define LOOP__48(WORK, x, ...) WORK(x) THEN LOOP__47(WORK, __VA_ARGS__)
#    define LOOP__49(WORK, x, ...) WORK(x) THEN LOOP__48(WORK, __VA_ARGS__)
#    define LOOP__50(WORK, x, ...) WORK(x) THEN LOOP__49(WORK, __VA_ARGS__)
#    define LOOP__51(WORK, x, ...) WORK(x) THEN LOOP__50(WORK, __VA_ARGS__)
#    define LOOP__52(WORK, x, ...) WORK(x) THEN LOOP__51(WORK, __VA_ARGS__)
#    define LOOP__53(WORK, x, ...) WORK(x) THEN LOOP__52(WORK, __VA_ARGS__)
#    define LOOP__54(WORK, x, ...) WORK(x) THEN LOOP__53(WORK, __VA_ARGS__)
#    define LOOP__55(WORK, x, ...) WORK(x) THEN LOOP__54(WORK, __VA_ARGS__)
#    define LOOP__56(WORK, x, ...) WORK(x) THEN LOOP__55(WORK, __VA_ARGS__)
#    define LOOP__57(WORK, x, ...) WORK(x) THEN LOOP__56(WORK, __VA_ARGS__)
#    define LOOP__58(WORK, x, ...) WORK(x) THEN LOOP__57(WORK, __VA_ARGS__)
#    define LOOP__59(WORK, x, ...) WORK(x) THEN LOOP__58(WORK, __VA_ARGS__)
#    define LOOP__60(WORK, x, ...) WORK(x) THEN LOOP__59(WORK, __VA_ARGS__)
#    define LOOP__61(WORK, x, ...) WORK(x) THEN LOOP__60(WORK, __VA_ARGS__)
#    define LOOP__62(WORK, x, ...) WORK(x) THEN LOOP__61(WORK, __VA_ARGS__)
#    define LOOP__63(WORK, x, ...) WORK(x) THEN LOOP__62(WORK, __VA_ARGS__)
#    define LOOP__64(WORK, x, ...) WORK(x) THEN LOOP__63(WORK, __VA_ARGS__)
#    define LOOP__65(WORK, x, ...) WORK(x) THEN LOOP__64(WORK, __VA_ARGS__)
#    define LOOP__66(WORK, x, ...) WORK(x) THEN LOOP__65(WORK, __VA_ARGS__)
#    define LOOP__67(WORK, x, ...) WORK(x) THEN LOOP__66(WORK, __VA_ARGS__)
#    define LOOP__68(WORK, x, ...) WORK(x) THEN LOOP__67(WORK, __VA_ARGS__)
#    define LOOP__69(WORK, x, ...) WORK(x) THEN LOOP__68(WORK, __VA_ARGS__)
#    define LOOP__70(WORK, x, ...) WORK(x) THEN LOOP__69(WORK, __VA_ARGS__)
#    define LOOP__71(WORK, x, ...) WORK(x) THEN LOOP__70(WORK, __VA_ARGS__)
#    define LOOP__72(WORK, x, ...) WORK(x) THEN LOOP__71(WORK, __VA_ARGS__)
#    define LOOP__73(WORK, x, ...) WORK(x) THEN LOOP__72(WORK, __VA_ARGS__)
#    define LOOP__74(WORK, x, ...) WORK(x) THEN LOOP__73(WORK, __VA_ARGS__)
#    define LOOP__75(WORK, x, ...) WORK(x) THEN LOOP__74(WORK, __VA_ARGS__)
#    define LOOP__76(WORK, x, ...) WORK(x) THEN LOOP__75(WORK, __VA_ARGS__)
#    define LOOP__77(WORK, x, ...) WORK(x) THEN LOOP__76(WORK, __VA_ARGS__)
#    define LOOP__78(WORK, x, ...) WORK(x) THEN LOOP__77(WORK, __VA_ARGS__)
#    define LOOP__79(WORK, x, ...) WORK(x) THEN LOOP__78(WORK, __VA_ARGS__)
#    define LOOP__80(WORK, x, ...) WORK(x) THEN LOOP__79(WORK, __VA_ARGS__)
#    define LOOP__81(WORK, x, ...) WORK(x) THEN LOOP__80(WORK, __VA_ARGS__)
#    define LOOP__82(WORK, x, ...) WORK(x) THEN LOOP__81(WORK, __VA_ARGS__)
#    define LOOP__83(WORK, x, ...) WORK(x) THEN LOOP__82(WORK, __VA_ARGS__)
#    define LOOP__84(WORK, x, ...) WORK(x) THEN LOOP__83(WORK, __VA_ARGS__)
#    define LOOP__85(WORK, x, ...) WORK(x) THEN LOOP__84(WORK, __VA_ARGS__)
#    define LOOP__86(WORK, x, ...) WORK(x) THEN LOOP__85(WORK, __VA_ARGS__)
#    define LOOP__87(WORK, x, ...) WORK(x) THEN LOOP__86(WORK, __VA_ARGS__)
#    define LOOP__88(WORK, x, ...) WORK(x) THEN LOOP__87(WORK, __VA_ARGS__)
#    define LOOP__89(WORK, x, ...) WORK(x) THEN LOOP__88(WORK, __VA_ARGS__)
#    define LOOP__90(WORK, x, ...) WORK(x) THEN LOOP__89(WORK, __VA_ARGS__)
#    define LOOP__91(WORK, x, ...) WORK(x) THEN LOOP__90(WORK, __VA_ARGS__)
#    define LOOP__92(WORK, x, ...) WORK(x) THEN LOOP__91(WORK, __VA_ARGS__)
#    define LOOP__93(WORK, x, ...) WORK(x) THEN LOOP__92(WORK, __VA_ARGS__)
#    define LOOP__94(WORK, x, ...) WORK(x) THEN LOOP__93(WORK, __VA_ARGS__)
#    define LOOP__95(WORK, x, ...) WORK(x) THEN LOOP__94(WORK, __VA_ARGS__)
#    define LOOP__96(WORK, x, ...) WORK(x) THEN LOOP__95(WORK, __VA_ARGS__)
#    define LOOP__97(WORK, x, ...) WORK(x) THEN LOOP__96(WORK, __VA_ARGS__)
#    define LOOP__98(WORK, x, ...) WORK(x) THEN LOOP__97(WORK, __VA_ARGS__)
#    define LOOP__99(WORK, x, ...) WORK(x) THEN LOOP__98(WORK, __VA_ARGS__)
#    define LOOP__100(WORK, x, ...) WORK(x) THEN LOOP__99(WORK, __VA_ARGS__)

#    define LOOP_Num(                                                          \
        __100, __99, __98, __97, __96, __95, __94, __93, __92, __91, __90,     \
        __89, __88, __87, __86, __85, __84, __83, __82, __81, __80, __79,      \
        __78, __77, __76, __75, __74, __73, __72, __71, __70, __69, __68,      \
        __67, __66, __65, __64, __63, __62, __61, __60, __59, __58, __57,      \
        __56, __55, __54, __53, __52, __51, __50, __49, __48, __47, __46,      \
        __45, __44, __43, __42, __41, __40, __39, __38, __37, __36, __35,      \
        __34, __33, __32, __31, __30, __29, __28, __27, __26, __25, __24,      \
        __23, __22, __21, __20, __19, __18, __17, __16, __15, __14, __13,      \
        __12, __11, __10, __09, __08, __07, __06, __05, __04, __03, __02,      \
        __01, Num, ...)                                                        \
        Num
#    define LOOP_N                                                             \
        __100, __99, __98, __97, __96, __95, __94, __93, __92, __91, __90,     \
            __89, __88, __87, __86, __85, __84, __83, __82, __81, __80, __79,  \
            __78, __77, __76, __75, __74, __73, __72, __71, __70, __69, __68,  \
            __67, __66, __65, __64, __63, __62, __61, __60, __59, __58, __57,  \
            __56, __55, __54, __53, __52, __51, __50, __49, __48, __47, __46,  \
            __45, __44, __43, __42, __41, __40, __39, __38, __37, __36, __35,  \
            __34, __33, __32, __31, __30, __29, __28, __27, __26, __25, __24,  \
            __23, __22, __21, __20, __19, __18, __17, __16, __15, __14, __13,  \
            __12, __11, __10, __09, __08, __07, __06, __05, __04, __03, __02,  \
            __01,

#endif
