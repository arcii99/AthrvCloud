//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    int size;
    Contact* contacts;
} MailingList;

void initMailingList(MailingList* list) {
    list->size = 0;
    list->contacts = NULL;
}

void addContact(MailingList* list, const char* name, const char* email) {
    if (list->contacts == NULL) {
        list->contacts = (Contact*) malloc(sizeof(Contact));
    } else {
        list->contacts = (Contact*) realloc(list->contacts, (list->size + 1) * sizeof(Contact));
    }
    snprintf(list->contacts[list->size].name, MAX_NAME_LENGTH, "%s", name);
    snprintf(list->contacts[list->size].email, MAX_EMAIL_LENGTH, "%s", email);
    list->size++;
}

void removeContact(MailingList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index!\n");
        return;
    }
    for (int i = index; i < list->size - 1; i++) {
        list->contacts[i] = list->contacts[i + 1];
    }
    list->size--;
    list->contacts = (Contact*) realloc(list->contacts, list->size * sizeof(Contact));
}

void printContacts(MailingList* list) {
    printf("Contacts:\n");
    for (int i = 0; i < list->size; i++) {
        printf("%d. %s <%s>\n", i + 1, list->contacts[i].name, list->contacts[i].email);
    }
}

int main() {
    MailingList list;
    initMailingList(&list);
    addContact(&list, "John Doe", "john.doe@example.com");
    addContact(&list, "Jane Doe", "jane.doe@example.com");
    addContact(&list, "Bob Smith", "bob.smith@example.com");
    printContacts(&list);
    removeContact(&list, 1);
    printContacts(&list);
    return 0;
}