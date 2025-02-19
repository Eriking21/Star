#pragma once

#define THEN ;
#define CONCATENATE(x, y) x##y


#define FOR_EACH__0(FUNC)
#define FOR_EACH__1(FUNC, ...) __VA_OPT__(FUNC(__VA_ARGS__))
#define FOR_EACH__2(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_1(FUNC, yS)
#define FOR_EACH__3(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_2(FUNC, yS)
#define FOR_EACH__4(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_3(FUNC, yS)
#define FOR_EACH__5(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_4(FUNC, yS)
#define FOR_EACH__6(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_5(FUNC, yS)
#define FOR_EACH__7(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_6(FUNC, yS)
#define FOR_EACH__8(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_7(FUNC, yS)
#define FOR_EACH__9(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_8(FUNC, yS)
#define FOR_EACH__10(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_9(FUNC, yS)
#define FOR_EACH__11(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_10(FUNC, yS)
#define FOR_EACH__12(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_11(FUNC, yS)
#define FOR_EACH__13(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_12(FUNC, yS)
#define FOR_EACH__14(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_13(FUNC, yS)
#define FOR_EACH__15(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_14(FUNC, yS)
#define FOR_EACH__16(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_15(FUNC, yS)
#define FOR_EACH__17(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_16(FUNC, yS)
#define FOR_EACH__18(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_17(FUNC, yS)
#define FOR_EACH__19(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_18(FUNC, yS)
#define FOR_EACH__20(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_19(FUNC, yS)
#define FOR_EACH__21(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_20(FUNC, yS)
#define FOR_EACH__22(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_21(FUNC, yS)
#define FOR_EACH__23(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_22(FUNC, yS)
#define FOR_EACH__24(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_23(FUNC, yS)
#define FOR_EACH__25(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_24(FUNC, yS)
#define FOR_EACH__26(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_25(FUNC, yS)
#define FOR_EACH__27(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_26(FUNC, yS)
#define FOR_EACH__28(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_27(FUNC, yS)
#define FOR_EACH__29(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_28(FUNC, yS)
#define FOR_EACH__30(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_29(FUNC, yS)
#define FOR_EACH__31(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_30(FUNC, yS)
#define FOR_EACH__32(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_31(FUNC, yS)
#define FOR_EACH__33(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_32(FUNC, yS)
#define FOR_EACH__34(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_33(FUNC, yS)
#define FOR_EACH__35(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_34(FUNC, yS)
#define FOR_EACH__36(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_35(FUNC, yS)
#define FOR_EACH__37(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_36(FUNC, yS)
#define FOR_EACH__38(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_37(FUNC, yS)
#define FOR_EACH__39(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_38(FUNC, yS)
#define FOR_EACH__40(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_39(FUNC, yS)
#define FOR_EACH__41(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_40(FUNC, yS)
#define FOR_EACH__42(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_41(FUNC, yS)
#define FOR_EACH__43(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_42(FUNC, yS)
#define FOR_EACH__44(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_43(FUNC, yS)
#define FOR_EACH__45(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_44(FUNC, yS)
#define FOR_EACH__46(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_45(FUNC, yS)
#define FOR_EACH__47(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_46(FUNC, yS)
#define FOR_EACH__48(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_47(FUNC, yS)
#define FOR_EACH__49(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_48(FUNC, yS)
#define FOR_EACH__50(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_49(FUNC, yS)
#define FOR_EACH__51(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_50(FUNC, yS)
#define FOR_EACH__52(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_51(FUNC, yS)
#define FOR_EACH__53(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_52(FUNC, yS)
#define FOR_EACH__54(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_53(FUNC, yS)
#define FOR_EACH__55(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_54(FUNC, yS)
#define FOR_EACH__56(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_55(FUNC, yS)
#define FOR_EACH__57(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_56(FUNC, yS)
#define FOR_EACH__58(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_57(FUNC, yS)
#define FOR_EACH__59(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_58(FUNC, yS)
#define FOR_EACH__60(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_59(FUNC, yS)
#define FOR_EACH__61(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_60(FUNC, yS)
#define FOR_EACH__62(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_61(FUNC, yS)
#define FOR_EACH__63(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_62(FUNC, yS)
#define FOR_EACH__64(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_63(FUNC, yS)
#define FOR_EACH__65(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_64(FUNC, yS)
#define FOR_EACH__66(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_65(FUNC, yS)
#define FOR_EACH__67(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_66(FUNC, yS)
#define FOR_EACH__68(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_67(FUNC, yS)
#define FOR_EACH__69(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_68(FUNC, yS)
#define FOR_EACH__70(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_69(FUNC, yS)
#define FOR_EACH__71(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_70(FUNC, yS)
#define FOR_EACH__72(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_71(FUNC, yS)
#define FOR_EACH__73(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_72(FUNC, yS)
#define FOR_EACH__74(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_73(FUNC, yS)
#define FOR_EACH__75(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_74(FUNC, yS)
#define FOR_EACH__76(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_75(FUNC, yS)
#define FOR_EACH__77(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_76(FUNC, yS)
#define FOR_EACH__78(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_77(FUNC, yS)
#define FOR_EACH__79(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_78(FUNC, yS)
#define FOR_EACH__80(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_79(FUNC, yS)
#define FOR_EACH__81(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_80(FUNC, yS)
#define FOR_EACH__82(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_81(FUNC, yS)
#define FOR_EACH__83(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_82(FUNC, yS)
#define FOR_EACH__84(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_83(FUNC, yS)
#define FOR_EACH__85(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_84(FUNC, yS)
#define FOR_EACH__86(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_85(FUNC, yS)
#define FOR_EACH__87(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_86(FUNC, yS)
#define FOR_EACH__88(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_87(FUNC, yS)
#define FOR_EACH__89(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_88(FUNC, yS)
#define FOR_EACH__90(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_89(FUNC, yS)
#define FOR_EACH__91(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_90(FUNC, yS)
#define FOR_EACH__92(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_91(FUNC, yS)
#define FOR_EACH__93(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_92(FUNC, yS)
#define FOR_EACH__94(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_93(FUNC, yS)
#define FOR_EACH__95(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_94(FUNC, yS)
#define FOR_EACH__96(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_95(FUNC, yS)
#define FOR_EACH__97(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_96(FUNC, yS)
#define FOR_EACH__98(FUNC, x, yS...) FUNC(x) THEN FOR_EACH_97(FUNC, yS)
#define FOR_EACH__99(FUNC, x, yS...) FUN(x) THEN FOR_EACH_98(FUN, yS)
#define FOR_EACH__100(FUNC, x, yS...) FUN(x) THEN FOR_EACH_99(FUN, yS)

