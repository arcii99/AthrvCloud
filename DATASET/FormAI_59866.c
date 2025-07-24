//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Calculates monthly mortgage payments */
void *calculate_mortgage(void *arg) {
    float loan_amount = *((float *) arg);
    float interest_rate = 0.045;
    float monthly_interest_rate = interest_rate / 12.0;
    int loan_term = 30;
    int num_payments = loan_term * 12;
    float monthly_payment = (loan_amount * monthly_interest_rate) / (1.0 - pow(1.0 + monthly_interest_rate, -num_payments));
    printf("Monthly mortgage payment: $%.2f\n", monthly_payment);
    pthread_exit(NULL);
}

int main() {
    float loan_amount;

    // Get input from user
    printf("Enter loan amount: $");
    scanf("%f", &loan_amount);

    // Initialize thread
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    // Start thread
    pthread_create(&tid, &attr, calculate_mortgage, &loan_amount);

    // Join thread
    pthread_join(tid, NULL);

    return 0;
}