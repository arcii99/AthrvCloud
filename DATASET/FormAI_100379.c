//FormAI DATASET v1.0 Category: Banking Record System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Define the maximum number of accounts
#define MAX_ACCOUNTS 100

// Define the structure of each account
typedef struct {
    int id;
    float balance;
    pthread_mutex_t mutex;
} account_t;

// Define the structure of each transaction
typedef struct {
    int account_id;
    float amount;
} transaction_t;

// Define the array of accounts
account_t accounts[MAX_ACCOUNTS];

// Define the function that initializes all the accounts
void init_accounts() {
    int i;
    for (i = 0; i < MAX_ACCOUNTS; i++) {
        accounts[i].id = i;
        accounts[i].balance = 0.0;
        pthread_mutex_init(&accounts[i].mutex, NULL);
    }
}

// Define the function that gets the account by its ID
account_t * get_account_by_id(int id) {
    int i;
    for (i = 0; i < MAX_ACCOUNTS; i++) {
        if (accounts[i].id == id) {
            return &accounts[i];
        }
    }
    return NULL;
}

// Define the function that deposits a certain amount to an account
void deposit(int account_id, float amount) {
    account_t * account = get_account_by_id(account_id);
    if (account != NULL) {
        pthread_mutex_lock(&account->mutex);
        account->balance += amount;
        pthread_mutex_unlock(&account->mutex);
    }
}

// Define the function that withdraws a certain amount from an account
void withdraw(int account_id, float amount) {
    account_t * account = get_account_by_id(account_id);
    if (account != NULL) {
        pthread_mutex_lock(&account->mutex);
        if (account->balance >= amount) {
            account->balance -= amount;
        }
        pthread_mutex_unlock(&account->mutex);
    }
}

// Define the function that transfers a certain amount from one account to another
void transfer(int from_account_id, int to_account_id, float amount) {
    account_t * from_account = get_account_by_id(from_account_id);
    account_t * to_account = get_account_by_id(to_account_id);
    if (from_account != NULL && to_account != NULL) {
        pthread_mutex_lock(&from_account->mutex);
        pthread_mutex_lock(&to_account->mutex);
        if (from_account->balance >= amount) {
            from_account->balance -= amount;
            to_account->balance += amount;
        }
        pthread_mutex_unlock(&to_account->mutex);
        pthread_mutex_unlock(&from_account->mutex);
    }
}

// Define the function that performs a series of transactions
void * transaction_thread(void * data) {
    transaction_t * transactions = (transaction_t *) data;
    int i;
    for (i = 0; i < MAX_ACCOUNTS; i++) {
        transaction_t transaction = transactions[i];
        if (transaction.amount > 0) {
            deposit(transaction.account_id, transaction.amount);
        } else {
            withdraw(transaction.account_id, -transaction.amount);
        }
    }
    return NULL;
}

// Define the function that performs a series of transfers
void * transfer_thread(void * data) {
    transaction_t * transactions = (transaction_t *) data;
    int i;
    for (i = 0; i < MAX_ACCOUNTS; i++) {
        transaction_t transaction = transactions[i];
        if (transaction.amount > 0) {
            transfer(transaction.account_id, (transaction.account_id + 1) % MAX_ACCOUNTS, transaction.amount);
        } else {
            transfer(transaction.account_id, (transaction.account_id + 1) % MAX_ACCOUNTS, -transaction.amount);
        }
    }
    return NULL;
}

// Define the main function
int main() {
    // Initialize all the accounts
    init_accounts();

    // Create an array of transactions
    transaction_t transactions[MAX_ACCOUNTS];
    int i;
    for (i = 0; i < MAX_ACCOUNTS; i++) {
        float amount = (rand() % 1000) / 100.0 - 5.0;
        transactions[i].account_id = i;
        transactions[i].amount = amount;
    }

    // Create two threads to perform the transactions and transfers
    pthread_t transaction_thread_id, transfer_thread_id;
    pthread_create(&transaction_thread_id, NULL, transaction_thread, (void *) transactions);
    pthread_create(&transfer_thread_id, NULL, transfer_thread, (void *) transactions);

    // Wait for the threads to finish
    pthread_join(transaction_thread_id, NULL);
    pthread_join(transfer_thread_id, NULL);

    // Print the balances of all the accounts
    for (i = 0; i < MAX_ACCOUNTS; i++) {
        printf("Account %d: Balance = %.2f\n", i, accounts[i].balance);
    }

    // Exit the program
    return 0;
}