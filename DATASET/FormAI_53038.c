//FormAI DATASET v1.0 Category: Banking Record System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_ACCOUNTS 10 // maximum number of accounts
#define MAX_TRANSACTIONS 100 // maximum number of transactions per account
#define MIN_BALANCE 1000 // minimum balance required to open an account

typedef struct {
    int account_no;
    int balance;
    int num_transactions;
    int transactions[MAX_TRANSACTIONS];
} account_t;

account_t accounts[MAX_ACCOUNTS];
int num_accounts = 0;
pthread_mutex_t lock[MAX_ACCOUNTS];

void add_account(int init_balance) {
    if (num_accounts < MAX_ACCOUNTS && init_balance >= MIN_BALANCE) {
        account_t new_account = {num_accounts + 1, init_balance, 0};
        accounts[num_accounts++] = new_account;
    } else {
        printf("Could not create account. Maximum number of accounts reached or minimum balance not met.\n");
    }
}

void deposit(int account_no, int amount) {
    if (account_no >= 1 && account_no <= num_accounts) {
        pthread_mutex_lock(&lock[account_no-1]);
        accounts[account_no-1].balance += amount;
        accounts[account_no-1].transactions[accounts[account_no-1].num_transactions++] = amount;
        pthread_mutex_unlock(&lock[account_no-1]);
    } else {
        printf("Invalid account number.\n");
    }
}

void withdraw(int account_no, int amount) {
    if (account_no >=1 && account_no <= num_accounts) {
        pthread_mutex_lock(&lock[account_no-1]);
        if (accounts[account_no-1].balance - amount >= MIN_BALANCE) {
            accounts[account_no-1].balance -= amount;
            accounts[account_no-1].transactions[accounts[account_no-1].num_transactions++] = -amount;
        } else {
            printf("Insufficient balance.\n");
        }
        pthread_mutex_unlock(&lock[account_no-1]);
    } else {
        printf("Invalid account number.\n");
    }
}

int transfer(int from, int to, int amount) {
    if (from >= 1 && from <= num_accounts && to >= 1 && to <= num_accounts) {
        if (from == to) {
            printf("Cannot transfer to the same account.\n");
            return -1;
        } else {
            int from_idx = from-1;
            int to_idx = to-1;
            if (from_idx < to_idx) {
                pthread_mutex_lock(&lock[from_idx]);
                pthread_mutex_lock(&lock[to_idx]);
            } else {
                pthread_mutex_lock(&lock[to_idx]);
                pthread_mutex_lock(&lock[from_idx]);
            }
            if (accounts[from_idx].balance - amount >= MIN_BALANCE) {
                accounts[from_idx].balance -= amount;
                accounts[from_idx].transactions[accounts[from_idx].num_transactions++] = -amount;
                accounts[to_idx].balance += amount;
                accounts[to_idx].transactions[accounts[to_idx].num_transactions++] = amount;
                pthread_mutex_unlock(&lock[from_idx]);
                pthread_mutex_unlock(&lock[to_idx]);
                return 0;
            } else {
                printf("Insufficient balance.\n");
                pthread_mutex_unlock(&lock[from_idx]);
                pthread_mutex_unlock(&lock[to_idx]);
                return -1;
            }
        }
    } else {
        printf("Invalid account number.\n");
        return -1;
    }
}

void *random_transactions(void *arg) {
    int *thread_num = (int *) arg;
    srand(time(NULL) + *thread_num);
    for (int i = 0; i < 10; i++) {
        int from = rand() % num_accounts + 1;
        int to = rand() % num_accounts + 1;
        int amount = rand() % 100 + 1;
        int success;
        if (rand() % 2 == 0) {
            success = transfer(from, to, amount);
            printf("Thread %d transferred %d from account %d to account %d. Success: %s\n",
                    *thread_num, amount, from, to, success == 0 ? "true" : "false");
        } else {
            success = 0;
            if (rand() % 2 == 0) {
                deposit(from, amount);
                printf("Thread %d deposited %d into account %d.\n", *thread_num, amount, from);
            } else {
                withdraw(from, amount);
                printf("Thread %d withdrew %d from account %d.\n", *thread_num, amount, from);
            }
        }
        usleep(rand() % 1000000); // sleep for up to 1 second
    }
    free(arg);
    return NULL;
}

int main() {
    // initialize mutex locks
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        pthread_mutex_init(&lock[i], NULL);
    }
    // create initial accounts
    add_account(5000);
    add_account(2000);
    add_account(3000);
    // create 5 threads for random transactions
    pthread_t threads[5];
    for (int i = 0; i < 5; i++) {
        int *thread_num = malloc(sizeof(int));
        *thread_num = i+1;
        pthread_create(&threads[i], NULL, random_transactions, thread_num);
    }
    // join threads
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }
    // print transaction history for each account
    for (int i = 0; i < num_accounts; i++) {
        printf("Account %d:\nBalance: %d\nTransaction history:\n", accounts[i].account_no, accounts[i].balance);
        for (int j = 0; j < accounts[i].num_transactions; j++) {
            if (accounts[i].transactions[j] > 0) {
                printf("Deposit: +%d\n", accounts[i].transactions[j]);
            } else {
                printf("Withdrawal: %d\n", accounts[i].transactions[j]);
            }
        }
        printf("\n");
    }
    // destroy mutex locks
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        pthread_mutex_destroy(&lock[i]);
    }
    return 0;
}