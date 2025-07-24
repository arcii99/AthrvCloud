//FormAI DATASET v1.0 Category: Expense Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    int id;
    char date[11];
    char category[20];
    char description[50];
    float amount;
};

int main() {
    FILE *fp;
    char ch;
    int count = 0;
    struct expense exp;
    fp = fopen("expense.txt", "a");
    if (fp == NULL) {
        printf("Failed to open file\n");
        exit(1);
    }
    printf("Enter date: ");
    scanf("%s", exp.date);
    printf("Enter category: ");
    scanf("%s", exp.category);
    printf("Enter description: ");
    scanf(" %[^\n]", exp.description);
    printf("Enter amount: ");
    scanf("%f", &exp.amount);
    fseek(fp, 0, SEEK_END); // Move file pointer to the end
    if (ftell(fp) == 0) { // Check if file is empty
        fprintf(fp, "ID,Date,Category,Description,Amount\n");
    }
    exp.id = ++count; // Generate unique ID for expense
    fprintf(fp, "%d,%s,%s,%s,%.2f\n", exp.id, exp.date, exp.category, exp.description, exp.amount);
    fclose(fp);
    printf("Expense added successfully!\n");
    return 0;
}