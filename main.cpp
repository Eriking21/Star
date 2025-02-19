//#pragma once
#define CONCATENATE(x, y) x##y
#define EXPAND(...) __VA_ARGS__

#define FOR_EACH_0(FN)
#define FOR_EACH_1(FN, x) FN(x)
#define FOR_EACH_2(FN, x, yS...)                                               \
  FN(x);                                                                       \
  FOR_EACH_1(FN, yS)
#define FOR_EACH_3(FN, x, yS...)                                               \
  FN(x);                                                                       \
  FOR_EACH_2(FN, yS)
#define FOR_EACH_4(FN, x, yS...)                                               \
  FN(x);                                                                       \
  FOR_EACH_3(FN, yS)
#define FOR_EACH_5(FN, x, yS...)                                               \
  FN(x);                                                                       \
  FOR_EACH_4(FN, yS)
#define FOR_EACH_6(FN, x, yS...)                                               \
  FN(x);                                                                       \
  FOR_EACH_5(FN, yS)
#define FOR_EACH_7(FN, x, yS...)                                               \
  FN(x);                                                                       \
  FOR_EACH_6(FN, yS)
#define FOR_EACH_8(FN, x, yS...)                                               \
  FN(x);                                                                       \
  FOR_EACH_7(FN, yS)
#define FOR_EACH_9(FN, x, yS...)                                               \
  FN(x);                                                                       \
  FOR_EACH_8(FN, yS)
#define FOR_EACH_10(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_9(FN, yS)
#define FOR_EACH_11(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_10(FN, yS)
#define FOR_EACH_12(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_11(FN, yS)
#define FOR_EACH_13(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_12(FN, yS)
#define FOR_EACH_14(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_13(FN, yS)
#define FOR_EACH_15(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_14(FN, yS)
#define FOR_EACH_16(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_15(FN, yS)
#define FOR_EACH_17(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_16(FN, yS)
#define FOR_EACH_18(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_17(FN, yS)
#define FOR_EACH_19(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_18(FN, yS)
#define FOR_EACH_20(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_19(FN, yS)
#define FOR_EACH_21(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_20(FN, yS)
#define FOR_EACH_22(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_21(FN, yS)
#define FOR_EACH_23(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_22(FN, yS)
#define FOR_EACH_24(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_23(FN, yS)
#define FOR_EACH_25(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_24(FN, yS)
#define FOR_EACH_26(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_25(FN, yS)
#define FOR_EACH_27(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_26(FN, yS)
#define FOR_EACH_28(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_27(FN, yS)
#define FOR_EACH_29(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_28(FN, yS)
#define FOR_EACH_30(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_29(FN, yS)
#define FOR_EACH_31(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_30(FN, yS)
#define FOR_EACH_32(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_31(FN, yS)
#define FOR_EACH_33(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_32(FN, yS)
#define FOR_EACH_34(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_33(FN, yS)
#define FOR_EACH_35(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_34(FN, yS)
#define FOR_EACH_36(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_35(FN, yS)
#define FOR_EACH_37(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_36(FN, yS)
#define FOR_EACH_38(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_37(FN, yS)
#define FOR_EACH_39(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_38(FN, yS)
#define FOR_EACH_40(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_39(FN, yS)
#define FOR_EACH_41(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_40(FN, yS)
#define FOR_EACH_42(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_41(FN, yS)
#define FOR_EACH_43(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_42(FN, yS)
#define FOR_EACH_44(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_43(FN, yS)
#define FOR_EACH_45(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_44(FN, yS)
#define FOR_EACH_46(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_45(FN, yS)
#define FOR_EACH_47(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_46(FN, yS)
#define FOR_EACH_48(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_47(FN, yS)
#define FOR_EACH_49(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_48(FN, yS)
#define FOR_EACH_50(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_49(FN, yS)
#define FOR_EACH_51(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_50(FN, yS)
#define FOR_EACH_52(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_51(FN, yS)
#define FOR_EACH_53(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_52(FN, yS)
#define FOR_EACH_54(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_53(FN, yS)
#define FOR_EACH_55(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_54(FN, yS)
#define FOR_EACH_56(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_55(FN, yS)
#define FOR_EACH_57(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_56(FN, yS)
#define FOR_EACH_58(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_57(FN, yS)
#define FOR_EACH_59(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_58(FN, yS)
#define FOR_EACH_60(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_59(FN, yS)
#define FOR_EACH_61(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_60(FN, yS)
#define FOR_EACH_62(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_61(FN, yS)
#define FOR_EACH_63(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_62(FN, yS)
#define FOR_EACH_64(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_63(FN, yS)
#define FOR_EACH_65(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_64(FN, yS)
#define FOR_EACH_66(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_65(FN, yS)
#define FOR_EACH_67(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_66(FN, yS)
#define FOR_EACH_68(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_67(FN, yS)
#define FOR_EACH_69(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_68(FN, yS)
#define FOR_EACH_70(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_69(FN, yS)
#define FOR_EACH_71(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_70(FN, yS)
#define FOR_EACH_72(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_71(FN, yS)
#define FOR_EACH_73(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_72(FN, yS)
#define FOR_EACH_74(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_73(FN, yS)
#define FOR_EACH_75(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_74(FN, yS)
#define FOR_EACH_76(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_75(FN, yS)
#define FOR_EACH_77(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_76(FN, yS)
#define FOR_EACH_78(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_77(FN, yS)
#define FOR_EACH_79(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_78(FN, yS)
#define FOR_EACH_80(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_79(FN, yS)
#define FOR_EACH_81(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_80(FN, yS)
#define FOR_EACH_82(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_81(FN, yS)
#define FOR_EACH_83(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_82(FN, yS)
#define FOR_EACH_84(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_83(FN, yS)
#define FOR_EACH_85(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_84(FN, yS)
#define FOR_EACH_86(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_85(FN, yS)
#define FOR_EACH_87(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_86(FN, yS)
#define FOR_EACH_88(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_87(FN, yS)
#define FOR_EACH_89(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_88(FN, yS)
#define FOR_EACH_90(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_89(FN, yS)
#define FOR_EACH_91(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_90(FN, yS)
#define FOR_EACH_92(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_91(FN, yS)
#define FOR_EACH_93(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_92(FN, yS)
#define FOR_EACH_94(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_93(FN, yS)
#define FOR_EACH_95(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_94(FN, yS)
#define FOR_EACH_96(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_95(FN, yS)
#define FOR_EACH_97(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_96(FN, yS)
#define FOR_EACH_98(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_97(FN, yS)
#define FOR_EACH_99(FN, x, yS...)                                              \
  FN(x);                                                                       \
  FOR_EACH_98(FN, yS)
