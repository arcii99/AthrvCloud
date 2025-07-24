//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to hold item information
typedef struct item {
    int itemId;
    char itemName[20];
    int quantity;
    float price;
} Item;

// array of items in the warehouse
Item inventory[50];
int numItems = 0;

// function to add a new item to the warehouse
void addItem(int itemId, char itemName[], int quantity, float price) {
    // create a new Item struct and fill it with information
    Item newItem;
    newItem.itemId = itemId;
    strcpy(newItem.itemName, itemName);
    newItem.quantity = quantity;
    newItem.price = price;

    // add the new item to the inventory array
    inventory[numItems] = newItem;
    numItems++;

    // print a success message
    printf("\nItem added to inventory.\n");
}

// function to search for an item in the warehouse by ID
void searchById(int itemId) {
    // initialize index variable to -1 (item not found)
    int index = -1;

    // search through the inventory array for an item with a matching ID
    for (int i = 0; i < numItems; i++) {
        if (inventory[i].itemId == itemId) {
            index = i;
            break;
        }
    }

    // print item information or an error message if the item was not found
    if (index == -1) {
        printf("\nItem not found.\n");
    } else {
        printf("\nItem ID: %d\nItem Name: %s\nQuantity: %d\nPrice: %.2f\n",
            inventory[index].itemId, inventory[index].itemName,
            inventory[index].quantity, inventory[index].price);
    }
}

// function to search for an item in the warehouse by name
void searchByName(char itemName[]) {
    // initialize index variable to -1 (item not found)
    int index = -1;

    // search through the inventory array for an item with a matching name
    for (int i = 0; i < numItems; i++) {
        if (strcmp(inventory[i].itemName, itemName) == 0) {
            index = i;
            break;
        }
    }

    // print item information or an error message if the item was not found
    if (index == -1) {
        printf("\nItem not found.\n");
    } else {
        printf("\nItem ID: %d\nItem Name: %s\nQuantity: %d\nPrice: %.2f\n",
            inventory[index].itemId, inventory[index].itemName,
            inventory[index].quantity, inventory[index].price);
    }
}

int main() {
    // test the functions by adding some items and searching for them
    addItem(1001, "Shampoo", 20, 5.99);
    addItem(1002, "Soap", 30, 2.49);
    addItem(1003, "Toothpaste", 15, 3.79);

    searchById(1002);
    searchByName("Shampoo");
    searchByName("Toothbrush");

    return 0;
}