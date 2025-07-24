//FormAI DATASET v1.0 Category: Scientific ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int choice;
    double num, result;
    printf("Enter a number: ");
    scanf("%lf", &num);
    
    printf("\n1. Square root\n2. Natural logarithm\n3. Logarithm(base 10)\n4. Exponent\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
            result = sqrt(num);
            printf("Square root of %lf is %lf\n", num, result);
            break;
        case 2:
            result = log(num);
            printf("Natural logarithm of %lf is %lf\n", num, result);
            break;
        case 3:
            result = log10(num);
            printf("Logarithm (base 10) of %lf is %lf\n", num, result);
            break;
        case 4:
            result = exp(num);
            printf("Exponential of %lf is %lf\n", num, result);
            break;
        default:
            printf("Invalid Input\n");
            break;
    }
    
    return 0;
}