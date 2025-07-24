//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: intelligent
#include<stdio.h>
#include<math.h>

int main(){
    float principal, interest_rate, repayment_term;
    float monthly_interest_rate, numerator, denominator, monthly_repayments;

    printf("Welcome to Mortgage Calculator!\n");
    printf("Enter the Principal Amount: ");
    scanf("%f", &principal);
    printf("Enter the Interest Rate (in Percentage): ");
    scanf("%f", &interest_rate);
    printf("Enter the Repayment Term (in Years): ");
    scanf("%f", &repayment_term);

    // Calculation
    monthly_interest_rate = interest_rate/(12*100);
    numerator = principal * monthly_interest_rate * pow(1+monthly_interest_rate, repayment_term*12);
    denominator = pow(1+monthly_interest_rate, repayment_term*12) - 1;
    monthly_repayments = numerator / denominator;

    // Output
    printf("\n");
    printf("%-25s%.2f\n","Principal Amount:", principal);
    printf("%-25s%.2f%s\n","Interest Rate:", interest_rate,"%");
    printf("%-25s%.2f%s\n","Repayment Term:", repayment_term," years");
    printf("%-25s%.2f\n","Monthly Repayments:", monthly_repayments);

    return 0;
}