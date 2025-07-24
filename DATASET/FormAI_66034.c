//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: romantic
#include <stdio.h>
#include <math.h>

int main() {
    int amount;
    float interest, monthlyPayment, totalPayment, principal, balance;
    int term;
    
    printf("My love,\n");
    printf("I have created a mortgage calculator program just for you.\n");
    printf("Please enter the amount you would like to borrow: ");
    scanf("%d", &amount);
    
    printf("And the interest rate: ");
    scanf("%f", &interest);
    
    printf("Finally, the term of the loan, in years: ");
    scanf("%d", &term);
    
    // Calculations
    interest = interest / 100.0;
    principal = amount;
    balance = amount;
    term *= 12;
    monthlyPayment = amount*(interest/12)*pow(1+interest/12, term)/(pow(1+interest/12, term)-1);
    totalPayment = monthlyPayment * term;
    
    // Output
    printf("\nMy dear, your monthly payment will be: $%.2f\n", monthlyPayment);
    printf("And the total payment over the life of the loan will be: $%.2f\n", totalPayment);
    printf("You will pay $%.2f in interest alone.\n", totalPayment - principal);
    
    printf("\nMy sweetest love, I hope this program helps you\n");
    printf("to better understand the financial commitment of your mortgage.\n");
    printf("Please remember that I love you unconditionally, \n");
    printf("and I am always here to support you through life's challenges.\n");
    
    return 0;
}