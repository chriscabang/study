#include <stdlib.h>
#include <string.h>

/* Median of Two Sorted Arrays
 * 
 * Given two sorted arrays `nums` and `nums2` of size `m` and `n`
 * respectively, return the median of the two sorted arrays.
 *
 * The overall run time complexity should be O(log (m+n)).
 *
 * Example:
 *   Input: nums1 = [1,3], nums2 = [2]
 *   Output: 2.00000
 *   Explanation: merged array = [1,2,3] and median is 2
 *
 * Example:
 *  Input: nums1 = [1,2], nums = [3,4]
 *  Output: 2.50000
 *  Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5
 */

int compare(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

double get_median(int nums1[], int m, int nums2[], int n) {
  double median = 0;

  int size = m + n;
  int* nums = (int*) malloc(size * sizeof(int));
  memcpy(nums, nums1, m * sizeof(int));
  memcpy(nums+m, nums2, n * sizeof(int));

  qsort(nums, size, sizeof(int), compare);

  // check if odd or even, that's how we start computing for median
  if (size % 2 == 1) {
    median = (double)(nums[(int)(size / 2)]);
  } else {
    median = ((double)(nums[(int)( (size - 1) / 2)     ])  +
              (double)(nums[(int)(((size - 1) / 2) + 1)])) / 2;
  }
  return median;
}

int main() {
  int nums1[2] = { 1, 3 };
  int nums2[2] = { 2, 4 };
  double median = get_median(
      nums1, 
      sizeof(nums1)/sizeof(nums1[0]), 
      nums2, 
      sizeof(nums2)/sizeof(nums2[0]));
  return 0;
}
