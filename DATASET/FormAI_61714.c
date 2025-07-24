//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: recursive
#include <stdio.h>

// Recursive calculation of simple interest
float calc_simple_interest(float principle, float rate, int time) {
    if (time == 0) {
        return principle;
    }
    return calc_simple_interest(principle * (1 + rate), rate, time - 1);
}

// Recursive calculation of compound interest
float calc_compound_interest(float principle, float rate, int time) {
    if (time == 0) {
        return principle;
    }
    return calc_compound_interest(principle * (1 + rate), rate, time - 1);
}

int main() {
    float principle, rate, result;
    int time;

    printf("Enter principle amount: ");
    scanf("%f", &principle);

    printf("Enter interest rate: ");
    scanf("%f", &rate);

    printf("Enter time period (in years): ");
    scanf("%d", &time);

    result = calc_simple_interest(principle, rate, time);
    printf("Simple interest after %d years: %.2f\n", time, result);

    result = calc_compound_interest(principle, rate, time);
    printf("Compound interest after %d years: %.2f\n", time, result);

    return 0;
}