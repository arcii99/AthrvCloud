//FormAI DATASET v1.0 Category: Database Indexing System ; Style: accurate
#include <stdio.h>
#include <string.h>

// Define a structure for the index
struct index_entry {
    char key[20];
    int offset;
};

// Define a function to search for a key in the index
int search_index(struct index_entry index[], int n, char* key) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(index[i].key, key) == 0) {
            return index[i].offset;
        }
    }
    return -1;
}

// Define a function to insert a new entry into the index
void insert_index(struct index_entry index[], int n, char* key, int offset) {
    if (n >= 100) {
        printf("Error: index table full\n");
        return;
    }
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(index[i].key, key) == 0) {
            printf("Error: key already exists in index\n");
            return;
        }
    }
    strncpy(index[n].key, key, 20);
    index[n].offset = offset;
}

int main() {
    struct index_entry index[100];
    int num_entries = 0;

    // Insert some example entries
    insert_index(index, num_entries++, "apple", 0);
    insert_index(index, num_entries++, "banana", 10);
    insert_index(index, num_entries++, "orange", 20);
    insert_index(index, num_entries++, "pear", 30);

    // Search for some keys
    printf("offset of banana: %d\n", search_index(index, num_entries, "banana"));
    printf("offset of kiwi: %d\n", search_index(index, num_entries, "kiwi"));

    return 0;
}