#define FOR_EACH_Num(                                                          \
    __100, __99, __98, __97, __96, __95, __94, __93, __92, __91, __90, __89,   \
    __88, __87, __86, __85, __84, __83, __82, __81, __80, __79, __78, __77,    \
    __76, __75, __74, __73, __72, __71, __70, __69, __68, __67, __66, __65,    \
    __64, __63, __62, __61, __60, __59, __58, __57, __56, __55, __54, __53,    \
    __52, __51, __50, __49, __48, __47, __46, __45, __44, __43, __42, __41,    \
    __40, __39, __38, __37, __36, __35, __34, __33, __32, __31, __30, __29,    \
    __28, __27, __26, __25, __24, __23, __22, __21, __20, __19, __18, __17,    \
    __16, __15, __14, __13, __12, __11, __10, __9, __8, __7, __6, __5, __4,    \
    __3, __2, __1, Num, ...)                                                   \
  Num
#define FOR_EACH_N                                                            \
  __100, __99, __98, __97, __96, __95, __94, __93, __92, __91, __90, __89,     \
      __88, __87, __86, __85, __84, __83, __82, __81, __80, __79, __78, __77,  \
      __76, __75, __74, __73, __72, __71, __70, __69, __68, __67, __66, __65,  \
      __64, __63, __62, __61, __60, __59, __58, __57, __56, __55, __54, __53,  \
      __52, __51, __50, __49, __48, __47, __46, __45, __44, __43, __42, __41,  \
      __40, __39, __38, __37, __36, __35, __34, __33, __32, __31, __30, __29,  \
      __28, __27, __26, __25, __24, __23, __22, __21, __20, __19, __18, __17,  \
      __16, __15, __14, __13, __12, __11, __10, __9, __8, __7, __6, __5, __4,  \
      __3, __2, __1

#define FOR_EACH_COUNT(PARAMS...) FOR_EACH_Num(PARAMS)
#define FOR_EACH_(PARAMS...) FOR_EACH_COUNT(PARAMS, FOR_EACH_N, _0)
#define FOR_EACH__(N, FUNC, PARAMS...) CONCATENATE(FOR_EACH, N)(FUNC, PARAMS)
#define FOR_EACH(FUNC, PARAMS...) FOR_EACH__(FOR_EACH_(PARAMS), FUNC, PARAMS)