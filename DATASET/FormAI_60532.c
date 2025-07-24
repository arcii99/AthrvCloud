//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: statistical
/* This C program is a scientific calculator that can perform various arithmetic operations as well as trigonometric, logarithmic and exponential functions
   The user is prompted to enter the desired operation and the operands
   Statistical calculations such as mean, median and mode can also be performed on a set of numbers entered by the user
   The program uses user-defined functions for the statistical calculations
   Author: [Your Name]
   Date: [Date]
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes for statistical calculations
float mean(float arr[], int n);
float median(float arr[], int n);
float mode(float arr[], int n);

int main()
{
    int choice, n, i;
    float result;
    float x, y;
    float arr[100];

    printf("Scientific Calculator\n");
    printf("\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Modulus\n");
    printf("6. Power function\n7. Square root\n8. Logarithmic function\n9. Exponential function\n");
    printf("10. Mean\n11. Median\n12. Mode\n");
    printf("Enter your choice (1-12): ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\nEnter two numbers to add: ");
            scanf("%f %f", &x, &y);
            result = x + y;
            printf("\nThe sum is %.2f", result);
            break;

        case 2:
            printf("\nEnter two numbers to subtract: ");
            scanf("%f %f", &x, &y);
            result = x - y;
            printf("\nThe difference is %.2f", result);
            break;

        case 3:
            printf("\nEnter two numbers to multiply: ");
            scanf("%f %f", &x, &y);
            result = x * y;
            printf("\nThe product is %.2f", result);
            break;

        case 4:
            printf("\nEnter two numbers to divide: ");
            scanf("%f %f", &x, &y);
            if(y == 0)
            {
                printf("\nDivision by zero error!");
                exit(0);
            }
            result = x / y;
            printf("\nThe quotient is %.2f", result);
            break;

        case 5:
            printf("\nEnter two numbers to find the modulus: ");
            scanf("%f %f", &x, &y);
            if(y == 0)
            {
                printf("\nDivision by zero error!");
                exit(0);
            }
            result = fmod(x,y);
            printf("\nThe modulus is %.2f", result);
            break;

        case 6:
            printf("\nEnter the base and exponent: ");
            scanf("%f %f", &x, &y);
            result = pow(x,y);
            printf("\nThe result is %.2f", result);
            break;

        case 7:
            printf("\nEnter a number to find the square root: ");
            scanf("%f", &x);
            result = sqrt(x);
            printf("\nThe square root is %.2f", result);
            break;

        case 8:
            printf("\nEnter a number to find the natural logarithm (base e): ");
            scanf("%f", &x);
            result = log(x);
            printf("\nThe natural logarithm is %.2f", result);
            break;

        case 9:
            printf("\nEnter a number to find the exponential (e^x): ");
            scanf("%f", &x);
            result = exp(x);
            printf("\nThe exponential is %.2f", result);
            break;

        case 10:
            printf("\nEnter the number of elements: ");
            scanf("%d", &n);
            printf("\nEnter the elements: ");
            for(i=0; i<n; i++)
            {
                scanf("%f", &arr[i]);
            }
            result = mean(arr,n);
            printf("\nThe mean is %.2f", result);
            break;

        case 11:
            printf("\nEnter the number of elements: ");
            scanf("%d", &n);
            printf("\nEnter the elements: ");
            for(i=0; i<n; i++)
            {
                scanf("%f", &arr[i]);
            }
            result = median(arr,n);
            printf("\nThe median is %.2f", result);
            break;

        case 12:
            printf("\nEnter the number of elements: ");
            scanf("%d", &n);
            printf("\nEnter the elements: ");
            for(i=0; i<n; i++)
            {
                scanf("%f", &arr[i]);
            }
            result = mode(arr,n);
            if(result == -1)
                printf("\nNo mode found!");
            else
                printf("\nThe mode is %.2f", result);
            break;

        default:
            printf("\nInvalid choice!");
    }

    return 0;
}

// Function definition for mean calculation
float mean(float arr[], int n)
{
    int i;
    float sum = 0;
    for(i=0; i<n; i++)
    {
        sum += arr[i];
    }
    return sum/n;
}

// Function definition for median calculation
float median(float arr[], int n)
{
    int i, j;
    float mid;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                float temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    if(n%2 == 0)
        mid = (arr[n/2] + arr[n/2-1])/2;
    else
        mid = arr[n/2];
    return mid;
}

// Function definition for mode calculation
float mode(float arr[], int n)
{
    int i, j, max_count=0, count;
    float mode = -1;
    for(i=0; i<n; i++)
    {
        count = 0;
        for(j=0; j<n; j++)
        {
            if(arr[i] == arr[j])
                count++;
        }
        if(count > max_count)
        {
            max_count = count;
            mode = arr[i];
        }
    }
    if(max_count == 1)
        mode = -1;
    return mode;
}