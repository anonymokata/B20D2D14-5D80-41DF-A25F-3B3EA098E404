#include <stdint.h>
#include <stdlib.h>
#include <check.h>

#include "RomanNumberMath.h"

/*******************************************************************************
 * Create Data Structure to Represent a Roman Digit                            *
 ******************************************************************************/

/************** Create Data Structure to Represent a Roman Digit **************/
START_TEST(create_data_structure_to_represent_a_roman_digit) {
   RomanDigit rd = {'I', 1};

   ck_assert(rd.Symbol == 'I');
   ck_assert_int_eq(rd.Value, 1);
} END_TEST

/******** Character of "i" or "I" should have symbol "I" and value of 1 *******/
START_TEST(initialize_roman_digit_with_i_or_I_returns_symbol_I_value_1) {
   RomanDigit rd1 = newRomanDigit('i');
   RomanDigit rd2 = newRomanDigit('I');

   ck_assert(rd1.Symbol == 'I');
   ck_assert(rd2.Symbol == 'I');
   ck_assert_int_eq(rd1.Value, 1);
   ck_assert_int_eq(rd2.Value, 1);
} END_TEST

/******** Character of "v" or "V" should have symbol "V" and value of 5 *******/
START_TEST(initialize_roman_digit_with_v_or_V_returns_symbol_V_value_5) {
   RomanDigit rd1 = newRomanDigit('v');
   RomanDigit rd2 = newRomanDigit('V');

   ck_assert(rd1.Symbol == 'V');
   ck_assert(rd2.Symbol == 'V');
   ck_assert_int_eq(rd1.Value, 5);
   ck_assert_int_eq(rd2.Value, 5);
} END_TEST

/******** Character of "x" or "X" should have symbol "X" and value of 10 ******/
START_TEST(initialize_roman_digit_with_x_or_X_returns_symbol_X_value_10) {
   RomanDigit rd1 = newRomanDigit('x');
   RomanDigit rd2 = newRomanDigit('X');

   ck_assert(rd1.Symbol == 'X');
   ck_assert(rd2.Symbol == 'X');
   ck_assert_int_eq(rd1.Value, 10);
   ck_assert_int_eq(rd2.Value, 10);
} END_TEST

/******** Character of "l" or "L" should have symbol "L" and value of 50 ******/
START_TEST(initialize_roman_digit_with_l_or_L_returns_symbol_L_value_50) {
   RomanDigit rd1 = newRomanDigit('l');
   RomanDigit rd2 = newRomanDigit('L');

   ck_assert(rd1.Symbol == 'L');
   ck_assert(rd2.Symbol == 'L');
   ck_assert_int_eq(rd1.Value, 50);
   ck_assert_int_eq(rd2.Value, 50);
} END_TEST

/******* Character of "c" or "C" should have symbol "C" and value of 100 ******/
START_TEST(initialize_roman_digit_with_c_or_C_returns_symbol_C_value_100) {
   RomanDigit rd1 = newRomanDigit('c');
   RomanDigit rd2 = newRomanDigit('C');

   ck_assert(rd1.Symbol == 'C');
   ck_assert(rd2.Symbol == 'C');
   ck_assert_int_eq(rd1.Value, 100);
   ck_assert_int_eq(rd2.Value, 100);
} END_TEST

/******* Character of "d" or "D" should have symbol "D" and value of 500 ******/
START_TEST(initialize_roman_digit_with_d_or_D_returns_symbol_D_value_500) {
   RomanDigit rd1 = newRomanDigit('d');
   RomanDigit rd2 = newRomanDigit('D');

   ck_assert(rd1.Symbol == 'D');
   ck_assert(rd2.Symbol == 'D');
   ck_assert_int_eq(rd1.Value, 500);
   ck_assert_int_eq(rd2.Value, 500);
} END_TEST

/****** Character of "m" or "M" should have symbol "M" and value of 1000 ******/
START_TEST(initialize_roman_digit_with_m_or_M_returns_symbol_M_value_1000) {
   RomanDigit rd1 = newRomanDigit('m');
   RomanDigit rd2 = newRomanDigit('M');

   ck_assert(rd1.Symbol == 'M');
   ck_assert(rd2.Symbol == 'M');
   ck_assert_int_eq(rd1.Value, 1000);
   ck_assert_int_eq(rd2.Value, 1000);
} END_TEST

