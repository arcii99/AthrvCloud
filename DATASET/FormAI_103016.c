//FormAI DATASET v1.0 Category: Expense Tracker ; Style: excited
#include <stdio.h> // Standard Input/Output header file
#include <stdlib.h> // Standard library header file

struct Expense {
    char title[50];
    float amount;
    int day;
    int month;
    int year;
};

int main() {
    int n, i;
    float total = 0; // Initialize total to 0
    
    printf("Enter how many expenses you want to track: ");
    scanf("%d", &n);
    
    struct Expense expenses[n]; // Create an array of Expense structs
    
    // Prompt user to input expense details
    for (i = 0; i < n; i++) {
        printf("\nEnter Title of Expense %d: ", (i+1));
        scanf("%s", expenses[i].title);
        printf("Enter Amount of Expense %d: ", (i+1));
        scanf("%f", &expenses[i].amount);
        printf("Enter Date of Expense %d (DD MM YYYY): ", (i+1));
        scanf("%d %d %d", &expenses[i].day, &expenses[i].month, &expenses[i].year);
        total += expenses[i].amount; // Add to the total amount
    }
    
    // Print all the expenses entered by the user
    printf("\n\n#----- EXPENSE TRACKER -----#\n\n");
    printf("Title\t\tAmount\tDate\n");
    printf("-----\t\t------\t----\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%.2f\t%d/%d/%d\n", expenses[i].title, expenses[i].amount, expenses[i].day, expenses[i].month, expenses[i].year);
    }
    printf("-----\t\t------\t----\n");
    printf("Total\t\t%.2f\n", total);
    
    return 0; // End of program
}