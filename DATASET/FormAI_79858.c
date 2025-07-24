//FormAI DATASET v1.0 Category: Math exercise ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("\nI am so excited to show you this unique C Math exercise example program!\n\n");

    // Let's generate two random numbers
    srand(time(NULL));
    int num1 = rand() % 100;
    int num2 = rand() % 100;

    // Let's add them together
    int sum = num1 + num2;

    // Let's subtract the smaller from the larger
    int diff = abs(num1 - num2);

    // Let's multiply them together
    int product = num1 * num2;

    // Let's divide the larger from the smaller
    float quotient;
    if (num1 > num2) {
        quotient = (float) num1 / num2;
    } else {
        quotient = (float) num2 / num1;
    }

    // Let's find the average of the two numbers
    float average = (num1 + num2) / 2.0;

    // Let's print the results
    printf("The first random number is: %d\n", num1);
    printf("The second random number is: %d\n", num2);
    printf("The sum of the two numbers is: %d\n", sum);
    printf("The absolute difference between the two numbers is: %d\n", diff);
    printf("The product of the two numbers is: %d\n", product);
    printf("The larger number divided by the smaller number is: %f\n", quotient);
    printf("The average of the two numbers is: %f\n", average);

    printf("\nWasn't that exciting? I hope you had fun with this unique C Math exercise example program!");
    return 0;
}