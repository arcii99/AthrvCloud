//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: intelligent
#include <stdio.h>
#include <math.h>

int add(int num1, int num2){
    return (num1 + num2);
}

int subtract(int num1, int num2){
    return (num1 - num2);
}

float multiply(float num1, float num2){
    return (num1 * num2);
}

float divide(float num1, float num2){
    return (num1 / num2);
}

float power(float num1, float num2){
    return pow(num1, num2);
}

float square_root(float num){
    return sqrt(num);
}

int main(){
    int choice, num1, num2;
    float res, num;
    
    printf("***** Welcome to the Intelligent Scientific Calculator *****\n\n");
    
    printf("MENU:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Exit\n\n");
    
    while(1){
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);
        
        switch(choice){
            
            case 1:
                printf("Enter first number: ");
                scanf("%d", &num1);
                printf("Enter second number: ");
                scanf("%d", &num2);
                res = add(num1, num2);
                printf("Result: %.2f\n\n", res);
                break;
                
            case 2:
                printf("Enter first number: ");
                scanf("%d", &num1);
                printf("Enter second number: ");
                scanf("%d", &num2);
                res = subtract(num1, num2);
                printf("Result: %.2f\n\n", res);
                break;
                
            case 3:
                printf("Enter first number: ");
                scanf("%f", &num1);
                printf("Enter second number: ");
                scanf("%f", &num2);
                res = multiply(num1, num2);
                printf("Result: %.2f\n\n", res);
                break;
                
            case 4:
                printf("Enter dividend: ");
                scanf("%f", &num1);
                printf("Enter divisor: ");
                scanf("%f", &num2);
                if(num2==0){
                    printf("ERROR: Division by Zero!\n\n");
                }
                else{
                    res = divide(num1, num2);
                    printf("Result: %.2f\n\n", res);
                }
                break;
                
            case 5:
                printf("Enter base number: ");
                scanf("%f", &num1);
                printf("Enter exponent: ");
                scanf("%f", &num2);
                res = power(num1, num2);
                printf("Result: %.2f\n\n", res);
                break;
            
            case 6:
                printf("Enter number: ");
                scanf("%f", &num);
                if(num<0){
                    printf("ERROR: Square root of negative number is not defined!\n\n");
                }
                else{
                    res = square_root(num);
                    printf("Result: %.2f\n\n", res);
                }
                break;
                
            case 7:
                printf("Exiting calculator...\n\n");
                exit(0);
                break;
                
            default:
                printf("ERROR: Invalid choice!\n\n");
                
        }
    }
    return 0;
}