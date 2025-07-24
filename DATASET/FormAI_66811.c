//FormAI DATASET v1.0 Category: Sorting ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define a custom struct called Item
typedef struct {
    int value;
    char label[20];
} Item;

// Define a custom comparison function for sorting based on value
int compareValues(const void* a, const void* b) {
    const Item* itemA = (const Item*)a;
    const Item* itemB = (const Item*)b;
    return itemA->value - itemB->value;
}

// Define a custom comparison function for sorting based on label
int compareLabels(const void* a, const void* b) {
    const Item* itemA = (const Item*)a;
    const Item* itemB = (const Item*)b;
    return strcmp(itemA->label, itemB->label);
}

// Define a function to print the contents of an array of Items
void printItems(Item arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d: %s\n", arr[i].value, arr[i].label);
    }
}

int main() {
    // Create an array of Items and initialize values and labels
    Item items[6] = {
        { 42, "The Answer" },
        { 15, "Fifteen" },
        { 7, "Lucky Number" },
        { 100, "One Hundred" },
        { 3, "Three" },
        { 8, "Eight" }
    };
    
    // Print the original array
    printf("Original array:\n");
    printItems(items, 6);
    
    // Sort the array based on value
    qsort(items, 6, sizeof(Item), compareValues);
    
    // Print the array after sorting by value
    printf("\nSorted by value:\n");
    printItems(items, 6);
    
    // Sort the array based on label
    qsort(items, 6, sizeof(Item), compareLabels);
    
    // Print the array after sorting by label
    printf("\nSorted by label:\n");
    printItems(items, 6);
    
    return 0;
}