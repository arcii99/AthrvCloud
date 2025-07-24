//FormAI DATASET v1.0 Category: Expense Tracker ; Style: inquisitive
#include <stdio.h>

// Function to calculate total expenses
float calculateTotal(float expenses[], int size) {
    float total = 0.0;
    for(int i = 0; i < size; i++) {
        total += expenses[i];
    }
    return total;
}

int main() {
    float dailyExpenses[7];
    char days[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int i; 

    // Prompt user to input daily expenses for the week
    for(i = 0; i < 7; i++) {
        printf("Enter expenses on %s: ", days[i]);
        scanf("%f", &dailyExpenses[i]);
    }
    
    // Calculate total expenses for the week
    float totalExpenses = calculateTotal(dailyExpenses, 7);
    
    // Generate report
    printf("\n=========================================\n");
    printf("\t\t Report\n");
    printf("=========================================\n");
    printf("Day\t\tExpenses\n");
    printf("=========================================\n");
    for(i = 0; i < 7; i++) {
        printf("%s\t\t$%.2f\n", days[i], dailyExpenses[i]); 
    }
    printf("=========================================\n");
    printf("Total expenses\t$%.2f\n", totalExpenses);
}