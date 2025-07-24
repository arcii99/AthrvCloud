//FormAI DATASET v1.0 Category: Database simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a database item
struct Item {
    int id;
    char name[50];
    char description[100];
    float price;
};

// Declare a global variable for our database
struct Item items[100];

// Declare a variable to keep track of the number of items in the database
int count = 0;

// Function to add an item to the database
void addItem(int id, char* name, char* description, float price) {
    // Create a new item struct and add it to the items array
    struct Item newItem;
    newItem.id = id;
    strcpy(newItem.name, name);
    strcpy(newItem.description, description);
    newItem.price = price;

    items[count] = newItem;
    count++;
}

// Function to print out all items in the database
void printItems() {
    printf("ID\tName\t\t\t\tDescription\t\t\tPrice\n");
    for(int i=0; i<count; i++) {
        printf("%d\t%s\t\t\t\t%s\t\t\t\t%.2f\n", items[i].id, items[i].name, items[i].description, items[i].price);
    }
}

// Function to search for an item in the database by ID and return a pointer to that item
struct Item* searchById(int id) {
    for(int i=0; i<count; i++) {
        if(items[i].id == id) {
            return &items[i];
        }
    }
    return NULL;
}

int main() {
    // Add some items to our database
    addItem(1, "Apple", "A delicious fruit", 0.50);
    addItem(2, "Banana", "A tasty tropical fruit", 0.75);
    addItem(3, "Carrot", "A healthy root vegetable", 1.00);

    // Print out all items in the database
    printf("Initial Items:\n");
    printItems();

    // Search for an item in the database by ID and print out its details
    printf("Searching for item with ID 2:\n");
    struct Item* item = searchById(2);
    if(item != NULL) {
        printf("Item found:\n");
        printf("ID: %d\nName: %s\nDescription: %s\nPrice: %.2f\n", item->id, item->name, item->description, item->price);
    } else {
        printf("Item not found.\n");
    }

    // Update an item's details in the database
    printf("Updating item with ID 3...\n");
    item = searchById(3);
    if(item != NULL) {
        strcpy(item->name, "Organic Carrot");
        strcpy(item->description, "A healthy organic root vegetable");
        item->price = 1.50;
        printf("Item updated successfully.\n");
    } else {
        printf("Item not found.\n");
    }

    // Print out all items in the database after updating an item
    printf("Updated Items:\n");
    printItems();

    return 0;
}