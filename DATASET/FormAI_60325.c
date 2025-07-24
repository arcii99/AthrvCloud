//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    printf("Welcome to the fun and frolic world of geometric algorithms!\n");
    printf("Are you ready to impress your friends with your math skills? Let's begin!\n");

    int choice;
    float radius, area, circumference;
    float length, width, height, surfaceArea, volume;

    while (1){
        printf("Choose a shape:\n");
        printf("1. Circle\n");
        printf("2. Rectangle\n");
        printf("3. Sphere\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("Enter the radius of the circle: ");
                scanf("%f", &radius);
                area = M_PI * pow(radius, 2);
                circumference = 2 * M_PI * radius;
                printf("The area of the circle is: %f\n", area);
                printf("The circumference of the circle is: %f\n", circumference);
                break;

            case 2:
                printf("Enter the length of the rectangle: ");
                scanf("%f", &length);
                printf("Enter the width of the rectangle: ");
                scanf("%f", &width);
                surfaceArea = 2 * (length * width + width * height + height * length);
                printf("The surface area of the rectangle is: %f\n", surfaceArea);
                break;

            case 3:
                printf("Enter the radius of the sphere: ");
                scanf("%f", &radius);
                area = 4 * M_PI * pow(radius, 2);
                volume = (4/3) * M_PI * pow(radius, 3);
                printf("The surface area of the sphere is: %f\n", area);
                printf("The volume of the sphere is: %f\n", volume);
                break;

            case 4:
                printf("Leaving already? Okay then, bye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Try again.\n");
                break;
            }
    }
    return 0;
}