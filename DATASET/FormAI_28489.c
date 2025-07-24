//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Welcome to the immersive world of Geometric Algorithms in C!\n");

    /* Let's start by defining a few variables */
    int choice, radius, side, base, height, length, breadth, area, perimeter, volume, lsa, tsa;
    float pi = 3.1415926535;

    do
    {
        /* Display a menu of options to the user */
        printf("\nPlease choose from the following options:\n");
        printf("1. Calculate the Area and Perimeter of a Circle\n");
        printf("2. Calculate the Area and Perimeter of a Square\n");
        printf("3. Calculate the Area and Perimeter of a Rectangle\n");
        printf("4. Calculate the Volume and Total Surface Area of a Sphere\n");
        printf("5. Quit\n");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1: /* Calculate the Area and Perimeter of a Circle */
                printf("\nEnter the radius of the circle:\n");
                scanf("%d", &radius);

                area = pi * radius * radius;
                perimeter = 2 * pi * radius;

                printf("\nThe area of the circle is: %d\n", area);
                printf("The perimeter of the circle is: %d\n", perimeter);

                break;

            case 2: /* Calculate the Area and Perimeter of a Square */
                printf("\nEnter the length of a side of the square:\n");
                scanf("%d", &side);

                area = side * side;
                perimeter = 4 * side;

                printf("\nThe area of the square is: %d\n", area);
                printf("The perimeter of the square is: %d\n", perimeter);

                break;

            case 3: /* Calculate the Area and Perimeter of a Rectangle */
                printf("\nEnter the length and breadth of the rectangle:\n");
                scanf("%d %d", &length, &breadth);

                area = length * breadth;
                perimeter = 2 * (length + breadth);

                printf("\nThe area of the rectangle is: %d\n", area);
                printf("The perimeter of the rectangle is: %d\n", perimeter);

                break;

            case 4: /* Calculate the Volume and Total Surface Area of a Sphere */
                printf("\nEnter the radius of the sphere:\n");
                scanf("%d", &radius);

                volume = (4/3) * pi * pow(radius, 3);
                lsa = 4 * pi * pow(radius, 2);
                tsa = 4 * lsa;

                printf("\nThe volume of the sphere is: %d\n", volume);
                printf("The lateral surface area of the sphere is: %d\n", lsa);
                printf("The total surface area of the sphere is: %d\n", tsa);

                break;

            case 5: /* Quit the program */
                printf("Thank you for using this Geometric Algorithms program in C. Goodbye!\n");
                exit(0);

            default: /* Handle invalid input */
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}