//FormAI DATASET v1.0 Category: Expense Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char name[50];
    float amount;
    char date[20];
};

typedef struct expense Expense;

int main() {
    Expense e[50];
    int i = 0, j = 0, ch = 0;
    float total_amount = 0;

    do {
        printf("\n================ EXPENSE TRACKER ================\n");
        printf("1. Add Expense\n2. View Expenses\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("\n========== ADD EXPENSE ==========\n");
                printf("Enter Expense Name: ");
                getchar();
                fgets(e[i].name, sizeof(e[i].name), stdin);
                printf("Enter Expense Amount: ");
                scanf("%f", &e[i].amount);
                getchar();
                printf("Enter Expense Date (DD/MM/YYYY): ");
                fgets(e[i].date, sizeof(e[i].date), stdin);
                total_amount += e[i].amount;
                i++;
                break;
            case 2:
                printf("\n========== VIEW EXPENSES ==========\n");
                printf("S.No.\tExpense Name\tExpense Amount\tExpense Date\n");
                for(j = 0; j < i; j++) {
                    printf("%d\t%s\t%.2f\t\t%s\n", j+1, e[j].name, e[j].amount, e[j].date);
                }
                printf("Total Expenses: %.2f\n", total_amount);
                break;
            case 3:
                printf("\n============ THANK YOU ============\n");
                exit(0);
                break;
            default:
                printf("\nPlease enter a valid choice!\n");
        }
    } while(ch != 3);

    return 0;
}