//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double calculate_mortgage(double amount, double interest_rate, int years){
    double monthly_rate = interest_rate/1200;
    int months = years*12;
    double factor = pow(1+monthly_rate, months);
    double payment = (amount*monthly_rate*factor)/(factor-1);
    return payment;
}

int main(){
    double amount, interest_rate, payment;
    int years;
    
    printf("Enter the loan amount: ");
    scanf("%lf", &amount);
    printf("Enter the interest rate: ");
    scanf("%lf", &interest_rate);
    printf("Enter the loan term (in years): ");
    scanf("%d", &years);
    
    payment = calculate_mortgage(amount, interest_rate, years);
    
    printf("Loan amount: $%.2lf\n", amount);
    printf("Interest rate: %.2lf%%\n", interest_rate);
    printf("Loan term: %d years\n", years);
    printf("Monthly payment: $%.2lf\n", payment);
    
    return 0;
}