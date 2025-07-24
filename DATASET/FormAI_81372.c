//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct expense {
    char date[15];
    char category[15];
    float amount;
};

int main() {

    struct expense exp[MAX];
    int n, i;
    float total = 0;

    printf("Enter the number of expenses: ");
    scanf("%d", &n);

    for(i=0;i<n;i++) {
        printf("Enter the details for expense %d:\n", i+1);
        printf("Date (mm/dd/yyyy): ");
        scanf("%s", &exp[i].date);
        printf("Category: ");
        scanf("%s", &exp[i].category);
        printf("Amount (USD): ");
        scanf("%f", &exp[i].amount);
        total += exp[i].amount;
    }

    printf("\nExpenses:\n");
    for(i=0;i<n;i++) {
        printf("%s  %s  %.2f USD\n", exp[i].date, exp[i].category, exp[i].amount);
    }

    printf("\nTotal Expenses: %.2f USD\n", total);

    return 0;
}