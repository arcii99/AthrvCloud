//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *name = "Alice";
    float amount = 0.0;
    float rate = 0.0;
    int years = 0;
    printf("Welcome, %s! Let's calculate your mortgage payment.\n\n", name);
    printf("Please enter the amount of your mortgage: ");
    scanf("%f", &amount);
    printf("Please enter the interest rate in percentage: ");
    scanf("%f", &rate);
    printf("Please enter the number of years of your mortgage: ");
    scanf("%d", &years);

    float monthly_rate = rate / 1200;
    int months = years * 12;
    float monthly_payment = amount * monthly_rate / (1 - 1 / pow(1 + monthly_rate, months));

    printf("\n\nAfter some calculations, I have arrived at your monthly mortgage payment of %.2f.\n\n", monthly_payment);
    printf("Do you want to know how much interest you'll pay over the life of the mortgage?\n");
    printf("Type 'yes' or 'no': ");

    char input[10];
    scanf("%s", &input);
    if(strcmp(input, "yes") == 0) {
        float total_interest = monthly_payment * months - amount;
        printf("You will pay a total of %.2f in interest over the life of your mortgage.\n", total_interest);
    }
    printf("\nThank you for using our surreal mortgage calculator!");

    return 0;
}