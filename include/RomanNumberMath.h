#include <stdint.h>

#ifndef __ROMAN_MATH_2_H_
#define __ROMAN_MATH_2_H_

typedef struct {
   char Symbol;
   int Value;
} RomanDigit;

typedef struct {
   int Size;
   RomanDigit Digit[100];
} RomanNumber;

RomanDigit newRomanDigit(char);
RomanNumber newRomanNumber(char *);

uint32_t to_a(RomanNumber);
char *to_string(RomanNumber);

void rnRemoveSubtractive(RomanNumber *);

#endif
