//FormAI DATASET v1.0 Category: Mailing list manager ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define struct for mailing list
typedef struct {
    char name[50];
    char email[50];
} MailingList;

int main() {
    int numContacts = 0; // initialize number of contacts to 0
    MailingList *mailList = NULL; // initialize mailing list pointer to null

    while(1) {
        printf("Enter 1 to add a contact, 2 to view all contacts, or 3 to exit: ");
        int choice;
        scanf("%d", &choice);

        if(choice == 1) {
            numContacts++; // increment number of contacts
            mailList = realloc(mailList, numContacts*sizeof(MailingList)); // reallocate memory for mailing list

            printf("Enter name: ");
            scanf("%s", mailList[numContacts-1].name);
            printf("Enter email: ");
            scanf("%s", mailList[numContacts-1].email);
         }
         else if(choice == 2) {
            printf("\nMailing List:\n");
            for(int i=0; i<numContacts; i++) {
                printf("Name: %s\nEmail: %s\n\n", mailList[i].name, mailList[i].email);
            }
         }
         else if(choice == 3) {
             printf("Exiting program...");
             break;
         }
         else {
            printf("Invalid choice. Please try again.\n");
         }
    }

    free(mailList); // free allocated memory
    return 0;
}