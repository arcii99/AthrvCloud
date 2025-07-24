//FormAI DATASET v1.0 Category: Math exercise ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_num(int start, int end) {
    // Generate a random number given a starting and ending point
    return (rand() % (end - start + 1)) + start;
}

int gcd(int a, int b) {
    // Find the greatest common divisor of two integers using the Euclidean algorithm
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int num1 = random_num(1, 100); // Generate a random number between 1 and 100
    int num2 = random_num(1, 100);

    // Find the greatest common divisor of num1 and num2
    int greatest_common_divisor = gcd(num1, num2);

    // Calculate the least common multiple of num1 and num2
    int least_common_multiple = (num1 * num2) / greatest_common_divisor;

    // Ask the user to input an integer
    int input;
    printf("Enter an integer: ");
    scanf("%d", &input);

    // Compute the third number based on the input and print it
    int third_num = least_common_multiple / input;
    printf("The third number that when multiplied with %d and %d yields the same LCM as %d and %d is: %d\n", num1, num2, num1, num2, third_num);

    return 0;
}