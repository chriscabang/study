#include <stdio.h>
#include <stdlib.h>

/* Two Sum
 * 
 * Source : https://oj.leetcode.com/problems/two-sum
 * 
 * Given an array if integers, find two numbers such that they add up to a
 * specific target numbers.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * You can return the answer in any order.
 *
 * Example:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0,1]
 *
 * Example:
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 */

// rev.1
// Brute force our way to finding it, doing a nested loop until we find
// the pair. 
// Time Complexity: O(n^2) : Nested loops
// Space Complexity: O(1)  : No extra space, doing return by reference
int* rev1(int* nums, int numSize, int target, int* returnSize) {
  *returnSize = 2;
  int* answer = (int*) malloc(*returnSize * sizeof(int));

  for (int i = 0; i < numSize; i++) {
    for (int n = i + 1; n < numSize; n++) {
      if (nums[i] + nums[n] == target) {
        answer[0] = i;
        answer[1] = n;
        return answer;
      }
    }
  }
  *returnSize = 0;
  return 0;
}

typedef struct {
  int index;
  int value;
} Number;

int compare(const void* a, const void* b) {
  return ((Number*)a)->value - ((Number*)b)->value;
}

// rev.2
// Two pointer approach, after sorting array.
// Time Complexity: O(n) + O(nlogn) = O(nlogn) : sorting and array traversal
// Space Complexity: O(n) : additional array
int* rev2(int* nums, int numSize, int target, int* returnSize) {
  // Load array and its indexes into the structured array.
  Number numbers[numSize];
  for (int i = 0; i < numSize; i++) {
    numbers[i].index = i;
    numbers[i].value = nums[i];
  }

  // Sort array ascendingly.
  qsort(numbers, numSize, sizeof(Number), compare);

  int left = 0;
  int right = numSize - 1;
  while (left < right) {
    int sum = numbers[left].value + numbers[right].value;
    if (sum == target) {
      *returnSize = 2;
      int* answer = (int*) malloc(*returnSize * sizeof(int));
      answer[0] = numbers[left].index;
      answer[1] = numbers[right].index;
      return answer;
    } else if (sum < target) {
      // Move towards the right
      // -->
      left++;
    } else {
      // Move towards the left
      // <--
      right--;
    }
  }

  *returnSize = 0;
  return 0;
}

int main() {
  int size = 0;
  // int nums[] = { 3, 2, 4 }; int target = 6
  int nums[] = { 2, 7, 11, 15 }; int target = 9;
  // int nums[] = { 3, 3 }; int target = 6;
  //int nums[] = { 2, 1 }; int target = 4;
  int numSize = (int)(sizeof(nums)/sizeof(int));
  int* answer = rev2(nums, numSize, target, &size);
  printf("[ ");
  for (int n = 0; n < numSize; n++) {
    printf("%d", nums[n]);
    if (n+1 != numSize) printf(",");
  } printf(" ]");
  printf(" : target = %d -> ", target);
  if (size == 0 ) {
    printf("no possible answer found\n");
  } else {
    printf("answer = [ %d, %d ]\n", answer[0], answer[1]);
  }
  return 0;
}
