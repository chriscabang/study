#include <stdio.h>

int binary_gap(int N) {
    int maxGap = 0;
    int currentGap = 0;
    int countZeroes = 0;
    int foundOne = 0;

    // Iterate through the bits of N
    while (N > 0) {
        // Check if the least significant bit is a one
        if (N & 1) {
            if (foundOne) {
                // If a one is found after another one, update maxGap if needed
                maxGap = (currentGap > maxGap) ? currentGap : maxGap;
                currentGap = 0;
            } else {
                // Found the first one
                foundOne = 1;
            }
        } else {
            if (foundOne) {
                // Count consecutive zeroes after the first one
                currentGap++;
            }
        }

        // Right shift N by 1 bit
        N >>= 1;
    }

    return maxGap;
}

int main() {
    int number = 20; // Example input
    int result = binary_gap(number);

    printf("Longest sequence of zeroes: %d\n", result);

    return 0;
}
