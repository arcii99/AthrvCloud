//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: portable
#include <stdio.h>

int main() {
    float income, expense, savings, totalSavings = 0;
    char choice;
    
    do {
        printf("Enter your monthly income: $");
        scanf("%f", &income);
        
        printf("Enter your monthly expenses: $");
        scanf("%f", &expense);
        
        savings = income - expense;
        totalSavings += savings;
        
        printf("Your monthly savings: $%.2f\n", savings);
        printf("Total savings so far: $%.2f\n", totalSavings);
        
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    
    printf("Goodbye!");
    
    return 0;
}