//FormAI DATASET v1.0 Category: Banking Record System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_RECORDS 100

typedef struct {
    int acc_number;
    char name[50];
    double balance;
} BankAccount;

BankAccount bank_records[MAX_RECORDS];
int current_records = 0;

pthread_mutex_t lock;

void add_account(int acc_number, char* name, double balance) {
    pthread_mutex_lock(&lock);
    BankAccount bank_account;
    bank_account.acc_number = acc_number;
    strncpy(bank_account.name, name, 49);
    bank_account.balance = balance;
    bank_records[current_records] = bank_account;
    current_records++;
    pthread_mutex_unlock(&lock);
}

BankAccount* find_account(int acc_number) {
    pthread_mutex_lock(&lock);
    for(int i = 0; i < current_records; i++) {
        if(bank_records[i].acc_number == acc_number) {
            pthread_mutex_unlock(&lock);
            return &bank_records[i];
        }
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

void withdraw_amount(int acc_number, double amount) {
    BankAccount* bank_account = find_account(acc_number);
    if(bank_account == NULL) {
        printf("Error: Account not found\n");
        return;
    }

    pthread_mutex_lock(&lock);
    double new_balance = bank_account->balance - amount;
    if(new_balance < 0) {
        printf("Error: Insufficient balance\n");
        pthread_mutex_unlock(&lock);
        return;
    }

    bank_account->balance = new_balance;
    printf("Withdrawal successful\n");
    pthread_mutex_unlock(&lock);
}

void deposit_amount(int acc_number, double amount) {
    BankAccount* bank_account = find_account(acc_number);
    if(bank_account == NULL) {
        printf("Error: Account not found\n");
        return;
    }

    pthread_mutex_lock(&lock);
    bank_account->balance += amount;
    printf("Deposit successful\n");
    pthread_mutex_unlock(&lock);
}

void* thread_task(void* arg) {
    int acc_number = *((int*)arg);
    double amount = fmod(rand(), 10000);
    printf("Thread started for account %d\n", acc_number);
    while(true) {
        int action = rand() % 3;
        switch(action) {
            case 0:
                printf("Thread %d: Withdrawing %f\n", acc_number, amount);
                withdraw_amount(acc_number, amount);
                break;
            case 1:
                printf("Thread %d: Depositing %f\n", acc_number, amount);
                deposit_amount(acc_number, amount);
                break;
            default:
                printf("Thread %d: Skipping action\n", acc_number);
                break;
        }
        sleep(3);
    }
    free(arg);
    return NULL;
}

int main() {
    pthread_mutex_init(&lock, NULL);

    add_account(1, "John Doe", 10000.0);
    add_account(2, "Jane Doe", 5000.0);
    add_account(3, "Alice Smith", 7500.0);

    srand(time(NULL));
    for(int i = 0; i < 10; i++) {
        int* acc_number = malloc(sizeof(int));
        *acc_number = rand() % 3 + 1;
        pthread_t thread;
        pthread_create(&thread, NULL, thread_task, acc_number);
    }

    while(true) {
        char input[100];
        printf("Enter account number or exit: ");
        fgets(input, 100, stdin);
        if(strncmp(input, "exit", 4) == 0) {
            break;
        }
        int acc_number = atoi(input);
        BankAccount* bank_account = find_account(acc_number);
        if(bank_account == NULL) {
            printf("Account not found\n");
            continue;
        }
        printf("Name: %s\n", bank_account->name);
        printf("Balance: %f\n", bank_account->balance);
    }

    pthread_mutex_destroy(&lock);

    return 0;
}