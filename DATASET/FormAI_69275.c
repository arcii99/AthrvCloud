//FormAI DATASET v1.0 Category: Phone Book ; Style: happy
#include <stdio.h>
#include <string.h>

typedef struct contact {
    char name[50];
    char number[20];
    char email[100];
} Contact;

int main() {
    Contact phonebook[1000];
    int numContacts = 0;
    char input[10];

    printf("Welcome to the Happy Phone Book!\n");

    int running = 1;
    while(running) {
        printf("\n-------------------\n");
        printf("What would you like to do?\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. List all contacts\n");
        printf("4. Delete a contact\n");
        printf("5. Exit\n");
        printf("-------------------\n");
        fgets(input, 10, stdin);

        switch(input[0]) {
            case '1': // Add a contact
                printf("Enter the name of the contact: ");
                fgets(phonebook[numContacts].name, 50, stdin);
                phonebook[numContacts].name[strcspn(phonebook[numContacts].name, "\n")] = 0;

                printf("Enter the phone number of the contact: ");
                fgets(phonebook[numContacts].number, 20, stdin);
                phonebook[numContacts].number[strcspn(phonebook[numContacts].number, "\n")] = 0;

                printf("Enter the email address of the contact: ");
                fgets(phonebook[numContacts].email, 100, stdin);
                phonebook[numContacts].email[strcspn(phonebook[numContacts].email, "\n")] = 0;

                printf("Contact added successfully!\n");
                numContacts++;
                break;

            case '2': // Search for a contact
                printf("Enter the name of the contact to search for: ");
                char searchName[50];
                fgets(searchName, 50, stdin);
                searchName[strcspn(searchName, "\n")] = 0;

                int contactFound = 0;
                for(int i = 0; i < numContacts; i++) {
                    if(strcmp(searchName, phonebook[i].name) == 0) {
                        printf("Contact found:\n");
                        printf("Name: %s\n", phonebook[i].name);
                        printf("Phone number: %s\n", phonebook[i].number);
                        printf("Email address: %s\n", phonebook[i].email);
                        contactFound = 1;
                        break;
                    }
                }

                if(!contactFound) {
                    printf("Contact not found.\n");
                }

                break;

            case '3': // List all contacts
                if(numContacts == 0) {
                    printf("No contacts to display.\n");
                } else {
                    printf("All contacts:\n");
                    for(int i = 0; i < numContacts; i++) {
                        printf("%s | %s | %s\n", phonebook[i].name, phonebook[i].number, phonebook[i].email);
                    }
                }

                break;

            case '4': // Delete a contact
                printf("Enter the name of the contact to delete: ");
                char deleteName[50];
                fgets(deleteName, 50, stdin);
                deleteName[strcspn(deleteName, "\n")] = 0;

                int contactDeleted = 0;
                for(int i = 0; i < numContacts; i++) {
                    if(strcmp(deleteName, phonebook[i].name) == 0) {
                        for(int j = i; j < numContacts - 1; j++) {
                            phonebook[j] = phonebook[j + 1];
                        }
                        numContacts--;
                        printf("Contact deleted.\n");
                        contactDeleted = 1;
                        break;
                    }
                }

                if(!contactDeleted) {
                    printf("Contact not found.\n");
                }

                break;

            case '5': // Exit program
                running = 0;
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid input.\n");
                break;
        }
    }

    return 0;
}