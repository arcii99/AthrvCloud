//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEMS 1000

struct Item {
    char name[50];
    int price;
    int quantity;
};

struct Stock {
    int numberOfItems;
    struct Item items[MAX_ITEMS];
};

struct Customer {
    char name[50];
    int id;
    int numberOfPurchases;
};

struct Purchases {
    int customerId;
    int numberOfItems;
    struct Item items[MAX_ITEMS];
};

void addItem(struct Stock* stock, char name[], int price, int quantity) {
    if (stock->numberOfItems < MAX_ITEMS) {
        struct Item newItem;
        strcpy(newItem.name, name);
        newItem.price = price;
        newItem.quantity = quantity;
        stock->items[stock->numberOfItems++] = newItem;
        printf("Item added successfully\n");
    }
    else {
        printf("Stock is full, cannot add more items\n");
    }
}

void removeItem(struct Stock* stock, int index) {
    if (index < 0 || index >= stock->numberOfItems) {
        printf("Invalid item index\n");
    }
    else {
        for (int i = index; i < stock->numberOfItems - 1; i++) {
            stock->items[i] = stock->items[i + 1];
        }
        stock->numberOfItems--;
        printf("Item removed successfully\n");
    }
}

void displayStock(struct Stock stock) {
    if (stock.numberOfItems == 0) {
        printf("Stock is empty\n");
    }
    else {
        printf("Name\tPrice\tQuantity\n");
        for (int i = 0; i < stock.numberOfItems; i++) {
            printf("%s\t%d\t%d\n", stock.items[i].name, stock.items[i].price, stock.items[i].quantity);
        }
    }
}

void displayCustomer(struct Customer customer) {
    printf("ID: %d\tName: %s\tNumber of purchases: %d\n", customer.id, customer.name, customer.numberOfPurchases);    
}

void addPurchase(struct Purchases* purchases, int customerId, struct Stock* stock, int itemIndex, int quantity) {
    if (customerId < 0) {
        printf("Invalid customer ID\n");
    }
    else if (itemIndex < 0 || itemIndex >= stock->numberOfItems) {
        printf("Invalid item index\n");
    }
    else if (quantity <= 0) {
        printf("Invalid quantity\n");
    }
    else if (stock->items[itemIndex].quantity < quantity) {
        printf("Insufficient quantity in stock\n");
    }
    else {
        purchases->customerId = customerId;
        purchases->items[purchases->numberOfItems] = stock->items[itemIndex];
        purchases->items[purchases->numberOfItems].quantity = quantity;
        purchases->numberOfItems++;
        stock->items[itemIndex].quantity -= quantity;
        printf("Purchase added successfully\n");
    }
}

void displayPurchase(struct Purchases purchases) {
    printf("Customer ID: %d\n", purchases.customerId);
    printf("Name\tPrice\tQuantity\n");
    for (int i = 0; i < purchases.numberOfItems; i++) {
        printf("%s\t%d\t%d\n", purchases.items[i].name, purchases.items[i].price, purchases.items[i].quantity);
    }
}

int main() {
    struct Stock stock;
    struct Customer customers[MAX_ITEMS];
    struct Purchases purchases;
    int numberOfCustomers = 0;

    stock.numberOfItems = 0;
    purchases.numberOfItems = 0;

    addItem(&stock, "Paracetamol", 5, 50);
    addItem(&stock, "Aspirin", 6, 40);
    addItem(&stock, "Ibuprofen", 7, 30);

    int choice = 0;
    while (choice != 6) {
        printf("\nMenu:\n1.Add Customer\n2.Display Customers\n3.Add Purchase\n4.Display Purchase\n5.Display Stock\n6.Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (numberOfCustomers < MAX_ITEMS) {
                struct Customer newCustomer;
                printf("Enter customer name: ");
                scanf("%s", newCustomer.name);
                newCustomer.id = numberOfCustomers++;
                newCustomer.numberOfPurchases = 0;
                customers[newCustomer.id] = newCustomer;
                printf("Customer added successfully, customer ID is %d\n", newCustomer.id);
            }
            else {
                printf("Maximum number of customers reached, cannot add more customers\n");
            }
            break;

        case 2:
            if (numberOfCustomers == 0) {
                printf("No customers found\n");
            }
            else {
                printf("ID\tName\tNumber of purchases\n");
                for (int i = 0; i < numberOfCustomers; i++) {
                    displayCustomer(customers[i]);
                }
            }
            break;

        case 3:
            if (numberOfCustomers == 0) {
                printf("No customers found, cannot add purchase\n");
            }
            else if (stock.numberOfItems == 0) {
                printf("Stock is empty, cannot add purchase\n");
            }
            else {
                int customerId, itemIndex, quantity;
                printf("Enter customer ID: ");
                scanf("%d", &customerId);
                printf("Enter item index: ");
                scanf("%d", &itemIndex);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                addPurchase(&purchases, customerId, &stock, itemIndex, quantity);
                customers[customerId].numberOfPurchases++;
            }
            break;

        case 4:
            if (purchases.numberOfItems == 0) {
                printf("No purchases made\n");
            }
            else {
                displayPurchase(purchases);
            }
            break;

        case 5:
            displayStock(stock);
            break;

        case 6:
            printf("Exiting program\n");
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}