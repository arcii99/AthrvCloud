//FormAI DATASET v1.0 Category: Math exercise ; Style: excited
#include <stdio.h>
#include <math.h>

int main() {
    printf("Let's practice some amazing C Math exercises!\n");
    printf("Are you ready to dive in? Let's do this!\n\n");

    // Exercise 1: Calculate the area of a circle
    float radius = 5.6;
    float circle_area = M_PI * pow(radius, 2);
    printf("Exercise 1:\n");
    printf("Calculate the area of a circle with a radius of %f.\n", radius);
    printf("Answer: %f sq. units\n\n", circle_area);

    // Exercise 2: Convert radians to degrees
    float radians = 1.57; // 90 degrees
    float degrees = radians * (180/M_PI);
    printf("Exercise 2:\n");
    printf("Convert %f radians into degrees.\n", radians);
    printf("Answer: %f degrees\n\n", degrees);

    // Exercise 3: Find the hypotenuse of a right triangle
    float side1 = 4.2;
    float side2 = 7.5;
    float hypotenuse = sqrt(pow(side1, 2) + pow(side2, 2));
    printf("Exercise 3:\n");
    printf("Find the hypotenuse of a right triangle with sides of %f and %f.\n", side1, side2);
    printf("Answer: %f units\n\n", hypotenuse);

    // Exercise 4: Calculate the natural logarithm of a number
    float num = 12.3;
    float logarithm = log(num);
    printf("Exercise 4:\n");
    printf("Calculate the natural logarithm of %f.\n", num);
    printf("Answer: %f\n\n", logarithm);

    // Exercise 5: Calculate the power of a number
    float base = 2.5;
    float exponent = 3.0;
    float power = pow(base, exponent);
    printf("Exercise 5:\n");
    printf("Calculate %f raised to the power of %f.\n", base, exponent);
    printf("Answer: %f\n\n", power);

    printf("Wow, that was amazing! Keep practicing! :)\n");

    return 0;
}