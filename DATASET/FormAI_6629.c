//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: futuristic
#include<stdio.h>
#include<math.h>

int main() {
    double loan_amount, interest_rate, monthly_payment, remaining_balance, monthly_interest_rate;
    int years, months, i;
    
    printf("Welcome to the Mortgage Calculator!\n\n");
    
    //Getting user inputs
    printf("Enter loan amount: ");
    scanf("%lf", &loan_amount);
    printf("Enter interest rate (in percentage): ");
    scanf("%lf", &interest_rate);
    printf("Enter loan term (in years): ");
    scanf("%d", &years);
    printf("Enter loan term (in months): ");
    scanf("%d", &months);
    
    //Converting interest rate to monthly rate
    monthly_interest_rate = interest_rate / 1200;
    
    //Calculating monthly payment
    int total_months = years * 12 + months;
    double numerator = loan_amount * monthly_interest_rate * pow((1+monthly_interest_rate), total_months);
    double denominator = pow((1+monthly_interest_rate), total_months) - 1;
    monthly_payment = numerator / denominator;
    
    //Printing monthly payment
    printf("\nYour monthly payment is: $%.2lf\n", monthly_payment);
    
    //Looping to print payment schedule
    remaining_balance = loan_amount;
    printf("\nPayment Schedule\n");
    printf("Payment\t\tInterest\tPrincipal\tBalance\n");
    for(i=1;i<=total_months;i++) {
        double interest = remaining_balance * monthly_interest_rate;
        double principal = monthly_payment - interest;
        remaining_balance = remaining_balance - principal;
        printf("%d\t\t$%.2lf\t$%.2lf\t$%.2lf\n", i, interest, principal, remaining_balance);
    }
    
    return 0;
}