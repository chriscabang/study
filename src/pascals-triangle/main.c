#include <stdio.h>

int binomial_coefficient(int n, int k) {
  if (k == 0 || k == n) {
    return 1;
  }

  return binomial_coefficient(n - 1, k - 1) + binomial_coefficient(n - 1, k);
}

void pascal_triangle(int rows) {
  // loop through the number of rows
  for (int count = 0; count < rows; count++) {
    // 1. prettify, show spaces
    for (int space = 0; space < rows - count - 1; space++) {
      printf(" ");
    }

    // 2. set values per row
    for (int value = 0; value <= count; value++) {
      printf("%d ", binomial_coefficient(count, value));
    }

    printf("\n");
  }
}

int main() {
  int rows = 6;
  
  pascal_triangle(rows);

  return 0;
}