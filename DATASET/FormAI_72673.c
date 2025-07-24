//FormAI DATASET v1.0 Category: Arithmetic ; Style: portable
#include<stdio.h>

int main(){
    
    printf("Welcome to our Arithmetic Program\n\n");
    
    //variables to store user inputs
    float x, y;
    
    //prompt the user for inputs
    printf("Enter first number: ");
    scanf("%f", &x);
    
    printf("Enter second number: ");
    scanf("%f", &y);
    
    //addition operation
    float sum = x + y;
    printf("\nAddition result of %.2f + %.2f is %.2f\n", x, y, sum);
    
    //subtraction operation
    float diff = x - y;
    printf("Subtraction result of %.2f - %.2f is %.2f\n", x, y, diff);
    
    //multiplication operation
    float prod = x * y;
    printf("Multiplication result of %.2f * %.2f is %.2f\n", x, y, prod);
    
    //division operation
    if(y != 0){
        float quo = x / y;
        printf("Division result of %.2f / %.2f is %.2f\n", x, y, quo);
    }
    else{
        printf("Cannot divide by zero\n");
    }
    
    //modulo operation
    if(x > 0 && y > 0){
        int mod = (int)x % (int)y;
        printf("Modulo result of %.2f %% %.2f is %d\n", x, y, mod);
    }
    else{
        printf("Modulo operation cannot be performed as either x or y or both are negative\n");
    }
    
    return 0;
}