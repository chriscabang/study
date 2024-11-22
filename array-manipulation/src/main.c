#include <stdio.h>

#define max(x, y) ((x >= y) ? x : y)

void print_array(int arr[]) {
  int size = 5; //sizeof(arr)/sizeof(arr[0]);
  for (int i = 0; i < size; i++) {
      printf("%d ", arr[i]);
  }
  printf("\n");
}

/**
 * Find smallest missing value in array { 1, -3, 2, 1, -1 };
*/
int smallest_missing_value(int A[], int N) {
  // Mark the existence of values using the array indices
  print_array(A);
  for (int i = 0; i < N; i++) {
    while (A[i] >= 1 && A[i] <= N && A[A[i] - 1] != A[i]) {
      int temp = A[A[i] - 1];
      A[A[i] - 1] = A[i];
      A[i] = temp;
    }
  }
  print_array(A);

  // Find the first missing value by checking for mismatches
  for (int i = 0; i < N; i++) {
    if (A[i] != i + 1) {
      return i + 1;
    }
  }
  print_array(A);

  // If all values are present, return the next value
  return N + 1;
}

/**
 * Find the max sum of any contiguous sub array.
*/
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
  
  printf("Subarray has max contiguous value: %d\n", max_sum_contiguous_subarray(arr, length));

  printf("Smallest missing value: %d \n", smallest_missing_value(arr, length));

  return 0;
}