//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: beginner-friendly
#include <stdio.h>

// Function that squares a number
float square(float num)
{
    float result = num * num;
    return result;
}

int main()
{
    float number;
    float result;

    // Input from user
    printf("Enter a number to be squared: ");
    scanf("%f", &number);

    // Squaring the number
    result = square(number);

    // Displaying the result
    printf("The square of %.2f is %.2f\n", number, result);

    return 0;
}