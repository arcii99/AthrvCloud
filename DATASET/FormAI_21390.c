//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: thoughtful
#include <stdio.h>
#include <math.h>

int main() {
    float principle, roi, emi, interest;
    int tenure, months;
    
    printf("Enter the Loan Amount: ");
    scanf("%f", &principle);
    
    printf("Enter the Rate of Interest: ");
    scanf("%f", &roi);
    
    printf("Enter the Tenure (in years): ");
    scanf("%d", &tenure);
    
    months = tenure * 12; // Converting years to months for easier calculation
    
    roi = roi / (12 * 100); // Converting annual interest rate to monthly interest rate
    
    emi = (principle * roi * pow(1 + roi, months)) / (pow(1 + roi, months) - 1);
    
    printf("\nEMI: Rs.%f", emi);
    
    interest = (emi * months) - principle;
    
    printf("\nTotal Interest Payable: Rs.%f", interest);
    
    return 0;
}