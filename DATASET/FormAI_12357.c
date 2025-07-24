//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: shape shifting
#include <stdio.h>

// Function to find area of a rectangle
int rectangle_area(int l, int b) {
    return l * b;
}

// Function to find area of a triangle
int triangle_area(int b, int h) {
    return 0.5 * b * h;
}

int main() {
    int choice;
    int l, b, h;
    while(1) {
        printf("Enter 1 to calculate area of a rectangle\nEnter 2 to calculate area of a triangle\nEnter 3 to exit\n");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("Enter length and breadth of the rectangle: ");
            scanf("%d %d", &l, &b);
            printf("Area of the rectangle is %d\n\n", rectangle_area(l, b));
        }
        else if(choice == 2) {
            printf("Enter base and height of the triangle: ");
            scanf("%d %d", &b, &h);
            printf("Area of the triangle is %d\n\n", triangle_area(b, h));
        }
        else if(choice == 3) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice, please try again\n\n");
        }
    }
    return 0;
}