//FormAI DATASET v1.0 Category: Database Indexing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_KEY_LENGTH 32
#define MAX_VALUE_LENGTH 128
#define MAX_ENTRIES 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH]; 
} Record;

typedef struct {
    Record records[MAX_ENTRIES];
    int num_records;
} Index;

void initialize_index(Index* index) {
    index->num_records = 0;
}

bool insert_record(Index* index, char key[], char value[]) {
    if(index->num_records >= MAX_ENTRIES) {
        return false;
    }

    // check if key already exists
    for(int i = 0; i < index->num_records; i++) {
        if(strcmp(index->records[i].key, key) == 0) {
            strcpy(index->records[i].value, value);
            return true;
        }
    }

    // key is not already in index, add new record
    strcpy(index->records[index->num_records].key, key);
    strcpy(index->records[index->num_records].value, value);
    index->num_records++;
    return true;
}

char* search_record(Index* index, char key[]) {
    for(int i = 0; i < index->num_records; i++) {
        if(strcmp(index->records[i].key, key) == 0) {
            return index->records[i].value;
        }
    }
    return NULL;
}

int main() {
    Index index;
    initialize_index(&index);

    insert_record(&index, "apple", "A sweet fruit");
    insert_record(&index, "banana", "A yellow fruit");
    insert_record(&index, "cherry", "A small red fruit");
    insert_record(&index, "dates", "A sweet dried fruit");
    insert_record(&index, "elderberry", "A sour fruit");

    printf("The description of banana is: %s\n", search_record(&index, "banana"));
    printf("The description of elderberry is: %s\n", search_record(&index, "elderberry"));
    printf("The description of orange is: %s\n", search_record(&index, "orange"));

    return 0;
}