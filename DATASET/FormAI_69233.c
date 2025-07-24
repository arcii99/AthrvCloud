//FormAI DATASET v1.0 Category: Mailing list manager ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAILS 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Person;

typedef struct {
    Person people[MAX_EMAILS];
    int count;
} MailingList;

void addPerson(MailingList *list, char *name, char *email) {
    if (list->count < MAX_EMAILS) {
        strcpy(list->people[list->count].name, name);
        strcpy(list->people[list->count].email, email);
        list->count++;
        printf("%s added successfully.\n", name);
    } else {
        printf("Mailing list is full. Could not add %s.\n", name);
    }
}

void printList(MailingList *list) {
    printf("Mailing List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%s (%s)\n", list->people[i].name, list->people[i].email);
    }
}

int main() {
    MailingList list = {.count = 0};
    int option;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    while (1) {
        printf("Menu\n");
        printf("1. Add person to mailing list\n");
        printf("2. Print mailing list\n");
        printf("3. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                addPerson(&list, name, email);
                break;
            case 2:
                printList(&list);
                break;
            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}