/*********** Test to insure values other than IVXLCD or M will fail ***********/
START_TEST(initialize_roman_digit_with_invalid_value_returns_symbol_Null_value_0) {
   RomanDigit rd1 = newRomanDigit('A');

   ck_assert(rd1.Symbol == 'N');
   ck_assert_int_eq(rd1.Value, 0);
} END_TEST

/*******************************************************************************
 * Create Data Structure to Represent a Roman Number                           *
 ******************************************************************************/

/************** Create Data Structure to Represent a Roman Number *************/
START_TEST(create_data_structure_to_represent_a_roman_number) {
   RomanDigit rd = newRomanDigit('M');
   RomanNumber rn;
  
   rn.Size = 1;
   rn.Digit[0] = rd;

   ck_assert_int_eq(rn.Size, 1);
   ck_assert(rn.Digit[0].Symbol == 'M');
   ck_assert_int_eq(rn.Digit[0].Value, 1000);
} END_TEST

/***** Initialize a simple value then check the structure that comes back *****/
START_TEST(initialize_roman_number_with_a_simple_single_digit_value) {
   RomanNumber rn = newRomanNumber("I");

   ck_assert_int_eq(rn.Size, 1);
   ck_assert(rn.Digit[0].Symbol == 'I');
   ck_assert_int_eq(rn.Digit[0].Value, 1);
} END_TEST

/**** Initialize a two-digit value then check the structure that comes back ***/
START_TEST(initialize_roman_number_with_a_simple_two_digit_value) {
   RomanNumber rn = newRomanNumber("VI");

   ck_assert_int_eq(rn.Size, 2);
   ck_assert(rn.Digit[0].Symbol == 'V');
   ck_assert_int_eq(rn.Digit[0].Value, 5);
   ck_assert(rn.Digit[1].Symbol == 'I');
   ck_assert_int_eq(rn.Digit[1].Value, 1);
} END_TEST

/***************** Initialize a value with subtractive digits *****************/
START_TEST(initialize_a_value_with_subtractive_digits) {
   RomanNumber rn = newRomanNumber("XIX");

   ck_assert_int_eq(rn.Size, 3);

   ck_assert(rn.Digit[0].Symbol == 'X');
   ck_assert_int_eq(rn.Digit[0].Value, 10);

   ck_assert(rn.Digit[1].Symbol == 'I');
   ck_assert_int_eq(rn.Digit[1].Value, -1);

   ck_assert(rn.Digit[2].Symbol == 'X');
   ck_assert_int_eq(rn.Digit[2].Value, 10);
} END_TEST

/********************** Initialize a Complex Number Value *********************/
START_TEST(initialize_a_value_with_complex_structure) {
   RomanNumber rn = newRomanNumber("MCMXCIX");

   ck_assert_int_eq(rn.Size, 7);

   ck_assert(rn.Digit[0].Symbol == 'M');
   ck_assert_int_eq(rn.Digit[0].Value, 1000);

   ck_assert(rn.Digit[1].Symbol == 'C');
   ck_assert_int_eq(rn.Digit[1].Value, -100);

   ck_assert(rn.Digit[2].Symbol == 'M');
   ck_assert_int_eq(rn.Digit[2].Value, 1000);

   ck_assert(rn.Digit[3].Symbol == 'X');
   ck_assert_int_eq(rn.Digit[3].Value, -10);

   ck_assert(rn.Digit[4].Symbol == 'C');
   ck_assert_int_eq(rn.Digit[4].Value, 100);

   ck_assert(rn.Digit[5].Symbol == 'I');
   ck_assert_int_eq(rn.Digit[5].Value, -1);

   ck_assert(rn.Digit[6].Symbol == 'X');
   ck_assert_int_eq(rn.Digit[6].Value, 10);
} END_TEST

/*******************************************************************************
 * Create a "toInt" function to return value of a Roman Number                 *
 ******************************************************************************/

/********* Create a "toInt" function to return value of a Roman Number ********/
START_TEST(roman_numberal_to_a_function) {
   RomanNumber rn = newRomanNumber("iiiiiii");
   uint32_t value = to_a(rn);

   ck_assert_int_eq(value, 7);
} END_TEST

