//FormAI DATASET v1.0 Category: Expense Tracker ; Style: distributed
//This is an example program for an Expense Tracker in C, implemented using a distributed architecture.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_USERS 50
#define MAX_EXPENSES 100

//Global variables
int num_users = 0;
int num_expenses = 0;

//Data structures
typedef struct {
  char name[20]; //Username
  float budget; //Amount of money allocated for expenses
  float balance; //The remaining balance after expenses
} User;

typedef struct {
  char description[50]; //Description of expense
  float cost; //Amount of the expense
  char user[20]; //Username of the user who made the expense
} Expense;

User users[MAX_USERS];
Expense expenses[MAX_EXPENSES];
pthread_mutex_t user_mutex[MAX_USERS]; //Locks for each user to prevent concurrent modification
pthread_mutex_t expense_mutex; //Lock for the expenses array to prevent concurrent modification

//Function to add a new User
void add_new_user(char username[], float budget) {
  if(num_users < MAX_USERS) {
    strcpy(users[num_users].name, username);
    users[num_users].budget = budget;
    users[num_users].balance = budget;
    num_users++;
    printf("User %s added successfully\n", username);
  }
}

//Function to add a new Expense
void add_new_expense(char description[], float cost, char username[]) {
  int user_index = -1;
  for(int i = 0; i < num_users; i++) {
    if(strcmp(users[i].name, username) == 0) {
      user_index = i;
      break;
    }
  }

  if(user_index == -1) {
    printf("No user found with name %s\n", username);
    return;
  }

  if(cost > users[user_index].balance) {
    printf("Expense cost exceeds available balance for user %s\n", username);
    return;
  }

  pthread_mutex_lock(&user_mutex[user_index]); //Acquire lock before modifying user balance

  pthread_mutex_lock(&expense_mutex); //Acquire lock before modifying expenses array

  strcpy(expenses[num_expenses].description, description);
  expenses[num_expenses].cost = cost;
  strcpy(expenses[num_expenses].user, username);
  num_expenses++;

  users[user_index].balance -= cost;

  printf("Expense added successfully\n");

  pthread_mutex_unlock(&expense_mutex); //Release lock after modifying expenses array

  pthread_mutex_unlock(&user_mutex[user_index]); //Release lock after modifying user balance
}

//Function to get the total expenses made by a user
float get_user_expenses(char username[]) {
  float total_expenses = 0;
  for(int i = 0; i < num_expenses; i++) {
    if(strcmp(expenses[i].user, username) == 0) {
      total_expenses += expenses[i].cost;
    }
  }
  return total_expenses;
}

//Function to get the remaining balance of a user
float get_user_balance(char username[]) {
  int user_index = -1;
  for(int i = 0; i < num_users; i++) {
    if(strcmp(users[i].name, username) == 0) {
      user_index = i;
      break;
    }
  }
  if(user_index == -1) {
    printf("No user found with name %s\n", username);
    return -1;
  }
  return users[user_index].balance;
}

//Thread function to print all the expenses made by a user
void* print_user_expenses(void* arg) {
  char* username = (char*)arg;
  printf("Expenses made by user %s:\n", username);
  for(int i = 0; i < num_expenses; i++) {
    if(strcmp(expenses[i].user, username) == 0) {
      printf("%s - %.2f\n", expenses[i].description, expenses[i].cost);
    }
  }
  pthread_exit(NULL);
}

//Main function
int main() {
  //Initialize user locks
  for(int i = 0; i < MAX_USERS; i++) {
    pthread_mutex_init(&user_mutex[i], NULL);
  }

  //Initialize expense lock
  pthread_mutex_init(&expense_mutex, NULL);

  //Add some sample users
  add_new_user("John", 100);
  add_new_user("Mary", 200);
  add_new_user("Bob", 50);

  //Make some sample expenses
  add_new_expense("Lunch", 10, "John");
  add_new_expense("Dinner", 20, "Mary");
  add_new_expense("Coffee", 5, "Bob");
  add_new_expense("Snacks", 2.5, "John");

  //Print the total expenses made by each user
  printf("Total expenses made by each user:\n");
  for(int i = 0; i < num_users; i++) {
    printf("%s - %.2f\n", users[i].name, get_user_expenses(users[i].name));
  }

  //Print the remaining balance of each user
  printf("Remaining balance of each user:\n");
  for(int i = 0; i < num_users; i++) {
    printf("%s - %.2f\n", users[i].name, get_user_balance(users[i].name));
  }

  //Create threads to print the expenses made by each user
  pthread_t threads[num_users];
  for(int i = 0; i < num_users; i++) {
    pthread_create(&threads[i], NULL, print_user_expenses, (void*)users[i].name);
  }

  //Wait for all threads to finish
  for(int i = 0; i < num_users; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}