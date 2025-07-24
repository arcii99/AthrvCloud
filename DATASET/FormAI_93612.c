//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: happy
// Happy Geometric Algorithms
// By Chatbot V1.0.0

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int radius, x, y;

    printf("Welcome to my happy geometric algorithms program!\n");
    printf("Please enter the radius of your circle: ");
    scanf("%d", &radius);

    float area = M_PI * pow(radius, 2);
    printf("\nAccording to my calculations, the area of your circle is %.2f.\n", area);

    printf("\nNow, please enter the x and y coordinates of your circle's center separated by a space: ");
    scanf("%d %d", &x, &y);

    printf("\nCalculating the equation of your circle...");
    printf("\nThe equation of your circle is (x-%d)^2 + (y-%d)^2 = %d^2.\n", x, y, radius);
    printf("\nGreat job! Your circle is perfectly happy. Thanks for using my program!");

    return 0;
}