//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // welcome message
    printf("Welcome to the post-apocalyptic world of geometric algorithms!\n");

    // get user input for shape type and dimensions
    int shape_type;
    printf("Please select a shape type:\n");
    printf("1. Square\n");
    printf("2. Circle\n");
    printf("3. Triangle\n");
    scanf("%d", &shape_type);

    double dimension;
    printf("Please enter the dimension of the selected shape:\n");
    scanf("%lf", &dimension);

    // declare and initialize variables
    double area = 0;
    double perimeter = 0;

    // perform shape calculations based on user input
    switch(shape_type) {
        case 1:
            // calculate area and perimeter of square
            area = pow(dimension, 2);
            perimeter = 4 * dimension;
            break;
        case 2:
            // calculate area and circumference of circle
            area = M_PI * pow(dimension, 2);
            perimeter = 2 * M_PI * dimension;
            break;
        case 3:
            // calculate area and perimeter of equilateral triangle
            area = (sqrt(3) / 4) * pow(dimension, 2);
            perimeter = 3 * dimension;
            break;
        default:
            // invalid shape type entered
            printf("Invalid shape type selected, please try again.\n");
            exit(EXIT_FAILURE);
    }

    // display shape calculations to user
    printf("The area of the selected shape is: %lf\n", area);
    printf("The perimeter of the selected shape is: %lf\n", perimeter);

    // end program
    printf("Thank you for using the post-apocalyptic world of geometric algorithms program!\n");
    return 0;
}