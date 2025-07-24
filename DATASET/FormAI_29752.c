//FormAI DATASET v1.0 Category: Banking Record System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILENAME "bank_transactions.txt"
#define MAX_NAME_LENGTH 50
#define MAX_TRANSACTION_LENGTH 100

void record_transaction(char *name, float amount, char *type)
{
    FILE *fp;
    struct tm *tm_info;
    char timestamp[26];
    char transaction[MAX_TRANSACTION_LENGTH];
    
    time_t timer;
    time(&timer);
    tm_info = localtime(&timer);
    strftime(timestamp, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    
    snprintf(transaction, MAX_TRANSACTION_LENGTH, "[%s] %s $%.2f %s\n", timestamp, name, amount, type);
    
    fp = fopen(FILENAME, "a");
    if (fp == NULL) {
        printf("Error: could not open file for writing.\n");
    }
    fputs(transaction, fp);
    fclose(fp);
}

int main() 
{
    char name[MAX_NAME_LENGTH];
    float amount;
    char type[MAX_TRANSACTION_LENGTH];
    
    printf("Hello, Watson. Please enter a name, amount, and transaction type:\n");
    scanf("%s %f %s", name, &amount, type);
    
    record_transaction(name, amount, type);
    
    printf("Thank you, Watson. The transaction has been recorded.\n");
    return 0;
}