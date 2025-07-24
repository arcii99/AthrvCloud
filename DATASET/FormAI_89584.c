//FormAI DATASET v1.0 Category: Mailing list manager ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the structure of the mailing list entries
typedef struct {
    char name[50];
    char email[100];
} MailingListEntry;

// define the structure of the mailing list
typedef struct {
    int size;
    MailingListEntry *entries;
} MailingList;

// function that adds an entry to the mailing list
void addEntry(MailingList *list, char *name, char* email) {
    // allocate memory for the new entry
    MailingListEntry *newEntry = (MailingListEntry*)malloc(sizeof(MailingListEntry));
    // copy the name and email strings into the new entry
    strcpy(newEntry->name, name);
    strcpy(newEntry->email, email);
    // increase the size of the mailing list
    list->size++;
    // reallocate memory for the entries array
    list->entries = (MailingListEntry*)realloc(list->entries, list->size * sizeof(MailingListEntry));
    // add the new entry to the end of the entries array
    list->entries[list->size-1] = *newEntry;
}

// function that removes an entry from the mailing list
void removeEntry(MailingList *list, char *email) {
    int i;
    for(i = 0; i < list->size; i++) {
        // if the email matches, remove the entry
        if(strcmp(list->entries[i].email, email) == 0) {
            // move all the entries after the removed entry back by one position
            for(int j = i; j < list->size-1; j++) {
                list->entries[j] = list->entries[j+1];
            }
            // decrease the size of the mailing list
            list->size--;
            // reallocate memory for the entries array
            list->entries = (MailingListEntry*)realloc(list->entries, list->size * sizeof(MailingListEntry));
            // break out of the loop as we have found and removed the entry
            break;
        }
    }
}

// function that prints all the entries in the mailing list
void printList(MailingList *list) {
    int i;
    printf("Mailing List Contents:\n");
    for(i = 0; i < list->size; i++) {
        printf("%s <%s>\n", list->entries[i].name, list->entries[i].email);
    }
}

int main() {
    int choice;
    MailingList list = {0, NULL};

    while(1) {
        printf("\nEnter a choice:\n");
        printf("1: Add Entry\n");
        printf("2: Remove Entry\n");
        printf("3: Print List\n");
        printf("4: Exit\n");
        scanf("%d", &choice);
        getchar();  // consume the newline character from the scanf input buffer

        switch(choice) {
            case 1:
                // add a new entry to the mailing list
                char name[50], email[100];
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';  // remove the trailing newline character added by fgets
                printf("Enter Email: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = '\0';  // remove the trailing newline character added by fgets
                addEntry(&list, name, email);
                printf("Entry added to mailing list.\n");
                break;
            case 2:
                // remove an entry from the mailing list
                char removeEmail[100];
                printf("Enter Email: ");
                fgets(removeEmail, sizeof(removeEmail), stdin);
                removeEmail[strcspn(removeEmail, "\n")] = '\0';  // remove the trailing newline character added by fgets
                removeEntry(&list, removeEmail);
                printf("Entry removed from mailing list.\n");
                break;
            case 3:
                // print all the entries in the mailing list
                printList(&list);
                break;
            case 4:
                // exit the program
                printf("Exiting program...\n");
                exit(0);
            default:
                // invalid choice
                printf("Invalid choice.\n");
        }
    }

    return 0;
}