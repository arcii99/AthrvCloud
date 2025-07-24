//FormAI DATASET v1.0 Category: Expense Tracker ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char choice[10];
    float expense, totalExpense = 0;
    FILE *filePointer;
    filePointer = fopen("expenseTracker.txt", "w");

    if(filePointer == NULL) {
        printf("File does not exist!");
        exit(0);
    }

    printf("\n\n Welcome to the Post-Apocalyptic Expense Tracker!\n\n\n");

    while(1) {
        printf("Choose an option: \n\n");
        printf("1. Add Expense\n2. Get Total Expense\n3. Exit\n\n");
        scanf("%s", choice);

        if(strcmp(choice, "1") == 0) {
            printf("\n\n Enter the amount: ");
            scanf("%f", &expense);

            totalExpense += expense;

            fprintf(filePointer, "Expense of %.2f rupees added to the tracker.\n", expense);
        }
        else if(strcmp(choice, "2") == 0) {
            printf("\n\n Your total expense is %.2f rupees.\n\n", totalExpense);
        }
        else if(strcmp(choice, "3") == 0) {
            printf("\n\nThank you for using the Post-Apocalyptic Expense Tracker. Goodbye!\n\n");
            break;
        }
        else {
            printf("\n\nInvalid choice. Please choose again.\n\n");
        }
    }

    fclose(filePointer);
    return 0;
}