#include <ctype.h>
#include <stdio.h>
#define SIZE 100

int getfloat(double *pf) {
  int c, sign, dec;
  while (isspace(c = getchar())) /* ignore whitespace */
    ;
  if (c != EOF && c != '.' && c != '+' && c != '-' && !isdigit(c)) {
    ungetc(c, stdin); // not a number
    return c;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getchar();

  for (*pf = 0; isdigit(c); c = getchar()) {
    *pf = 10 * *pf + (c - '0');
  }

  if (c != '.' && c != EOF) {
    ungetc(c, stdin); // not a number after decimal
    return c;
  }

  if (c == '.') {
    c = getchar();
    for (dec = 1; isdigit(c); c = getchar(), dec++)
      *pf = *pf + (double)(c - '0') / (10 * dec);
  }

  *pf *= sign;

  if (c != EOF)
    ungetc(c, stdin);
  return c;
}

int main() {
  int n;
  double array[SIZE];
  for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
    ;
  printf("%lf", array[0]);
}
