//FormAI DATASET v1.0 Category: Database Indexing System ; Style: peaceful
#include <stdio.h>

#define MAX_RECORDS 100
#define MAX_INDEX 100

struct Record {
    char name[20];
    int age;
};

struct Index {
    char name[20];
    int index;
};

int num_records = 0;
struct Record records[MAX_RECORDS];
struct Index index_list[MAX_INDEX];

void add_record(char name[], int age);
void add_index(char name[], int index);
void search_index(char name[]);

int main() {
    add_record("Alice", 25);
    add_record("Bob", 30);
    add_record("Charlie", 20);

    add_index("Alice", 0);
    add_index("Bob", 1);
    add_index("Charlie", 2);

    search_index("Alice");
    search_index("Bob");
    search_index("Charlie");

    return 0;
}

void add_record(char name[], int age) {
    if (num_records < MAX_RECORDS) {
        struct Record record = { name, age };
        records[num_records++] = record;
    }
}

void add_index(char name[], int index) {
    if (index < MAX_INDEX) {
        struct Index idx = { name, index };
        index_list[index] = idx;
    }
}

void search_index(char name[]) {
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(records[i].name, name) == 0) {
            printf("Name: %s\n", records[i].name);
            printf("Age: %d\n", records[i].age);
            break;
        }
    }

    if (i == num_records) {
        printf("%s not found\n", name);
    }
}