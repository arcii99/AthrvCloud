//FormAI DATASET v1.0 Category: Math exercise ; Style: unmistakable
#include <stdio.h>      // Required header files

int main() 
{
    int num1, num2, num3, sum;      // Declaring variables
    float avg;

    printf("Enter three integers: ");        // Prompting user to enter input
    scanf("%d %d %d", &num1, &num2, &num3);         // Reading user input

    sum = num1 + num2 + num3;       // Calculating sum
    avg = (float) sum / 3;      // Calculating average of the given inputs

    printf("Sum = %d\n", sum);         // Displaying the sum of the given inputs
    printf("Average = %.2f\n", avg);        // Displaying the average of the given inputs
    printf("Ceiling value is %d\n", (int) ceil(avg));    // Displaying the ceiling value of the average
    printf("Floor value is %d\n", (int) floor(avg));      // Displaying the floor value of the average

    return 0;       // Returning exit status 0
}