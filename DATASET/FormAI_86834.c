//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: interoperable
#include<stdio.h>

int main(){
    float principal, rate, time, interest, total;
    
    //take input from user
    printf("Enter Principal (Loan Amount): ");
    scanf("%f", &principal);
    printf("Enter Annual Interest Rate: ");
    scanf("%f", &rate);
    printf("Enter Time Period (in years): ");
    scanf("%f", &time);
    
    //calculate interest and total payment
    interest = (principal * rate * time) / 100;
    total = principal + interest;
    
    //print the result
    printf("\nMortgage Details\n");
    printf("*****************\n");
    printf("Loan Amount: $%.2f\n", principal);
    printf("Annual Interest Rate: %.2f%%\n", rate);
    printf("Time Period (in years): %.2f\n", time);
    printf("Interest Amount: $%.2f\n", interest);
    printf("Total Payment: $%.2f\n", total);
    
    return 0;
}