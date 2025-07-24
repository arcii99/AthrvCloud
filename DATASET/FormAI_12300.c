//FormAI DATASET v1.0 Category: Mailing list manager ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

Contact mailingList[MAX_EMAILS];
int numContacts = 0;

void addContact(char *name, char *email) {
    if (numContacts >= MAX_EMAILS) {
        printf("Mailing list is full\n");
        return;
    }
    strncpy(mailingList[numContacts].name, name, MAX_NAME_LEN);
    strncpy(mailingList[numContacts].email, email, MAX_EMAIL_LEN);
    numContacts++;
    printf("%s added to the mailing list\n", name);
}

void removeContact(char *name) {
    int i, j;
    for (i = 0; i < numContacts; i++) {
        if (strcmp(mailingList[i].name, name) == 0) {
            printf("%s removed from the mailing list\n", name);
            for (j = i; j < numContacts - 1; j++) {
                strncpy(mailingList[j].name, mailingList[j+1].name, MAX_NAME_LEN);
                strncpy(mailingList[j].email, mailingList[j+1].email, MAX_EMAIL_LEN);
            }
            numContacts--;
            return;
        }
    }
    printf("%s not found in the mailing list\n", name);
}

void printList() {
    int i;
    printf("Mailing list:\n");
    for (i = 0; i < numContacts; i++) {
        printf("%s: %s\n", mailingList[i].name, mailingList[i].email);
    }
}

int main() {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char command[10];
    while (1) {
        printf("Enter a command (add, remove, print, quit): ");
        fgets(command, 10, stdin);
        if (strcmp(command, "add\n") == 0) {
            printf("Enter name: ");
            fgets(name, MAX_NAME_LEN, stdin);
            printf("Enter email: ");
            fgets(email, MAX_EMAIL_LEN, stdin);
            addContact(name, email);
        } else if (strcmp(command, "remove\n") == 0) {
            printf("Enter name: ");
            fgets(name, MAX_NAME_LEN, stdin);
            removeContact(name);
        } else if (strcmp(command, "print\n") == 0) {
            printList();
        } else if (strcmp(command, "quit\n") == 0) {
            return 0;
        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}