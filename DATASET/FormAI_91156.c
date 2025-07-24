//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int balance = 5000; // Starting balance

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex to lock the balance variable

void* deposit(void* arg) {
    int amount = *(int*) arg;
    pthread_mutex_lock(&mutex); // Lock the balance variable
    balance += amount;
    printf("Deposited $%d. New balance is $%d.\n", amount, balance);
    pthread_mutex_unlock(&mutex); // Unlock the balance variable
    return NULL;
}

void* withdraw(void* arg) {
    int amount = *(int*) arg;
    pthread_mutex_lock(&mutex); // Lock the balance variable
    if (balance >= amount) {
        balance -= amount;
        printf("Withdrew $%d. New balance is $%d.\n", amount, balance);
    } else {
        printf("Not enough funds to withdraw $%d. Current balance is $%d.\n", amount, balance);
    }
    pthread_mutex_unlock(&mutex); // Unlock the balance variable
    return NULL;
}

int main() {
    pthread_t thread1, thread2; // Two threads for deposit and withdraw operations
    int deposit_amount = 2000;
    int withdraw_amount = 1000;
    printf("Starting balance is $%d.\n", balance);
    pthread_create(&thread1, NULL, deposit, &deposit_amount); // Create deposit thread
    pthread_create(&thread2, NULL, withdraw, &withdraw_amount); // Create withdraw thread
    pthread_join(thread1, NULL); // Wait for deposit thread to finish
    pthread_join(thread2, NULL); // Wait for withdraw thread to finish
    printf("Ending balance is $%d.\n", balance);
    return 0;
}