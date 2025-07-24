//FormAI DATASET v1.0 Category: Banking Record System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define ACCOUNTS 5
#define BALANCE_LIMIT 10000
#define TRANSACTIONS 10

int account_balances[ACCOUNTS];

pthread_mutex_t lock;

//function to generate random amount in a given range
int generateAmount(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

//function to perform withdrawal from an account
void* withdrawFromAccount(void* arg) {
    int account_no = *((int*)arg);
    int amount;
    for(int i=0; i<TRANSACTIONS; i++) {
        amount = generateAmount(100, 5000);
        pthread_mutex_lock(&lock);
        if(account_balances[account_no] - amount >= 0) {
            account_balances[account_no] -= amount;
            printf("Withdrawal: Account %d, Amount %d, Balance %d\n", account_no, amount, account_balances[account_no]);
        }
        else {
            printf("Withdrawal: Account %d, Insufficient Balance, Balance %d\n", account_no, account_balances[account_no]);
        }
        pthread_mutex_unlock(&lock);
        usleep(1000);
    }
    return NULL;
}

//function to perform deposit to an account
void* depositToAccount(void* arg) {
    int account_no = *((int*)arg);
    int amount;
    for(int i=0; i<TRANSACTIONS; i++) {
        amount = generateAmount(100, 5000);
        pthread_mutex_lock(&lock);
        if(account_balances[account_no] + amount <= BALANCE_LIMIT) {
            account_balances[account_no] += amount;
            printf("Deposit: Account %d, Amount %d, Balance %d\n", account_no, amount, account_balances[account_no]);
        }
        else {
            printf("Deposit: Account %d, Balance Limit Exceeded, Balance %d\n", account_no, account_balances[account_no]);
        }
        pthread_mutex_unlock(&lock);
        usleep(1000);
    }
    return NULL;
}

int main() {
    pthread_t threads[ACCOUNTS*2];
    int account_nos[ACCOUNTS];
    srand(time(NULL)); //seed the random number generator

    //initialize account balances
    for(int i=0; i<ACCOUNTS; i++) {
        account_balances[i] = generateAmount(5000, 9000);
    }

    //create threads for withdrawals and deposits
    for(int i=0; i<ACCOUNTS; i++) {
        account_nos[i] = i;
        pthread_create(&threads[i], NULL, withdrawFromAccount, &account_nos[i]);
        pthread_create(&threads[ACCOUNTS+i], NULL, depositToAccount, &account_nos[i]);
    }

    //wait for all threads to finish
    for(int i=0; i<ACCOUNTS*2; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}