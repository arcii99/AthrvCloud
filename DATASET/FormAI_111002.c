//FormAI DATASET v1.0 Category: Database simulation ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for each record to be stored in the database
struct Record {
    int id;
    char name[50];
};

int main() {
    int num_records, option;
    printf("Welcome to the Database Simulation Program!\n");

    // Get the number of records to be stored
    printf("Enter the number of records you want to store in the database: ");
    scanf("%d", &num_records);

    // Allocate memory for the records
    struct Record* records = (struct Record*) malloc(num_records*sizeof(struct Record));

    // Ask the user for the records
    for(int i=0; i<num_records; i++) {
        printf("Enter details for Record %d:\n", i+1);
        printf("Enter the ID: ");
        scanf("%d", &records[i].id);
        printf("Enter the Name: ");
        scanf("%s", records[i].name);
    }

    // Ask the user for the operation they want to perform
    printf("\nEnter the option number of the operation you want to perform:\n");
    printf("1. Print all records\n");
    printf("2. Search for a record by ID\n");
    printf("3. Quit\n");
    scanf("%d", &option);

    // Perform the operation based on the user's choice
    switch(option) {
        case 1:
            // Print all records
            printf("\nPrinting all records...\n");
            for(int i=0; i<num_records; i++) {
                printf("ID: %d\t Name: %s\n", records[i].id, records[i].name);
            }
            break;

        case 2:
            // Search for a record by ID
            int search_id, found = 0;
            printf("\nEnter the ID you want to search: ");
            scanf("%d", &search_id);
            for(int i=0; i<num_records; i++) {
                if(records[i].id == search_id) {
                    found = 1;
                    printf("Record found! Name: %s\n", records[i].name);
                    break;
                }
            }
            if(found == 0) {
                printf("Record not found!\n");
            }
            break;

        case 3:
            // Quit the program
            printf("\nQuitting the program...\n");
            break;

        default:
            // Handle invalid input
            printf("\nInvalid option! Please choose a valid option.\n");
            break;
    }

    // Free the memory allocated for the records
    free(records);

    return 0;
}