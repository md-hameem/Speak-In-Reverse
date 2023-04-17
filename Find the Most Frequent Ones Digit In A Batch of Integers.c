#include <stdio.h>

int main() {
    int maxLength;
    int len = 0;

    // Prompt user to enter maximum number of integers to read and read input from user
    printf("Enter the maximum number of integers to read: ");
    scanf("%d", &maxLength);

    // Declare array to store integers entered by user
    int num[maxLength];

    // Prompt user to enter up to maxLength integers separated by spaces and read input from user
    printf("Enter up to %d integers separated by spaces: ", maxLength);
    while (len < maxLength && scanf("%d", &num[len]) == 1) {
        len++;
    }

    // Initialize an array to store count of each digit in all numbers entered by user
    int count[10] = {0};

    // Iterate over all numbers entered by user to count digits
    for (int i = 0; i < len; i++) {
        int n = num[i];

        // Count each digit in the number
        while (n > 0) {
            int digit = n % 10;
            count[digit]++;
            n /= 10;
        }
    }

    // Find the digit with the highest frequency count
    int max = 0;
    int maxIndex = 0;

    for (int i = 0; i < 10; i++) {
        if (count[i] > max) {
            max = count[i];
            maxIndex = i;
        }
    }

    // Set the frequency count of the most frequent digit to zero to find the next most frequent digit
    count[maxIndex] = 0;
    int maxEnd = 0;
    int maxEndIndex = 0;

    // Find the digit with the second highest frequency count
    for (int i = 0; i < 10; i++) {
        if (count[i] > maxEnd) {
            maxEnd = count[i];
            maxEndIndex = i;
        }
    }

    // Print the result to the user
    if (max == maxEnd) {
        printf("The most frequent integers are %d and %d, each occurred %d times.", maxIndex, maxEndIndex, max);
    } else {
        printf("The most frequent integer is %d, occurred %d times.", maxIndex, max);
    }

    return 0;
}
