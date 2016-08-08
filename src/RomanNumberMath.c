#include <stdio.h>
#include <stdlib.h>
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

int main (int argc, char *argv[]) {
   exit(EXIT_SUCCESS);
}
