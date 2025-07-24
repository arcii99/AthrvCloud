//FormAI DATASET v1.0 Category: Math exercise ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {

    srand(time(NULL));   // seeding the random number generator 

    int num1 = rand() % 100 + 1;    // generating a random number between 1-100 for num1
    int num2 = rand() % 100 + 1;    // generating a random number between 1-100 for num2

    // displaying the problem statement
    printf("Find the value of x in the equation: %.2fx + %.2f = %.2f\n\n", (double) num1 / 10, (double) num2 / 10, 10.5);

    double answer = (10.5 - (double) num2 / 10) / ((double) num1 / 10); // calculating the value of x 

    // displaying the solution
    printf("Solution: x = %.2f\n\n", answer);

    // generating a new problem statement
    printf("Find the value of y in the equation: y^2 + %.2fy + %.2f = 0\n\n", (double) num1 / 10, (double) num2 / 10);

    double discriminant = pow((double) num1 / 10, 2) - 4 * (double) num2 / 10;

    // checking if roots are real or complex
    if (discriminant > 0) {
        double root1 = (-1 * ((double) num1 / 10) + sqrt(discriminant)) / 2;
        double root2 = (-1 * ((double) num1 / 10) - sqrt(discriminant)) / 2;
        // displaying the roots
        printf("Roots are: %.2f and %.2f\n", root1, root2);
    }
    else if (discriminant == 0) {
        double root = -1 * ((double) num1 / 10) / 2;
        // displaying the root
        printf("Root is: %.2f\n", root);
    }
    else {
        // displaying the roots
        printf("Roots are complex numbers.\n");
    }

    return 0;
}