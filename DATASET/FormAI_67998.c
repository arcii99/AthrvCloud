//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum input length for the user's name
#define MAX_NAME_LENGTH 50

// Define the maximum number of records that the fitness tracker can hold
#define MAX_RECORDS 1000

// Define the fitness record struct
typedef struct {
    char name[MAX_NAME_LENGTH];
    float weight;
    float height;
    float bmi;
} FitnessRecord;

// Define the function to calculate the BMI
float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

// Define the main function
int main() {
    // Create the array to hold the fitness records
    FitnessRecord records[MAX_RECORDS];

    // Create a counter variable to keep track of the number of records
    int counter = 0;

    // Create a variable to hold the user's choice
    int choice = 0;

    // Loop through the menu until the user chooses to exit
    while (choice != 4) {
        printf("\nFitness Tracker\n");
        printf("---------------\n");
        printf("1. Add a new record\n");
        printf("2. View all records\n");
        printf("3. Search for a record\n");
        printf("4. Exit\n");

        // Get the user's choice
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Handle the user's choice
        switch (choice) {
            case 1:
                // Add a new record

                // Get the user's name
                printf("\nEnter your name: ");
                scanf("%s", records[counter].name);

                // Get the user's weight
                printf("\nEnter your weight in kg: ");
                scanf("%f", &records[counter].weight);

                // Get the user's height
                printf("\nEnter your height in m: ");
                scanf("%f", &records[counter].height);

                // Calculate the BMI
                records[counter].bmi = calculateBMI(records[counter].weight, records[counter].height);

                // Increment the counter
                counter++;

                // Print a success message
                printf("\nRecord added successfully!\n");
                break;
            case 2:
                // View all records

                // Print the header
                printf("\nAll Records\n");
                printf("------------\n");

                // Loop through all the records and print them
                for (int i = 0; i < counter; i++) {
                    printf("Name: %s\n", records[i].name);
                    printf("Weight: %.2f kg\n", records[i].weight);
                    printf("Height: %.2f m\n", records[i].height);
                    printf("BMI: %.2f\n\n", records[i].bmi);
                }

                // Print the footer
                printf("Total Records: %d\n", counter);
                break;
            case 3:
                // Search for a record

                // Get the user's search term
                char searchTerm[MAX_NAME_LENGTH];
                printf("\nEnter a name to search for: ");
                scanf("%s", searchTerm);

                // Loop through all the records and find the matching ones
                int matches = 0;
                for (int i = 0; i < counter; i++) {
                    if (strcmp(records[i].name, searchTerm) == 0) {
                        // Print the matching record
                        printf("\nMatching Record\n");
                        printf("----------------\n");
                        printf("Name: %s\n", records[i].name);
                        printf("Weight: %.2f kg\n", records[i].weight);
                        printf("Height: %.2f m\n", records[i].height);
                        printf("BMI: %.2f\n", records[i].bmi);
                        matches++;
                    }
                }

                // Print the number of matches
                printf("\n%d record(s) found.\n", matches);
                break;
            case 4:
                // Exit the program
                printf("\nGoodbye!\n");
                break;
            default:
                // Invalid choice
                printf("\nInvalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}