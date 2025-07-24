//FormAI DATASET v1.0 Category: Phone Book ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct contact {
    char name[50];
    char phone[20];
};

struct phone_book {
    struct contact contacts[MAX_CONTACTS];
    int count;
};

void add_contact(struct phone_book *book, char *name, char *phone) {
    if(book->count >= MAX_CONTACTS) {
        printf("Phone book is full.\n");
        return;
    }

    strcpy(book->contacts[book->count].name, name);
    strcpy(book->contacts[book->count].phone, phone);
    book->count++;
}

void display_phone_book(struct phone_book book) {
    printf("Contact List:\n");

    for(int i = 0; i < book.count; i++) {
        printf("Name: %s\n", book.contacts[i].name);
        printf("Phone: %s\n\n", book.contacts[i].phone);
    }
}

int main() {
    struct phone_book book;
    book.count = 0;

    add_contact(&book, "John Doe", "123-456-7890");
    add_contact(&book, "Jane Doe", "987-654-3210");
    add_contact(&book, "Bob Smith", "555-555-5555");

    display_phone_book(book);

    return 0;
}