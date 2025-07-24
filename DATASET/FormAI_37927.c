//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265 //define PI constant

int main()
{
    int choice;
    float num, result; 
    
    printf("Welcome to the Scientific Calculator!\n");
    printf("-------------------------------------\n");
    
    while(1)
    {
        printf("Please select an operation:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exponentiation\n6. Logarithm\n7. Trigonometry\n8. Exit\n");
        scanf("%d", &choice); //read user choice
        
        switch(choice)
        {
            case 1:
                printf("Enter two numbers to add: ");
                scanf("%f%f", &num, &result);
                result += num;
                printf("Result: %f\n", result);
                break;
                
            case 2:
                printf("Enter two numbers to subtract: ");
                scanf("%f%f", &num, &result);
                result -= num;
                printf("Result: %f\n", result);
                break;
                
            case 3:
                printf("Enter two numbers to multiply: ");
                scanf("%f%f", &num, &result);
                result *= num;
                printf("Result: %f\n", result);
                break;
                
            case 4:
                printf("Enter two numbers to divide: ");
                scanf("%f%f", &num, &result);
                if(num == 0) //check for division by zero
                {
                    printf("Error: Division by zero is not allowed.\n");
                    break;
                }
                result /= num;
                printf("Result: %f\n", result);
                break;
                
            case 5:
                printf("Enter a number to exponentiate and its exponent: ");
                scanf("%f%f", &num, &result);
                result = pow(num, result);
                printf("Result: %f\n", result);
                break;
                
            case 6:
                printf("Enter a number to take the natural logarithm of: ");
                scanf("%f", &num);
                if(num <= 0) //check for invalid input
                {
                    printf("Error: The natural logarithm is undefined for non-positive numbers.\n");
                    break;
                }
                result = log(num);
                printf("Result: %f\n", result);
                break;
                
            case 7:
                printf("Please select a trigonometric operation:\n");
                printf("1. Sine\n2. Cosine\n3. Tangent\n4. Inverse sine\n5. Inverse cosine\n6. Inverse tangent\n");
                scanf("%d", &choice);
                
                printf("Enter an angle in degrees: ");
                scanf("%f", &num);
                num = num * PI / 180; //convert to radians
                
                switch(choice)
                {
                    case 1:
                        result = sin(num);
                        printf("Result: %f\n", result);
                        break;
                        
                    case 2:
                        result = cos(num);
                        printf("Result: %f\n", result);
                        break;
                        
                    case 3:
                        result = tan(num);
                        printf("Result: %f\n", result);
                        break;
                        
                    case 4:
                        if(num < -1 || num > 1) //check for out-of-range input
                        {
                            printf("Error: Invalid input for inverse sine.\n");
                            break;
                        }
                        result = asin(num);
                        result = result * 180 / PI; //convert back to degrees
                        printf("Result: %f\n", result);
                        break;
                        
                    case 5:
                        if(num < -1 || num > 1) //check for out-of-range input
                        {
                            printf("Error: Invalid input for inverse cosine.\n");
                            break;
                        }
                        result = acos(num);
                        result = result * 180 / PI; //convert back to degrees
                        printf("Result: %f\n", result);
                        break;
                        
                    case 6:
                        result = atan(num);
                        result = result * 180 / PI; //convert back to degrees
                        printf("Result: %f\n", result);
                        break;
                        
                    default:
                        printf("Error: Invalid input.\n");
                        break;
                }
                
                break;
                
            case 8:
                printf("Thank you for using the Scientific Calculator.\n");
                exit(0); //exit program
                break;
                
            default:
                printf("Error: Invalid input.\n");
                break;
        }
        
        printf("-------------------------------------\n\n");
    }
    
    return 0;
}