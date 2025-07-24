//FormAI DATASET v1.0 Category: Educational ; Style: invasive
#include <stdio.h> 

int main() {

    printf("Welcome to the invasive style C program!\n");
    printf("We will be creating a program that calculates the average of 5 numbers.\n");

    int num1, num2, num3, num4, num5, sum;
    float avg;

    printf("Please enter the first number: ");
    scanf("%d", &num1);

    printf("Please enter the second number: ");
    scanf("%d", &num2);

    printf("Please enter the third number: ");
    scanf("%d", &num3);

    printf("Please enter the fourth number: ");
    scanf("%d", &num4);

    printf("Please enter the fifth number: ");
    scanf("%d", &num5);

    sum = num1 + num2 + num3 + num4 + num5;
    avg = (float)sum / 5;

    printf("\nThe sum of the numbers is: %d \n", sum);
    printf("The average of the numbers is: %f \n", avg);
    printf("Thank you for using this invasive program!\n");

    return 0; 
}