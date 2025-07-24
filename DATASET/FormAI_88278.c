//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_INVESTMENT 100000
#define MIN_INVESTMENT 1000

float calculate_earnings(float investment, int years, float rate);

int main() {
    float investment, rate;
    int years;

    printf("What is your initial investment?\n");
    scanf("%f", &investment);

    if (investment < MIN_INVESTMENT) {
        printf("Error: The minimum investment is $1,000.\n");
        exit(0);
    }

    if (investment > MAX_INVESTMENT) {
        printf("Error: The maximum investment is $100,000.\n");
        exit(0);
    }

    printf("What is the annual percentage rate (in decimal form)?\n");
    scanf("%f", &rate);

    printf("How many years will you be investing?\n");
    scanf("%d", &years);

    float earnings = calculate_earnings(investment, years, rate);

    printf("You will earn $%.2f after %d years of investing.\n", earnings, years);

    return 0;
}

float calculate_earnings(float investment, int years, float rate) {
    float balance = investment;
    for (int i = 0; i < years; i++) {
        balance += balance * rate;
    }
    return balance - investment;
}