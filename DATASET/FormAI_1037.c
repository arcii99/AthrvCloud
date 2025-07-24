//FormAI DATASET v1.0 Category: Math exercise ; Style: calm
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random float number between a given range
float randomFloat(float min, float max) {
    float range = (max - min);
    float div = RAND_MAX / range;
    return min + (rand() / div);
}

int main() {

    // seed the random number generator
    srand(time(NULL));

    printf("************ Math Exercise Example Program  ************\n\n");

    printf("In this exercise, we will generate three random numbers between 1 and 10 (inclusive).\n");
    printf("We will then use these numbers to solve three problems: \n\n");

    // generate a random integer between 1 and 10 (inclusive)
    int x = rand() % 10 + 1;
    int y = rand() % 10 + 1;
    int z = rand() % 10 + 1;

    // calculate the area of a triangle with base x and height y
    float triangleArea = 0.5 * x * y;

    printf("Problem 1: What is the area of a triangle with a base of %d and a height of %d?\n", x, y);
    printf("Answer: The area of the triangle is %.2f \n\n", triangleArea);

    // calculate the volume of a rectangular prism with dimensions x, y, and z 
    float rectPrismVol = x * y * z;

    printf("Problem 2: What is the volume of a rectangular prism with dimensions %d, %d, and %d?\n", x, y, z);
    printf("Answer: The volume of the rectangular prism is %.2f \n\n", rectPrismVol);

    // generate a random angle in degrees between 0 and 360 (inclusive)
    float angle = randomFloat(0.0, 360.0);

    // convert the angle to radians
    float radians = angle * M_PI / 180.0;

    // calculate the sine of the angle
    float sine = sin(radians);

    printf("Problem 3: What is the sine of an angle of %.2f degrees?\n", angle);
    printf("Answer: The sine of the angle is %.2f \n\n", sine);

    printf("****************** End of Program *****************\n");

    return 0;
}