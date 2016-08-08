#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "RomanNumberMath.h"

#define NUMDIGITS 3

RomanDigit allowedDigits[NUMDIGITS] = {
   {'I', 1},
   {'V', 5},
   {'X', 10}
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
