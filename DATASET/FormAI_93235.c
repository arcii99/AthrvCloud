//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: peaceful
#include<stdio.h>

int main(){
    float principal, rate, years, EMI;
    printf("Enter the principal (loan amount): ");
    scanf("%f", &principal);

    printf("Enter the rate of interest (in percentage): ");
    scanf("%f", &rate);

    printf("Enter the time period (in years): ");
    scanf("%f", &years);

    rate = (rate/100);
    float monthly_rate = rate/12;
    float total_months = years * 12;

    EMI = (principal * monthly_rate * pow(1+monthly_rate, total_months))/(pow(1+monthly_rate, total_months)-1);

    printf("The EMI (Equated Monthly Installment) for the loan is %.2f", EMI);

    return 0;
}