//FormAI DATASET v1.0 Category: Database Indexing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 50
#define MAX_ENTRIES 100

struct Entry {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
};

struct Index {
    struct Entry entries[MAX_ENTRIES];
    int size;
};

struct Index createIndex() {
    struct Index index = { .size = 0 };
    return index;
}

void printIndex(struct Index index) {
    printf("Index:\n");
    for (int i = 0; i < index.size; i++) {
        printf("%s: %s\n", index.entries[i].key, index.entries[i].value);
    }
}

int insertEntry(struct Index *index, struct Entry entry) {
    if (index->size >= MAX_ENTRIES) {
        printf("Index is full.\n");
        return 0;
    }
    index->entries[index->size++] = entry;
    return 1;
}

int removeEntry(struct Index *index, char key[MAX_KEY_LENGTH]) {
    for (int i = 0; i < index->size; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            for (int j = i; j < index->size - 1; j++) {
                index->entries[j] = index->entries[j+1];
            }
            index->size--;
            return 1;
        }
    }
    return 0;
}

int searchEntry(struct Index index, char key[MAX_KEY_LENGTH], char value[MAX_VALUE_LENGTH]) {
    for (int i = 0; i < index.size; i++) {
        if (strcmp(index.entries[i].key, key) == 0) {
            strcpy(value, index.entries[i].value);
            return 1;
        }
    }
    return 0;
}

int main() {
    struct Index index = createIndex();
    struct Entry entry1 = { .key = "cat", .value = "feline" };
    struct Entry entry2 = { .key = "dog", .value = "canine" };
    struct Entry entry3 = { .key = "bird", .value = "feathered" };
    insertEntry(&index, entry1);
    insertEntry(&index, entry2);
    insertEntry(&index, entry3);
    printIndex(index);
    char value[MAX_VALUE_LENGTH];
    if (searchEntry(index, "cat", value)) {
        printf("Value of cat is: %s\n", value);
    } else {
        printf("Cat not found in index.\n");
    }
    removeEntry(&index, "dog");
    printIndex(index);
    return 0;
}