/******** Create a number from the string "I" -> toInt should return 1 ********/
START_TEST(roman_number_I_should_have_value_1) {
   RomanNumber rn = newRomanNumber("I");
   uint32_t value = to_a(rn);

   ck_assert_int_eq(value, 1);
} END_TEST

/******** Create a number from the string "VI" -> toInt should return 6 *******/
START_TEST(roman_number_VI_should_have_value_6) {
   RomanNumber rn = newRomanNumber("VI");
   uint32_t value = to_a(rn);

   ck_assert_int_eq(value, 6);
} END_TEST

/******* Create a number from the string "XIX" -> toInt should return 19 ******/
START_TEST(roman_number_XIX_should_have_value_19) {
   RomanNumber rn = newRomanNumber("XIX");
   uint32_t value = to_a(rn);

   ck_assert_int_eq(value, 19);
} END_TEST

/**** Create a number from the string "MCMXCIX" -> toInt should return 1999 ***/
START_TEST(roman_number_MCMXCIX_should_have_value_1999) {
   RomanNumber rn = newRomanNumber("MCMXCIX");
   uint32_t value = to_a(rn);

   ck_assert_int_eq(value, 1999);
} END_TEST

/*******************************************************************************
 * Create a "toString" function to return the the string form of Roman Number  *
 ******************************************************************************/

/* Create a "toString" function to return the the string form of Roman Number */
START_TEST(roman_numberal_to_string_function) {
   RomanNumber rn = newRomanNumber("iiiiiii");

   ck_assert_str_eq("IIIIIII", to_string(rn));
} END_TEST

/*************** Testing "to_string()" with single digit value ****************/
START_TEST(roman_numberal_to_string_single_digit) {
   ck_assert_str_eq("I", to_string(newRomanNumber("i")));
} END_TEST

/**************** Testing "to_string()" with multi-digit value ****************/
START_TEST(roman_numberal_to_string_multi_digit) {
   ck_assert_str_eq("VI", to_string(newRomanNumber("vi")));
} END_TEST

/*********** Testing "to_string()" with subtractive notation value ************/
START_TEST(roman_numberal_to_string_with_subtractive_notation) {
   ck_assert_str_eq("XIX", to_string(newRomanNumber("xix")));
} END_TEST

/****************** Testing "to_string()" with complex value ******************/
START_TEST(roman_numberal_to_string_with_complex_value) {
   ck_assert_str_eq("MCMXCIX", to_string(newRomanNumber("mcmxcix")));
} END_TEST

/*******************************************************************************
 * Substitute for any subtractives in value                                    *
 ******************************************************************************/

/******* Create a function to rewrite value into additive only notation *******/
START_TEST(substitute_for_any_subtractives_in_value) {
   RomanNumber rn = newRomanNumber("MDCLXVI");
   char *before, *after;

   before = to_string(rn);
   rnRemoveSubtractive(&rn);
   after = to_string(rn);

   ck_assert_str_eq(before, after);
} END_TEST

/*** A single digit can not be out of order, so it should not change value ****/
START_TEST(substitute_for_any_subtractives_single_digit_value) {
   RomanNumber rn = newRomanNumber("I");

   rnRemoveSubtractive(&rn);

   ck_assert_str_eq("I", to_string(rn));
} END_TEST

/* Testing a simple number consisting of only a single value needing conversion */
START_TEST(substitute_for_any_subtractives_simple_subtractive_value) {
   RomanNumber rn = newRomanNumber("IV");

   rnRemoveSubtractive(&rn);

   ck_assert_str_eq("IIII", to_string(rn));
} END_TEST

/********* Testing Remove Subtractive with static and changing values *********/
/** Also testing subtractive value two values above subtractor instead of one */
START_TEST(substitute_for_any_subtractives_with_changing_and_nonchanging_values) {
   RomanNumber rn = newRomanNumber("XIX");

   rnRemoveSubtractive(&rn);

   ck_assert_str_eq("XVIIII", to_string(rn));
} END_TEST

/*************** Testing Remove Subtractive with complex value ****************/
START_TEST(substitute_for_any_subtractives_complex_subtractive_value) {
   RomanNumber rn = newRomanNumber("MCMXCIX");

   rnRemoveSubtractive(&rn);

   ck_assert_str_eq("MDCCCCLXXXXVIIII", to_string(rn));
} END_TEST

