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

Suite * roman_number_math_suite(void) {
   Suite *testSuite;
   TCase *tc_roman_digit;

   testSuite = suite_create("Roman Math 2");

   /* Testing Creating of Roman Digits */
   tc_roman_digit = tcase_create("Roman Digits");

   tcase_add_test(tc_roman_digit, create_data_structure_to_represent_a_roman_digit);
   tcase_add_test(tc_roman_digit, initialize_roman_digit_with_i_or_I_returns_symbol_I_value_1);
   tcase_add_test(tc_roman_digit, initialize_roman_digit_with_v_or_V_returns_symbol_V_value_5);

   suite_add_tcase(testSuite, tc_roman_digit);

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

