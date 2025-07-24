//FormAI DATASET v1.0 Category: Mailing list manager ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 50

struct Email {
    char* name;
    char* email;
};

struct MailingList {
    struct Email emails[MAX_EMAILS];
    int numEmails;
};

struct MailingList createList()
{
    struct MailingList list;
    list.numEmails = 0;
    return list;
}

void addEmail(struct MailingList* list, struct Email email)
{
    if (list->numEmails < MAX_EMAILS) {
        struct Email* emailPtr = &(list->emails[list->numEmails]);
        emailPtr->name = (char*)malloc(sizeof(char) * (strlen(email.name) + 1));
        emailPtr->email = (char*)malloc(sizeof(char) * (strlen(email.email) + 1));
        strcpy(emailPtr->name, email.name);
        strcpy(emailPtr->email, email.email);
        list->numEmails++;
        printf("Added email for %s (%s)\n", email.name, email.email);
    }
}

void printList(struct MailingList list)
{
    printf("---Mailing List---\n");
    for (int i = 0; i < list.numEmails; i++) {
        printf("%s: %s\n", list.emails[i].name, list.emails[i].email);
    }
}

int main()
{
    struct MailingList list = createList();

    struct Email email1 = {"John Smith", "johnsmith@example.com"};
    struct Email email2 = {"Jane Doe", "janedoe@example.com"};

    addEmail(&list, email1);
    addEmail(&list, email2);

    printList(list);

    return 0;
}