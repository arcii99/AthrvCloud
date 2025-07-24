//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: automated
#include <stdio.h>

int main(){
    float principal, rate, time, installment, total_amount;
    int n = 1;

    printf("Enter principal amount: ");
    scanf("%f", &principal);

    printf("Enter annual interest rate: ");
    scanf("%f", &rate);

    printf("Enter loan term (in years): ");
    scanf("%f", &time);

    float temp_rate = rate / 12 / 100;
    int temp_time = time * 12;
    float x = pow((1 + temp_rate), temp_time);
    installment = principal * x * temp_rate / (x - 1);
    total_amount = installment * temp_time;
    
    printf("\n-----------------------------------------------\n\n");
    printf("Loan Report\n\n");
    printf("Principal Amount: %.2f\n", principal);
    printf("Annual Interest Rate: %.2f\n", rate);
    printf("Loan Term: %.2f years\n", time);
    printf("Number of Installments: %d\n", temp_time);
    printf("Monthly Installment: Rs. %.2f\n", installment);
    printf("Total Amount Payable: Rs. %.2f\n\n", total_amount);
    printf("-----------------------------------------------\n");
    
    return 0;
}