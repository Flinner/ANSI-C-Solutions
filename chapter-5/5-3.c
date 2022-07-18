/* Exercise 5-3. Write a pointer version of the function strcat that we showed
 * in Chapter 2:  strcat(s,t) copies the string t to the end of s.  */

#include <ctype.h>
#include <stdio.h>

// version 1
void my_strcat1(char *s, char *t) {
  while (*s)
    s++; // go to end of s

  while ((*s = *t) != '\0') {
    s++;
    t++;
  }
}

// version 2
void my_strcat2(char *s, char *t) {
  while (*s)
    s++; // go to end of s
  while ((*s++ = *t++))
    ; // then copy
}

int main() {
  char s[50] = "Hello, ";
  char t[] = "world!";

  my_strcat2(s, t);

  printf("%s\n", s);

  return 0;
}
