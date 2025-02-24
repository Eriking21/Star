#ifndef OPTIONAL
#define OPTIONAL(X, Y)                                                         \
    ([] {                                                                      \
        if constexpr (requires{X;})                                                       \
            return X;                                                          \
        else                                                                   \
            return Y;                                                          \
    }())
#endif

#ifndef FOR_EACH

#define THEN ;
#define CONCATENATE(x, y) x##y
#define FOR_EACH(WORK, ARGS...) FOR_EACH__(FOR_EACH_(ARGS), WORK, ARGS)
#define FOR_EACH__(N, WORK, ARGS...) CONCATENATE(FOR_EACH, N)(WORK, ARGS)
#define FOR_EACH_(ARGS...) FOR_EACH_COUNT(ARGS, FOR_EACH_N, _0)
#define FOR_EACH_COUNT(ARGS...) FOR_EACH_Num(ARGS)

#if __cplusplus >= 20202L // c++20 allow FOR_EACH without a job
#    define FOR_EACH__01(WORK, ...) __VA_OPT__(WORK(__VA_ARGS__))
#else
#    define FOR_EACH__01(WORK, yS...) WORK(yS) // yS cannot be empty
#endif
#define FOR_EACH__02(WORK, x, yS...) WORK(x) THEN FOR_EACH__01(WORK, yS)
#define FOR_EACH__03(WORK, x, yS...) WORK(x) THEN FOR_EACH__02(WORK, yS)
#define FOR_EACH__04(WORK, x, yS...) WORK(x) THEN FOR_EACH__03(WORK, yS)
#define FOR_EACH__05(WORK, x, yS...) WORK(x) THEN FOR_EACH__04(WORK, yS)
#define FOR_EACH__06(WORK, x, yS...) WORK(x) THEN FOR_EACH__05(WORK, yS)
#define FOR_EACH__07(WORK, x, yS...) WORK(x) THEN FOR_EACH__06(WORK, yS)
#define FOR_EACH__08(WORK, x, yS...) WORK(x) THEN FOR_EACH__07(WORK, yS)
#define FOR_EACH__09(WORK, x, yS...) WORK(x) THEN FOR_EACH__08(WORK, yS)
#define FOR_EACH__10(WORK, x, yS...) WORK(x) THEN FOR_EACH__09(WORK, yS)
#define FOR_EACH__11(WORK, x, yS...) WORK(x) THEN FOR_EACH__10(WORK, yS)
#define FOR_EACH__12(WORK, x, yS...) WORK(x) THEN FOR_EACH__11(WORK, yS)
#define FOR_EACH__13(WORK, x, yS...) WORK(x) THEN FOR_EACH__12(WORK, yS)
#define FOR_EACH__14(WORK, x, yS...) WORK(x) THEN FOR_EACH__13(WORK, yS)
#define FOR_EACH__15(WORK, x, yS...) WORK(x) THEN FOR_EACH__14(WORK, yS)
#define FOR_EACH__16(WORK, x, yS...) WORK(x) THEN FOR_EACH__15(WORK, yS)
#define FOR_EACH__17(WORK, x, yS...) WORK(x) THEN FOR_EACH__16(WORK, yS)
#define FOR_EACH__18(WORK, x, yS...) WORK(x) THEN FOR_EACH__17(WORK, yS)
#define FOR_EACH__19(WORK, x, yS...) WORK(x) THEN FOR_EACH__18(WORK, yS)
#define FOR_EACH__20(WORK, x, yS...) WORK(x) THEN FOR_EACH__19(WORK, yS)
#define FOR_EACH__21(WORK, x, yS...) WORK(x) THEN FOR_EACH__20(WORK, yS)
#define FOR_EACH__22(WORK, x, yS...) WORK(x) THEN FOR_EACH__21(WORK, yS)
#define FOR_EACH__23(WORK, x, yS...) WORK(x) THEN FOR_EACH__22(WORK, yS)
#define FOR_EACH__24(WORK, x, yS...) WORK(x) THEN FOR_EACH__23(WORK, yS)
#define FOR_EACH__25(WORK, x, yS...) WORK(x) THEN FOR_EACH__24(WORK, yS)
#define FOR_EACH__26(WORK, x, yS...) WORK(x) THEN FOR_EACH__25(WORK, yS)
#define FOR_EACH__27(WORK, x, yS...) WORK(x) THEN FOR_EACH__26(WORK, yS)
#define FOR_EACH__28(WORK, x, yS...) WORK(x) THEN FOR_EACH__27(WORK, yS)
#define FOR_EACH__29(WORK, x, yS...) WORK(x) THEN FOR_EACH__28(WORK, yS)
#define FOR_EACH__30(WORK, x, yS...) WORK(x) THEN FOR_EACH__29(WORK, yS)
#define FOR_EACH__31(WORK, x, yS...) WORK(x) THEN FOR_EACH__30(WORK, yS)
#define FOR_EACH__32(WORK, x, yS...) WORK(x) THEN FOR_EACH__31(WORK, yS)
#define FOR_EACH__33(WORK, x, yS...) WORK(x) THEN FOR_EACH__32(WORK, yS)
#define FOR_EACH__34(WORK, x, yS...) WORK(x) THEN FOR_EACH__33(WORK, yS)
#define FOR_EACH__35(WORK, x, yS...) WORK(x) THEN FOR_EACH__34(WORK, yS)
#define FOR_EACH__36(WORK, x, yS...) WORK(x) THEN FOR_EACH__35(WORK, yS)
#define FOR_EACH__37(WORK, x, yS...) WORK(x) THEN FOR_EACH__36(WORK, yS)
#define FOR_EACH__38(WORK, x, yS...) WORK(x) THEN FOR_EACH__37(WORK, yS)
#define FOR_EACH__39(WORK, x, yS...) WORK(x) THEN FOR_EACH__38(WORK, yS)
#define FOR_EACH__40(WORK, x, yS...) WORK(x) THEN FOR_EACH__39(WORK, yS)
#define FOR_EACH__41(WORK, x, yS...) WORK(x) THEN FOR_EACH__40(WORK, yS)
#define FOR_EACH__42(WORK, x, yS...) WORK(x) THEN FOR_EACH__41(WORK, yS)
#define FOR_EACH__43(WORK, x, yS...) WORK(x) THEN FOR_EACH__42(WORK, yS)
#define FOR_EACH__44(WORK, x, yS...) WORK(x) THEN FOR_EACH__43(WORK, yS)
#define FOR_EACH__45(WORK, x, yS...) WORK(x) THEN FOR_EACH__44(WORK, yS)
#define FOR_EACH__46(WORK, x, yS...) WORK(x) THEN FOR_EACH__45(WORK, yS)
#define FOR_EACH__47(WORK, x, yS...) WORK(x) THEN FOR_EACH__46(WORK, yS)
#define FOR_EACH__48(WORK, x, yS...) WORK(x) THEN FOR_EACH__47(WORK, yS)
#define FOR_EACH__49(WORK, x, yS...) WORK(x) THEN FOR_EACH__48(WORK, yS)
#define FOR_EACH__50(WORK, x, yS...) WORK(x) THEN FOR_EACH__49(WORK, yS)
#define FOR_EACH__51(WORK, x, yS...) WORK(x) THEN FOR_EACH__50(WORK, yS)
#define FOR_EACH__52(WORK, x, yS...) WORK(x) THEN FOR_EACH__51(WORK, yS)
#define FOR_EACH__53(WORK, x, yS...) WORK(x) THEN FOR_EACH__52(WORK, yS)
#define FOR_EACH__54(WORK, x, yS...) WORK(x) THEN FOR_EACH__53(WORK, yS)
#define FOR_EACH__55(WORK, x, yS...) WORK(x) THEN FOR_EACH__54(WORK, yS)
#define FOR_EACH__56(WORK, x, yS...) WORK(x) THEN FOR_EACH__55(WORK, yS)
#define FOR_EACH__57(WORK, x, yS...) WORK(x) THEN FOR_EACH__56(WORK, yS)
#define FOR_EACH__58(WORK, x, yS...) WORK(x) THEN FOR_EACH__57(WORK, yS)
#define FOR_EACH__59(WORK, x, yS...) WORK(x) THEN FOR_EACH__58(WORK, yS)
#define FOR_EACH__60(WORK, x, yS...) WORK(x) THEN FOR_EACH__59(WORK, yS)
#define FOR_EACH__61(WORK, x, yS...) WORK(x) THEN FOR_EACH__60(WORK, yS)
#define FOR_EACH__62(WORK, x, yS...) WORK(x) THEN FOR_EACH__61(WORK, yS)
#define FOR_EACH__63(WORK, x, yS...) WORK(x) THEN FOR_EACH__62(WORK, yS)
#define FOR_EACH__64(WORK, x, yS...) WORK(x) THEN FOR_EACH__63(WORK, yS)
#define FOR_EACH__65(WORK, x, yS...) WORK(x) THEN FOR_EACH__64(WORK, yS)
#define FOR_EACH__66(WORK, x, yS...) WORK(x) THEN FOR_EACH__65(WORK, yS)
#define FOR_EACH__67(WORK, x, yS...) WORK(x) THEN FOR_EACH__66(WORK, yS)
#define FOR_EACH__68(WORK, x, yS...) WORK(x) THEN FOR_EACH__67(WORK, yS)
#define FOR_EACH__69(WORK, x, yS...) WORK(x) THEN FOR_EACH__68(WORK, yS)
#define FOR_EACH__70(WORK, x, yS...) WORK(x) THEN FOR_EACH__69(WORK, yS)
#define FOR_EACH__71(WORK, x, yS...) WORK(x) THEN FOR_EACH__70(WORK, yS)
#define FOR_EACH__72(WORK, x, yS...) WORK(x) THEN FOR_EACH__71(WORK, yS)
#define FOR_EACH__73(WORK, x, yS...) WORK(x) THEN FOR_EACH__72(WORK, yS)
#define FOR_EACH__74(WORK, x, yS...) WORK(x) THEN FOR_EACH__73(WORK, yS)
#define FOR_EACH__75(WORK, x, yS...) WORK(x) THEN FOR_EACH__74(WORK, yS)
#define FOR_EACH__76(WORK, x, yS...) WORK(x) THEN FOR_EACH__75(WORK, yS)
#define FOR_EACH__77(WORK, x, yS...) WORK(x) THEN FOR_EACH__76(WORK, yS)
#define FOR_EACH__78(WORK, x, yS...) WORK(x) THEN FOR_EACH__77(WORK, yS)
#define FOR_EACH__79(WORK, x, yS...) WORK(x) THEN FOR_EACH__78(WORK, yS)
#define FOR_EACH__80(WORK, x, yS...) WORK(x) THEN FOR_EACH__79(WORK, yS)
#define FOR_EACH__81(WORK, x, yS...) WORK(x) THEN FOR_EACH__80(WORK, yS)
#define FOR_EACH__82(WORK, x, yS...) WORK(x) THEN FOR_EACH__81(WORK, yS)
#define FOR_EACH__83(WORK, x, yS...) WORK(x) THEN FOR_EACH__82(WORK, yS)
#define FOR_EACH__84(WORK, x, yS...) WORK(x) THEN FOR_EACH__83(WORK, yS)
#define FOR_EACH__85(WORK, x, yS...) WORK(x) THEN FOR_EACH__84(WORK, yS)
#define FOR_EACH__86(WORK, x, yS...) WORK(x) THEN FOR_EACH__85(WORK, yS)
#define FOR_EACH__87(WORK, x, yS...) WORK(x) THEN FOR_EACH__86(WORK, yS)
#define FOR_EACH__88(WORK, x, yS...) WORK(x) THEN FOR_EACH__87(WORK, yS)
#define FOR_EACH__89(WORK, x, yS...) WORK(x) THEN FOR_EACH__88(WORK, yS)
#define FOR_EACH__90(WORK, x, yS...) WORK(x) THEN FOR_EACH__89(WORK, yS)
#define FOR_EACH__91(WORK, x, yS...) WORK(x) THEN FOR_EACH__90(WORK, yS)
#define FOR_EACH__92(WORK, x, yS...) WORK(x) THEN FOR_EACH__91(WORK, yS)
#define FOR_EACH__93(WORK, x, yS...) WORK(x) THEN FOR_EACH__92(WORK, yS)
#define FOR_EACH__94(WORK, x, yS...) WORK(x) THEN FOR_EACH__93(WORK, yS)
#define FOR_EACH__95(WORK, x, yS...) WORK(x) THEN FOR_EACH__94(WORK, yS)
#define FOR_EACH__96(WORK, x, yS...) WORK(x) THEN FOR_EACH__95(WORK, yS)
#define FOR_EACH__97(WORK, x, yS...) WORK(x) THEN FOR_EACH__96(WORK, yS)
#define FOR_EACH__98(WORK, x, yS...) WORK(x) THEN FOR_EACH__97(WORK, yS)
#define FOR_EACH__99(WORK, x, yS...) WORK(x) THEN FOR_EACH__98(WORK, yS)
#define FOR_EACH__100(WORK, x, yS...) WORK(x) THEN FOR_EACH__99(WORK, yS)