#define FOR_EACH_100(FN, x, yS...)                                             \
  FN(x);                                                                       \
  FOR_EACH_99(FN, yS)

#define FOR_EACH(FN, ...) FOR_EACH_(FOR_EACH__(__VA_ARGS__), FN, __VA_ARGS__)
#define FOR_EACH_(Num, FN, ...) CONCATENATE(FOR_EACH, Num)(FN, __VA_ARGS__)
#define FOR_EACH__(...) FOR_EACH___(__VA_ARGS__, FOR_EACH_Nums, _0)
#define FOR_EACH___(...) FOR_EACH____(__VA_ARGS__)
#define FOR_EACH____(                                                            \
    _100, _99, _98, _97, _96, _95, _94, _93, _92, _91, _90, _89, _88, _87,     \
    _86, _85, _84, _83, _82, _81, _80, _79, _78, _77, _76, _75, _74, _73, _72, \
    _71, _70, _69, _68, _67, _66, _65, _64, _63, _62, _61, _60, _59, _58, _57, \
    _56, _55, _54, _53, _52, _51, _50, _49, _48, _47, _46, _45, _44, _43, _42, \
    _41, _40, _39, _38, _37, _36, _35, _34, _33, _32, _31, _30, _29, _28, _27, \
    _26, _25, _24, _23, _22, _21, _20, _19, _18, _17, _16, _15, _14, _13, _12, \
    _11, _10, _9, _8, _7, _6, _5, _4, _3, _2, _1, N, ...)                      \
  N
#define FOR_EACH_Nums                                                           \
  _100, _99, _98, _97, _96, _95, _94, _93, _92, _91, _90, _89, _88, _87, _86,  \
      _85, _84, _83, _82, _81, _80, _79, _78, _77, _76, _75, _74, _73, _72,    \
      _71, _70, _69, _68, _67, _66, _65, _64, _63, _62, _61, _60, _59, _58,    \
      _57, _56, _55, _54, _53, _52, _51, _50, _49, _48, _47, _46, _45, _44,    \
      _43, _42, _41, _40, _39, _38, _37, _36, _35, _34, _33, _32, _31, _30,    \
      _29, _28, _27, _26, _25, _24, _23, _22, _21, _20, _19, _18, _17, _16,    \
      _15, _14, _13, _12, _11, _10, _9, _8, _7, _6, _5, _4, _3, _2, _1

#define mk_table(NAME) struct NAME##_Format *NAME
#define mk_tables(NAMES...) FOR_EACH(mk_table, NAMES)
mk_tables(a, u, i, op, af, ujv, eyda, thb, fgbi);

int main(int, char**) {
    // std::cout << "Hello, from star!\n";
}
