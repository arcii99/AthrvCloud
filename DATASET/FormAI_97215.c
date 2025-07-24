//FormAI DATASET v1.0 Category: Expense Tracker ; Style: intelligent
#include <stdio.h>
#include <string.h>

struct expense {
    char name[50];
    float price;
};

int main() {
    int n;
    float total = 0;
    printf("How many expenses to track?\n");
    scanf("%d", &n);
    struct expense expenses[n];
    for(int i = 0; i < n; i++) {
        printf("Enter expense #%d name: ", i+1);
        scanf("%s", expenses[i].name);
        printf("Enter expense #%d price: ", i+1);
        scanf("%f", &expenses[i].price);
        total += expenses[i].price;
    }
    printf("\nExpense Tracker\n");
    printf("----------------\n");
    for(int i = 0; i < n; i++) {
        printf("%d. %s: $%.2f\n", i+1, expenses[i].name, expenses[i].price);
    }
    printf("----------------\n");
    printf("Total: $%.2f\n", total);
    return 0;
}