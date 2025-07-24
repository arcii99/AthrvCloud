//FormAI DATASET v1.0 Category: Mailing list manager ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 20
#define MAX_LIST_LENGTH 1000

struct Email {
    char email[MAX_EMAIL_LENGTH];
    char name[MAX_NAME_LENGTH];
};

struct MailingList {
    char name[MAX_NAME_LENGTH];
    struct Email emails[MAX_LIST_LENGTH];
    int count;
};

void addEmail(struct MailingList* list, char* name, char* email) {
    if (list->count == MAX_LIST_LENGTH) {
        printf("Error: Mailing list is full\n");
        return;
    }

    struct Email newEmail;
    strcpy(newEmail.email, email);
    strcpy(newEmail.name, name);

    list->emails[list->count++] = newEmail;
}

void printList(struct MailingList* list) {
    printf("Mailing list for %s:\n", list->name);

    for (int i = 0; i < list->count; i++) {
        printf("%s: %s\n", list->emails[i].name, list->emails[i].email);
    }
}

int main() {
    struct MailingList newList;
    strcpy(newList.name, "Newsletter");

    addEmail(&newList, "John", "john@example.com");
    addEmail(&newList, "Jane", "jane@example.com");

    printList(&newList);

    return 0;
}