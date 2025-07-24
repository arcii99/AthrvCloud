//FormAI DATASET v1.0 Category: Data mining ; Style: Sherlock Holmes
//The Adventure of the Stolen Money

/*
In this C program, we will be mining through a large dataset of bank transactions to find patterns
that might indicate a theft. The data is in the form of a linked list, and we will be using various
data manipulation techniques to sort and analyze the data.

Written by: Sherlock Holmes
Date: October 15, 1890
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a structure to hold individual transaction data
typedef struct Transaction {
  int amount;
  char* type;
  char* location;
  struct Transaction* next;
} Transaction;

// function to add a new transaction to the linked list
void AddTransaction(Transaction** head, int amount, char* type, char* location) {
  Transaction* newTransaction = (Transaction*)malloc(sizeof(Transaction));
  newTransaction->amount = amount;
  newTransaction->type = type;
  newTransaction->location = location;
  newTransaction->next = NULL;

  // add new transaction to end of list
  Transaction* current = *head;
  if (*head == NULL) {
    *head = newTransaction;
  } else {
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newTransaction;
  }
}

// function to print out all transactions
void PrintTransactions(Transaction* head) {
  Transaction* current = head;
  while (current != NULL) {
    printf("Type: %s, Amount: %d, Location: %s\n", current->type, current->amount, current->location);
    current = current->next;
  }
}

// function to sort transactions by amount (ascending)
void SortTransactions(Transaction** head) {
  Transaction* current = *head;
  Transaction* index = NULL;
  int tempAmount;
  char* tempType;
  char* tempLocation;

  while (current != NULL) {
    index = current->next;
    while (index != NULL) {
      if (current->amount > index->amount) {
        // swap
        tempAmount = current->amount;
        tempType = current->type;
        tempLocation = current->location;
        current->amount = index->amount;
        current->type = index->type;
        current->location = index->location;
        index->amount = tempAmount;
        index->type = tempType;
        index->location = tempLocation;
      }
      index = index->next;
    }
    current = current->next;
  }
}

// function to find a transaction by amount
Transaction* FindTransaction(Transaction* head, int amount) {
  Transaction* current = head;
  while (current != NULL) {
    if (current->amount == amount) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

int main() {
  printf("Welcome to the data mining program.\n");

  // create linked list of transactions
  Transaction* transactions = NULL;

  AddTransaction(&transactions, 50, "Withdrawal", "Bank of London");
  AddTransaction(&transactions, 100, "Deposit", "Bank of London");
  AddTransaction(&transactions, 25, "Withdrawal", "Bank of Liverpool");
  AddTransaction(&transactions, 150, "Deposit", "Bank of Liverpool");
  AddTransaction(&transactions, 75, "Withdrawal", "Bank of Manchester");
  AddTransaction(&transactions, 200, "Deposit", "Bank of Manchester");
  AddTransaction(&transactions, 500, "Withdrawal", "Bank of Nottingham");
  AddTransaction(&transactions, 300, "Deposit", "Bank of Nottingham");

  printf("Initial transactions:\n");
  PrintTransactions(transactions);

  // sort transactions
  SortTransactions(&transactions);

  printf("\nSorted transactions:\n");
  PrintTransactions(transactions);

  // find a transaction with a specific amount
  int amountToFind = 75;
  Transaction* foundTransaction = FindTransaction(transactions, amountToFind);
  if (foundTransaction != NULL) {
    printf("\nFound transaction with amount %d:\n", amountToFind);
    printf("Type: %s, Amount: %d, Location: %s\n", foundTransaction->type, foundTransaction->amount, foundTransaction->location);
  } else {
    printf("\nNo transaction found with amount %d.\n", amountToFind);
  }

  // free memory
  Transaction* current = transactions;
  while (current != NULL) {
    Transaction* next = current->next;
    free(current);
    current = next;
  }

  printf("Program complete. Goodbye.\n");

  return 0;
}