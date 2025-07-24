//FormAI DATASET v1.0 Category: Phone Book ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PhoneBook {
    char name[50];
    char phoneNumber[20];
};

int main() {
    int numContacts;
    printf("How many contacts would you like to add to your phone book? ");
    scanf("%d", &numContacts);
    getchar();

    struct PhoneBook contacts[numContacts];

    for(int i = 0; i < numContacts; i++) {
        printf("Enter name for contact %d: ", i+1);
        fgets(contacts[i].name, sizeof(contacts[i].name), stdin);
        contacts[i].name[strcspn(contacts[i].name, "\n")] = 0; // removes newline character from input

        printf("Enter phone number for contact %d: ", i+1);
        fgets(contacts[i].phoneNumber, sizeof(contacts[i].phoneNumber), stdin);
        contacts[i].phoneNumber[strcspn(contacts[i].phoneNumber, "\n")] = 0; // removes newline character from input

        printf("\n");
    }

    printf("Your phone book has %d contacts:\n\n", numContacts);
    for(int i = 0; i < numContacts; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone Number: %s\n\n", contacts[i].phoneNumber);
    }

    return 0;
}