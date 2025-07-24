//FormAI DATASET v1.0 Category: Database Indexing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100  // Maximum size of the index table
#define MAX_STRING_LEN 50  // Maximum length of the string

// Definition of the Index table struct
typedef struct {
    char string[MAX_STRING_LEN];
    int index;
} IndexTable;

/*
Function to print the index table.
*/
void printIndexTable(IndexTable* indexTable, int size) {
    printf("\nIndex Table:\n");
    for(int i = 0; i < size; i++) {
        printf("[%d]: %s\n", indexTable[i].index, indexTable[i].string);
    }
}

/*
Function to compare strings for qsort.
*/
int cmpString(const void* a, const void* b) {
    return strcmp(((IndexTable*)a)->string, ((IndexTable*)b)->string);
}

/*
Function to search for a string in the index table using binary search.
*/
int searchIndexTable(char* string, IndexTable* indexTable, int size) {
    int left = 0;
    int right = size - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(strcmp(string, indexTable[mid].string) == 0) {
            return indexTable[mid].index;
        } else if(strcmp(string, indexTable[mid].string) < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

/*
Main function
*/
int main() {
    char inputString[MAX_STRING_LEN];
    IndexTable indexTable[MAX_SIZE];
    int size = 0;

    // Reading strings from the console
    printf("Enter strings to index (maximum 100):\n");
    while(size < MAX_SIZE && fgets(inputString, MAX_STRING_LEN, stdin) != NULL) {
        inputString[strcspn(inputString, "\n")] = '\0'; // Removing newline char
        strcpy(indexTable[size].string, inputString);
        indexTable[size].index = size;
        size++;
    }

    // Sorting the index table
    qsort(indexTable, size, sizeof(IndexTable), cmpString);

    // Printing the index table
    printIndexTable(indexTable, size);

    // Searching for strings in the index table
    while(1) {
        printf("\nEnter a string to search for (type 'exit' to exit): ");
        fgets(inputString, MAX_STRING_LEN, stdin);
        inputString[strcspn(inputString, "\n")] = '\0'; // Removing newline char
        if(strcmp(inputString, "exit") == 0) {
            break;
        }
        int index = searchIndexTable(inputString, indexTable, size);
        if(index == -1) {
            printf("String not found in index table!\n");
        } else {
            printf("String found at index %d in index table!\n", index);
        }
    }

    return 0;
}