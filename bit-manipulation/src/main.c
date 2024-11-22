#include <stdio.h>

#define and(x, y)   (x & y)
#define  or(x, y)   (x | y)
#define xor(x, y)   (x ^ y)
#define not(x   )   (~x   )

#define shift_left(x) (x << 1)
#define shift_right(x)(x >> 1)

int main() {
  int x = 5, y = 9;
  printf("and(%d, %d) = %d\n", x, y, and(x, y));
  printf("or (%d, %d) = %d\n", x, y, or (x, y));
  printf("xor(%d, %d) = %d\n", x, y, xor(x, y));
  printf("not(%d, %d) = %d\n", x, y, not(x   ));
  printf("");

  return 0;
}