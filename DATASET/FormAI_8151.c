//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: thoughtful
#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    double x, y, result;
    
    printf("Welcome to my Scientific Calculator!\n");
    printf("What operation would you like to perform?\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exponentiation\n6. Square Root\n7. Logarithm\n8. Trigonometry\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter the first number: ");
            scanf("%lf", &x);
            printf("Enter the second number: ");
            scanf("%lf", &y);
            result = x + y;
            printf("The sum of %lf and %lf is %lf\n", x, y, result);
            break;
        
        case 2:
            printf("Enter the first number: ");
            scanf("%lf", &x);
            printf("Enter the second number: ");
            scanf("%lf", &y);
            result = x - y;
            printf("The difference of %lf and %lf is %lf\n", x, y, result);
            break;
            
        case 3:
            printf("Enter the first number: ");
            scanf("%lf", &x);
            printf("Enter the second number: ");
            scanf("%lf", &y);
            result = x * y;
            printf("The product of %lf and %lf is %lf\n", x, y, result);
            break;
            
        case 4:
            printf("Enter the dividend: ");
            scanf("%lf", &x);
            printf("Enter the divisor: ");
            scanf("%lf", &y);
            if(y == 0) {
                printf("Error: Division by zero\n");
            }
            else {
                result = x / y;
                printf("%lf divided by %lf is %lf\n", x, y, result);
            }
            break;
            
        case 5:
            printf("Enter the base: ");
            scanf("%lf", &x);
            printf("Enter the exponent: ");
            scanf("%lf", &y);
            result = pow(x, y);
            printf("%lf raised to the power of %lf is %lf\n", x, y, result);
            break;
            
        case 6:
            printf("Enter the number: ");
            scanf("%lf", &x);
            result = sqrt(x);
            printf("The square root of %lf is %lf\n", x, result);
            break;
            
        case 7:
            printf("Enter the number: ");
            scanf("%lf", &x);
            result = log(x);
            printf("The natural logarithm of %lf is %lf\n", x, result);
        break;
            
        case 8:
            printf("What trigonometric function would you like to use?\n");
            printf("1. Sine\n2. Cosine\n3. Tangent\n4. Cosecant\n5. Secant\n6. Cotangent\n");
            scanf("%d", &choice);
            printf("Enter the angle in radians: ");
            scanf("%lf", &x);
            switch(choice) {
                case 1:
                    result = sin(x);
                    printf("The sine of %lf radians is %lf\n", x, result);
                    break;
                case 2:
                    result = cos(x);
                    printf("The cosine of %lf radians is %lf\n", x, result);
                    break;
                case 3:
                    result = tan(x);
                    printf("The tangent of %lf radians is %lf\n", x, result);
                    break;
                case 4:
                    result = 1 / sin(x);
                    printf("The cosecant of %lf radians is %lf\n", x, result);
                    break;
                case 5:
                    result = 1 / cos(x);
                    printf("The secant of %lf radians is %lf\n", x, result);
                    break;
                case 6:
                    result = 1 / tan(x);
                    printf("The cotangent of %lf radians is %lf\n", x, result);
                    break;
                default:
                    printf("Error: invalid choice\n");
                    break;
            }
            break;
         
        default:
            printf("Error: invalid choice\n");
            break;
    }
    
    return 0;
}