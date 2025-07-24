//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: lively
#include<stdio.h>
#include<math.h>

int main(){

    float Principal, Rate, Time, EM, Total_Payable;
    

    printf("Welcome to Mortgage Calculator\n\n");

    //Getting Input Values
    
    printf("Enter principal (loan amount): $");
    scanf("%f", &Principal);
    
    printf("Enter Interest Rate: ");
    scanf("%f", &Rate);
    
    printf("Enter Loan Period (in years): ");
    scanf("%f", &Time);

    //Calculating Monthly Payment

    Rate = Rate/(12*100);        //Monthly Interest Rate
    Time = Time*12;              //Loan Period in Months
    EM = (Principal*Rate*pow(1+Rate,Time))/(pow(1+Rate,Time)-1);
    
    //Calculating Total Payable Amount
    
    Total_Payable = EM * Time;

    //Displaying Results

    printf("\nYour monthly payment: $%.2f\n", EM);
    printf("Total payable amount: $%.2f\n", Total_Payable);
    
    return 0;
}