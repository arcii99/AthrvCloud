//FormAI DATASET v1.0 Category: Database querying ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 50
#define MAX_NAME_LENGTH 20

struct student {
    int id;
    char name[MAX_NAME_LENGTH];
    float gpa;
};

// function to populate the database with sample data
void populate_database(struct student *database) {
    for (int i = 0; i < MAX_RECORDS; i++) {
        database[i].id = i+1;
        strcpy(database[i].name, "John Doe");
        database[i].gpa = 3.5;
    }
}

// function to print all records in the database
void print_database(struct student *database) {
    printf("%-4s %-20s %-4s\n", "ID", "NAME", "GPA");
    for (int i = 0; i < MAX_RECORDS; i++) {
        printf("%-4d %-20s %-4.2f\n", database[i].id, database[i].name, database[i].gpa);
    }
}

// function to query the database by ID
void query_by_id(struct student *database, int id) {
    for (int i = 0; i < MAX_RECORDS; i++) {
        if (database[i].id == id) {
            printf("%-4s %-20s %-4s\n", "ID", "NAME", "GPA");
            printf("%-4d %-20s %-4.2f\n", database[i].id, database[i].name, database[i].gpa);
            return;
        }
    }
    printf("Record with ID %d not found in database.\n", id);
}

int main() {
    struct student database[MAX_RECORDS];
    populate_database(database);

    printf("Printing all records in database:\n");
    print_database(database);

    printf("\nQuerying record with ID 5:\n");
    query_by_id(database, 5);

    return 0;
}