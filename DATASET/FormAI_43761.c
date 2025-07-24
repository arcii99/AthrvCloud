//FormAI DATASET v1.0 Category: Phone Book ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[20];
    char email[50];
    char address[100];
};

void addContact(struct Contact contact);
void displayContacts();
void searchContacts(char name[]);
void removeContact(char name[]);
void modifyContact(char name[]);

int main() {
    int choice;
    struct Contact contact;

    while (1) {
        printf("\n1. Add Contact\n2. Display Contacts\n3. Search Contacts\n4. Remove Contact\n5. Modify Contact\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the contact details: ");
                printf("\nEnter name: "); scanf("%s", &contact.name);
                printf("\nEnter phone: "); scanf("%s", &contact.phone);
                printf("\nEnter email: "); scanf("%s", &contact.email);
                printf("\nEnter address: "); scanf("%s", &contact.address);
                addContact(contact);
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                char name[50];
                printf("Enter contact name to search: ");
                scanf("%s", name);
                searchContacts(name);
                break;
            case 4:
                char name_remove[50];
                printf("Enter contact name to delete: ");
                scanf("%s", name_remove);
                removeContact(name_remove);
                break;
            case 5:
                char name_modify[50];
                printf("Enter contact name to modify: ");
                scanf("%s", name_modify);
                modifyContact(name_modify);
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void addContact(struct Contact contact) {
    FILE *fptr;
    fptr = fopen("contacts.txt", "a");
    fprintf(fptr, "%s, %s, %s, %s\n", contact.name, contact.phone, contact.email, contact.address);
    fclose(fptr);
    printf("\nContact added successfully.\n");
}

void displayContacts() {
    struct Contact contact;
    FILE *fptr;
    fptr = fopen("contacts.txt", "r");
    while (fscanf(fptr, "%[^,], %[^,], %[^,], %[^\n]\n", contact.name, contact.phone, contact.email, contact.address) != EOF) {
        printf("\nName: %s\nPhone: %s\nEmail: %s\nAddress: %s\n", contact.name, contact.phone, contact.email, contact.address);
    }
    fclose(fptr);
}

void searchContacts(char name[]) {
    struct Contact contact;
    FILE *fptr;
    fptr = fopen("contacts.txt", "r");
    int found = 0;
    while (fscanf(fptr, "%[^,], %[^,], %[^,], %[^\n]\n", contact.name, contact.phone, contact.email, contact.address) != EOF) {
        if (strcmp(contact.name, name) == 0) {
            found = 1;
            printf("\nName: %s\nPhone: %s\nEmail: %s\nAddress: %s\n", contact.name, contact.phone, contact.email, contact.address);
            break;
        }
    }
    fclose(fptr);
    if (!found) {
        printf("\nContact not found.\n");
    }
}

void removeContact(char name[]) {
    struct Contact contact;
    FILE *fptr1, *fptr2;
    fptr1 = fopen("contacts.txt", "r");
    fptr2 = fopen("temp.txt", "w");
    int found = 0;
    while (fscanf(fptr1, "%[^,], %[^,], %[^,], %[^\n]\n", contact.name, contact.phone, contact.email, contact.address) != EOF) {
        if (strcmp(contact.name, name) != 0) {
            fprintf(fptr2, "%s, %s, %s, %s\n", contact.name, contact.phone, contact.email, contact.address);
        } else {
            found = 1;
        }
    }
    fclose(fptr1);
    fclose(fptr2);
    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");
    if (found) {
        printf("\nContact removed successfully.\n");
    } else {
        printf("\nContact not found.\n");
    }
}

void modifyContact(char name[]) {
    struct Contact contact;
    FILE *fptr1, *fptr2;
    fptr1 = fopen("contacts.txt", "r");
    fptr2 = fopen("temp.txt", "w");
    int found = 0;
    while (fscanf(fptr1, "%[^,], %[^,], %[^,], %[^\n]\n", contact.name, contact.phone, contact.email, contact.address) != EOF) {
        if (strcmp(contact.name, name) != 0) {
            fprintf(fptr2, "%s, %s, %s, %s\n", contact.name, contact.phone, contact.email, contact.address);
        } else {
            found = 1;
            printf("\nEnter new contact details: ");
            printf("\nEnter phone: "); scanf("%s", &contact.phone);
            printf("\nEnter email: "); scanf("%s", &contact.email);
            printf("\nEnter address: "); scanf("%s", &contact.address);
            fprintf(fptr2, "%s, %s, %s, %s\n", contact.name, contact.phone, contact.email, contact.address);
        }
    }
    fclose(fptr1);
    fclose(fptr2);
    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");
    if (found) {
        printf("\nContact modified successfully.\n");
    } else {
        printf("\nContact not found.\n");
    }
}