//FormAI DATASET v1.0 Category: Database simulation ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000

// Struct for holding data
struct data {
    int id;
    char name[50];
    char email[50];
};

// Array to hold data
struct data records[MAX];

// Function to add data to the array
void addData(int id, char* name, char* email) {
    struct data newData;
    newData.id = id;
    strcpy(newData.name, name);
    strcpy(newData.email, email);
    records[id] = newData;
}

// Function to search for a record by name
void searchByName(char* name) {
    int i;
    for (i = 0; i < MAX; i++) {
        if (strcmp(records[i].name, name) == 0) {
            printf("Record found:\n");
            printf("ID: %d\nName: %s\nEmail: %s\n", records[i].id, records[i].name, records[i].email);
            return;
        }
    }
    printf("Record not found.\n");
}

// Function to sort records by ID in ascending order
void sortById() {
    int i, j;
    struct data temp;
    for (i = 0; i < MAX-1; i++) {
        for (j = i+1; j < MAX; j++) {
            if (records[i].id > records[j].id) {
                temp = records[i];
                records[i] = records[j];
                records[j] = temp;
            }
        }
    }
    printf("Records sorted by ID in ascending order.\n");
}

// Function to display all records
void displayRecords() {
    int i;
    printf("All records:\n");
    for (i = 0; i < MAX; i++) {
        if (records[i].id != NULL) {
            printf("ID: %d\nName: %s\nEmail: %s\n", records[i].id, records[i].name, records[i].email);
        }
    }
}

int main() {
    int choice = 0;
    int id;
    char name[50];
    char email[50];

    // Menu for interacting with the database
    while (choice != 5) {
        printf("\nDatabase Menu:\n");
        printf("1. Add record\n");
        printf("2. Search by name\n");
        printf("3. Sort by ID\n");
        printf("4. Display all records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                addData(id, name, email);
                printf("Record added.\n");
                break;
            case 2:
                printf("Enter name to search for: ");
                scanf("%s", name);
                searchByName(name);
                break;
            case 3:
                sortById();
                break;
            case 4:
                displayRecords();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}