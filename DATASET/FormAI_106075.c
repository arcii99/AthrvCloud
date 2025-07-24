//FormAI DATASET v1.0 Category: Banking Record System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_ACCOUNTS 10
#define MAX_AMOUNT 100

int accounts[NUM_ACCOUNTS];

void* transfer(void* arg) {
    int* params = (int*)arg;
    int account1 = params[0];
    int account2 = params[1];
    int amount = params[2];
    if (accounts[account1] < amount) {
        printf("Not enough balance in account %d for transfer to account %d\n", account1, account2);
        pthread_exit(NULL);
    }
    accounts[account1] -= amount;
    accounts[account2] += amount;
    printf("Transfer of amount %d from account %d to account %d has been completed successfully\n", amount, account1, account2);
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));
    pthread_t threads[NUM_ACCOUNTS*NUM_ACCOUNTS];
    int thread_args[NUM_ACCOUNTS*NUM_ACCOUNTS][3];
    int i, j, k = 0;
    for (i = 0; i < NUM_ACCOUNTS; i++) {
        accounts[i] = rand() % 1000;
        printf("Account %d has a balance of %d\n", i, accounts[i]);
        for (j = 0; j < NUM_ACCOUNTS; j++) {
            if (i != j) {
                int amount = rand() % MAX_AMOUNT;
                thread_args[k][0] = i;
                thread_args[k][1] = j;
                thread_args[k][2] = amount;
                pthread_create(&threads[k], NULL, transfer, thread_args[k]);
                k++;
            }
        }
    }
    for (i = 0; i < k; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("All transfers have been completed successfully\n");
    for (i = 0; i < NUM_ACCOUNTS; i++) {
        printf("Account %d now has a balance of %d\n", i, accounts[i]);
    }
    return 0;
}