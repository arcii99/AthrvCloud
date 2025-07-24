//FormAI DATASET v1.0 Category: Math exercise ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/* This program will prompt the user to enter 3 numbers. It will then calculate the roots of the quadratic equation
   using the quadratic formula and print out the results.*/

int main()
{
    double a, b, c; // The coefficients of the quadratic equation 
    double discriminant, root1, root2; // Variables for calculation and storing roots
    char answer; // Variable to store user response

    do {
        printf("Enter the coefficients a, b and c: ");
        scanf("%lf %lf %lf", &a, &b, &c);

        // Calculate the discriminant
        discriminant = b * b - 4 * a * c;

        // Check if the discriminant is positive, zero or negative
        if (discriminant > 0) {
            printf("Roots are real and unequal.\n");
            root1 = (-b + sqrt(discriminant)) / (2*a);
            root2 = (-b - sqrt(discriminant)) / (2*a);
            printf("The roots are %lf and %lf\n", root1, root2);
        } 
        else if (discriminant == 0) {
            printf("Roots are real and equal.\n");
            root1 = root2 = -b / (2*a);
            printf("The root is %lf\n", root1);
        } 
        else {
            double realPart = -b / (2*a);
            double imaginaryPart = sqrt(-discriminant) / (2*a);
            printf("Roots are complex and different.\n");
            printf("Root 1 = %lf + %lfi\n", realPart, imaginaryPart);
            printf("Root 2 = %lf - %lfi\n", realPart, imaginaryPart);
        }

        printf("Do you want to calculate the roots of another quadratic equation? (y/n): ");
        scanf(" %c", &answer);
    } while(tolower(answer) == 'y');

    return 0;
}