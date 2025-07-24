//FormAI DATASET v1.0 Category: Banking Record System ; Style: multi-threaded
//Header Files
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

//Global Variables
int account_balance[1000];
char customer_names[1000][50];
int num_customers = 0;

//Mutexes
pthread_mutex_t balance_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t name_mutex = PTHREAD_MUTEX_INITIALIZER;

//Function Prototypes
void add_customer(char *name, int balance);
void *deposit(void *arg);
void *withdraw(void *arg);

//Main Function
int main()
{
    pthread_t threads[1000];
    int num_threads = 0;
    
    add_customer("John Doe", 5000);
    add_customer("Jane Smith", 10000);
    add_customer("Bob Johnson", 7500);

    for(int i = 0; i < num_customers; i++)
    {
        pthread_create(&threads[num_threads++], NULL, deposit, (void *)i);
        pthread_create(&threads[num_threads++], NULL, withdraw, (void *)i);
    }

    for(int i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

//Add a new customer to the system
void add_customer(char *name, int balance)
{
    pthread_mutex_lock(&name_mutex);
    strcpy(customer_names[num_customers], name);
    pthread_mutex_unlock(&name_mutex);

    pthread_mutex_lock(&balance_mutex);
    account_balance[num_customers] = balance;
    pthread_mutex_unlock(&balance_mutex);

    num_customers++;
}

//Deposit money into a customer's account
void *deposit(void *arg)
{
    int customer_id = (int)arg;
    int amount = rand() % 10000 + 100;

    pthread_mutex_lock(&balance_mutex);
    account_balance[customer_id] += amount;
    printf("%s deposited $%d. New balance is $%d.\n",
           customer_names[customer_id], amount, account_balance[customer_id]);
    pthread_mutex_unlock(&balance_mutex);

    pthread_exit(NULL);
}

//Withdraw money from a customer's account
void *withdraw(void *arg)
{
    int customer_id = (int)arg;
    int amount = rand() % 1000 + 1;

    while(amount > account_balance[customer_id])
    {
        printf("Insufficient funds for %s. Waiting...\n", customer_names[customer_id]);
        sleep(1);
    }

    pthread_mutex_lock(&balance_mutex);
    account_balance[customer_id] -= amount;
    printf("%s withdrew $%d. New balance is $%d.\n",
           customer_names[customer_id], amount, account_balance[customer_id]);
    pthread_mutex_unlock(&balance_mutex);

    pthread_exit(NULL);
}