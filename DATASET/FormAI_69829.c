//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: single-threaded
#include<stdio.h>
#include<math.h>

int main(){
    int choice, num1, num2, result;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("\nMenu\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Square Root\n7. Logarithm\n8. Sine\n9. Cosine\n10. Tangent\n");
    printf("\nEnter choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            result = num1 + num2;
            printf("\n%d + %d = %d", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("\n%d - %d = %d", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("\n%d x %d = %d", num1, num2, result);
            break;
        case 4:
            result = num1 / num2;
            printf("\n%d / %d = %d", num1, num2, result);
            break;
        case 5:
            result = pow(num1, num2);
            printf("\n%d ^ %d = %d", num1, num2, result);
            break;
        case 6:
            printf("\nSquare root of %d = %f", num1, sqrt(num1));
            printf("\nSquare root of %d = %f", num2, sqrt(num2));
            break;
        case 7:
            printf("\nLog base 10 of %d = %f", num1, log10(num1));
            printf("\nLog base 10 of %d = %f", num2, log10(num2));
            break;
        case 8:
            printf("\nSine of %d = %f", num1, sin(num1));
            printf("\nSine of %d = %f", num2, sin(num2));
            break;
        case 9:
            printf("\nCosine of %d = %f", num1, cos(num1));
            printf("\nCosine if %d = %f", num2, cos(num2));
            break;
        case 10:
            printf("\nTangent of %d = %f", num1, tan(num1));
            printf("\nTangent of %d = %f", num2, tan(num2));
            break;
        default:
            printf("\nInvalid choice");
    }
    printf("\n");
    return 0;
}