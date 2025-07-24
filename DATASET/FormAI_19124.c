//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: enthusiastic
#include <stdio.h>
#define PI 3.14159265 //setting the value of Pi as constant

int main()
{
    printf("Welcome to the Circle Area Calculator!\n");
    printf("Please enter the radius of the circle: ");

    float radius; //declaring a variable to store the radius input
    scanf("%f", &radius); //taking user input for the radius

    float area = PI * radius * radius; //performing the calculation for circle area

    printf("The area of the circle with radius %.2f is %.2f.\n", radius, area);
    printf("Thank you for using the Circle Area Calculator. Have a great day!");

    return 0;
}