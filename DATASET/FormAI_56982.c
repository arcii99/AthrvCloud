//FormAI DATASET v1.0 Category: Database querying ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct representing a single record
typedef struct {
    char name[50];
    int id;
    float gpa;
} Record;

// Function to print a single record
void printRecord(Record r) {
    printf("Name: %s\nID: %d\nGPA: %.2f\n\n", r.name, r.id, r.gpa);
}

int main() {
    // Hard-coded database for example purposes
    Record database[5] = {
        {"Alice", 1, 3.5},
        {"Bob", 2, 3.2},
        {"Charlie", 3, 3.8},
        {"David", 4, 2.9},
        {"Emma", 5, 3.7}
    };
    
    int choice;
    
    do {
        // Print menu options
        printf("Select a query:\n");
        printf("1. List all records\n");
        printf("2. Search by name\n");
        printf("3. Search by ID\n");
        printf("4. Search by GPA\n");
        printf("5. Exit\n");
        
        // Get user choice
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                // List all records
                for(int i=0; i<5; i++) {
                    printRecord(database[i]);
                }
                break;
            case 2:
                // Search by name
                char queryName[50];
                printf("Enter name to search: ");
                scanf("%s", queryName);
                
                for(int i=0; i<5; i++) {
                    if(strcmp(database[i].name, queryName) == 0) {
                        printRecord(database[i]);
                    }
                }
                break;
            case 3:
                // Search by ID
                int queryID;
                printf("Enter ID to search: ");
                scanf("%d", &queryID);
                
                for(int i=0; i<5; i++) {
                    if(database[i].id == queryID) {
                        printRecord(database[i]);
                    }
                }
                break;
            case 4:
                // Search by GPA
                float queryGPA;
                printf("Enter GPA to search: ");
                scanf("%f", &queryGPA);
                
                for(int i=0; i<5; i++) {
                    if(database[i].gpa == queryGPA) {
                        printRecord(database[i]);
                    }
                }
                break;
            case 5:
                // Exit program
                printf("Exiting...\n");
                break;
            default:
                // Handle invalid input
                printf("Invalid selection. Please try again.\n");
                break;
        }
    } while(choice != 5);
    
    return 0;
}