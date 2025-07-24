//FormAI DATASET v1.0 Category: Banking Record System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ACCOUNTS 100
#define INIT_BALANCE 1000
#define NUM_THREADS 10

typedef struct Account {
    int id;
    int balance;
    pthread_mutex_t lock;
} Account;

Account accounts[MAX_ACCOUNTS];
int num_accounts;

void *transfer(void *arg) {
    int from_id, to_id, amount;
    char *params = (char *) arg;

    sscanf(params, "%d %d %d", &from_id, &to_id, &amount);
    pthread_mutex_lock(&accounts[from_id].lock);
    pthread_mutex_lock(&accounts[to_id].lock);
    accounts[from_id].balance -= amount;
    accounts[to_id].balance += amount;
    printf("Transferred %d from account %d to account %d\n", amount, from_id, to_id);
    pthread_mutex_unlock(&accounts[to_id].lock);
    pthread_mutex_unlock(&accounts[from_id].lock);
    return NULL;
}

int main() {
    num_accounts = MAX_ACCOUNTS;
    for (int i = 0; i < num_accounts; i++) {
        accounts[i].id = i;
        accounts[i].balance = INIT_BALANCE;
        pthread_mutex_init(&accounts[i].lock, NULL);
    }

    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        int from_id = rand() % num_accounts;
        int to_id = rand() % num_accounts;
        while (to_id == from_id) {
            to_id = rand() % num_accounts;
        }
        int amount = rand() % 100 + 1;

        char params[100];
        snprintf(params, sizeof(params), "%d %d %d", from_id, to_id, amount);

        pthread_create(&threads[i], NULL, transfer, params);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < num_accounts; i++) {
        printf("Account %d balance: %d\n", accounts[i].id, accounts[i].balance);
    }

    return 0;
}