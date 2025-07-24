//FormAI DATASET v1.0 Category: Expense Tracker ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct expense {
    char item[20];
    float cost;
};

void add_expense(struct expense expenses[], int *count) {
    printf("Enter item: ");
    scanf("%s", expenses[*count].item);
    printf("Enter cost: ");
    scanf("%f", &expenses[*count].cost);
    *count += 1;
    printf("Expense added.\n");
}

void display_expense(struct expense expenses[], int count) {
    if(count == 0) {
        printf("No expenses to display.\n");
        return;
    }
    printf("Expenses:\n");
    for(int i = 0; i < count; i++) {
        printf("%s - %.2f\n", expenses[i].item, expenses[i].cost);
    }
}

int main() {
    struct expense expenses[100];
    int count = 0;
    int choice;
    do{
        printf("\nMENU\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: add_expense(expenses, &count);
                    break;
            case 2: display_expense(expenses, count);
                    break;
            case 3: printf("Exiting program.\n");
                    exit(0);
            default: printf("Invalid choice.\n");
        }
    }while(1);
    return 0;
}