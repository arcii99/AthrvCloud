//FormAI DATASET v1.0 Category: Math exercise ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    printf("Welcome to the Introspective Math Exercise example program!\n");
    printf("This program gives you some math exercises to practice your skills in C programming.\n");
    printf("Let's start!\n");

    int n1, n2, n3, n4, result, choice;
    float a, b, c, x, y;

    do {
        printf("\nPlease select the type of exercise you want to practice:\n");
        printf("1. Addition of two numbers\n");
        printf("2. Multiplication of two numbers\n");
        printf("3. Calculation of the quadratic equation: ax^2 + bx + c = 0\n");
        printf("4. Calculation of the distance between two points (x1,y1) and (x2,y2)\n");
        printf("5. Calculation of the area of a triangle with base b and height h\n");
        printf("0. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Exiting...\n");
                break;

            case 1:
                printf("Enter two numbers: ");
                scanf("%d %d", &n1, &n2);
                result = n1 + n2;
                printf("%d + %d = %d\n", n1, n2, result);
                break;

            case 2:
                printf("Enter two numbers: ");
                scanf("%d %d", &n1, &n2);
                result = n1 * n2;
                printf("%d * %d = %d\n", n1, n2, result);
                break;

            case 3:
                printf("Enter the values of a, b and c: ");
                scanf("%f %f %f", &a, &b, &c);
                result = (-b + sqrt(pow(b,2) - 4*a*c)) / (2*a);
                printf("The roots of the quadratic equation are: %d\n", result);
                result = (-b - sqrt(pow(b,2) - 4*a*c)) / (2*a);
                printf("The roots of the quadratic equation are: %d\n", result);
                break;

            case 4:
                printf("Enter the coordinates of point 1 (x1,y1): ");
                scanf("%f %f", &x, &y);
                printf("Enter the coordinates of point 2 (x2,y2): ");
                scanf("%f %f", &a, &b);
                result = sqrt(pow((a-x),2) + pow((b-y),2));
                printf("The distance between the points is: %d\n", result);
                break;

            case 5:
                printf("Enter the values of the base and height: ");
                scanf("%d %d", &n1, &n2);
                result = 0.5 * n1 * n2;
                printf("The area of the triangle is: %d\n", result);
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }

    } while (choice != 0);

    printf("Thank you for using the Introspective Math Exercise example program!\n");

    return 0;
}