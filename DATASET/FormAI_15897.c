//FormAI DATASET v1.0 Category: Database simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a struct to represent a fictional dataset
typedef struct {
    int id;
    char name[50];
    int value;
} Dataset;

// Define an array of fictional datasets to simulate a database
Dataset database[10];

// Define a function to add a new dataset to the array
void add_data() {
    // Prompt the user for information about the new dataset
    printf("Enter the ID: ");
    int id;
    scanf("%d", &id);

    printf("Enter the name: ");
    char name[50];
    scanf("%s", name);

    printf("Enter the value: ");
    int value;
    scanf("%d", &value);

    // Create a new dataset with the provided information
    Dataset new_data = { id, name, value };

    // Add the new dataset to the array
    for (int i = 0; i < 10; i++) {
        if (database[i].id == 0) {
            database[i] = new_data;
            printf("Dataset added successfully!\n");
            return;
        }
    }

    // If the array is full, display an error message
    printf("Error: Database is full!\n");
}

// Define a function to delete a dataset from the array
void delete_data() {
    // Prompt the user for the ID of the dataset to delete
    printf("Enter the ID of the dataset to delete: ");
    int id;
    scanf("%d", &id);

    // Search the array for the dataset with the provided ID
    for (int i = 0; i < 10; i++) {
        if (database[i].id == id) {
            // If the dataset is found, remove it from the array
            database[i].id = 0;
            memset(database[i].name, 0, sizeof(database[i].name));
            database[i].value = 0;
            printf("Dataset deleted successfully!\n");
            return;
        }
    }

    // If the dataset is not found, display an error message
    printf("Error: Dataset with ID %d not found!\n", id);
}

// Define a function to print all datasets in the array
void print_data() {
    printf("ID\tName\tValue\n");
    printf("--\t----\t-----\n");
    for (int i = 0; i < 10; i++) {
        if (database[i].id != 0) {
            printf("%d\t%s\t%d\n", database[i].id, database[i].name, database[i].value);
        }
    }
}

int main() {
    // Set up the random number generator
    srand(time(NULL));

    // Initialize the array with random data
    for (int i = 0; i < 10; i++) {
        database[i].id = (i + 1) * 100;
        sprintf(database[i].name, "Data%d", i + 1);
        database[i].value = rand() % 100;
    }

    // Main loop
    while (1) {
        // Prompt the user for a command
        printf("Enter a command (add, delete, print, quit): ");
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            // If the command is "add", call the add_data function
            add_data();
        } else if (strcmp(command, "delete") == 0) {
            // If the command is "delete", call the delete_data function
            delete_data();
        } else if (strcmp(command, "print") == 0) {
            // If the command is "print", call the print_data function
            print_data();
        } else if (strcmp(command, "quit") == 0) {
            // If the command is "quit", exit the program
            printf("Goodbye!\n");
            return 0;
        } else {
            // If the command is invalid, display an error message
            printf("Error: Invalid command!\n");
        }
    }
}