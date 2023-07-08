#include <stdio.h>

#define max(x, y) ((x >= y) ? x : y)

int max_sum_contiguous_subarray(int arr[], int n) {
  int max_sum = arr[0];
  int cur_sum = arr[0];

  for (int c = 1; c < n; c++) {
    cur_sum = max(arr[c], cur_sum + arr[c]);
    max_sum = max(max_sum, cur_sum);
  }

  return max_sum;
}

int main() {
  int arr[]  = { 1, -3, 2, 1, -1 };
  int length = sizeof(arr)/sizeof(arr[0]); 
  
  printf("%d\n", max_sum_contiguous_subarray(arr, length));

  return 0;
}