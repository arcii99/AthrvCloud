//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: calm
#include <stdio.h>

int main() {
    int choice;
    float radius, base, height, area;

    printf("Please choose an option:\n"); 
    printf("1. Calculate the area of a circle.\n");
    printf("2. Calculate the area of a triangle.\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Please enter the radius of the circle: ");
            scanf("%f", &radius);
            area = 3.14 * radius * radius;
            printf("The area of the circle with radius %f is %f.\n", radius, area);
            break;

        case 2:
            printf("Please enter the base and height of the triangle: ");
            scanf("%f %f", &base, &height);
            area = 0.5 * base * height;
            printf("The area of the triangle with base %f and height %f is %f.\n", base, height, area);
            break;

        default:
            printf("Invalid choice, please try again.\n");
            break;
    }

    return 0;
}