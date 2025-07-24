//FormAI DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000

// define the data structure for our index
typedef struct {
    int key;
    int value;
} IndexEntry;

// define our index array
IndexEntry indexArr[ARRAY_SIZE];

// define the function to search the index
int searchIndex(int key) {
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) {
        if (indexArr[i].key == key) {
            return i;
        }
    }
    return -1;
}

// define the function to insert into the index
void insertIndex(int key, int value) {
    // first check if this key exists already
    int index = searchIndex(key);
    if (index == -1) {
        // key not found, so insert new entry
        int i;
        for (i = 0; i < ARRAY_SIZE; i++) {
            if (indexArr[i].key == 0) {
                // found an empty entry, insert here
                indexArr[i].key = key;
                indexArr[i].value = value;
                break;
            }
        }
    } else {
        // key found, so update existing entry
        indexArr[index].value = value;
    }
}

// define the function to delete from the index
void deleteIndex(int key) {
    // first check if this key exists
    int index = searchIndex(key);
    if (index != -1) {
        // key found, so delete the entry
        indexArr[index].key = 0;
        indexArr[index].value = 0;
    }
}

// define the main function to test our index functions
int main() {
    // insert some entries into the index
    insertIndex(23, 100);
    insertIndex(35, 200);
    insertIndex(47, 300);
    insertIndex(59, 400);

    // search for an entry in the index
    int index = searchIndex(47);
    if (index != -1) {
        printf("Key found in index: %d\n", indexArr[index].value);
    } else {
        printf("Key not found in index\n");
    }

    // delete an entry from the index
    deleteIndex(35);

    // search for the deleted entry
    index = searchIndex(35);
    if (index != -1) {
        printf("Key found in index: %d\n", indexArr[index].value);
    } else {
        printf("Key not found in index\n");
    }

    return 0;
}