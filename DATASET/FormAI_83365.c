//FormAI DATASET v1.0 Category: Database Indexing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYS 1000

// Structure for a single key-value pair
typedef struct {
    int key;
    char value[20];
} KeyValue;

// Structure for a database index
typedef struct {
    KeyValue keys[MAX_KEYS];
    int numKeys;
} Index;

// Function to add a key-value pair to an index
void addKeyValue(Index *index, int key, const char *value) {
    if (index->numKeys < MAX_KEYS) {
        KeyValue *kv = &index->keys[index->numKeys++];
        kv->key = key;
        strncpy(kv->value, value, 20);
        kv->value[19] = '\0';
    }
}

// Function to find a key-value pair in an index
const char *findValueForKey(const Index *index, int key) {
    int i;
    for (i = 0; i < index->numKeys; i++) {
        if (index->keys[i].key == key) {
            return index->keys[i].value;
        }
    }
    return NULL;
}

// Function to print all key-value pairs in an index
void printIndex(const Index *index) {
    int i;
    for (i = 0; i < index->numKeys; i++) {
        printf("%d: %s\n", index->keys[i].key, index->keys[i].value);
    }
}

int main() {
    Index index;
    index.numKeys = 0;

    addKeyValue(&index, 1, "value1");
    addKeyValue(&index, 2, "value2");
    addKeyValue(&index, 3, "value3");
    addKeyValue(&index, 4, "value4");
    addKeyValue(&index, 5, "value5");

    printf("Value for key %d: %s\n", 3, findValueForKey(&index, 3));

    printf("All key-value pairs:\n");
    printIndex(&index);

    return 0;
}