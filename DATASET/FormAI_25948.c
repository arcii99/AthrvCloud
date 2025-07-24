//FormAI DATASET v1.0 Category: Database Indexing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

struct record {
    int id;
    char name[30];
    int age;
    float salary;
};

struct index {
    char name[30];
    int position;
};

struct record records[MAX_RECORDS];
struct index indices[MAX_RECORDS];
int current_position = 0;

void add_record(int id, char *name, int age, float salary) {
    if (current_position >= MAX_RECORDS) {
        printf("Database is full!\n");
        return;
    }

    struct record new_record = {id, "", age, salary};
    strcpy(new_record.name, name);

    records[current_position] = new_record;

    struct index new_index = {"", current_position};
    strcpy(new_index.name, name);

    indices[current_position] = new_index;

    current_position++;
}

void print_records() {
    printf("ID\tName\t\tAge\tSalary\n");
    for (int i = 0; i < current_position; i++) {
        printf("%d\t%s\t\t%d\t%f\n", records[i].id, records[i].name, records[i].age, records[i].salary);
    }
}

void print_indices() {
    printf("Name\tPosition\n");
    for (int i = 0; i < current_position; i++) {
        printf("%s\t%d\n", indices[i].name, indices[i].position);
    }
}

void search_by_name(char *name) {
    for (int i = 0; i < current_position; i++) {
        if (strcmp(records[i].name, name) == 0) {
            printf("Found record with name %s:\n", name);
            printf("ID\tName\t\tAge\tSalary\n");
            printf("%d\t%s\t\t%d\t%f\n", records[i].id, records[i].name, records[i].age, records[i].salary);
        }
    }
}

int main() {
    // Example usage
    add_record(1, "Alice", 25, 5000.0);
    add_record(2, "Bob", 30, 7000.0);
    add_record(3, "Charlie", 35, 9000.0);
    add_record(4, "David", 40, 11000.0);

    printf("Records:\n");
    print_records();

    printf("Indices:\n");
    print_indices();

    search_by_name("Bob");

    return 0;
}