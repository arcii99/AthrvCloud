//FormAI DATASET v1.0 Category: Phone Book ; Style: Sherlock Holmes
// The Adventure of the C Phone Book

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare variables
    char fileName[30];
    char searchName[30];
    int option, count = 0;
    FILE *file;
    
    // Display introductory message
    printf("Welcome to the C Phone Book!\n");
    printf("Enter the name of the file to access: ");
    scanf("%s", fileName);
    
    // Open the file and check for errors
    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("There was an error opening the file.\n");
        exit(1);
    }
    
    // Display a menu of options
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Search for a name\n");
        printf("2. Add a new contact\n");
        printf("3. Delete a contact\n");
        printf("4. Print all contacts\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        // Handle user input
        switch(option) {
            case 1: // Search for a contact
                printf("\nEnter the name to search for: ");
                scanf("%s", searchName);
                rewind(file); // Move file pointer to beginning
                while(!feof(file)) { // Search through entire file
                    char name[30], phone[30], email[30];
                    fscanf(file, "%s %s %s", name, phone, email); // Read data from file
                    if(strcmp(name, searchName) == 0) { // If name matches
                        printf("%s's phone number is %s and email is %s\n", name, phone, email);
                        count++; // Increase count of matches
                        break;
                    }
                }
                if (count == 0) { // If no match was found
                    printf("No contact found with name %s.\n", searchName);
                }
                count = 0; // Reset count
                break;
            case 2: // Add a new contact
                printf("\nEnter the name of the new contact: ");
                scanf("%s", searchName);
                rewind(file);
                while(!feof(file)) { // Check if contact already exists
                    char name[30], phone[30], email[30];
                    fscanf(file, "%s %s %s", name, phone, email);
                    if(strcmp(name, searchName) == 0) {
                        printf("A contact with the name %s already exists.\n", searchName);
                        break;
                    }
                }
                if(feof(file)) { // If name is unique, add contact to file
                    char phone[30], email[30];
                    printf("Enter %s's phone number: ", searchName);
                    scanf("%s", phone);
                    printf("Enter %s's email address: ", searchName);
                    scanf("%s", email);
                    fprintf(file, "%s %s %s\n", searchName, phone, email);
                    printf("%s has been added to the phone book.\n", searchName);
                }
                break;
            case 3: // Delete a contact
                char tempFile[30];
                printf("\nEnter the name of the contact to delete: ");
                scanf("%s", searchName);
                sprintf(tempFile, "%s.tmp", fileName); // Create temporary file
                FILE *temp = fopen(tempFile, "w");
                rewind(file);
                while(!feof(file)) {
                    char name[30], phone[30], email[30];
                    fscanf(file, "%s %s %s", name, phone, email);
                    if(strcmp(name, searchName) != 0) { // Copy all contacts except the one to delete to temp file
                        fprintf(temp, "%s %s %s\n", name, phone, email);
                    } else {
                        printf("%s has been deleted from the phone book.\n", name);
                    }
                }
                fclose(file);
                fclose(temp);
                remove(fileName); // Delete old file
                rename(tempFile, fileName); // Rename temp file to old file name
                file = fopen(fileName, "r"); // Reopen the file for reading
                break;
            case 4: // Print all contacts
                rewind(file);
                printf("\nThe contacts in the phone book are:\n");
                while(!feof(file)) {
                    char name[30], phone[30], email[30];
                    fscanf(file, "%s %s %s", name, phone, email);
                    printf("%s - %s - %s\n", name, phone, email);
                }
                break;
            case 5: // Quit the program
                printf("\nGoodbye!\n");
                break;
            default: // Invalid input
                printf("\nInvalid input. Please try again.\n");
        }
    } while(option != 5); // Continue until user chooses to quit
    
    fclose(file); // Close the file
    return 0;
}