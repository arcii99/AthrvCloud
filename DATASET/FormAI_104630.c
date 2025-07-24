//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char name[20];
    int quantity;
    float price;
};

struct order {
    struct item items[10];
    int quantity[10];
    int numItems;
    float totalPrice;
};

struct menu {
    struct item items[10];
    int numItems;
};

void addToMenu(struct menu *m) {
    struct item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    m->items[m->numItems] = newItem;
    m->numItems++;
}

void displayMenu(struct menu m) {
    printf("MENU:\n");
    for (int i = 0; i < m.numItems; i++) {
        printf("%d. %s - %d x $%.2f\n", i+1, m.items[i].name, m.items[i].quantity, m.items[i].price);
    }
}

void getOrder(struct menu m, struct order *o) {
    int choice, quantity;
    o->numItems = 0;
    o->totalPrice = 0;
    printf("Enter menu item number (0 to finish): ");
    scanf("%d", &choice);
    while (choice != 0) {
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        o->items[o->numItems] = m.items[choice-1];
        o->quantity[o->numItems] = quantity;
        o->totalPrice += m.items[choice-1].price * quantity;
        o->numItems++;
        printf("Enter menu item number (0 to finish): ");
        scanf("%d", &choice);
    }
}

void printOrder(struct order o) {
    printf("ORDER:\n");
    for (int i = 0; i < o.numItems; i++) {
        printf("%d x %s - $%.2f each\n", o.quantity[i], o.items[i].name, o.items[i].price);
    }
    printf("Total Price: $%.2f\n", o.totalPrice);
}

int main() {
    struct menu m;
    m.numItems = 0;
    int choice;
    do {
        printf("CAFE BILLING SYSTEM\n");
        printf("1. Add item to menu\n");
        printf("2. Display menu\n");
        printf("3. Create order\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addToMenu(&m);
                break;
            case 2:
                displayMenu(m);
                break;
            case 3:
                struct order o;
                getOrder(m, &o);
                printOrder(o);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}