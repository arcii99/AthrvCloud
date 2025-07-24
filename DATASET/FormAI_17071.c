//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: minimalist
#include<stdio.h>

int main(){
    float loan_amount, interest_rate, monthly_payment, balance, principle, interest;
    int num_months, payments_made;

    printf("Enter the loan amount: ");
    scanf("%f", &loan_amount);

    printf("Enter the interest rate (in percent): ");
    scanf("%f", &interest_rate);

    printf("Enter the number of months to repay the loan: ");
    scanf("%d", &num_months);

    interest_rate = interest_rate/100.0;
    balance = loan_amount;

    printf("\n\nMonth  \t Payment  \t Principle  \t Interest  \t Balance\n");

    for(int i=1;i<=num_months;i++){
        interest = balance * interest_rate/12.0;
        if(i == num_months){
            monthly_payment = balance + interest;
        }
        else{
            monthly_payment = balance/num_months + interest;
        }
        payments_made = i;
        principle = monthly_payment - interest;

        balance = balance - principle;

        printf("%d \t %.2f \t\t %.2f \t\t %.2f \t\t %.2f\n", i, monthly_payment, principle, interest, balance);

        if(balance <= 0.0){
            break;
        }
    }

    printf("\n\nLoan details: \n");
    printf("Loan amount: $%.2f\n", loan_amount);
    printf("Number of payments: %d\n", num_months);
    printf("Payments made: %d\n", payments_made);
    printf("Monthly payment: $%.2f\n", monthly_payment);
    printf("Total interest paid: $%.2f\n", (monthly_payment*num_months-loan_amount));

    return 0;
}