//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

typedef struct menuItem {
    char name[MAX_NAME_LEN];
    double price;
} MenuItem;

typedef struct orderItem {
    char name[MAX_NAME_LEN];
    double price;
    int quantity;
} OrderItem;

typedef struct order {
    OrderItem items[MAX_ITEMS];
    int itemCount;
    double total;
} Order;

MenuItem menu[] = {
    {"Coffee", 2.50},
    {"Tea", 1.75},
    {"Muffin", 1.99},
    {"Croissant", 2.50},
    {"Bagel", 2.25},
    {"Sandwich", 4.50},
    {"Salad", 5.99},
    {"Soup", 3.75},
    {"Smoothie", 4.25},
    {"Juice", 2.99}
};
int menuSize = sizeof(menu) / sizeof(MenuItem);

void printMenu() {
    printf("Welcome to Paranoid Cafe!\n\n");
    for (int i = 0; i < menuSize; i++) {
        printf("%d.%s\t%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("\n");
}

int validateInput(char *input) {
    char *end;
    int choice = strtol(input, &end, 10);

    if (end == input || choice <= 0 || choice > menuSize) {
        printf("Invalid input! Please enter a number between 1 and %d.\n\n", menuSize);
        return -1;
    }

    return choice;
}

void takeOrder(Order *order) {
    char input[10];
    int choice;

    do {
        printf("Enter item number to add to your order: ");
        fgets(input, sizeof(input), stdin);
        choice = validateInput(input);
    } while (choice == -1);

    OrderItem item = {
        .price = menu[choice - 1].price,
        .quantity = 1
    };
    strcpy(item.name, menu[choice - 1].name);

    order->items[order->itemCount++] = item;
    order->total += item.price;

    printf("%s added to your order! Your current total is $%.2f\n\n", item.name, order->total);
}

void printOrder(Order *order) {
    printf("\n\nYour Order:\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < order->itemCount; i++) {
        printf("%s\t\t$%.2f\t\tqty:%d\n", order->items[i].name, order->items[i].price, order->items[i].quantity);
    }
    printf("--------------------------------------------------\n");
    printf("Total:\t\t\t\t$%.2f\n\n", order->total);
}

void printReceipt(Order *order) {
    FILE *fp;
    char filename[MAX_NAME_LEN + 4];

    sprintf(filename, "%s.txt", order->items[0].name);
    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error writing to file.\n");
        return;
    }

    fprintf(fp, "Paranoid Cafe Receipt\n");
    fprintf(fp, "--------------------------------------------------\n");
    for (int i = 0; i < order->itemCount; i++) {
        fprintf(fp, "%s\t\t$%.2f\t\tqty:%d\n", order->items[i].name, order->items[i].price, order->items[i].quantity);
    }
    fprintf(fp, "--------------------------------------------------\n");
    fprintf(fp, "Total:\t\t\t\t$%.2f\n\n", order->total);
    fprintf(fp, "Thank you for choosing Paranoid Cafe!");

    printf("Receipt saved as %s\n", filename);
    fclose(fp);
}

void leave() {
    printf("Goodbye! Come back soon.\n");
    exit(0);
}

int main() {
    Order order = {
        .itemCount = 0,
        .total = 0.0
    };
    char input[10];
    int choice;

    while (1) {
        printMenu();

        do {
            printf("Enter your choice (or 0 to exit): ");
            fgets(input, sizeof(input), stdin);
            choice = validateInput(input);
        } while (choice == -1);

        if (choice == 0) {
            leave();
        } else {
            takeOrder(&order);
        }

        printOrder(&order);

        do {
            printf("Would you like to order anything else? (y/n) ");
            fgets(input, sizeof(input), stdin);
        } while (input[0] != 'y' && input[0] != 'n');

        if (input[0] == 'n') {
            printReceipt(&order);
            leave();
        }
    }

    return 0;
}