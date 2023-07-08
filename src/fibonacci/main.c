#include <stdio.h>

int fibonacci(int n) {
  if(n == 0 || n == 1) {
    return n;
  }

  return fibonacci(n - 1) + fibonacci(n -2);
}

void print_fibonacci_series(int n) {
  for (int i = 0; i <= n; i++) {
    printf("%d ", fibonacci(i));
  }
}

int main() {
  int n = 6;
  
  printf("The %dth fibonacci number is %d: [ ", n, fibonacci(n));
  print_fibonacci_series(n);
  printf("]\n");

  return 0;
}