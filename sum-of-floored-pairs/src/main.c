#include <stdio.h>

/* Sum of Floored Pairs
 *
 * Given an integer array `nums`, return the sum of `floor(nums[i] / nums[j])
 * for all pairs of indices `0 <= i, j < nums.length` in the array. Since the
 * answer may be too large, return **modulo** `10^9 + 7`.
 *
 * The `floor()` function returns the integer part of the division.
 *
 * Example:
 *   Input : nums = [2,5,9]
 *   Output: 10
 *   Explanation:
 *     floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
 *     floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
 *     floor(5 / 2) = 2
 *     floor(9 / 2) = 4
 *     floor(9 / 5) = 1
 *     We calculate the floor of the division for every pair of indices in
 *     the array then sum them up.
 *
 *  Input : nums = [7,7,7,7,7,7,7];
 *  Output: 49
 */

int get_floored_pair_sum(int* nums, int size) {
  int answer = 0;
  for (int n = 0; n < size; n++) {
    for (int i = 0; i < size; ++i) {
      if (n + 1 <= size) {
        answer += nums[n] / nums[i];
      } else {
        continue;
      }
    }
  }
  return answer;
}

int main() {
  int nums[] = 
    // { 2, 5, 9 }
  { 7, 7, 7, 7, 7, 7, 7 }
  ;
  int size = sizeof(nums)/sizeof(nums[0]);
  printf("nums = [");
  for (int i = 0; i < size; i++) {
    printf("%d", nums[i]);
    (i + 1) < size ? printf(", ") : printf("]");
  }
  printf(" = %d\n", get_floored_pair_sum(nums, size));
  return 0;
}
