//FormAI DATASET v1.0 Category: Database Indexing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 128
#define MAX_DATA_LEN 1024
#define TABLE_SIZE 10007

typedef struct {
    char key[MAX_KEY_LEN + 1];
    char data[MAX_DATA_LEN + 1];
} Record;

typedef struct {
    Record *records[TABLE_SIZE];
} Table;

unsigned long hash(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}

void table_init(Table *table) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        table->records[i] = NULL;
    }
}

void table_delete(Table *table) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        if (table->records[i] != NULL) {
            free(table->records[i]);
        }
    }
}

void table_insert(Table *table, const char *key, const char *data) {
    unsigned long h = hash(key) % TABLE_SIZE;
    Record *r = malloc(sizeof(Record));
    strncpy(r->key, key, MAX_KEY_LEN);
    strncpy(r->data, data, MAX_DATA_LEN);
    table->records[h] = r;
}

Record *table_search(Table *table, const char *key) {
    unsigned long h = hash(key) % TABLE_SIZE;
    return table->records[h];
}

int main() {
    Table table;
    table_init(&table);

    table_insert(&table, "cat", "meow");
    table_insert(&table, "dog", "woof");

    Record *r = table_search(&table, "cat");
    if (r != NULL) {
        printf("%s: %s\n", r->key, r->data);
    }

    table_delete(&table);
    return 0;
}