//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

struct Transaction {
    char type[20];
    float amount;
};

typedef struct Transaction Transaction;

int main() {
    int num_transactions;
    Transaction *trans;
    float total = 0;

    printf("Enter the number of transactions: ");
    scanf("%d", &num_transactions);

    trans = (Transaction*) malloc(num_transactions * sizeof(Transaction));

    // Retrieve transaction data
    for (int i = 0; i < num_transactions; i++) {
        printf("Enter transaction %d type (income/expense): ", i+1);
        scanf("%s", trans[i].type);
        printf("Enter transaction %d amount: ", i+1);
        scanf("%f", &trans[i].amount);
    }

    // Calculate and display finance summary
    printf("\nFinance Summary:\n");

    for (int i = 0; i < num_transactions; i++) {
        if (strcmp(trans[i].type, "income") == 0) {
            total += trans[i].amount;
        } else if (strcmp(trans[i].type, "expense") == 0) {
            total -= trans[i].amount;
        }
        printf("%s: $%.2f\n", trans[i].type, trans[i].amount);
    }

    printf("Total: $%.2f\n", total);

    free(trans);

    return 0;
}