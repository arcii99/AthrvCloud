//FormAI DATASET v1.0 Category: Mailing list manager ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 20
#define MAX_NAME_LENGTH 30
#define MAX_EMAIL_LENGTH 50

struct Person {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

struct MailingList {
    struct Person *recipients;
    int numRecipients;
};

void printMailingList(struct MailingList *list) {
    printf("Mailing List:\n");
    for (int i = 0; i < list->numRecipients; i++) {
        printf("%s: %s\n", list->recipients[i].name, list->recipients[i].email);
    }
}

void addRecipient(struct MailingList *list, char *name, char *email) {
    if (list->numRecipients == MAX_EMAILS) {
        printf("Error: Mailing list full\n");
        return;
    }
    struct Person recipient;
    strncpy(recipient.name, name, MAX_NAME_LENGTH);
    strncpy(recipient.email, email, MAX_EMAIL_LENGTH);
    list->recipients[list->numRecipients] = recipient;
    list->numRecipients++;
}

void removeRecipient(struct MailingList *list, char *name, char *email) {
    for (int i = 0; i < list->numRecipients; i++) {
        if (strcmp(list->recipients[i].name, name) == 0 && strcmp(list->recipients[i].email, email) == 0) {
            for (int j = i; j < list->numRecipients - 1; j++) {
                list->recipients[j] = list->recipients[j + 1];
            }
            list->numRecipients--;
            return;
        }
    }
    printf("Error: Recipient not found\n");
}

int main() {
    struct MailingList list;
    list.recipients = malloc(sizeof(struct Person) * MAX_EMAILS);
    list.numRecipients = 0;

    addRecipient(&list, "John", "john@example.com");
    addRecipient(&list, "Jane", "jane@example.com");
    addRecipient(&list, "Jack", "jack@example.com");
    printMailingList(&list);

    removeRecipient(&list, "Jane", "jane@example.com");
    printMailingList(&list);

    free(list.recipients);
    return 0;
}