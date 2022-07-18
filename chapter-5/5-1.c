
#include <ctype.h>
#include <stdio.h>
#define SIZE 100

int getint(int *pn) {
  int c, sign;
  while (isspace(c = getchar())) /* Ignore whitespace*/
    ;
  if (c != '+' && c != '-' && !isdigit(c) && c != EOF) {
    ungetc(c, stdin);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    c = getchar();
    if (!isdigit(c)) {
      ungetc(c, stdin);
      return c;
    }
  }

  for (*pn = 0; isdigit(c); c = getchar())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;

  if (c != EOF)
    ungetc(c, stdin);
  return c;
}

int main() {
  int n;
  double array[SIZE];
  for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
    ;
}
