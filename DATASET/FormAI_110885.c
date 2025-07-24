//FormAI DATASET v1.0 Category: Banking Record System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    char name[30];
    int account_num;
    float balance;
};

int main() {
    int input_choice, num_of_customers = 0, i = 0, j = 0;
    struct customer customers[10];
    
    // Initializing the customer array with placeholder information
    for (i = 0; i < 10; i++) {
        strcpy(customers[i].name, "None");
        customers[i].account_num = 0;
        customers[i].balance = 0;
    }
    
    while(1) {
        printf("\n----------------------------\n");
        printf("Welcome to the Apocalypse Bank\n");
        printf("Choose an option:\n");
        printf("1. Create a new account\n");
        printf("2. Make a deposit\n");
        printf("3. Make a withdrawal\n");
        printf("4. Account information\n");
        printf("5. Exit\n");
        printf("----------------------------\n");
        
        scanf("%d", &input_choice);
        printf("\n");

        switch(input_choice) {
            case 1:
                // Creating a new account
                printf("Enter your name: ");
                scanf("%s", customers[num_of_customers].name);
                customers[num_of_customers].account_num = num_of_customers + 100;
                printf("Your account number is: %d\n", customers[num_of_customers].account_num);
                num_of_customers++;
                break;
            case 2:
                // Making a deposit
                printf("Enter your account number: ");
                scanf("%d", &input_choice);

                for (i = 0; i < num_of_customers; i++) {
                    if (customers[i].account_num == input_choice) {
                        printf("Enter the amount you would like to deposit: ");
                        float deposit_amount;
                        scanf("%f", &deposit_amount);
                        customers[i].balance += deposit_amount;

                        printf("Your new balance is: $%.2f\n", customers[i].balance);
                        break;
                    }
                }

                if (i >= num_of_customers) {
                    printf("Invalid account number.\n");
                }

                break;
            case 3:
                // Making a withdrawal
                printf("Enter your account number: ");
                scanf("%d", &input_choice);
                
                for (i = 0; i < num_of_customers; i++) {
                    if (customers[i].account_num == input_choice) {
                        printf("Enter the amount you would like to withdraw: ");
                        float withdrawal_amount;
                        scanf("%f", &withdrawal_amount);
                        
                        if (customers[i].balance >= withdrawal_amount) {
                            customers[i].balance -= withdrawal_amount;
                            printf("Your new balance is: $%.2f\n", customers[i].balance);
                        } else {
                            printf("Insufficient funds to make withdrawal.\n");
                        }

                        break;
                    }
                }

                if (i >= num_of_customers) {
                    printf("Invalid account number.\n");
                }

                break;
            case 4:
                // Account information
                printf("Enter your account number: ");
                scanf("%d", &input_choice);

                for (i = 0; i < num_of_customers; i++) {
                    if (customers[i].account_num == input_choice) {
                        printf("Name: %s\n", customers[i].name);
                        printf("Account Number: %d\n", customers[i].account_num);
                        printf("Balance: $%.2f\n", customers[i].balance);
                        break;
                    }
                }

                if (i >= num_of_customers) {
                    printf("Invalid account number.\n");
                }

                break;
            case 5:
                // Exit program
                printf("Exiting program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}