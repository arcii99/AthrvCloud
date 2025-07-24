//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float principal;
    float rate;
    int term;
} Mortgage;

Mortgage* createMortgage(float principal, float rate, int term) {
    Mortgage* mortgage = malloc(sizeof(Mortgage));
    mortgage->principal = principal;
    mortgage->rate = rate / 100;
    mortgage->term = term * 12;
    return mortgage;
}

float calculateMonthlyPayment(Mortgage* mortgage) {
    float r = mortgage->rate / 12;
    float n = mortgage->term;
    float p = mortgage->principal;
    return p * r * powf(1 + r, n) / (powf(1 + r, n) - 1);
}

void printMortgage(Mortgage* mortgage) {
    printf("Mortgage Principal: %.2f\n", mortgage->principal);
    printf("Mortgage Interest Rate: %.2f%%\n", mortgage->rate * 100);
    printf("Mortgage Term: %d years\n", mortgage->term / 12);
    printf("Monthly Payment: $%.2f\n", calculateMonthlyPayment(mortgage));
}

int main() {
    float principal, rate;
    int term;
    printf("Enter mortgage principal: $");
    scanf("%f", &principal);
    printf("Enter mortgage interest rate: ");
    scanf("%f", &rate);
    printf("Enter mortgage term (in years): ");
    scanf("%d", &term);
    Mortgage* mortgage = createMortgage(principal, rate, term);
    printMortgage(mortgage);
    free(mortgage);
    return 0;
}