//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

int main() {
    float principal, rate, time, emi, total_amount, interest;
    int choice;

    printf("\n                      .                 ");
    printf("\n               .                    ");
    printf("\n                         ____...-----\\   _...-----.");
    printf("\n                        /      \"--..__ \"\"             `~-. ");
    printf("\n                       /             \"\"\"\"\"\"\"\"\"\"\"\"--.._    `.");
    printf("\n                      /                                    `\\ ");
    printf("\n                    .\'                                        ``.");
    printf("\n                 _.\'                                     ..-\"\'");
    printf("\n      _..-\"\"--. .'                               .-\"\"-\\__");
    printf("\n \\__          `.                               `.     |`.`.");
    printf("\n    \\\"\"--..__   \\                                |     |  \\\\");
    printf("\n            `\"\"-\\--                          .    \\    |  | \\\\");
    printf("\n                  \\           |            / `\"-._\\__ \'__|  |__");
    printf("\n                   `\"-\\__     |`.__      /       /\"\"\"`\"\"`\"\"\"\\");
    printf("\n                         \\\"\"--\\--\\ `\"-._/       /      .-\'\\ ");
    printf("\n                              `\"\"-\\__      .-\"/      /   |");
    printf("\n                                    `\"\`\"---\'_.-\'/    .\'\_/");
    printf("\n                                       \\=====\\__|__/");
    printf("\n                                        `\"\"\"\"\"\"\"\"\"|\"                Welcome to Cyber Mortgage Calculator!");
    printf("\n                                                                  ");
    printf("\n");

    printf("Enter the principal amount: ");
    scanf("%f", &principal);

    printf("Enter the interest rate per annum: ");
    scanf("%f", &rate);

    printf("Enter the time duration (in years): ");
    scanf("%f", &time);

    rate = rate / (12 * 100);
    time = time * 12;

    emi = (principal * rate * pow(1 + rate, time)) / (pow(1 + rate, time) - 1);
    total_amount = emi * time;
    interest = total_amount - principal;

    printf("\n   __    __                           __                           __             \n");
    printf("  / /_  / /_ ____ _ ____ ___   ____  / /_ ____   _____      ______ / /_ ___   _____\n");
    printf(" / __ \\/ __ `__ `// __ `__ \\ / __ \\/ __// __ \\ / ___/ | /| / / __ `__ \\ / ___/\n");
    printf("/ / / / / / / / // / / / / // /_/ / /_ / /_/ // /___  | |/ |/ / / / / / /(__  ) \n");
    printf("\\__/ /_/ /_/\\_,_//_/ /_/ /_/ \\____/\\__/ \\____/ \\___/  |__/|__/_/ /_/ /_//____/  \n\n");

    printf("Choose the output format:\n");
    printf("1. Monthly Installments (EMI)\n");
    printf("2. Total Amount Payable\n");
    printf("3. Total Interest Payable\n");
    printf("4. All of the above\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: 
            printf("\nYour monthly installments (EMI) are: $%.2f\n", emi);
            break;
        case 2:
            printf("\nYour total amount payable is: $%.2f\n", total_amount);
            break;
        case 3:
            printf("\nYour total interest payable is: $%.2f\n", interest);
            break;
        case 4:
            printf("\nYour monthly installments (EMI) are: $%.2f\n", emi);
            printf("Your total amount payable is: $%.2f\n", total_amount);
            printf("Your total interest payable is: $%.2f\n", interest);
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
    }

    return 0;
}