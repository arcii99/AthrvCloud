//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: innovative
#include<stdio.h>
#include<math.h>

int main(){

    float loan_amount,interest_rate,months,emi;
    printf("Enter the Loan Amount:\n");
    scanf("%f",&loan_amount);
    printf("Enter the Interest Rate:\n");
    scanf("%f",&interest_rate);
    printf("Enter the Number of Months:\n");
    scanf("%f",&months);

    printf("Loan Amount: %.2f\n",loan_amount);
    printf("Interest Rate: %.2f\n",interest_rate);
    printf("Number of Months: %.2f\n",months);

    float monthly_interest_rate = interest_rate/(12*100);
    emi = (loan_amount*monthly_interest_rate*pow(1+monthly_interest_rate,months))/(pow(1+monthly_interest_rate,months)-1);
    printf("EMI is: %.2f\n",emi);

    float total_payable = emi*months;
    float total_interest = total_payable-loan_amount;
    printf("Total Payable Amount: %f\n",total_payable);
    printf("Total Interest Amount: %f\n",total_interest);

    return 0;
}