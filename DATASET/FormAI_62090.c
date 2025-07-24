//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 50
#define MAX_EMAIL_SIZE 100

typedef struct {
    char name[MAX_NAME_SIZE];
    char email[MAX_EMAIL_SIZE];
} Contact;

typedef struct {
    Contact *contacts;
    int num_contacts;
} AddressBook;

void parse_xml(AddressBook *address_book, char *xml) {
    char *start, *end;
    char name[MAX_NAME_SIZE];
    char email[MAX_EMAIL_SIZE];
    
    start = strstr(xml, "<contact>");
    while (start != NULL) {
        end = strstr(start, "</contact>");
        if (end == NULL) {
            printf("Error: Could not find end tag for contact.\n");
            exit(1);
        }
        memcpy(name, start + strlen("<contact><name>"), MAX_NAME_SIZE);
        name[strcspn(name, "</name>")] = '\0';
        memcpy(email, start + strlen("<email>"), MAX_EMAIL_SIZE);
        email[strcspn(email, "</email>")] = '\0';
        Contact contact = {0};
        strncpy(contact.name, name, MAX_NAME_SIZE);
        strncpy(contact.email, email, MAX_EMAIL_SIZE);
        address_book->contacts[address_book->num_contacts++] = contact;
        start = strstr(end + strlen("</contact>"), "<contact>");
    }
}

int main() {
    char *xml = "<address_book><contact><name>John Doe</name><email>john.doe@example.com</email></contact><contact><name>Jane Smith</name><email>jane.smith@example.com</email></contact></address_book>";
    AddressBook address_book = {0};
    address_book.contacts = malloc(sizeof(Contact) * 10);
    parse_xml(&address_book, xml);
    for (int i = 0; i < address_book.num_contacts; i++) {
        printf("Name: %s\nEmail: %s\n", address_book.contacts[i].name, address_book.contacts[i].email);
    }
    free(address_book.contacts);
    return 0;
}