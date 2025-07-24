//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

// function to calculate the area of a circle
float area_of_circle(float radius)
{
    return PI * pow(radius, 2);
}

// function to calculate the circumference of a circle
float circumference_of_circle(float radius)
{
    return 2 * PI * radius;
}

// function to calculate the area of a rectangle
float area_of_rectangle(float width, float height)
{
    return width * height;
}

// function to calculate the perimeter of a rectangle
float perimeter_of_rectangle(float width, float height)
{
    return 2 * (width + height);
}

int main()
{
    int choice;
    float radius, width, height;

    do
    {
        printf("\nEnter a number to choose an option:\n");
        printf("1. Calculate the area of a circle.\n");
        printf("2. Calculate the circumference of a circle.\n");
        printf("3. Calculate the area of a rectangle.\n");
        printf("4. Calculate the perimeter of a rectangle.\n");
        printf("5. Exit.\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the radius of the circle: ");
                scanf("%f", &radius);
                printf("The area of the circle is %.2f.\n", area_of_circle(radius));
                break;
            case 2:
                printf("Enter the radius of the circle: ");
                scanf("%f", &radius);
                printf("The circumference of the circle is %.2f.\n", circumference_of_circle(radius));
                break;
            case 3:
                printf("Enter the width of the rectangle: ");
                scanf("%f", &width);
                printf("Enter the height of the rectangle: ");
                scanf("%f", &height);
                printf("The area of the rectangle is %.2f.\n", area_of_rectangle(width, height));
                break;
            case 4:
                printf("Enter the width of the rectangle: ");
                scanf("%f", &width);
                printf("Enter the height of the rectangle: ");
                scanf("%f", &height);
                printf("The perimeter of the rectangle is %.2f.\n", perimeter_of_rectangle(width, height));
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(1);

    return 0;
}