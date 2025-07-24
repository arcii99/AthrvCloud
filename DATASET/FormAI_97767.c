//FormAI DATASET v1.0 Category: Data mining ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    double total_spent;
} Customer;

int main() {
    Customer customers[5] = {
        { 1, "Alice", 100.50 },
        { 2, "Bob", 25.75 },
        { 3, "Charlie", 120.00 },
        { 4, "Dave", 58.20 },
        { 5, "Eve", 300.00 }
    };

    // Calculate average spending per customer
    double avg_spending = 0.0;
    for (int i = 0; i < 5; i++) {
        avg_spending += customers[i].total_spent;
    }
    avg_spending /= 5;
    printf("The average spending per customer is $%.2f.\n", avg_spending);

    // Identify high-spending customers
    printf("The following customers have spent more than the average:\n");
    for (int i = 0; i < 5; i++) {
        if (customers[i].total_spent > avg_spending) {
            printf("%s (ID %d) has spent $%.2f.\n", customers[i].name, customers[i].id, customers[i].total_spent);
        }
    }

    // Classify customers based on spending behavior
    printf("Here is a breakdown of customer spending behavior:\n");
    for (int i = 0; i < 5; i++) {
        if (customers[i].total_spent >= 200) {
            printf("%s (ID %d) is a VIP customer.\n", customers[i].name, customers[i].id);
        } else if (customers[i].total_spent >= 100) {
            printf("%s (ID %d) is a premium customer.\n", customers[i].name, customers[i].id);
        } else if (customers[i].total_spent >= avg_spending) {
            printf("%s (ID %d) is an average customer.\n", customers[i].name, customers[i].id);
        } else {
            printf("%s (ID %d) is a low-spending customer.\n", customers[i].name, customers[i].id);
        }
    }

    return 0;
}