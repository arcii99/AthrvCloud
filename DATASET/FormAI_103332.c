//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Cyberpunk
// Cyberpunk Expense Tracker

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float amount;
    char category[20];
} expense;

int main() {
    int num_expenses = 0;
    expense expenses[100];
    char choice;
    
    // Load previous expenses from file
    FILE *file = fopen("expenses.dat", "rb");
    if (file != NULL) {
        fread(&num_expenses, sizeof(int), 1, file);
        fread(expenses, sizeof(expense), num_expenses, file);
        fclose(file);
    }
    
    while (1) {
        // Display menu options
        printf("\nCYBERPUNK EXPENSE TRACKER\n\n");
        printf("1. Add a New Expense\n");
        printf("2. View All Expenses\n");
        printf("3. Search for an Expense\n");
        printf("4. Delete an Expense\n");
        printf("5. Save and Quit\n\n");
        printf("Enter your choice: ");
        
        // Get user choice
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1': // Add a new expense
                printf("\nEnter expense name: ");
                scanf("%s", expenses[num_expenses].name);
                printf("Enter expense amount: ");
                scanf("%f", &expenses[num_expenses].amount);
                printf("Enter expense category: ");
                scanf("%s", expenses[num_expenses].category);
                num_expenses++;
                break;
                
            case '2': // View all expenses
                printf("\nALL EXPENSES\n\n");
                printf("Name\t\tAmount\t\tCategory\n");
                for (int i = 0; i < num_expenses; i++) {
                    printf("%s\t\t$%.2f\t\t%s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
                }
                break;
                
            case '3': // Search for an expense
                char search_term[50];
                int found = 0;
                printf("\nEnter search term: ");
                scanf("%s", search_term);
                printf("\nSEARCH RESULTS\n\n");
                printf("Name\t\tAmount\t\tCategory\n");
                for (int i = 0; i < num_expenses; i++) {
                    if (strstr(expenses[i].name, search_term) != NULL || strstr(expenses[i].category, search_term) != NULL) {
                        printf("%s\t\t$%.2f\t\t%s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("No matching expenses.\n");
                }
                break;
                
            case '4': // Delete an expense
                int index;
                printf("\nEnter index of expense to delete: ");
                scanf("%d", &index);
                if (index >= 0 && index < num_expenses) {
                    for (int i = index; i < num_expenses - 1; i++) {
                        expenses[i] = expenses[i+1];
                    }
                    num_expenses--;
                    printf("Expense deleted.\n");
                } else {
                    printf("Invalid index.\n");
                }
                break;
                
            case '5': // Save and quit
                file = fopen("expenses.dat", "wb");
                fwrite(&num_expenses, sizeof(int), 1, file);
                fwrite(expenses, sizeof(expense), num_expenses, file);
                fclose(file);
                printf("\nExpenses saved. Goodbye.\n");
                exit(0);
                break;
                
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }
    
    return 0;
}