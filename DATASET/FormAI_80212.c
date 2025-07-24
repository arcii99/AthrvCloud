//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: futuristic
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main()
{
    int choice;
    double x, result;
    
    printf("=== Futuristic Scientific Calculator ===\n");
    printf("1. Sine\n");
    printf("2. Cosine\n");
    printf("3. Tangent\n");
    printf("4. Square Root\n");
    printf("5. Logarithm\n");
    printf("6. Power\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the angle in degrees: ");
            scanf("%lf", &x);
            result = sin(x * PI / 180);
            printf("Sine of %.2lf degrees is %.2lf\n", x, result);
            break;
        case 2:
            printf("Enter the angle in degrees: ");
            scanf("%lf", &x);
            result = cos(x * PI / 180);
            printf("Cosine of %.2lf degrees is %.2lf\n", x, result);
            break;
        case 3:
            printf("Enter the angle in degrees: ");
            scanf("%lf", &x);
            result = tan(x * PI / 180);
            printf("Tangent of %.2lf degrees is %.2lf\n", x, result);
            break;
        case 4:
            printf("Enter a number: ");
            scanf("%lf", &x);
            result = sqrt(x);
            printf("Square root of %.2lf is %.2lf\n", x, result);
            break;
        case 5:
            printf("Enter a number: ");
            scanf("%lf", &x);
            result = log10(x);
            printf("Logarithm of %.2lf is %.2lf\n", x, result);
            break;
        case 6:
            printf("Enter the base number: ");
            scanf("%lf", &x);
            double y;
            printf("Enter the power: ");
            scanf("%lf", &y);
            result = pow(x, y);
            printf("%.2lf to the power of %.2lf is %.2lf\n", x, y, result);
            break;
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}