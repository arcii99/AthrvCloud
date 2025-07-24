//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Structure for storing financial information of a person
struct FinancialInformation {
    float income;
    float expenses;
    float savings;
}; 

typedef struct FinancialInformation finInfo;

int main() {
    printf("Welcome to your Personal Finance Planner!\n\n");

    // Initializing a default financial information structure
    finInfo info = {0, 0, 0};

    // Function to get user input for financial information
    void getFinancialInfo(finInfo *info) {
        printf("Enter your monthly income: ");
        scanf("%f", &info->income);
        
        printf("Enter your monthly expenses: ");
        scanf("%f", &info->expenses);
        
        info->savings = info->income - info->expenses;

        printf("\nYour monthly savings: %.2f\n\n", info->savings);
    }

    // Function to display financial information
    void displayFinancialInfo(finInfo info) {
        printf("Your monthly income: %.2f\n", info.income);
        printf("Your monthly expenses: %.2f\n", info.expenses);
        printf("Your monthly savings: %.2f\n\n", info.savings);
    }

    // Function to save financial information to a file
    void saveFinancialInfoToFile(finInfo info) {
        FILE *fp;
        char fname[20];
        
        printf("Enter the name of the file to save your financial information: ");
        scanf("%s", fname);

        fp = fopen(fname, "w");

        if(fp == NULL) {
            printf("Error: Could not create file.\n");
            return;
        }

        fprintf(fp, "Monthly Income: %.2f\n", info.income);
        fprintf(fp, "Monthly Expenses: %.2f\n", info.expenses);
        fprintf(fp, "Monthly Savings: %.2f\n", info.savings);

        fclose(fp);

        printf("Your financial information has been saved to the file %s.\n\n", fname);
    }

    // Function to load financial information from a file
    void loadFinancialInfoFromFile(finInfo *info) {
        FILE *fp;
        char fname[20];
        char line[100];

        printf("Enter the name of the file to load your financial information: ");
        scanf("%s", fname);

        fp = fopen(fname, "r");

        if(fp == NULL) {
            printf("Error: Could not open file.\n");
            return;
        }

        while(fgets(line, sizeof(line), fp)) {
            if(line[strlen(line) - 1] == '\n') {
                line[strlen(line) - 1] = '\0';
            }

            if(sscanf(line, "Monthly Income: %f", &info->income) == 1) {
                continue;
            }

            if(sscanf(line, "Monthly Expenses: %f", &info->expenses) == 1) {
                continue;
            }

            if(sscanf(line, "Monthly Savings: %f", &info->savings) == 1) {
                continue;
            }
        }

        fclose(fp);

        printf("Your financial information has been loaded from the file %s.\n\n", fname);
    }

    // Display menu options to the user
    int userChoice = 0;
    
    while(userChoice != 5) {
        printf("Please select from the following options:\n\n");
        printf("1. Enter Financial Information\n");
        printf("2. Display Financial Information\n");
        printf("3. Save Financial Information\n");
        printf("4. Load Financial Information\n");
        printf("5. Exit\n\n");

        printf("Your choice: ");
        scanf("%d", &userChoice);
        
        switch(userChoice) {
            case 1:
                getFinancialInfo(&info);
                break;
            
            case 2:
                displayFinancialInfo(info);
                break;
            
            case 3:
                saveFinancialInfoToFile(info);
                break;
            
            case 4:
                loadFinancialInfoFromFile(&info);
                break;
            
            case 5:
                printf("Thank you for using your Personal Finance Planner.\n\n");
                break;
            
            default:
                printf("Invalid option, please try again.\n\n");
                break;
        }
    }

    return 0;
}