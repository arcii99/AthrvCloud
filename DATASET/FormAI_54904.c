//FormAI DATASET v1.0 Category: Expense Tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int expense = 0;
pthread_mutex_t expense_lock;

void *addExpense(void *arg) {
    int amount = *((int*) arg);
    pthread_mutex_lock(&expense_lock);
    expense += amount;
    printf("Added %d to expense, new expense is %d\n", amount, expense);
    pthread_mutex_unlock(&expense_lock);
    return NULL;
}

int main() {
    int num_threads = 5;
    pthread_t threads[num_threads];
    int amounts[num_threads];
    int i;

    if (pthread_mutex_init(&expense_lock, NULL) != 0) {
        printf("Error initializing mutex\n");
        return 1;
    }

    for (i = 0; i < num_threads; i++) {
        amounts[i] = rand() % 1000 + 1;
        if (pthread_create(&threads[i], NULL, addExpense, &amounts[i]) != 0) {
            printf("Error creating thread\n");
            return 1;
        }
    }

    for (i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            printf("Error joining thread\n");
            return 1;
        }
    }

    printf("Final expense is %d\n", expense);

    pthread_mutex_destroy(&expense_lock);

    return 0;
}