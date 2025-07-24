//FormAI DATASET v1.0 Category: Database simulation ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining the maximum no of records allowed (50 here)
#define MAX_RECORDS 50

// Defining structure of a record
struct Record{
    int id;
    char name[20];
    float score;
};

// Global variable to hold all the records
struct Record records[MAX_RECORDS];

// Function to insert a record in the database
void insertRecord(int id, char* name, float score){

    // Check if the record already exists in the database
    for(int i=0; i<MAX_RECORDS; i++){
        if(records[i].id == id){
            printf("Record with same ID already exists in the database.\n");
            return;
        }
    }

    // Check if the database is full
    int count = 0;
    for(int i=0; i<MAX_RECORDS; i++){
        if(records[i].id != -1){
            count++;
        }
    }
    if(count == MAX_RECORDS){
        printf("Cannot insert record. Database is full.\n");
        return;
    }

    // Insert the record in the first empty slot of the database
    for(int i=0; i<MAX_RECORDS; i++){
        if(records[i].id == -1){
            records[i].id = id;
            strcpy(records[i].name, name);
            records[i].score = score;
            printf("Record inserted successfully.\n");
            return;
        }
    }
}

// Function to search for a record in the database
void searchRecord(int id){

    // Check if the record exists in the database
    for(int i=0; i<MAX_RECORDS; i++){
        if(records[i].id == id){
            printf("ID: %d\n", records[i].id);
            printf("Name: %s\n", records[i].name);
            printf("Score: %.2f\n", records[i].score);
            return;
        }
    }

    // If record not found
    printf("Record not found in the database.\n");
}

// Function to update a record in the database
void updateRecord(int id, char* name, float score){

    // Check if the record exists in the database
    for(int i=0; i<MAX_RECORDS; i++){
        if(records[i].id == id){
            strcpy(records[i].name, name);
            records[i].score = score;
            printf("Record updated successfully.\n");
            return;
        }
    }

    // If record not found
    printf("Record not found in the database.\n");
}

// Function to delete a record from the database
void deleteRecord(int id){

    // Check if the record exists in the database
    for(int i=0; i<MAX_RECORDS; i++){
        if(records[i].id == id){
            records[i].id = -1;
            strcpy(records[i].name, "");
            records[i].score = -1;
            printf("Record deleted successfully.\n");
            return;
        }
    }

    // If record not found
    printf("Record not found in the database.\n");
}

int main(){

    // Initialize all records to -1 (indicating empty)
    for(int i=0; i<MAX_RECORDS; i++){
        records[i].id = -1;
        strcpy(records[i].name, "");
        records[i].score = -1;
    }

    // Menu-driven program
    printf("Welcome to Database Simulation Program\n\n");
    int choice, id;
    char name[20];
    float score;
    while(1){
        printf("1. Insert Record\n2. Search Record\n3. Update Record\n4. Delete Record\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter ID, Name and Score (separated by spaces): ");
                scanf("%d %s %f", &id, name, &score);
                insertRecord(id, name, score);
                break;
            case 2:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                searchRecord(id);
                break;
            case 3:
                printf("Enter ID, updated Name and Score (separated by spaces): ");
                scanf("%d %s %f", &id, name, &score);
                updateRecord(id, name, score);
                break;
            case 4:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteRecord(id);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}