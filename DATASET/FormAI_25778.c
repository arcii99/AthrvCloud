//FormAI DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// structure to store the index node
typedef struct IndexNode {
    int key;
    int offset;
} IndexNode;

// function to compare two index nodes based on their keys
int compare(const void* a, const void* b) {
    IndexNode* nodeA = (IndexNode*)a;
    IndexNode* nodeB = (IndexNode*)b;
    if (nodeA->key < nodeB->key) return -1;
    else if (nodeA->key > nodeB->key) return 1;
    else return 0;
}

// function to perform binary search on index nodes
int binarySearch(IndexNode* index, int size, int key) {
    int low = 0, high = size - 1, mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (index[mid].key == key) return index[mid].offset;
        else if (index[mid].key < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // key not found
}

int main() {
    // example code to generate index nodes
    int data[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int dataSize = sizeof(data) / sizeof(int);
    IndexNode index[dataSize];
    for (int i = 0; i < dataSize; i++) {
        index[i].key = data[i];
        index[i].offset = i;
    }

    // sort the index nodes based on their keys
    qsort(index, dataSize, sizeof(IndexNode), compare);

    // perform binary search on the index nodes
    int searchKey = 7;
    int result = binarySearch(index, dataSize, searchKey);
    if (result != -1) {
        printf("Key %d found at offset %d.\n", searchKey, result);
    } else {
        printf("Key %d not found.\n", searchKey);
    }

    return 0;
}