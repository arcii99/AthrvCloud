//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: excited
#include<stdio.h>
#include<math.h>

// This is a cool mortgage calculator program
// that will help you calculate your monthly mortgage payments

int main()
{
    float principle, rate, time, payment, total_interest;
    int periods;
    
    printf("Welcome to the Mortgage Calculator!\n\n");
    printf("Please enter the principle amount: ");
    scanf("%f", &principle);
    printf("Please enter the interest rate (in decimal form): ");
    scanf("%f", &rate);
    printf("Please enter the number of years for the mortgage: ");
    scanf("%f", &time);
    
    periods = time * 12;
    rate /= 12;
    
    // Here we will use the mortgage formula to calculate the monthly payments and total interest
    payment = (principle * rate) / (1 - pow(1 + rate, -periods));
    total_interest = (payment * periods) - principle;
    
    printf("\nYour monthly payment will be: $%.2f\n", payment);
    printf("Over the course of %d years, you will pay a total of: $%.2f\n", (int)time, (payment * periods));
    printf("Of that amount, $%.2f will be paid in interest.\n", total_interest);
    
    return 0;
}