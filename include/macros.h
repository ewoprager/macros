#define PARENS ()
#define EXPAND(...) EXPAND4(EXPAND4(EXPAND4(EXPAND4(__VA_ARGS__))))
#define EXPAND4(...) EXPAND3(EXPAND3(EXPAND3(EXPAND3(__VA_ARGS__))))
#define EXPAND3(...) EXPAND2(EXPAND2(EXPAND2(EXPAND2(__VA_ARGS__))))
#define EXPAND2(...) EXPAND1(EXPAND1(EXPAND1(EXPAND1(__VA_ARGS__))))
#define EXPAND1(...) __VA_ARGS__

#define FOR_EACH(macro, ...) __VA_OPT__(EXPAND(FOR_EACH_HELPER(macro, __VA_ARGS__)))
#define FOR_EACH_HELPER(macro, a1, ...) macro(a1) __VA_OPT__(FOR_EACH_AGAIN PARENS (macro, __VA_ARGS__))
#define FOR_EACH_AGAIN() FOR_EACH_HELPER

#define FOR_EACH_EX(macro, firstArg, ...) __VA_OPT__(EXPAND(FOR_EACH_EX_HELPER(macro, firstArg, __VA_ARGS__)))
#define FOR_EACH_EX_HELPER(macro, firstArg, a1, ...) macro(firstArg, a1) __VA_OPT__(FOR_EACH_EX_AGAIN PARENS (macro, firstArg, __VA_ARGS__))
#define FOR_EACH_EX_AGAIN() FOR_EACH_EX_HELPER

#define BETWEEN_EACH(binary_operator, a1, ...) (a1) __VA_OPT__(EXPAND(BETWEEN_EACH_HELPER(binary_operator, __VA_ARGS__)))
#define BETWEEN_EACH_HELPER(binary_operator, a1, ...) binary_operator (a1) __VA_OPT__(BETWEEN_EACH_AGAIN PARENS (binary_operator, __VA_ARGS__))
#define BETWEEN_EACH_AGAIN() BETWEEN_EACH_HELPER

#define COMMA_SEPARATED_FOR_EACH(macro, a1, ...) macro(a1) __VA_OPT__(EXPAND(COMMA_SEPARATED_FOR_EACH_HELPER(macro, __VA_ARGS__)))
#define COMMA_SEPARATED_FOR_EACH_HELPER(macro, a1, ...) , macro(a1) __VA_OPT__(COMMA_SEPARATED_FOR_EACH_AGAIN PARENS (macro, __VA_ARGS__))
#define COMMA_SEPARATED_FOR_EACH_AGAIN() COMMA_SEPARATED_FOR_EACH_HELPER

#define COMMA_SEPARATED_FOR_EACH_EX(macro, firstArg, a1, ...) macro(firstArg, a1) __VA_OPT__(EXPAND(COMMA_SEPARATED_FOR_EACH_EX_HELPER(macro, firstArg, __VA_ARGS__)))
#define COMMA_SEPARATED_FOR_EACH_EX_HELPER(macro, firstArg, a1, ...) , macro(firstArg, a1) __VA_OPT__(COMMA_SEPARATED_FOR_EACH_EX_AGAIN PARENS (macro, firstArg, __VA_ARGS__))
#define COMMA_SEPARATED_FOR_EACH_EX_AGAIN() COMMA_SEPARATED_FOR_EACH_EX_HELPER

#define FOR_EACH_PAIR(macro, ...) __VA_OPT__(EXPAND(FOR_EACH_PAIR_HELPER(macro, __VA_ARGS__)))
#define FOR_EACH_PAIR_HELPER(macro, a1, a2, ...) macro(a1, a2) __VA_OPT__(FOR_EACH_PAIR_AGAIN PARENS (macro, __VA_ARGS__))
#define FOR_EACH_PAIR_AGAIN() FOR_EACH_PAIR_HELPER

#define FOR_EACH_TRIPLE(macro, ...) __VA_OPT__(EXPAND(FOR_EACH_TRIPLE_HELPER(macro, __VA_ARGS__)))
#define FOR_EACH_TRIPLE_HELPER(macro, a1, a2, a3, ...) macro(a1, a2, a3) __VA_OPT__(FOR_EACH_TRIPLE_AGAIN PARENS (macro, __VA_ARGS__))
#define FOR_EACH_TRIPLE_AGAIN() FOR_EACH_TRIPLE_HELPER

#define COMMA_SEPARATED_FOR_SECOND_OF_EACH_PAIR(macro, a1, a2, ...) macro(a2) __VA_OPT__(EXPAND(COMMA_SEPARATED_FOR_SECOND_OF_EACH_PAIR_HELPER(macro, __VA_ARGS__)))
#define COMMA_SEPARATED_FOR_SECOND_OF_EACH_PAIR_HELPER(macro, a1, a2, ...) , macro(a2) __VA_OPT__(COMMA_SEPARATED_FOR_SECOND_OF_EACH_PAIR_AGAIN PARENS (macro, __VA_ARGS__))
#define COMMA_SEPARATED_FOR_SECOND_OF_EACH_PAIR_AGAIN() COMMA_SEPARATED_FOR_SECOND_OF_EACH_PAIR_HELPER

#define CUSTOM_SEPARATED_FOR_EACH(macro, separator, a1, ...) macro(a1) __VA_OPT__(EXPAND(CUSTOM_SEPARATED_FOR_EACH_HELPER(macro, separator, __VA_ARGS__)))
#define CUSTOM_SEPARATED_FOR_EACH_HELPER(macro, separator, a1, ...) separator macro(a1) __VA_OPT__(CUSTOM_SEPARATED_FOR_EACH_AGAIN PARENS (macro, separator, __VA_ARGS__))
#define CUSTOM_SEPARATED_FOR_EACH_AGAIN() CUSTOM_SEPARATED_FOR_EACH_HELPER

#define CUSTOM_SEPARATED_FOR_EACH_PAIR(macro, separator, a1, a2, ...) macro(a1, a2) __VA_OPT__(EXPAND(CUSTOM_SEPARATED_FOR_EACH_PAIR_HELPER(macro, separator, __VA_ARGS__)))
#define CUSTOM_SEPARATED_FOR_EACH_PAIR_HELPER(macro, separator, a1, a2, ...) separator macro(a1, a2) __VA_OPT__(CUSTOM_SEPARATED_FOR_EACH_PAIR_AGAIN PARENS (macro, separator, __VA_ARGS__))
#define CUSTOM_SEPARATED_FOR_EACH_PAIR_AGAIN() CUSTOM_SEPARATED_FOR_EACH_PAIR_HELPER
