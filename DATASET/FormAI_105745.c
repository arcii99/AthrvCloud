//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// create a struct to represent each item in the cyber store
typedef struct CyberItem {
    char itemName[20];
    int price;
    char category[10];
} CyberItem;

// function to search for an item by name
int searchCyberItem(CyberItem items[], int size, char searchName[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(items[i].itemName, searchName) == 0) {
            printf("Item found!\n");
            printf("Name: %s\nPrice: %d\nCategory: %s\n", items[i].itemName, items[i].price, items[i].category);
            return 1;
        }
    }
    printf("Item not found.\n");
    return 0;
}

int main() {
    // create an array of CyberItems
    CyberItem cyberStore[] = {
        {"Neural Implant", 10000, "Tech"},
        {"Cybernetic Arm", 5000, "Prosthetics"},
        {"Data Jack", 2500, "Tech"},
        {"Holographic Projector", 7500, "Tech"},
        {"Smart Gun", 10000, "Weapons"}
    };
    
    // get the size of the array
    int size = sizeof(cyberStore) / sizeof(cyberStore[0]);
    
    // prompt user to enter an item name to search for
    char searchName[20];
    printf("Enter the name of the item you're looking for: ");
    scanf("%s", searchName);
    
    // search for the item
    searchCyberItem(cyberStore, size, searchName);
    
    return 0;
}