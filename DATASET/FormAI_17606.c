//FormAI DATASET v1.0 Category: Data mining ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Transaction {
    int id;
    char date[12];
    float amount;
    char category[20];
};

int main() {
    int num_transactions;
    printf("Enter the number of transactions: ");
    scanf("%d", &num_transactions);

    struct Transaction transactions[num_transactions];

    // Input transactions
    printf("Enter transaction details (id, date, amount, category):\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%d. ", i+1);
        scanf("%d %s %f %s", &transactions[i].id, transactions[i].date, &transactions[i].amount, transactions[i].category);
    }

    // Sort transactions by date using bubble sort
    for (int i = 0; i < num_transactions-1; i++) {
        for (int j = 0; j < num_transactions-i-1; j++) {
            if (strcmp(transactions[j].date, transactions[j+1].date) > 0) {
                struct Transaction temp = transactions[j];
                transactions[j] = transactions[j+1];
                transactions[j+1] = temp;
            }
        }
    }

    // Output transactions
    printf("Transactions sorted by date:\n");
    printf("ID\tDate\t\tAmount\t\tCategory\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%d\t%s\t%.2f\t%s\n", transactions[i].id, transactions[i].date, transactions[i].amount, transactions[i].category);
    }
    
    return 0;
}