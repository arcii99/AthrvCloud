//FormAI DATASET v1.0 Category: Database simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct Record {
    int id;
    char name[50];
    int age;
} Record;

Record database[MAX_RECORDS];
int num_records = 0;

void add_record(int id, char* name, int age) {
    // check if id already exists in database
    for (int i = 0; i < num_records; i++) {
        if (database[i].id == id) {
            printf("Error: Record with id %d already exists.\n", id);
            return;
        }
    }
    // add record to database
    if (num_records < MAX_RECORDS) {
        database[num_records].id = id;
        strcpy(database[num_records].name, name);
        database[num_records].age = age;
        num_records++;
    } else {
        printf("Error: Maximum number of records reached.\n");
    }
}

void print_records() {
    printf("ID\tName\tAge\n");
    for (int i = 0; i < num_records; i++) {
        printf("%d\t%s\t%d\n", database[i].id, database[i].name, database[i].age);
    }
}

void delete_record(int id) {
    // find record in database
    int index = -1;
    for (int i = 0; i < num_records; i++) {
        if (database[i].id == id) {
            index = i;
            break;
        }
    }
    // delete record from database
    if (index != -1) {
        for (int i = index; i < num_records - 1; i++) {
            database[i] = database[i+1];
        }
        num_records--;
    } else {
        printf("Error: Record with id %d not found.\n", id);
    }
}

int main() {
    // initialize database
    add_record(1, "John Smith", 25);
    add_record(2, "Jane Doe", 30);
    add_record(3, "Bob Johnson", 45);
    add_record(4, "Mary Williams", 20);

    // test database operations
    printf("Initial records:\n");
    print_records();

    add_record(5, "Tom Lee", 35);
    printf("After adding record:\n");
    print_records();

    delete_record(3);
    printf("After deleting record:\n");
    print_records();

    add_record(1, "Mike Brown", 28);
    printf("After adding duplicate record:\n");
    print_records();

    add_record(6, "Sarah Taylor", 24);
    add_record(7, "David Kim", 27);
    add_record(8, "Lisa Chen", 29);
    add_record(9, "James Wilson", 33);
    add_record(10, "Emily Davis", 26);
    printf("After adding maximum number of records:\n");
    print_records();

    add_record(11, "Alex Wong", 31);

    return 0;
}