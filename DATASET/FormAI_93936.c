//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: random
#include <stdio.h>
#include <math.h>

//Function to calculate monthly interest
double calculateMonthlyInterest(int principal, double rate, int years) {
    double monthlyRate = rate/1200;
    int months = years * 12;
    double monthlyInterest = principal * monthlyRate * pow(1+monthlyRate, months)/(pow(1+monthlyRate, months)-1);
    return monthlyInterest;
}

int main() {
    int principal, years;
    double rate, monthlyInterest;

    //Taking input for principal amount
    printf("Enter the principal amount: ");
    scanf("%d", &principal);

    //Taking input for interest rate
    printf("Enter the interest rate: ");
    scanf("%lf", &rate);

    //Taking input for number of years
    printf("Enter the number of years: ");
    scanf("%d", &years);

    //Calculating the monthly interest
    monthlyInterest = calculateMonthlyInterest(principal, rate, years);

    //Printing the monthly interest
    printf("\nYour monthly interest is: %.2lf", monthlyInterest);

    //Calculating the total payment
    double totalPayment = monthlyInterest * 12 * years;

    //Printing the total payment
    printf("\nYour total payment for this mortgage is: %.2lf", totalPayment);

    return 0;
}