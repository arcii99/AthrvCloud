//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: surprised
#include<stdio.h>
#include<math.h>

int main()
{
    float principle, rate, time, emi, interest, payment;
    printf("Welcome to the Mortgage Calculator!\n\n");
    printf("Enter the principle amount (in USD): "); scanf("%f", &principle);
    printf("Enter the rate of interest (in percentage): "); scanf("%f", &rate);
    printf("Enter the time period (in years): "); scanf("%f", &time);
    
    interest = (principle * rate * time) / 100;
    payment = principle + interest;
    emi = payment / (time * 12);
    
    printf("\nAfter %0.2f years, your total payment with interest will be: $%0.2f\n", time, payment);
    printf("And your monthly EMI will be: $%0.2f\n", emi);
    printf("Surprise! We have also calculated for you the total amount of interest you will pay: $%0.2f\n", interest);

    return 0;
}