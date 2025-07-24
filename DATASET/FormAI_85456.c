//FormAI DATASET v1.0 Category: Mailing list manager ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

struct Email {
    char address[MAX_EMAIL_LENGTH];
    struct Email *next;
};

struct Contact {
    char name[MAX_NAME_LENGTH];
    struct Email *email_list;
    struct Contact *next;
};

struct Email *new_email(char *address);
void add_email(struct Contact *contact, char *address);
int remove_email(struct Contact *contact, char *address);
void add_contact(struct Contact **list, char *name, char *address);
int remove_contact(struct Contact **list, char *name);
void print_contacts(struct Contact *list);

int main() {
    struct Contact *list = NULL;
    add_contact(&list, "John Doe", "johndoe@example.com");
    add_email(list, "johndoe@gmail.com");
    remove_email(list, "johndoe@example.com");
    remove_contact(&list, "John Doe");
    print_contacts(list);
    return 0;
}

struct Email *new_email(char *address) {
    struct Email *email = malloc(sizeof(struct Email));
    if (email == NULL) {
        printf("Cannot allocate memory for email\n");
        exit(1);
    }
    strcpy(email->address, address);
    email->next = NULL;
    return email;
}

void add_email(struct Contact *contact, char *address) {
    struct Email *email = new_email(address);
    if (contact->email_list == NULL) {
        contact->email_list = email;
    } else {
        struct Email *curr = contact->email_list;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = email;
    }
}

int remove_email(struct Contact *contact, char *address) {
    struct Email *curr = contact->email_list;
    struct Email *prev = NULL;
    while (curr != NULL) {
        if (strcmp(curr->address, address) == 0) {
            if (prev == NULL) {
                contact->email_list = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            return 1;
        }
        prev = curr;
        curr = curr->next;
    }
    return 0;
}

void add_contact(struct Contact **list, char *name, char *address) {
    struct Contact *contact = malloc(sizeof(struct Contact));
    if (contact == NULL) {
        printf("Cannot allocate memory for contact\n");
        exit(1);
    }
    strcpy(contact->name, name);
    contact->email_list = new_email(address);
    contact->next = *list;
    *list = contact;
}

int remove_contact(struct Contact **list, char *name) {
    struct Contact *curr = *list;
    struct Contact *prev = NULL;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            if (prev == NULL) {
                *list = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            return 1;
        }
        prev = curr;
        curr = curr->next;
    }
    return 0;
}

void print_contacts(struct Contact *list) {
    while (list != NULL) {
        printf("%s\n", list->name);
        struct Email *email = list->email_list;
        while (email != NULL) {
            printf("\t%s\n", email->address);
            email = email->next;
        }
        list = list->next;
    }
}