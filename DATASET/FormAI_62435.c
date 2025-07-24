//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: romantic
#include <stdio.h>
#include <math.h>

int main() {
    int choice; 
    float num, result;

    printf("Welcome to the Romantic Scientific Calculator!\n");

    printf("Choose an operation to perform:");

    printf("\n1. Addition");
    printf("\n2. Subtraction");
    printf("\n3. Multiplication");
    printf("\n4. Division");
    printf("\n5. Square root");
    printf("\n6. Exponent");
    printf("\n7. Sine");
    printf("\n8. Cosine");
    printf("\n9. Tangent");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nEnter two numbers to add: ");
            scanf("%f", &num);
            scanf("%f", &result);
            printf("\n%.2f + %.2f = %.2f\n", num, result, num + result);
        break;
        
        case 2:
            printf("\nEnter two numbers to subtract: ");
            scanf("%f", &num);
            scanf("%f", &result);
            printf("\n%.2f - %.2f = %.2f\n", num, result, num - result);
        break;

        case 3:
            printf("\nEnter two numbers to multiply: ");
            scanf("%f", &num);
            scanf("%f", &result);
            printf("\n%.2f x %.2f = %.2f\n", num, result, num * result);
        break;
        
        case 4:
            printf("\nEnter two numbers to divide: ");
            scanf("%f", &num);
            scanf("%f", &result);
            if(result == 0) printf("\nDivision by zero is not possible\n");
            else printf("\n%.2f / %.2f = %.2f\n", num, result, num / result);
        break;
        
        case 5:
            printf("\nEnter a number to find its square root: ");
            scanf("%f", &num);
            printf("\nSqrt(%.2f) = %.2f\n", num, sqrt(num));
        break;
        
        case 6:
            printf("\nEnter a base number: ");
            scanf("%f", &num);
            printf("\nEnter an exponent: ");
            scanf("%f", &result);
            printf("\n%.2f ^ %.2f = %.2f\n", num, result, pow(num, result));
        break;
        
        case 7:
            printf("\nEnter an angle in degrees: ");
            scanf("%f", &num);
            printf("\nSin(%.2f) = %.2f\n", num, sin(num * M_PI / 180));
        break;
        
        case 8:
            printf("\nEnter an angle in degrees: ");
            scanf("%f", &num);
            printf("\nCos(%.2f) = %.2f\n", num, cos(num * M_PI / 180));
        break;
        
        case 9:
            printf("\nEnter an angle in degrees: ");
            scanf("%f", &num);
            printf("\nTan(%.2f) = %.2f\n", num, tan(num * M_PI / 180));
        break;
        
        default:
            printf("\nInvalid choice\n");
    }

    return 0;
}