#define FOR_EACH_Num(                                                          \
    __100, __99, __98, __97, __96, __95, __94, __93, __92, __91, __90, __89,   \
    __88, __87, __86, __85, __84, __83, __82, __81, __80, __79, __78, __77,    \
    __76, __75, __74, __73, __72, __71, __70, __69, __68, __67, __66, __65,    \
    __64, __63, __62, __61, __60, __59, __58, __57, __56, __55, __54, __53,    \
    __52, __51, __50, __49, __48, __47, __46, __45, __44, __43, __42, __41,    \
    __40, __39, __38, __37, __36, __35, __34, __33, __32, __31, __30, __29,    \
    __28, __27, __26, __25, __24, __23, __22, __21, __20, __19, __18, __17,    \
    __16, __15, __14, __13, __12, __11, __10, __09, __08, __07, __06, __05,    \
    __04, __03, __02, __01, Num, ...)                                          \
    Num
#define FOR_EACH_N                                                             \
    __100, __99, __98, __97, __96, __95, __94, __93, __92, __91, __90, __89,   \
        __88, __87, __86, __85, __84, __83, __82, __81, __80, __79, __78,      \
        __77, __76, __75, __74, __73, __72, __71, __70, __69, __68, __67,      \
        __66, __65, __64, __63, __62, __61, __60, __59, __58, __57, __56,      \
        __55, __54, __53, __52, __51, __50, __49, __48, __47, __46, __45,      \
        __44, __43, __42, __41, __40, __39, __38, __37, __36, __35, __34,      \
        __33, __32, __31, __30, __29, __28, __27, __26, __25, __24, __23,      \
        __22, __21, __20, __19, __18, __17, __16, __15, __14, __13, __12,      \
        __11, __10, __09, __08, __07, __06, __05, __04, __03, __02, __01,

#endif