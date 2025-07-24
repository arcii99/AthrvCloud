//FormAI DATASET v1.0 Category: Database simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATABASE_SIZE 100

// Struct to store information about a case
struct case_record {
    int case_id;
    char name[50];
    char address[100];
    char occupation[50];
    char crime[200];
    int age;
    char status[20];
};

// Struct to store the database
struct case_database {
    int size;
    struct case_record records[MAX_DATABASE_SIZE];
};

// Function to add a case to the database
void add_case(struct case_database *db, struct case_record *rec) {
    // Check if the database is full
    if (db->size >= MAX_DATABASE_SIZE) {
        printf("Sorry, the database is full.\n");
        return;
    }
    // Add the case to the database
    db->records[db->size] = *rec;
    db->size++;
    printf("Case %d has been added to the database.\n", rec->case_id);
}

// Function to find a case by ID
void find_case_by_id(struct case_database db, int case_id) {
    int i;
    for (i = 0; i < db.size; i++) {
        if (db.records[i].case_id == case_id) {
            printf("Case ID: %d\nName: %s\nAddress: %s\nOccupation: %s\nCrime: %s\nAge: %d\nStatus: %s\n",
                   db.records[i].case_id, db.records[i].name, db.records[i].address, db.records[i].occupation,
                   db.records[i].crime, db.records[i].age, db.records[i].status);
            return;
        }
    }
    printf("Sorry, no case was found with ID %d.\n", case_id);
}

// Function to delete a case by ID
void delete_case_by_id(struct case_database *db, int case_id) {
    int i;
    for (i = 0; i < db->size; i++) {
        if (db->records[i].case_id == case_id) {
            // Delete the case by shifting all records above it down by one
            int j;
            for (j = i; j < db->size - 1; j++) {
                db->records[j] = db->records[j+1];
            }
            db->size--;
            printf("Case %d has been deleted from the database.\n", case_id);
            return;
        }
    }
    printf("Sorry, no case was found with ID %d.\n", case_id);
}

int main() {
    struct case_database db;
    db.size = 0;
    int choice = 0;
    while (choice != 4) {
        printf("\nWelcome to the case database of Sherlock Holmes.\n");
        printf("Please choose an option:\n");
        printf("1) Add a new case\n");
        printf("2) Find a case by ID\n");
        printf("3) Delete a case by ID\n");
        printf("4) Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                struct case_record rec;
                printf("\nEnter information about the case:\n");
                printf("Case ID: ");
                scanf("%d", &rec.case_id);
                printf("Name: ");
                scanf(" %[^\n]s", rec.name);
                printf("Address: ");
                scanf(" %[^\n]s", rec.address);
                printf("Occupation: ");
                scanf(" %[^\n]s", rec.occupation);
                printf("Crime: ");
                scanf(" %[^\n]s", rec.crime);
                printf("Age: ");
                scanf("%d", &rec.age);
                printf("Status: ");
                scanf(" %[^\n]s", rec.status);
                add_case(&db, &rec);
                break;
            }
            case 2: {
                int case_id;
                printf("\nEnter the case ID: ");
                scanf("%d", &case_id);
                find_case_by_id(db, case_id);
                break;
            }
            case 3: {
                int case_id;
                printf("\nEnter the case ID: ");
                scanf("%d", &case_id);
                delete_case_by_id(&db, case_id);
                break;
            }
            case 4:
                printf("\nThank you for using the case database of Sherlock Holmes.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}