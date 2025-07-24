//FormAI DATASET v1.0 Category: Sorting ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent the data to be sorted
struct Data {
    int key;
    char name[20];
};

// Define a function to compare two Data structs based on their keys
int compareData(const void *a, const void *b) {
    int keyA = ((struct Data*)a)->key;
    int keyB = ((struct Data*)b)->key;
    return (keyA - keyB);
}

int main() {
    // Initialize an array of Data structs to be sorted
    struct Data data[] = {
        {5, "John"},
        {2, "Anna"},
        {10, "Dave"},
        {3, "Emily"},
        {7, "Bob"}
    };
    
    int numData = sizeof(data) / sizeof(data[0]); // Calculate the number of data items
    
    // Print the original array of data
    printf("Original data:\n");
    for(int i = 0; i < numData; i++) {
        printf("%d %s\n", data[i].key, data[i].name);
    }
    
    // Sort the array of data using qsort
    qsort(data, numData, sizeof(struct Data), compareData);
    
    // Print the sorted array of data
    printf("\nSorted data:\n");
    for(int i = 0; i < numData; i++) {
        printf("%d %s\n", data[i].key, data[i].name);
    }
    
    return 0;
}