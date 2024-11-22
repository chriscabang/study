#include <stdio.h>
#include <string.h>

int main() {

  int count = 100;
  for (int n = 1; n <= count; n++) {
    char s[10] = "";
    if (n % 3 == 0) strcat(s, "Fizz");
    if (n % 5 == 0) strcat(s, "Buzz");
    if (strlen(s) == 0) printf("%d ", n);
    else                printf("%s ", s);
  }
  printf("\n");

  return 0;
}