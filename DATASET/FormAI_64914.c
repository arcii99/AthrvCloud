//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: decentralized
#include <stdio.h>

int main(){
    float principal, rate, time, monthlyPayment;
    printf("Enter Principal Amount: ");
    scanf("%f", &principal);
    printf("Enter Rate of Interest: ");
    scanf("%f", &rate);
    printf("Enter Time in Years: ");
    scanf("%f", &time);
    
    rate = rate / 1200; //convert to monthly interest rate
    time = time * 12; //convert to months
    
    monthlyPayment = (principal * rate * pow(1+rate, time)) / (pow(1+rate, time) - 1);
    
    printf("\nMonthly Mortgage Payment: %.2f", monthlyPayment);
    return 0;
}