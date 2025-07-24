//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    printf("Welcome to the Funny Geometric Algorithm Program!\n\n");
    printf("Please enter the radius of your pizza: ");
    double radius;
    scanf("%lf", &radius);
    printf("\nCalculating the area of your pizza...\n");
    double area = pow(radius, 2) * M_PI;
    printf("The area of your pizza is %lf sq. inches.\n\n", area);

    printf("Please enter the height of your soda can: ");
    double height;
    scanf("%lf", &height);
    printf("\nPlease enter the radius of your soda can: ");
    scanf("%lf", &radius);
    printf("\nCalculating the volume of your soda can...\n");
    double volume = pow(radius, 2) * M_PI * height;
    printf("The volume of your soda can is %lf cubic inches.\n\n", volume);

    printf("Now let's see if your pencil can fit in your pencil holder...\n");
    printf("Please enter the diameter of your pencil: ");
    double diameter_pencil;
    scanf("%lf", &diameter_pencil);
    printf("\nPlease enter the diameter of your pencil holder: ");
    double diameter_holder;
    scanf("%lf", &diameter_holder);
    double difference = diameter_holder - diameter_pencil;
    if (difference >= 0) {
        printf("\nCongratulations! Your pencil can fit in your pencil holder!\n\n");
    } else {
        printf("\nUnfortunately, your pencil cannot fit in your pencil holder.\n\n");
    }

    printf("Thank you for using the Funny Geometric Algorithm Program!\n");
    return 0;
}