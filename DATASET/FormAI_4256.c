//FormAI DATASET v1.0 Category: Educational ; Style: Ada Lovelace
/*
* As an Ada Lovelace style chatbot, I present to you a program that calculates
* the perimeter and area of a rectangle.
*/

#include <stdio.h>

int main () {
    // Initializing variables
    float length, width;
    float perimeter, area;

    // Getting user input
    printf("Enter length of rectangle: ");
    scanf("%f", &length);

    printf("Enter width of rectangle: ");
    scanf("%f",&width);

    // Calculating perimeter and area
    perimeter = 2*(length + width);
    area = length*width;

    // Displaying results to the user
    printf("Perimeter of rectangle = %.2f units\n", perimeter);
    printf("Area of rectangle = %.2f square units\n", area);

    // Exiting
    return 0;
}