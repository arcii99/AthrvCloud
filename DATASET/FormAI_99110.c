//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 50
#define MAX_LIST_SIZE 50

typedef struct {
    char email[MAX_EMAIL_LENGTH];
    char name[MAX_NAME_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_LIST_SIZE];
    int size;
} MailingList;

MailingList createMailingList() {
    MailingList mailingList;
    mailingList.size = 0;
    return mailingList;
}

void addContact(MailingList *mailingList, char *email, char *name) {
    if (mailingList->size >= MAX_LIST_SIZE) {
        printf("Mailing list is full.");
        return;
    }

    Contact contact;
    strcpy(contact.email, email);
    strcpy(contact.name, name);

    mailingList->contacts[mailingList->size++] = contact;
}

void removeContact(MailingList *mailingList, char *email) {
    for (int i = 0; i < mailingList->size; i++) {
        if (strcmp(mailingList->contacts[i].email, email) == 0) {
            for (int j = i; j < mailingList->size - 1; j++) {
                mailingList->contacts[j] = mailingList->contacts[j + 1];
            }
            mailingList->size--;
            return;
        }
    }

    printf("Contact not found.");
}

void printContacts(MailingList mailingList) {
    for (int i = 0; i < mailingList.size; i++) {
        printf("%s, %s\n", mailingList.contacts[i].name, mailingList.contacts[i].email);
    }
}

void saveMailingList(MailingList mailingList, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error saving file.");
        return;
    }

    for (int i = 0; i < mailingList.size; i++) {
        fprintf(file, "%s %s\n", mailingList.contacts[i].email, mailingList.contacts[i].name);
    }

    fclose(file);
}

MailingList loadMailingList(char *filename) {
    MailingList mailingList = createMailingList();
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading file.");
        return mailingList;
    }

    char email[MAX_EMAIL_LENGTH];
    char name[MAX_NAME_LENGTH];

    while (fscanf(file, "%s %s", email, name) != EOF) {
        addContact(&mailingList, email, name);
    }

    fclose(file);

    return mailingList;
}

int main() {
    MailingList mailingList = createMailingList();

    addContact(&mailingList, "test1@example.com", "John Doe");
    addContact(&mailingList, "test2@example.com", "Jane Smith");
    addContact(&mailingList, "test3@example.com", "Bob Johnson");

    removeContact(&mailingList, "test2@example.com");

    printContacts(mailingList);

    saveMailingList(mailingList, "mailing_list.txt");

    MailingList loadedList = loadMailingList("mailing_list.txt");

    printf("\nLoaded Mailing List:\n");
    printContacts(loadedList);

    return 0;
}