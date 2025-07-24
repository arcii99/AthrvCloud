//FormAI DATASET v1.0 Category: Database Indexing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

struct Table {
    int id;
    char name[50];
    int age;
};

struct Index {
    int key;
    int position;
};

void addEntry(struct Table *table, struct Index *index, int id, char *name, int age, int count) {
    int key = id % MAX_SIZE;
    int i = 0;
    // check for duplicate keys
    while (index[i].key != 0 && index[i].key != key) {
        i++;
    }
    if (index[i].position == 0) {
        // add new entry to table and index
        table[count].id = id;
        strcpy(table[count].name, name);
        table[count].age = age;
        index[i].key = key;
        index[i].position = count;
    }
}

void printTable(struct Table *table, int count) {
    printf("ID\tName\tAge\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\n", table[i].id, table[i].name, table[i].age);
    }
}

int main() {
    struct Table table[MAX_SIZE];
    struct Index index[MAX_SIZE] = {0};
    int count = 0;

    addEntry(table, index, 123, "John Smith", 30, count++);
    addEntry(table, index, 456, "Jane Doe", 25, count++);
    addEntry(table, index, 789, "Bob Johnson", 35, count++);
    addEntry(table, index, 984, "Amanda Lee", 28, count++);
    addEntry(table, index, 345, "Samantha Kim", 22, count++);

    printTable(table, count);

    return 0;
}