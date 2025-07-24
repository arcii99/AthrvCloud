//FormAI DATASET v1.0 Category: Banking Record System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 1000

typedef struct Record {
    char account[50];
    char name[50];
    float balance;
    struct Record* next;
} Record;

Record* hash_table[HASH_SIZE];

unsigned long hash(char* str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash % HASH_SIZE;
}

Record* create_record() {
    Record* record = malloc(sizeof(Record));
    record->next = NULL;
    return record;
}

Record* add_record(char* account, char* name, float balance) {
    unsigned long hash_val = hash(account);
    Record* pos = hash_table[hash_val];

    while (pos != NULL) {
        if (strcmp(pos->account, account) == 0) {
            pos->balance += balance;
            return pos;
        }

        pos = pos->next;
    }

    Record* record = create_record();
    strncpy(record->account, account, 50);
    strncpy(record->name, name, 50);
    record->balance = balance;

    record->next = hash_table[hash_val];
    hash_table[hash_val] = record;

    return record;
}

Record* get_record(char* account) {
    unsigned long hash_val = hash(account);
    Record* pos = hash_table[hash_val];

    while (pos != NULL) {
        if (strcmp(pos->account, account) == 0) {
            return pos;
        }

        pos = pos->next;
    }

    return NULL;
}

int main() {
    memset(hash_table, 0, sizeof(hash_table));

    add_record("123456789", "John Smith", 1000);
    add_record("987654321", "Jane Doe", 500);
    add_record("555555555", "Bob Johnson", 2000);

    Record* record = get_record("123456789");
    printf("%s: %f\n", record->name, record->balance);

    record = get_record("987654321");
    printf("%s: %f\n", record->name, record->balance);

    record = get_record("555555555");
    printf("%s: %f\n", record->name, record->balance);

    return 0;
}