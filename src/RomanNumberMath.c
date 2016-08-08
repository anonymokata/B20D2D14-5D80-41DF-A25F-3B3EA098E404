#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "RomanNumberMath.h"

RomanDigit newRomanDigit(char c) {
   RomanDigit rd;

   rd.Symbol = toupper(c);
   rd.Value = 1;

   return rd;
}

int main (int argc, char *argv[]) {
   exit(EXIT_SUCCESS);
}
