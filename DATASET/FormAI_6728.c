//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int balance = 0;
pthread_mutex_t lock; // mutex for thread safety

void *deposit(void *arg) {
    int deposit_amount = *((int *) arg);
    pthread_mutex_lock(&lock); // acquire the lock
    balance += deposit_amount;
    printf("Deposited $%d, new balance is $%d\n", deposit_amount, balance);
    pthread_mutex_unlock(&lock); // release the lock
    return NULL;
}

void *withdraw(void *arg) {
    int withdraw_amount = *((int *) arg);
    pthread_mutex_lock(&lock); // acquire the lock
    if (withdraw_amount > balance) {
        printf("Insufficient balance: cannot withdraw $%d\n", withdraw_amount);
    } else {
        balance -= withdraw_amount;
        printf("Withdrawn $%d, new balance is $%d\n", withdraw_amount, balance);
    }
    pthread_mutex_unlock(&lock); // release the lock
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int deposit_amount = 1000, withdraw_amount = 500;

    if (pthread_mutex_init(&lock, NULL) != 0) { // initialize the lock
        printf("Mutex init failed\n");
        return 1;
    }

    if (pthread_create(&thread1, NULL, deposit, &deposit_amount) != 0) { // create the deposit thread
        printf("Thread creation failed\n");
        return 1;
    }

    if (pthread_create(&thread2, NULL, withdraw, &withdraw_amount) != 0) { // create the withdraw thread
        printf("Thread creation failed\n");
        return 1;
    }

    pthread_join(thread1, NULL); // wait for deposit thread to finish
    pthread_join(thread2, NULL); // wait for withdraw thread to finish

    pthread_mutex_destroy(&lock); // destroy the lock

    return 0;
}