/*******************************************************************************
 * Concatinate digits of two values into one new one                           *
 ******************************************************************************/

/******** Create a function to create one value from the digits of two ********/
START_TEST(concatinate_all_the_digits_of_two_numbers_into_a_new_value) {
   RomanNumber rnFirst = newRomanNumber("MDC");
   RomanNumber rnSecond = newRomanNumber("LXVI");

   RomanNumber concat = rnConcatinate(rnFirst, rnSecond);

   ck_assert_str_eq("MDCLXVI", to_string(concat));
} END_TEST

/********************** Combine two single digit values ***********************/
START_TEST(concatinate_all_the_digits_two_single_digit_values) {
   RomanNumber rnFirst = newRomanNumber("I");
   RomanNumber rnSecond = newRomanNumber("I");

   RomanNumber concat = rnConcatinate(rnFirst, rnSecond);

   ck_assert_str_eq("II", to_string(concat));
} END_TEST

/***************** Combine a single digit to multiple digits ******************/
START_TEST(concatinate_all_the_digits_of_a_single_and_double_digit_value) {
   RomanNumber rnFirst = newRomanNumber("I");
   RomanNumber rnSecond = newRomanNumber("VI");

   RomanNumber concat = rnConcatinate(rnFirst, rnSecond);

   ck_assert_str_eq("IVI", to_string(concat));
} END_TEST

/************* Concatenate single digit to non-standardized value *************/
START_TEST(concatinate_all_the_digits_of_a_single_and_nonstandard_value) {
   RomanNumber rnFirst = newRomanNumber("I");
   RomanNumber rnSecond = newRomanNumber("XVIIII");

   RomanNumber concat = rnConcatinate(rnFirst, rnSecond);

   ck_assert_str_eq("IXVIIII", to_string(concat));
} END_TEST

/***** Concatenate multi-digit value to a non-standardized complex value ******/
START_TEST(concatinate_all_the_digits_of_a_multidigit_and_complex_value) {
   RomanNumber rnFirst = newRomanNumber("VI");
   RomanNumber rnSecond = newRomanNumber("MDCCCCLXXXXVIIII");

   RomanNumber concat = rnConcatinate(rnFirst, rnSecond);

   ck_assert_str_eq("VIMDCCCCLXXXXVIIII", to_string(concat));
} END_TEST

/****************** Concatenate two non-standardized numbers ******************/
START_TEST(concatinate_all_the_digits_of_two_nonstandard_values) {
   RomanNumber rnFirst = newRomanNumber("XVIIII");
   RomanNumber rnSecond = newRomanNumber("XVIIII");

   RomanNumber concat = rnConcatinate(rnFirst, rnSecond);

   ck_assert_str_eq("XVIIIIXVIIII", to_string(concat));
} END_TEST

/************** Concatenate multi-digit value to a complex value **************/
START_TEST(concatinate_all_the_digits_of_two_complex_values) {
   RomanNumber rnFirst = newRomanNumber("MDCCCCLXXXXVIIII");
   RomanNumber rnSecond = newRomanNumber("MDCCCCLXXXXVIIII");

   RomanNumber concat = rnConcatinate(rnFirst, rnSecond);

   ck_assert_str_eq("MDCCCCLXXXXVIIIIMDCCCCLXXXXVIIII", to_string(concat));
} END_TEST

