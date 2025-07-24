//FormAI DATASET v1.0 Category: Database querying ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 100

typedef struct Record Record;
struct Record {
    char name[20];
    int age;
    float salary;
};

typedef struct Table Table;
struct Table {
    Record *records[TABLE_SIZE];
};

Table createTable() {
    Table table;
    for (int i = 0; i < TABLE_SIZE; i++) {
        table.records[i] = NULL;
    }
    return table;
}

int hash(char *str) {
    int hash = 0;
    for (int i = 0; i < strlen(str); i++) {
        hash += str[i];
    }
    return hash % TABLE_SIZE;
}

void insert(Table *table, char *name, int age, float salary) {
    Record *record = (Record *) malloc(sizeof(Record));
    strcpy(record->name, name);
    record->age = age;
    record->salary = salary;
    int index = hash(name);
    while (table->records[index] != NULL) {
        index = (index + 1) % TABLE_SIZE;
    }
    table->records[index] = record;
}

Record *search(Table *table, char *name) {
    int index = hash(name);
    while (table->records[index] != NULL && strcmp(table->records[index]->name, name) != 0) {
        index = (index + 1) % TABLE_SIZE;
    }
    return table->records[index];
}

void delete(Table *table, char *name) {
    int index = hash(name);
    while (table->records[index]->name != NULL) {
        if (strcmp(table->records[index]->name, name) == 0) {
            table->records[index] = NULL;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    }
}

void display(Table *table) {
    printf("Name\tAge\tSalary\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table->records[i] != NULL) {
            printf("%s\t%d\t%.2f\n", table->records[i]->name, table->records[i]->age, table->records[i]->salary);
        }
    }
}

int main() {
    Table employeeTable = createTable();

    insert(&employeeTable, "John", 25, 2500.00);
    insert(&employeeTable, "Alice", 30, 3000.00);
    insert(&employeeTable, "Bob", 35, 3500.00);

    printf("Before deletion:\n");
    display(&employeeTable);

    delete(&employeeTable, "Alice");

    printf("\nAfter deletion:\n");
    display(&employeeTable);

    Record *found = search(&employeeTable, "Bob");
    if (found != NULL) {
        printf("\n%s found with age %d and salary %.2f\n", found->name, found->age, found->salary);
    } else {
        printf("\nRecord not found\n");
    }

    return 0;
}