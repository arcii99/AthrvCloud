//FormAI DATASET v1.0 Category: Expense Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char date[11], category[20], description[50];
    float amount;
    FILE *fp;

    fp = fopen("expenses.txt", "a"); // open file in append mode

    if (fp == NULL) {
        printf("Error in opening file\n");
        exit(1);
    }

    // get user inputs for expense details
    printf("Enter date(dd/mm/yyyy): ");
    scanf("%s", date);
    printf("Enter category: ");
    scanf("%s", category);
    printf("Enter description: ");
    scanf("%s", description);
    printf("Enter amount: ");
    scanf("%f", &amount);

    // write data to file
    fprintf(fp, "%s, %s, %s, %f\n", date, category, description, amount);

    // close file
    fclose(fp);

    printf("Expense saved successfully!\n");

    return 0;
}