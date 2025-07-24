//FormAI DATASET v1.0 Category: Banking Record System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int account_balance = 100;

pthread_mutex_t lock;

void *withdraw(void *arg){
    int amount = *(int*)arg;
    pthread_mutex_lock(&lock);
    if(account_balance >= amount){
        printf("Withdrawal successful.\n");
        account_balance -= amount;
        printf("Account balance: %d\n", account_balance);
    }
    else{
        printf("Insufficient funds.\n");
    }
    
    pthread_mutex_unlock(&lock);
    return NULL;
}

void *deposit(void *arg){
    int amount = *(int*)arg;
    pthread_mutex_lock(&lock);
    printf("Deposit successful.\n");
    account_balance += amount;
    printf("Account balance: %d\n", account_balance);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(){
    pthread_t threads[4];
    int withdraw_amount = 50;
    int deposit_amount = 150;

    pthread_mutex_init(&lock, NULL);
    
    pthread_create(&threads[0], NULL, withdraw, &withdraw_amount);
    
    pthread_create(&threads[1], NULL, deposit, &deposit_amount);
    
    pthread_create(&threads[2], NULL, withdraw, &withdraw_amount);
    
    pthread_create(&threads[3], NULL, deposit, &deposit_amount);

    for(int i=0; i<4; i++){
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    return 0;
}