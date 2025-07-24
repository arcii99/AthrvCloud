//FormAI DATASET v1.0 Category: Math exercise ; Style: brave
#include <stdio.h>
#include <math.h>

//This program calculates the distance between two points in 2D space

int main()
{
    double x1, y1, x2, y2, distance;

    printf("Enter the coordinates of the first point (x1,y1): ");
    scanf("%lf,%lf", &x1, &y1);

    printf("Enter the coordinates of the second point (x2,y2): ");
    scanf("%lf,%lf", &x2, &y2);

    distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    printf("The distance between the two points is: %.2lf\n", distance);

    printf("Now let's do something brave! Let's calculate the sine of the distance!\n");

    double sine = sin(distance);

    printf("The sine of %.2lf is: %.2lf\n", distance, sine);

    printf("Wow! That was fun! Let's do something even more adventurous!\n");

    double thirdSide = sqrt(pow(distance, 2) + pow(sine, 2));

    printf("We can now use the distance and sine to calculate the length of the third side of a right triangle.\n");

    printf("The length of the third side of a right triangle with hypotenuse %.2lf and opposite side sine(%.2lf) is %.2lf.\n", distance, distance, thirdSide);

    printf("We did a lot of math today! Hope you had as much fun as I did!");

    return 0;
}