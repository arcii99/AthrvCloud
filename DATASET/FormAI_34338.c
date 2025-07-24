//FormAI DATASET v1.0 Category: Error handling ; Style: excited
#include<stdio.h>

int main(){

printf("Welcome to our Exciting Error Handling Program!\n\n");

int dividend, divisor, quotient;

printf("Enter dividend: ");
scanf("%d",&dividend);

printf("\nEnter divisor: ");
scanf("%d",&divisor);

if(divisor == 0){
    printf("\nOops! Division by ZERO is impossible\n\n");
    return 1;  //Returning 1 as an error code 
}

quotient = dividend/divisor;

printf("\nResult: %d",quotient);

return 0;  //Returning 0 as success code

}