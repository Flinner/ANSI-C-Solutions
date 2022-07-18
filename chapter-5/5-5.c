/* Exercise 5-5. Write versions of the library functions strncpy,
strncat, and strncmp, which  operate on at most the first n
characters of their argument strings. For example,
strncpy(s,t,n) copies at most n characters of t to s. Full
descriptions are in Appendix B.  */

#include <stdio.h>

void my_strncpy(char *s, char *t, int n) {
  while (n-- > 0 && (*s++ = *t++))
    ;
}

void my_strncat(char *s, char *t, int n) {
  while (*s)
    s++;
  while (n-- > 0 && (*s++ = *t++))
    ;
}

int my_strncmp(char *s, char *t, int n) {
  while (n-- > 0 && (*s == *t)) {
    s++;
    t++;
  };
  return *s - *t;
}

int main() {
  char s1[30] = "Hello, Gentlemen!";
  char t1[30] = "1234567890:D";

  // this is for printf
  char *s_old = "Hello, Gentlemen!";

  my_strncpy(s1, t1, 5);
  printf("strncpy(s = %s,t = %s, n = %d ) = %s \n", s_old, t1, 5, s1);

  //
  char a[30] = "Hello, ";
  char *b = "World!lol, not included";
  my_strncat(a, b, 6);
  printf("%s\n", a);

  // tested on more cases.
  char *smol = "123445";
  char *larg = "123455";
  printf("strncmp(s = %s,t = %s, n = %d ) = %d \n", smol, larg, 5,
         my_strncmp(smol, larg, 5));
  return 0;
}
