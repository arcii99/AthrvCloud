//FormAI DATASET v1.0 Category: Database Indexing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

/* This is a unique database indexing system program */

/* Define a struct for the database table */
typedef struct {
    int id;
    char name[50];
    char email[50];
} TableEntry;

/* Define a struct for the index table */
typedef struct {
    int id;
    int offset;
} IndexEntry;

/* Declare the functions for the program */
void readTable(TableEntry[], int);
void writeIndex(IndexEntry[], int);
void readIndex(IndexEntry[], int);
void addUser(TableEntry[], int*, IndexEntry[], int*);
void searchUsers(TableEntry[], int, IndexEntry[], int);

/* Define the main function */
int main() {
    int tableSize = 10;
    int indexSize = 10;
    TableEntry table[tableSize];
    IndexEntry index[indexSize];
    readTable(table, tableSize);
    readIndex(index, indexSize);
    int numUsers = tableSize; /* This will be updated as new users are added */
    int numIndexes = indexSize; /* This will be updated as new indexes are added */

    int choice;
    do {
        printf("\nWelcome to the Database Indexing System.\n");
        printf("1. Add user\n");
        printf("2. Search users\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addUser(table, &numUsers, index, &numIndexes);
                break;
            case 2:
                searchUsers(table, numUsers, index, numIndexes);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while(choice != 3);

    writeIndex(index, numIndexes);

    return 0;
}

/* This function reads the database table from a file */
void readTable(TableEntry table[], int size) {
    FILE* fp = fopen("users.txt", "r");
    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int i;
    for(i = 0; i < size; i++) {
        fscanf(fp, "%d %s %s\n", &table[i].id, table[i].name, table[i].email);
    }

    fclose(fp);
}

/* This function writes the index table to a file */
void writeIndex(IndexEntry index[], int size) {
    FILE* fp = fopen("index.txt", "w");
    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int i;
    for(i = 0; i < size; i++) {
        fprintf(fp, "%d %d\n", index[i].id, index[i].offset);
    }

    fclose(fp);
}

/* This function reads the index table from a file */
void readIndex(IndexEntry index[], int size) {
    FILE* fp = fopen("index.txt", "r");
    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int i;
    for(i = 0; i < size; i++) {
        fscanf(fp, "%d %d\n", &index[i].id, &index[i].offset);
    }

    fclose(fp);
}

/* This function adds a new user to the database table and index table */
void addUser(TableEntry table[], int* numUsers, IndexEntry index[], int* numIndexes) {
    int id;
    char name[50];
    char email[50];

    printf("Enter user ID: ");
    scanf("%d", &id);
    printf("Enter user name: ");
    scanf("%s", name);
    printf("Enter user email: ");
    scanf("%s", email);

    /* Add the user to the table */
    table[*numUsers].id = id;
    strcpy(table[*numUsers].name, name);
    strcpy(table[*numUsers].email, email);
    (*numUsers)++;

    /* Add the user to the index */
    index[*numIndexes].id = id;
    index[*numIndexes].offset = (*numUsers) - 1;
    (*numIndexes)++;

    printf("User added to database.\n");
}

/* This function searches for users in the database */
void searchUsers(TableEntry table[], int numUsers, IndexEntry index[], int numIndexes) {
    int id;
    printf("Enter user ID to search: ");
    scanf("%d", &id);

    /* Use binary search to find the user in the index */
    int start = 0;
    int end = numIndexes - 1;
    int middle;
    while(start <= end) {
        middle = (start + end) / 2;
        if(index[middle].id == id) {
            /* User found in index, print their details */
            printf("User details:\n");
            TableEntry user = table[index[middle].offset];
            printf("ID: %d\n", user.id);
            printf("Name: %s\n", user.name);
            printf("Email: %s\n", user.email);
            return;
        }
        else if(index[middle].id < id) {
            start = middle + 1;
        }
        else {
            end = middle - 1;
        }
    }

    /* User not found in index */
    printf("User not found.\n");
}