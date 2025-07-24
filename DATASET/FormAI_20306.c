//FormAI DATASET v1.0 Category: Arithmetic ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    int start, end, sum;
    printf("Please enter the starting number: ");
    scanf("%d", &start);
    getchar(); // remove the newline character from the input buffer
    printf("Please enter the ending number: ");
    scanf("%d", &end);
    getchar(); // remove the newline character from the input buffer

    // Calculate the sum of integers in the given range using the arithmetic sequence formula
    sum = (end - start + 1) * (start + end) / 2;

    printf("The sum of integers from %d to %d is %d\n", start, end, sum);
    printf("Elementary, my dear Watson!\n");
    return 0;
}