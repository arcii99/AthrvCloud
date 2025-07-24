//FormAI DATASET v1.0 Category: Arithmetic ; Style: high level of detail
#include <stdio.h>

/* Function to calculate the average of two numbers */
float calculateAverage(float num1, float num2) {
    float sum = num1 + num2;
    float avg = sum / 2.0;
    return avg;
}

/* Main function */
int main() {
    float x, y, z;

    /* Take input from the user */
    printf("Enter the value of x: ");
    scanf("%f", &x);

    printf("Enter the value of y: ");
    scanf("%f", &y);

    printf("Enter the value of z: ");
    scanf("%f", &z);

    /* Calculate the average of x and y */
    float avg1 = calculateAverage(x, y);

    /* Calculate the average of y and z */
    float avg2 = calculateAverage(y, z);

    /* Calculate the average of x, y, and z */
    float avg3 = calculateAverage(x, calculateAverage(y, z));

    /* Print the results */
    printf("The average of x and y is %.2f\n", avg1);
    printf("The average of y and z is %.2f\n", avg2);
    printf("The average of x, y, and z is %.2f\n", avg3);

    return 0;
}