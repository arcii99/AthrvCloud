//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: relaxed
#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    float x, y;
    printf("Welcome to the Scientific Calculator\n\n");

    while(1) {
        // Displaying the menu
        printf("\nPress 1 for Addition\n");
        printf("Press 2 for Subtraction\n");
        printf("Press 3 for Multiplication\n");
        printf("Press 4 for Division\n");
        printf("Press 5 for Square Root\n");
        printf("Press 6 for Power\n");
        printf("Press 7 for Sine\n");
        printf("Press 8 for Cosine\n");
        printf("Press 9 for Tangent\n");
        printf("Press 0 to Exit\n");

        printf("Enter your choice:");
        scanf("%d", &choice);

        // Handling user's choice
        switch (choice) {
            case 0:
                printf("\nGoodbye!\n");
                return 0;
            case 1:
                printf("Enter two numbers:");
                scanf("%f %f", &x, &y);
                printf("Result: %f\n", x + y);
                break;
            case 2:
                printf("Enter two numbers:");
                scanf("%f %f", &x, &y);
                printf("Result: %f\n", x - y);
                break;
            case 3:
                printf("Enter two numbers:");
                scanf("%f %f", &x, &y);
                printf("Result: %f\n", x * y);
                break;
            case 4:
                printf("Enter two numbers:");
                scanf("%f %f", &x, &y);
                printf("Result: %f\n", x / y);
                break;
            case 5:
                printf("Enter a number:");
                scanf("%f", &x);
                printf("Result: %f\n", sqrt(x));
                break;
            case 6:
                printf("Enter a number:");
                scanf("%f", &x);
                printf("Enter power:");
                scanf("%f", &y);
                printf("Result: %f\n", pow(x, y));
                break;
            case 7:
                printf("Enter a number in degrees:");
                scanf("%f", &x);
                printf("Result: %f\n", sin(x * M_PI / 180.0));
                break;
            case 8:
                printf("Enter a number in degrees:");
                scanf("%f", &x);
                printf("Result: %f\n", cos(x * M_PI / 180.0));
                break;
            case 9:
                printf("Enter a number in degrees:");
                scanf("%f", &x);
                printf("Result: %f\n", tan(x * M_PI / 180.0));
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}