//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: surrealist
#include <stdio.h>

// Function to generate unique menu items
void generateMenuItem(char* item) {
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    char consonants[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
    int i;

    for (i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            item[i] = consonants[rand() % 20];
        } else {
            item[i] = vowels[rand() % 5];
        }
    }

    item[10] = '\0';
}

int main() {
    int orderNumber = 1;
    float totalAmount = 0.0;
    char menuItem[11];

    printf("Welcome to The Red Herring Cafe!\n");

    while (1) {
        printf("\nEnter '111' to close the cafe for the day and generate the bill.\n");

        generateMenuItem(menuItem);
        printf("\nOrder Number: %d\n", orderNumber);
        printf("\nMenu Title: %s\n", menuItem);

        float itemPrice = (rand() % 10) + 1;
        printf("\nPrice: $%.2f\n", itemPrice);

        totalAmount += itemPrice;
        printf("\nOrder Total: $%.2f\n", totalAmount);

        orderNumber++;

        int closeCafe = rand() % 1000;
        if (closeCafe == 111) {
            break;
        }
    }

    printf("\nThank you for dining at The Red Herring Cafe!\n");
    printf("\nTotal bill amount: $%.2f\n", totalAmount);

    return 0;
}