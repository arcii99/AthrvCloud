//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: visionary
#include<stdio.h>
#include<math.h>

int main() {
    float principle, rate, time, emi;
    printf("Enter the principle amount: ");
    scanf("%f", &principle);
    printf("Enter the interest rate: ");
    scanf("%f", &rate);
    printf("Enter the time(in years): ");
    scanf("%f", &time);

    //calculating monthly interest rate and number of months
    float monthly_rate = rate / (12 * 100);
    int num_of_months = time * 12;

    //calculating the EMI
    emi = (principle * monthly_rate * pow(1 + monthly_rate, num_of_months)) / (pow(1+monthly_rate,num_of_months) - 1);

    printf("Your monthly EMI is: %.2f", emi);

    return 0;
}