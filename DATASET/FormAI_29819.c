//FormAI DATASET v1.0 Category: Mailing list manager ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define BUFFER_SIZE 1000

// Email struct
typedef struct {
    char* address;
    char* subject;
    char* body;
} Email;

// Mailing list struct
typedef struct {
    char name[50];
    Email emails[MAX_EMAILS];
    int count;
} MailingList;

// Function to add email to mailing list
void add_email(MailingList* list, char* address, char* subject, char* body) {
    if (list->count >= MAX_EMAILS) {
        printf("Mailing list is full! Cannot add any more emails.\n");
        return;
    }
    
    Email new_email;
    new_email.address = address;
    new_email.subject = subject;
    new_email.body = body;
    
    list->emails[list->count] = new_email;
    list->count++;
    printf("Email added to mailing list %s.\n", list->name);
}

// Function to print all emails in mailing list
void print_emails(MailingList list) {
    printf("Emails in mailing list %s:\n", list.name);
    for (int i = 0; i < list.count; i++) {
        printf("To: %s | Subject: %s | Body: %s\n", list.emails[i].address, list.emails[i].subject, list.emails[i].body);
    }
}

int main() {
    // Create new mailing list
    MailingList my_list;
    strcpy(my_list.name, "My Mailing List");
    my_list.count = 0;
    
    // Add some emails to the list
    add_email(&my_list, "john@example.com", "Hello", "Hello John, how are you doing?");
    add_email(&my_list, "sarah@example.com", "Meeting Reminder", "Reminder: our meeting is at 3pm today.");
    add_email(&my_list, "jane@example.com", "Important Notice", "Please be aware of the upcoming deadline for project submissions.");
    
    // Print out all the emails in the list
    print_emails(my_list);
    
    return 0;
}