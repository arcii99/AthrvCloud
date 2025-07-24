//FormAI DATASET v1.0 Category: Expense Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DESCRIPTION_LENGTH 50
#define MAX_CATEGORY_LENGTH 20
#define MAX_ENTRIES 100

struct ExpenseEntry {
    char description[MAX_DESCRIPTION_LENGTH + 1];
    char category[MAX_CATEGORY_LENGTH + 1];
    float amount;
};

int validateFloatInput(char input[]) {
    // Utility function to check if user input is a valid float
    int len = strlen(input);
    int decimal_count = 0;
    for (int i = 0; i < len; i++) {
        if (!isdigit(input[i])) {
            if (input[i] == '.') {
                decimal_count++;
                if (decimal_count > 1) {
                    return 0;
                }
            } else {
                return 0;
            }
        }
    }
    return 1;
}

int validateCategoryInput(char input[]) {
    // Utility function to check if user input is a valid category
    int len = strlen(input);
    if (len > MAX_CATEGORY_LENGTH) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isalpha(input[i]) && !isspace(input[i])) {
            return 0;
        }
    }
    return 1;
}

int validateDescriptionInput(char input[]) {
    // Utility function to check if user input is a valid description
    int len = strlen(input);
    if (len > MAX_DESCRIPTION_LENGTH) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isalpha(input[i]) && !isspace(input[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    struct ExpenseEntry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (1) {
        printf("Select an option:\n");
        printf("1. Add new expense entry\n");
        printf("2. View all expense entries\n");
        printf("3. Quit\n");

        char input[10];
        fgets(input, 10, stdin);

        if (strcmp(input, "1\n") == 0) {
            printf("Enter description (max %d characters): ", MAX_DESCRIPTION_LENGTH);
            char description[MAX_DESCRIPTION_LENGTH + 1];
            fgets(description, MAX_DESCRIPTION_LENGTH + 1, stdin);
            if (validateDescriptionInput(description)) {
                printf("Enter category (max %d characters): ", MAX_CATEGORY_LENGTH);
                char category[MAX_CATEGORY_LENGTH + 1];
                fgets(category, MAX_CATEGORY_LENGTH + 1, stdin);
                if (validateCategoryInput(category)) {
                    printf("Enter amount: ");
                    char amount_str[20];
                    fgets(amount_str, 20, stdin);
                    if (validateFloatInput(amount_str)) {
                        float amount = strtof(amount_str, NULL);
                        struct ExpenseEntry entry = {
                            .amount = amount
                        };
                        strncpy(entry.description, description, MAX_DESCRIPTION_LENGTH);
                        strncpy(entry.category, category, MAX_CATEGORY_LENGTH);
                        entries[num_entries++] = entry;
                        printf("Entry added successfully.\n");
                    } else {
                        printf("Invalid amount. Please enter a valid decimal number.\n");
                    }
                } else {
                    printf("Invalid category name. Please use only alphabets and spaces.\n");
                }
            } else {
                printf("Invalid description. Please use only alphabets and spaces.\n");
            }

        } else if (strcmp(input, "2\n") == 0) {
            if (num_entries == 0) {
                printf("No entries added yet.\n");
            } else {
                float total = 0.0;
                printf("%-4s %-20s %-20s %s\n", "S.No", "Description", "Category", "Amount");
                printf("---  -------------------- -------------------- -------\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("%-4d %-20s %-20s %.2f\n", i+1, entries[i].description, entries[i].category, entries[i].amount);
                    total += entries[i].amount;
                }
                printf("\nTotal amount spent: %.2f\n", total);
            }

        } else if (strcmp(input, "3\n") == 0) {
            printf("Closing the program...\n");
            break;

        } else {
            printf("Invalid input. Please enter a valid option.\n");
        }
    }

    return 0;
}