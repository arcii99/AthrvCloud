//FormAI DATASET v1.0 Category: Phone Book ; Style: cheerful
#include <stdio.h>
#include <string.h>

struct Contact {
    char name[20];
    char phoneNum[15];
};

int main() {
    printf("Welcome to the Cheerful Phone Book!\n\n");

    // Initialize an array of 100 contacts
    struct Contact phoneBook[100];
    int numContacts = 0;

    // Prompt the user for input
    char choice = 'a';
    while (choice != 'q') {
        printf("Enter 'a' to add a contact, 'l' to list all contacts, or 'q' to quit: ");
        scanf("%c", &choice);
        getchar(); //remove the new line character from input buffer

        if (choice == 'a') {
            printf("\nEnter the name of the contact: ");
            fgets(phoneBook[numContacts].name, 20, stdin);
            printf("Enter the phone number of the contact: ");
            fgets(phoneBook[numContacts].phoneNum, 15, stdin);
            numContacts++;
            printf("The contact has successfully been added to the Phone Book!\n\n");
        }
        else if (choice == 'l') {
            printf("\nHere are all your contacts: \n");
            for (int i = 0; i < numContacts; i++) {
                printf("%d. Name: %s Phone Number: %s\n", i+1, phoneBook[i].name, phoneBook[i].phoneNum);
            }
            printf("\n");
        }
        else if (choice == 'q') {
            printf("\nThank you for using the Cheerful Phone Book. Have a nice day!\n");
        }
        else {
            printf("\nThat choice is not valid. Please try again.\n\n");
        }
    }

    return 0;
}