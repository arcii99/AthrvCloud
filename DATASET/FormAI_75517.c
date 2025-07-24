//FormAI DATASET v1.0 Category: Phone Book ; Style: relaxed
#include <stdio.h>
#include <string.h>
#define MAX_CONTACTS 100

typedef struct Contact {
    char name[50];
    char phone_number[12];
} Contact;

Contact phone_book[MAX_CONTACTS];
int num_contacts = 0;

int main() {
    int option;
    do {
        printf("\nWelcome to C Phone Book!\n\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Update Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_contact();
                break;
            case 2:
                view_contacts();
                break;
            case 3:
                update_contact();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                printf("\nThank you for using C Phone Book!\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    } while(option != 5);

    return 0;
}

void add_contact() {
    if(num_contacts >= MAX_CONTACTS) {
        printf("\nPhone book is full!\n");
        return;
    }

    printf("\nEnter contact name: ");
    scanf("%s", phone_book[num_contacts].name);
    printf("Enter phone number (10 digits): ");
    scanf("%s", phone_book[num_contacts].phone_number);

    num_contacts++;
    printf("\nContact added successfully!\n");
}

void view_contacts() {
    if(num_contacts == 0) {
        printf("\nPhone book is empty!\n");
        return;
    }

    printf("\n%-20s %-15s\n", "Name", "Phone Number");
    for(int i=0; i<num_contacts; i++) {
        printf("%-20s %-15s\n", phone_book[i].name, phone_book[i].phone_number);
    }
}

void update_contact() {
    if(num_contacts == 0) {
        printf("\nPhone book is empty!\n");
        return;
    }

    char name[50];
    printf("\nEnter contact name: ");
    scanf("%s", name);

    for(int i=0; i<num_contacts; i++) {
        if(strcmp(phone_book[i].name, name) == 0) {
            printf("\nEnter new phone number (10 digits): ");
            scanf("%s", phone_book[i].phone_number);
            printf("\nContact updated successfully!\n");
            return;
        }
    }

    printf("\nContact not found!\n");
}

void delete_contact() {
    if(num_contacts == 0) {
        printf("\nPhone book is empty!\n");
        return;
    }

    char name[50];
    printf("\nEnter contact name: ");
    scanf("%s", name);

    for(int i=0; i<num_contacts; i++) {
        if(strcmp(phone_book[i].name, name) == 0) {
            for(int j=i; j<num_contacts-1; j++) {
                phone_book[j] = phone_book[j+1];
            }
            num_contacts--;
            printf("\nContact deleted successfully!\n");
            return;
        }
    }

    printf("\nContact not found!\n");
}