//FormAI DATASET v1.0 Category: Database querying ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 10

typedef struct student {
    char name[MAX_NAME_LENGTH];
    char id[MAX_ID_LENGTH];
    int age;
    float gpa;
} Student;

void search_by_name(Student records[], int count) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // remove trailing newline character

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].name, name) == 0) {
            printf("%s %s %d %.2f\n", records[i].name, records[i].id, records[i].age, records[i].gpa);
            found = true;
        }
    }

    if (!found) {
        printf("No records found for name: %s\n", name);
    }
}

void search_by_id(Student records[], int count) {
    char id[MAX_ID_LENGTH];
    printf("Enter ID: ");
    fgets(id, MAX_ID_LENGTH, stdin);
    id[strcspn(id, "\n")] = '\0'; // remove trailing newline character

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].id, id) == 0) {
            printf("%s %s %d %.2f\n", records[i].name, records[i].id, records[i].age, records[i].gpa);
            found = true;
        }
    }

    if (!found) {
        printf("No records found for ID: %s\n", id);
    }
}

int main() {
    Student records[MAX_RECORDS];

    // populate the database
    records[0] = (Student) {.name = "John Smith", .id = "123456789", .age = 20, .gpa = 3.5};
    records[1] = (Student) {.name = "Jane Doe", .id = "987654321", .age = 21, .gpa = 3.8};
    records[2] = (Student) {.name = "Bob Johnson", .id = "456123789", .age = 19, .gpa = 3.2};
    int count = 3;

    while (true) {
        printf("\nWhat would you like to do?\n");
        printf("1. Search by name\n");
        printf("2. Search by ID\n");
        printf("3. Quit\n");

        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // remove trailing newline character

        switch (choice) {
            case 1:
                search_by_name(records, count);
                break;
            case 2:
                search_by_id(records, count);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}