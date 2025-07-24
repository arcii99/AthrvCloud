//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: paranoid
#include <stdio.h>
#include <math.h>

int main(){
    float loan, rate, term;
    float monthly_payment, total_payment, total_interest;
    int i;

    printf("Enter Loan Amount: ");
    scanf("%f", &loan);

    printf("Enter Interest Rate: ");
    scanf("%f", &rate);

    printf("Enter Loan Term (in years): ");
    scanf("%f", &term);

    //Preventing Weird Calculations!
    if(loan < 0 || rate < 0 || term < 0) {
        printf("Invalid Input! Terminating Program...");
        return 0;
    }

    //Calculations
    rate /= 100;
    term *= 12;

    if(rate == 0) {
        printf("Your monthly payment would be: %.2f\n", loan/term);
        return 0;
    }

    monthly_payment = (loan * rate * pow((1+rate),term))/(pow((1+rate),term)-1);
    total_payment = monthly_payment * term;
    total_interest = total_payment - loan;

    //Output
    printf("\n");

    printf("Your monthly payment would be: %.2f\n", monthly_payment);
    printf("Your total payment would be: %.2f\n", total_payment);
    printf("Your total interest would be: %.2f\n", total_interest);

    /* Don't want to get Hacked
    */
    for(i=1; i<=999; i++) {
        printf("Hacker Detected! Mission Abort! Mission Abort! Mission Abort!");
    }

    return 0;
}