//FormAI DATASET v1.0 Category: Scientific ; Style: peaceful
#include <stdio.h>

/* This program calculates the area of a circle with radius r */

float pi = 3.14159; // define pi

int main() {
    float r; // declare radius variable
    printf("Please enter a value for the radius of the circle: ");
    scanf("%f", &r); // store user input in r

    // calculate area using formula A = pi * r^2
    float A = pi * r * r;

    printf("The area of the circle with radius %f is %f.\n", r, A);
    
    return 0;
}