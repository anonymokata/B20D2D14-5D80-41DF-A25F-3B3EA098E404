#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "RomanNumberMath.h"

#define NUMDIGITS 7

RomanDigit allowedDigits[NUMDIGITS] = {
   {'I', 1},
   {'V', 5},
   {'X', 10},
   {'L', 50},
   {'C', 100},
   {'D', 500},
   {'M', 1000}
};

RomanDigit newRomanDigit(char c) {
   RomanDigit rd = {'N', 0};
   int idx;

   for (idx =  0; idx < NUMDIGITS; idx++) {
      if (allowedDigits[idx].Symbol == toupper(c)) {
         rd = allowedDigits[idx];
         break;
      }
   }

   return rd;
}

RomanNumber newRomanNumber(char *number) {
   RomanNumber returnValue;
   int idx;

   for (idx = 0; number[idx] != '\0'; idx++) {
      RomanDigit rd = newRomanDigit(number[idx]);

      if (rd.Value == 0) {
         returnValue.Size = 0;
         returnValue.Digit[0] = rd;
         return returnValue;
      } else {
         returnValue.Digit[returnValue.Size] = rd;

         if (returnValue.Size > 0)
            if (returnValue.Digit[returnValue.Size].Value > returnValue.Digit[returnValue.Size-1].Value)
               returnValue.Digit[returnValue.Size-1].Value *= -1;

         returnValue.Size++;
      }
   }

   return returnValue;
}

uint32_t to_a(RomanNumber number) {
   uint32_t returnValue;
   int idx;

   returnValue = 0;
   for (idx = 0; idx < number.Size; idx++) {
      RomanDigit digit = number.Digit[idx];
      returnValue += digit.Value;
   }

   return returnValue;
}

char *to_string(RomanNumber number) {
   char *returnValue = (char *)malloc((number.Size+1) * sizeof(char));
   int idx;

   returnValue[number.Size] = '\0';
   for (idx = 0; idx < number.Size; idx++)
      returnValue[idx] = number.Digit[idx].Symbol;

   return returnValue;
}
