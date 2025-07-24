//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int inventory[MAX_SIZE];

void initializeInventory() {
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        inventory[i] = 0;
    }
}

void addInventory(int item) {
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        if (inventory[i] == 0) {
            inventory[i] = item;
            printf("Added item %d to inventory.\n", item);
            return;
        }
    }
    printf("Inventory is full.\n");
}

void removeInventory(int item) {
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        if (inventory[i] == item) {
            inventory[i] = 0;
            printf("Removed item %d from inventory.\n", item);
            return;
        }
    }
    printf("Item not found in inventory.\n");
}

void printInventory() {
    int i;
    printf("Inventory:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        if (inventory[i] != 0) {
            printf("%d\n", inventory[i]);
        }
    }
}

int main() {
    int choice, item;

   printf("Welcome to the Warehouse Management System!\n");
   printf("****************************************************\n\n");

    initializeInventory();

    while (1) {
        printf("\n1. Add item to inventory\n");
        printf("2. Remove item from inventory\n");
        printf("3. Print inventory\n");
        printf("4. Quit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to add: ");
                scanf("%d", &item);
                addInventory(item);
                break;
            case 2:
                printf("Enter item to remove: ");
                scanf("%d", &item);
                removeInventory(item);
                break;
            case 3:
                printInventory();
                break;
            case 4:
                printf("Thanks for using the Warehouse Management System!");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}