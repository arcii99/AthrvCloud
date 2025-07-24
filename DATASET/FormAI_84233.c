//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double principle;
double interest_rate;
double years;
double monthly_payment;

void *calculation_thread(void *arg) {
    double rate = interest_rate / 12.0;
    double num_payments = years * 12.0;
    double outstanding_balance = principle;
    double monthly_rate = rate / 100.0;
    double monthly_interest = monthly_rate * outstanding_balance;
    double numerator = monthly_interest * pow((1.0 + monthly_rate), num_payments);
    double denominator = pow((1.0 + monthly_rate), num_payments) - 1.0;
    monthly_payment = numerator / denominator;
    return NULL;
}

int main() {
    printf("Enter the principle: ");
    scanf("%lf", &principle);
    printf("Enter the interest rate: ");
    scanf("%lf", &interest_rate);
    printf("Enter the number of years: ");
    scanf("%lf", &years);
 
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, calculation_thread, NULL);
 
    pthread_join(thread_id, NULL);
 
    printf("\nMonthly Payments: %.2lf\n", monthly_payment);
 
    return 0;
}