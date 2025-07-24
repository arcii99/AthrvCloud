//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: brave
#include <stdio.h>
#include <math.h>

int main(){

    printf("\n           ***********************************************");
    printf("\n           ***                                         ***");
    printf("\n           ***            Mortgage Calculator           ***");
    printf("\n           ***                                         ***");
    printf("\n           ***********************************************\n\n\n");

    float loan_amount,interest_rate,monthly_payment,principal,interest,balance_owed;
    int loan_duration_in_years,total_number_of_payments,i;
    
    printf("Enter the loan amount: ");
    scanf("%f",&loan_amount);

    printf("Enter the interest rate (in percentage): ");
    scanf("%f",&interest_rate);

    printf("Enter the loan duration (in years): ");
    scanf("%d",&loan_duration_in_years);

    total_number_of_payments = loan_duration_in_years * 12;

    float monthly_interest_rate = interest_rate / (12 * 100);

    float numerator = monthly_interest_rate * pow((1 + monthly_interest_rate), total_number_of_payments);
    float denominator = pow((1 + monthly_interest_rate), total_number_of_payments) - 1;

    monthly_payment = loan_amount * (numerator / denominator);
    balance_owed = loan_amount;

    printf("\n\n\nMonthly Payment: %.2f",monthly_payment);

    printf("\n\n");

    printf("            Payment");
    printf("\t Principal");
    printf("\t Interest");
    printf("\t Balance");

    printf("\n\n");

    for(i=1;i<=total_number_of_payments;i++){

        interest = balance_owed * monthly_interest_rate;
        principal = monthly_payment - interest;
        balance_owed = balance_owed - principal;

        printf("Payment #%d:\t $%.2f\t $%.2f\t $%.2f\n",i,principal,interest,balance_owed);
    }

    printf("\n\n");

    return 0;
}