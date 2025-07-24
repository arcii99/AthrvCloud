//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: creative
#include<stdio.h>
#include<math.h>

/* Function to calculate monthly mortgage payments */
double calculatePayment(double loanAmt, double intRate, double termYrs)
{
    double intRatePct = intRate / 100;  
    double termMonths = termYrs * 12;    
    double monthlyRate = intRatePct / 12; 
    double numerator = loanAmt * monthlyRate; 
    double denominator = 1 - pow(1 + monthlyRate, -termMonths);  
    double paymentAmt = numerator / denominator; 
  
    return paymentAmt; 
}

int main()
{
    double loanAmt, intRate, termYrs, paymentAmt;
    
    printf("Welcome to the Mortgage Calculator!\n");
    printf("Please enter the following information:\n");
    
    printf("Loan amount: ");
    scanf("%lf", &loanAmt);
    
    printf("Interest rate: ");
    scanf("%lf", &intRate);
    
    printf("Loan term (in years): ");
    scanf("%lf", &termYrs);
    
    paymentAmt = calculatePayment(loanAmt, intRate, termYrs);
    
    printf("\nYour monthly payment amount is: $%.2lf\n", paymentAmt);
    
    return 0;
}