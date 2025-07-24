//FormAI DATASET v1.0 Category: Banking Record System ; Style: medieval
#include <stdio.h>
#include <string.h>

// Structure to store account record
struct account {
    char name[20];
    int account_number;
    double balance;
    int pin;
};

// Function to encrypt account PIN
int encrypt_pin(int pin) {
    int encrypted_pin = 0;
    while (pin > 0) {
        int digit = pin % 10;
        encrypted_pin = encrypted_pin * 10 + (digit + 7) % 10;
        pin /= 10;
    }
    return encrypted_pin;
}

// Function to decrypt account PIN
int decrypt_pin(int encrypted_pin) {
    int pin = 0;
    while (encrypted_pin > 0) {
        int digit = encrypted_pin % 10;
        pin = pin * 10 + (digit + 3) % 10;
        encrypted_pin /= 10;
    }
    return pin;
}

// Function to display account record
void display_account(struct account acc) {
    printf("Name: %s\n", acc.name);
    printf("Account Number: %d\n", acc.account_number);
    printf("Balance: %0.2f\n", acc.balance);
}

int main() {
    // Initialize account records
    struct account records[10];
    strcpy(records[0].name, "Sir Lancelot");
    records[0].account_number = 1001;
    records[0].balance = 5000.0;
    records[0].pin = encrypt_pin(1234);

    strcpy(records[1].name, "Sir Galahad");
    records[1].account_number = 1002;
    records[1].balance = 2500.0;
    records[1].pin = encrypt_pin(5678);

    // Display menu options
    printf("Welcome to Ye Olde Bank of Camelot!\n");
    printf("1. Display account record\n");
    printf("2. Deposit gold coins\n");
    printf("3. Withdraw gold coins\n");
    printf("4. Exit\n");

    // Get user input
    int choice, acc_num, amount, pin;
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Display account record
            printf("Enter account number: ");
            scanf("%d", &acc_num);
            printf("Enter PIN: ");
            scanf("%d", &pin);

            // Find account record with matching account number
            for (int i = 0; i < 10; i++) {
                if (records[i].account_number == acc_num) {
                    // Decrypt and verify PIN
                    int decrypted_pin = decrypt_pin(records[i].pin);
                    if (pin == decrypted_pin) {
                        // Display account record
                        display_account(records[i]);
                        break;
                    } else {
                        printf("Invalid PIN\n");
                        break;
                    }
                }
            }
            break;

        case 2:
            // Deposit gold coins
            printf("Enter account number: ");
            scanf("%d", &acc_num);
            printf("Enter PIN: ");
            scanf("%d", &pin);

            // Find account record with matching account number
            for (int i = 0; i < 10; i++) {
                if (records[i].account_number == acc_num) {
                    // Decrypt and verify PIN
                    int decrypted_pin = decrypt_pin(records[i].pin);
                    if (pin == decrypted_pin) {
                        // Get deposit amount and update balance
                        printf("Enter deposit amount: ");
                        scanf("%d", &amount);
                        records[i].balance += amount;
                        printf("New balance: %0.2f\n", records[i].balance);
                        break;
                    } else {
                        printf("Invalid PIN\n");
                        break;
                    }
                }
            }
            break;

        case 3:
            // Withdraw gold coins
            printf("Enter account number: ");
            scanf("%d", &acc_num);
            printf("Enter PIN: ");
            scanf("%d", &pin);

            // Find account record with matching account number
            for (int i = 0; i < 10; i++) {
                if (records[i].account_number == acc_num) {
                    // Decrypt and verify PIN
                    int decrypted_pin = decrypt_pin(records[i].pin);
                    if (pin == decrypted_pin) {
                        // Get withdrawal amount and update balance
                        printf("Enter withdrawal amount: ");
                        scanf("%d", &amount);
                        if (amount > records[i].balance) {
                            printf("Insufficient balance\n");
                            break;
                        }
                        records[i].balance -= amount;
                        printf("New balance: %0.2f\n", records[i].balance);
                        break;
                    } else {
                        printf("Invalid PIN\n");
                        break;
                    }
                }
            }
            break;

        case 4:
            // Exit program
            printf("Goodbye!\n");
            break;

        default:
            // Invalid option
            printf("Invalid choice\n");
            break;
    }

    return 0;
}