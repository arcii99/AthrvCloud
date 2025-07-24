//FormAI DATASET v1.0 Category: Expense Tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESCRIPTION_LEN 100
#define MAX_EXPENSES 100

struct expense {
    float amount;
    char description[MAX_DESCRIPTION_LEN];
    char date[20];
};

struct expense_list {
    struct expense expenses[MAX_EXPENSES];
    int count;
};

struct expense_list list;

int main() {
    // Code goes here
    return 0;
}