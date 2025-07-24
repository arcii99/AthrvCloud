//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

// Shape-shifting C program to generate random numbers and perform mathematical operations

int main()
{
    int n, i, operation;
    float result=0.0, num;
    
    // taking user input for number of iterations and mathematical operation
    printf("Enter the number of iterations: ");
    scanf("%d", &n);
    printf("\nEnter the mathematical operation you want to perform:\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n");
    scanf("%d", &operation);

    // generate random numbers and perform mathematical operation with all numbers
    for(i=1; i<=n; i++)
    {
        num = (float)(rand())/RAND_MAX; // generate random floating point number between 0 and 1
        switch(operation)
        {
            case 1: result += num; break; // addition
            case 2: result -= num; break; // subtraction
            case 3: result *= num; break; // multiplication
            case 4: result /= num; break; // division
            default: printf("Invalid operation selected!\n"); exit(0); break;
        }
        printf("Result after iteration %d is %f\n", i, result);
    }

    // print final result and exit
    printf("\nFinal result after %d iterations is %f\n", n, result);
    return 0;
}