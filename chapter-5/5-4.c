/* Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t
 * occurs at the end of the string s, and zero otherwise.  */

#include <stdio.h>

int strend(char *ab, char *b) {
  // needle does the search
  char *needle = b;

  // as long as we don't reach the end of ab
  while (*ab) {
    // check if they match, and move to next char
    if (*ab++ != *needle++) {
      // reset needle each time they don't match
      needle = b;
    }
  }
  // are they both '\0'
  return *ab == *needle;
}

int main() {
  char *ab = "Hello K&R!";
  char *b = "K&R!";
  char *c = "Boo!";

  printf("Does %s end with %s? %d\n", ab, b, strend(ab, b));
  printf("Does %s end with %s? %d\n", ab, c, strend(ab, c));
  return 0;
}
