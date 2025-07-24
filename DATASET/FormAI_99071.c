//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: shape shifting
#include <stdio.h>

int main() {
    int choice;
    
    while(choice != 4) {
        printf("\nWelcome to the Personal Finance Planner!\n");
        printf("1. Enter income\n");
        printf("2. Enter expenses\n");
        printf("3. View current balance\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter income amount: ");
                float income;
                scanf("%f", &income);
                printf("Income added successfully!\n");
                break;
                
            case 2:
                printf("\nEnter expense amount: ");
                float expense;
                scanf("%f", &expense);
                if(expense > income) {
                    printf("Error: Expense amount exceeds income. Please enter a valid amount.\n");
                }
                else {
                    printf("Expense added successfully!\n");
                }
                break;
                
            case 3:
                printf("\nCurrent balance: $%.2f\n", income - expense);
                break;
                
            case 4:
                printf("\nThank you for using the Personal Finance Planner!\n");
                break;
                
            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
        }
    }
    
    return 0;
}