Suite * roman_number_math_suite(void) {
   Suite *testSuite;
   TCase *tc_roman_digit, *tc_roman_number, *tc_debug, *tc_remove_sub, *tc_concat;

   testSuite = suite_create("Roman Math 2");

   /* Testing Creating of Roman Digits */
   tc_roman_digit = tcase_create("Roman Digits");

   tcase_add_test(tc_roman_digit, create_data_structure_to_represent_a_roman_digit);
   tcase_add_test(tc_roman_digit, initialize_roman_digit_with_i_or_I_returns_symbol_I_value_1);
   tcase_add_test(tc_roman_digit, initialize_roman_digit_with_v_or_V_returns_symbol_V_value_5);
   tcase_add_test(tc_roman_digit, initialize_roman_digit_with_x_or_X_returns_symbol_X_value_10);
   tcase_add_test(tc_roman_digit, initialize_roman_digit_with_l_or_L_returns_symbol_L_value_50);
   tcase_add_test(tc_roman_digit, initialize_roman_digit_with_c_or_C_returns_symbol_C_value_100);
   tcase_add_test(tc_roman_digit, initialize_roman_digit_with_d_or_D_returns_symbol_D_value_500);
   tcase_add_test(tc_roman_digit, initialize_roman_digit_with_m_or_M_returns_symbol_M_value_1000);
   tcase_add_test(tc_roman_digit, initialize_roman_digit_with_invalid_value_returns_symbol_Null_value_0);

   suite_add_tcase(testSuite, tc_roman_digit);

   /* Testing Creating of Roman Digits */
   tc_roman_number = tcase_create("Roman Numbers");

   tcase_add_test(tc_roman_number, create_data_structure_to_represent_a_roman_number);
   tcase_add_test(tc_roman_number, initialize_roman_number_with_a_simple_single_digit_value);
   tcase_add_test(tc_roman_number, initialize_roman_number_with_a_simple_two_digit_value);
   tcase_add_test(tc_roman_number, initialize_a_value_with_subtractive_digits);
   tcase_add_test(tc_roman_number, initialize_a_value_with_complex_structure);

   suite_add_tcase(testSuite, tc_roman_number);

   /* Testing Debug/Display functions */
   tc_debug = tcase_create("Debug");

   tcase_add_test(tc_debug, roman_numberal_to_a_function);
   tcase_add_test(tc_debug, roman_number_I_should_have_value_1);
   tcase_add_test(tc_debug, roman_number_VI_should_have_value_6);
   tcase_add_test(tc_debug, roman_number_XIX_should_have_value_19);
   tcase_add_test(tc_debug, roman_number_MCMXCIX_should_have_value_1999);

   tcase_add_test(tc_debug, roman_numberal_to_string_function);
   tcase_add_test(tc_debug, roman_numberal_to_string_single_digit);
   tcase_add_test(tc_debug, roman_numberal_to_string_multi_digit);
   tcase_add_test(tc_debug, roman_numberal_to_string_with_subtractive_notation);
   tcase_add_test(tc_debug, roman_numberal_to_string_with_complex_value);

   suite_add_tcase(testSuite, tc_debug);

   /* Testing Debug/Display functions */
   tc_remove_sub = tcase_create("Remove Subtractive Notation");

   tcase_add_test(tc_remove_sub, substitute_for_any_subtractives_in_value);
   tcase_add_test(tc_remove_sub, substitute_for_any_subtractives_single_digit_value);
   tcase_add_test(tc_remove_sub, substitute_for_any_subtractives_simple_subtractive_value);
   tcase_add_test(tc_remove_sub, substitute_for_any_subtractives_with_changing_and_nonchanging_values);
   tcase_add_test(tc_remove_sub, substitute_for_any_subtractives_complex_subtractive_value);
   
   suite_add_tcase(testSuite, tc_remove_sub);

   /* Testing Debug/Display functions */
   tc_concat= tcase_create("Remove Subtractive Notation");

   tcase_add_test(tc_concat, concatinate_all_the_digits_of_two_numbers_into_a_new_value);
   tcase_add_test(tc_concat, concatinate_all_the_digits_two_single_digit_values);
   tcase_add_test(tc_concat, concatinate_all_the_digits_of_a_single_and_double_digit_value);
   tcase_add_test(tc_concat, concatinate_all_the_digits_of_a_single_and_nonstandard_value);
   tcase_add_test(tc_concat, concatinate_all_the_digits_of_a_multidigit_and_complex_value);
   tcase_add_test(tc_concat, concatinate_all_the_digits_of_two_nonstandard_values);
   tcase_add_test(tc_concat, concatinate_all_the_digits_of_two_complex_values);

   suite_add_tcase(testSuite, tc_concat);

   return testSuite;
}

int main(int argc, char *argv[]) {
   int number_failed;
   Suite *testSuite;
   SRunner *suiteRunner;

   testSuite = roman_number_math_suite();
   suiteRunner = srunner_create(testSuite);

   srunner_run_all(suiteRunner, CK_NORMAL);
   number_failed = srunner_ntests_failed(suiteRunner);
   srunner_free(suiteRunner);
   return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

