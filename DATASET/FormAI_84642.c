//FormAI DATASET v1.0 Category: Banking Record System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_ACCOUNTS 10
#define MAX_TRANSACTIONS 100

typedef struct {
    int accountNumber;
    int accountBalance;
    pthread_mutex_t lock;
} Account;

typedef struct {
    int accountFrom;
    int accountTo;
    int transactionAmount;
} Transaction;

sem_t transactionSemaphore;

Account accounts[MAX_ACCOUNTS];
Transaction transactions[MAX_TRANSACTIONS];
int numAccounts = 0;
int numTransactions = 0;

void createAccount(int initialBalance) {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Reached maximum number of accounts.\n");
        return;
    }
    Account newAccount;
    newAccount.accountNumber = numAccounts;
    newAccount.accountBalance = initialBalance;
    pthread_mutex_init(&newAccount.lock, NULL);
    accounts[numAccounts++] = newAccount;
    printf("Created account with number %d and initial balance %d.\n", newAccount.accountNumber, newAccount.accountBalance);
}

void createTransaction(int from, int to, int amount) {
    if (numTransactions >= MAX_TRANSACTIONS) {
        printf("Reached maximum number of transactions.\n");
        return;
    }
    Transaction newTransaction;
    newTransaction.accountFrom = from;
    newTransaction.accountTo = to;
    newTransaction.transactionAmount = amount;
    transactions[numTransactions++] = newTransaction;
}

void* processTransactions(void* arg) {
    while (true) {
        sem_wait(&transactionSemaphore);

        Transaction transaction = transactions[numTransactions-1];
        numTransactions--;

        Account* fromAccount = &accounts[transaction.accountFrom];
        Account* toAccount = &accounts[transaction.accountTo];

        pthread_mutex_lock(&fromAccount->lock);
        if (fromAccount->accountBalance < transaction.transactionAmount) {
            printf("Transaction failed: insufficient funds in account %d.\n", fromAccount->accountNumber);
            pthread_mutex_unlock(&fromAccount->lock);
            continue;
        }
        fromAccount->accountBalance -= transaction.transactionAmount;
        pthread_mutex_unlock(&fromAccount->lock);

        pthread_mutex_lock(&toAccount->lock);
        toAccount->accountBalance += transaction.transactionAmount;
        pthread_mutex_unlock(&toAccount->lock);

        printf("Transaction successful: transferred %d from account %d to account %d.\n", transaction.transactionAmount, fromAccount->accountNumber, toAccount->accountNumber);
    }
}

int main() {
    sem_init(&transactionSemaphore, 0, 0);

    // create some accounts
    createAccount(1000);
    createAccount(500);
    createAccount(200);
    createAccount(3000);

    // create some transactions
    createTransaction(0, 1, 100);
    createTransaction(1, 2, 50);
    createTransaction(0, 3, 500);
    createTransaction(2, 0, 30);
    createTransaction(3, 0, 700);

    // start transaction processing thread
    pthread_t transactionThread;
    pthread_create(&transactionThread, NULL, processTransactions, NULL);

    // signal transaction processing thread to start
    sem_post(&transactionSemaphore);

    // wait for transaction processing thread to finish
    pthread_join(transactionThread, NULL);

    // cleanup
    sem_destroy(&transactionSemaphore);

    for (int i = 0; i < numAccounts; i++) {
        pthread_mutex_destroy(&accounts[i].lock);
    }

    return EXIT_SUCCESS;
}