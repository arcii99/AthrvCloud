//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: expert-level
#include<stdio.h>
#include<math.h>

int main(){
    double principal, annual_interest_rate, monthly_interest_rate, total_interest, total_payment;
    int duration_in_years, duration_in_months, remaining_months;
    printf("Enter the principal amount: ");
    scanf("%lf", &principal);
    printf("Enter the annual interest rate: ");
    scanf("%lf", &annual_interest_rate);
    printf("Enter the duration of the loan in years: ");
    scanf("%d", &duration_in_years);
    duration_in_months = duration_in_years * 12;
    monthly_interest_rate = annual_interest_rate / 1200;
    total_payment = principal * pow((1 + monthly_interest_rate), duration_in_months) * monthly_interest_rate / (pow((1 + monthly_interest_rate), duration_in_months) - 1);
    total_interest = total_payment * duration_in_months - principal;
    remaining_months = duration_in_months;
    
    printf("\nMortgage Payment Calculator\n");
    printf("==========================\n");
    printf("Principal amount: $%.2lf\n", principal);
    printf("Annual interest rate: %.2lf%%\n", annual_interest_rate);
    printf("Duration of loan: %d years\n", duration_in_years);
    printf("Monthly payment: $%.2lf\n", total_payment);
    printf("Total interest: $%.2lf\n", total_interest);
    
    printf("\nAmortization Schedule\n");
    printf("======================\n");
    printf("Month\t Payment\t Principal\t Interest\t Balance\n");
    
    for(int i=1; i<=duration_in_months; i++){
        double interest = monthly_interest_rate * principal;
        double payment = total_payment - interest;
        double balance = principal - payment;
        printf("%d\t $%.2lf\t $%.2lf\t $%.2lf\t $%.2lf\n", i, total_payment, payment, interest, balance);
        principal = balance;
        remaining_months--;
        if(remaining_months == 0){
            printf("\nYou have successfully paid off your mortgage in %d years.", duration_in_years);
            break;
        }
    }
    return 0;
}