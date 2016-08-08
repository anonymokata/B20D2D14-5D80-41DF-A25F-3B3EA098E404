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

Suite * roman_number_math_suite(void) {
   Suite *testSuite;
   TCase *tc_roman_digit, *tc_roman_number, *tc_debug;

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

   suite_add_tcase(testSuite, tc_debug);

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

