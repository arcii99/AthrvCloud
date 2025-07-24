//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: synchronous
#include<stdio.h>
#include<math.h>

int main(){
    float principal, rate, time, emi, total_amount, total_interest;
    int n;
    
    //asking user for input
    printf("Enter Principal amount: ");
    scanf("%f", &principal);
    printf("Enter Rate of Interest: ");
    scanf("%f", &rate);
    printf("Enter Time (in years): ");
    scanf("%f", &time);
    
    //calculating the monthly interest rate and number of months
    float monthly_rate = rate/(12*100);
    n = time*12;
    
    //calculating the EMI
    emi = (principal*monthly_rate*pow((1+monthly_rate),n))/(pow((1+monthly_rate),n)-1);
    
    //calculating the total amount and total interest
    total_amount = emi * n;
    total_interest = total_amount - principal;
    
    //printing the results
    printf("\n\nLoan Details:\n");
    printf("Principal Amount: %.2f\n", principal);
    printf("Rate of Interest: %.2f\n", rate);
    printf("Time (in years): %.2f\n", time);
    printf("Monthly EMI: %.2f\n", emi);
    printf("Total Amount to be paid: %.2f\n", total_amount);
    printf("Total Interest paid: %.2f\n", total_interest);
    
    return 0;
}