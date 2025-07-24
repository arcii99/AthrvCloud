//FormAI DATASET v1.0 Category: Math exercise ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
    int num1, num2, num3, num4, res;
    double angle1, angle2, hypotenuse, area, radius, circumference;

    // Generate random numbers between 1 and 10
    srand((unsigned)time(NULL)); 
    num1 = rand() % 10 + 1;
    num2 = rand() % 10 + 1;
    num3 = rand() % 10 + 1;
    num4 = rand() % 10 + 1;

    // Math problem 1: Add num1 and num2 and multiply by num3
    res = (num1 + num2) * num3;
    printf("Problem 1: What is (%d + %d) * %d?\n", num1, num2, num3);
    printf("Answer 1: %d\n", res);

    // Math problem 2: Find the hypotenuse of a right triangle with angle1 and angle2
    angle1 = rand() % 90 + 1;
    angle2 = 90 - angle1;
    hypotenuse = sqrt(pow(num1, 2) + pow(num2, 2));
    printf("\nProblem 2: What is the hypotenuse of a right triangle with angles %.2lf degrees and %.2lf degrees, and sides %d and %d?\n", angle1, angle2, num1, num2);
    printf("Answer 2: %.2lf\n", hypotenuse);

    // Math problem 3: Find the area of a circle with radius num3
    radius = num3;
    area = M_PI * pow(radius, 2);
    printf("\nProblem 3: What is the area of a circle with radius %d?\n", num3);
    printf("Answer 3: %.2lf\n", area);

    // Math problem 4: Find the circumference of a circle with radius num4
    circumference = 2 * M_PI * num4;
    printf("\nProblem 4: What is the circumference of a circle with radius %d?\n", num4);
    printf("Answer 4: %.2lf\n", circumference);

    return 0;
}