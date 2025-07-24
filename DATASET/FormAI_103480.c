//FormAI DATASET v1.0 Category: System administration ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// define the number of threads
#define NUM_THREADS 4
// define the maximum number of users
#define MAX_USERS 10

// define a global array to store the user accounts
int user_accounts[MAX_USERS];

// create a mutex object to protect the user_accounts array
pthread_mutex_t mutex;

// function to add or subtract from a user's account balance
void* update_balance(void* arg) {
  int user_id = *(int*)arg;
  int balance = rand() % 1000;
  int choice = rand() % 2;

  // acquire the mutex lock to protect the user_accounts array
  pthread_mutex_lock(&mutex);

  // update the user's account balance
  if (choice == 0) {
    // subtract balance
    user_accounts[user_id] -= balance;
    printf("User #%d withdrew $%d from account\n", user_id, balance);
  } else {
    // add balance
    user_accounts[user_id] += balance;
    printf("User #%d deposited $%d into account\n", user_id, balance);
  }

  // release the mutex lock
  pthread_mutex_unlock(&mutex);

  pthread_exit(NULL);
}

int main() {
  // initialize the user_accounts array
  memset(user_accounts, 0, sizeof(user_accounts));

  // initialize the mutex
  pthread_mutex_init(&mutex, NULL);

  // create an array to store the thread IDs
  pthread_t threads[NUM_THREADS];

  // create an array to store the user IDs
  int user_ids[MAX_USERS];

  // create the threads
  for (int i = 0; i < NUM_THREADS; i++) {
    int user_id = rand() % MAX_USERS;
    user_ids[i] = user_id;
    pthread_create(&threads[i], NULL, update_balance, &user_ids[i]);
  }

  // join the threads
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // print the final balances for each user
  for (int i = 0; i < MAX_USERS; i++) {
    printf("User #%d: $%d\n", i, user_accounts[i]);
  }

  // destroy the mutex
  pthread_mutex_destroy(&mutex);

  return 0;
}