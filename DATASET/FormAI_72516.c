//FormAI DATASET v1.0 Category: Phone Book ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
#define PASSWORD "MySecurePassword"

struct Contact {
    char name[MAX];
    char phone[MAX];
};

int main() {
    struct Contact phoneBook[MAX];
    int numContacts = 0;
    char passwordInput[MAX];

    printf("Welcome to the Phone Book Program!\n");
    printf("Please enter the password: ");
    fgets(passwordInput, MAX, stdin);
    passwordInput[strcspn(passwordInput, "\n")] = 0;

    if(strcmp(passwordInput, PASSWORD) != 0) {
        printf("Incorrect password. Exiting program.\n");
        return 0;
    }

    printf("Password accepted. You may now use the program.\n");

    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a contact\n");
        printf("2. Delete a contact\n");
        printf("3. View all contacts\n");
        printf("4. Search for a contact by name\n");
        printf("5. Exit program\n");

        int choice;
        scanf("%d", &choice);
        getchar(); // clear input buffer

        switch(choice) {
            case 1: {
                printf("\nEnter the contact name: ");
                fgets(phoneBook[numContacts].name, MAX, stdin);
                phoneBook[numContacts].name[strcspn(phoneBook[numContacts].name, "\n")] = 0;

                printf("Enter the phone number: ");
                fgets(phoneBook[numContacts].phone, MAX, stdin);
                phoneBook[numContacts].phone[strcspn(phoneBook[numContacts].phone, "\n")] = 0;

                printf("Contact added successfully.\n");
                numContacts++;
                break;
            }
            case 2: {
                char nameToDelete[MAX];
                printf("\nEnter the name of the contact you wish to delete: ");
                fgets(nameToDelete, MAX, stdin);
                nameToDelete[strcspn(nameToDelete, "\n")] = 0;

                int foundIndex = -1;
                for(int i = 0; i < numContacts; i++) {
                    if(strcmp(phoneBook[i].name, nameToDelete) == 0) {
                        foundIndex = i;
                        break;
                    }
                }

                if(foundIndex == -1) {
                    printf("Contact not found.\n");
                } else {
                    for(int i = foundIndex; i < numContacts - 1; i++) {
                        phoneBook[i] = phoneBook[i+1];
                    }
                    numContacts--;
                    printf("Contact deleted successfully.\n");
                }
                break;
            }
            case 3:
                if(numContacts == 0) {
                    printf("\nNo contacts to display.\n");
                    break;
                }
                printf("\n------All Contacts------\n");
                for(int i = 0; i < numContacts; i++) {
                    printf("\nName: %s\n", phoneBook[i].name);
                    printf("Phone: %s\n", phoneBook[i].phone);
                }
                break;
            case 4: {
                char nameToFind[MAX];
                printf("\nEnter the name of the contact you wish to find: ");
                fgets(nameToFind, MAX, stdin);
                nameToFind[strcspn(nameToFind, "\n")] = 0;

                int foundIndex = -1;
                for(int i = 0; i < numContacts; i++) {
                    if(strcmp(phoneBook[i].name, nameToFind) == 0) {
                        foundIndex = i;
                        break;
                    }
                }

                if(foundIndex == -1) {
                    printf("Contact not found.\n");
                } else {
                    printf("\nName: %s\n", phoneBook[foundIndex].name);
                    printf("Phone: %s\n", phoneBook[foundIndex].phone);
                }
                break;
            }
            case 5:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}