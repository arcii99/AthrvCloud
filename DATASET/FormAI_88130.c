//FormAI DATASET v1.0 Category: Database Indexing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY_SIZE 100
#define MAX_ENTRIES 1000

typedef struct {
    char key[MAX_ENTRY_SIZE];
    int value;
} Entry;

typedef struct {
    int size;
    Entry entries[MAX_ENTRIES];
} DBIndex;

void add_entry(DBIndex* index, char* key, int value) {
    if (index->size == MAX_ENTRIES) {
        printf("Error: index is already full!\n");
        return;
    }

    Entry new_entry;

    strcpy(new_entry.key, key);
    new_entry.value = value;

    index->entries[index->size++] = new_entry;
}

int find_entry(DBIndex* index, char* key) {
    for (int i = 0; i < index->size; i++) {
        if (strcmp(index->entries[i].key, key) == 0)
            return index->entries[i].value;
    }

    return -1;
}

int main() {
    DBIndex index;
    index.size = 0;

    add_entry(&index, "John", 1);
    add_entry(&index, "Jane", 2);
    add_entry(&index, "Jack", 3);
    add_entry(&index, "Jill", 4);

    printf("Value for key 'John': %d\n", find_entry(&index, "John"));
    printf("Value for key 'Jane': %d\n", find_entry(&index, "Jane"));
    printf("Value for key 'Jack': %d\n", find_entry(&index, "Jack"));
    printf("Value for key 'Jill': %d\n", find_entry(&index, "Jill"));

    return 0;
}