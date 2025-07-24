//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: real-life
/* This program is a simple example of a C Threading Library implementation for a real-life scenario where multiple threads need to access a shared resource (in this case, a bank account) */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Define a global variable to represent the bank account balance
int balance = 0;

// Define a struct to hold information about a transaction
struct transaction {
    int amount;
    char type; // 'd' for deposit, 'w' for withdrawal
};

// Define a mutex variable to ensure thread safety
pthread_mutex_t mutex;

// Define a function to execute a transaction and update the balance
void do_transaction(struct transaction *trans) {
    pthread_mutex_lock(&mutex);
    // Acquire the lock to prevent other threads from modifying the balance
    if (trans->type == 'd') {
        balance += trans->amount;
        printf("Deposit of %d processed successfully. New balance is %d\n", trans->amount, balance);
    } else {
        if (trans->amount > balance) {
            printf("Insufficient balance to withdraw %d. Current balance is %d\n", trans->amount, balance);
        } else {
            balance -= trans->amount;
            printf("Withdrawal of %d processed successfully. New balance is %d\n", trans->amount, balance);
        }
    }
    pthread_mutex_unlock(&mutex);
    // Release the lock once the transaction is complete
}

// Define a function to represent the behavior of a deposit thread
void *deposit(void *arg) {
    struct transaction *trans = (struct transaction *) arg;
    do_transaction(trans);
    pthread_exit(NULL);
}

// Define a function to represent the behavior of a withdrawal thread
void *withdraw(void *arg) {
    struct transaction *trans = (struct transaction *) arg;
    do_transaction(trans);
    pthread_exit(NULL);
}

// Define the main function to test the C Threading Library implementation
int main() {
    // Declare variables to hold the transaction details
    struct transaction t1 = {100, 'd'};
    struct transaction t2 = {50, 'w'};
    struct transaction t3 = {200, 'd'};
    struct transaction t4 = {300, 'w'};
    
    // Initialize the mutex variable
    pthread_mutex_init(&mutex, NULL);
    
    // Declare thread variables to store the thread IDs
    pthread_t deposit_thread1, withdraw_thread1, deposit_thread2, withdraw_thread2;
    
    // Create the threads and execute the transactions
    pthread_create(&deposit_thread1, NULL, deposit, (void *) &t1);
    pthread_create(&withdraw_thread1, NULL, withdraw, (void *) &t2);
    pthread_create(&deposit_thread2, NULL, deposit, (void *) &t3);
    pthread_create(&withdraw_thread2, NULL, withdraw, (void *) &t4);
    
    // Wait for the threads to finish executing
    pthread_join(deposit_thread1, NULL);
    pthread_join(withdraw_thread1, NULL);
    pthread_join(deposit_thread2, NULL);
    pthread_join(withdraw_thread2, NULL);
    
    // Destroy the mutex variable
    pthread_mutex_destroy(&mutex);
    
    return 0;
}