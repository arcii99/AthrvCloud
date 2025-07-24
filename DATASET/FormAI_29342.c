//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ITEMS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    int item_id;
    char item_name[MAX_NAME_LENGTH];
    int quantity;
} Item;

Item items[NUM_ITEMS];
int num_items = 0;

void print_menu();
void add_item();
void remove_item();
void display_items();

int main() {
    int choice;

    // initialize items list
    for (int i = 0; i < NUM_ITEMS; i++) {
        items[i].item_id = i + 1;
        strcpy(items[i].item_name, "empty");
        items[i].quantity = 0;
    }

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                display_items();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void print_menu() {
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. Display items\n");
    printf("4. Exit\n");
}

void add_item() {
    if (num_items == NUM_ITEMS) {
        printf("Warehouse is already full.\n");
        return;
    }

    int id, quantity;
    char name[MAX_NAME_LENGTH];

    printf("Enter item ID: ");
    scanf("%d", &id);

    if (id < 1 || id > NUM_ITEMS) {
        printf("Invalid item ID. Please try again.\n");
        return;
    }

    if (strcmp(items[id-1].item_name, "empty") != 0) {
        printf("Item with this ID already exists. Please try again.\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", name);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    items[id-1].item_id = id;
    strcpy(items[id-1].item_name, name);
    items[id-1].quantity = quantity;

    num_items++;

    printf("Item successfully added.\n");
}

void remove_item() {
    if (num_items == 0) {
        printf("Warehouse is already empty.\n");
        return;
    }

    int id;

    printf("Enter item ID: ");
    scanf("%d", &id);

    if (id < 1 || id > NUM_ITEMS) {
        printf("Invalid item ID. Please try again.\n");
        return;
    }

    if (strcmp(items[id-1].item_name, "empty") == 0) {
        printf("Item with this ID does not exist. Please try again.\n");
        return;
    }

    items[id-1].item_id = id;
    strcpy(items[id-1].item_name, "empty");
    items[id-1].quantity = 0;

    num_items--;

    printf("Item successfully removed.\n");
}

void display_items() {
    if (num_items == 0) {
        printf("Warehouse is empty.\n");
        return;
    }

    printf("| %-5s | %-20s | %-10s |\n", "ID", "Name", "Quantity");
    printf("|-------|----------------------|------------|\n");

    for (int i = 0; i < NUM_ITEMS; i++) {
        if (strcmp(items[i].item_name, "empty") != 0) {
            printf("| %-5d | %-20s | %-10d |\n", items[i].item_id, items[i].item_name, items[i].quantity);
        }
    }
}