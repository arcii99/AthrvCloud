//FormAI DATASET v1.0 Category: Mailing list manager ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_EMAILS 100 // Maximum number of emails in our mailing list

struct Email {
    char name[50];
    char email[50];
};

struct MailingList {
    struct Email emails[MAX_EMAILS];
    int count;
};

void addEmail(struct MailingList* ml, char* name, char* email) {
    if (ml->count >= MAX_EMAILS) {
        printf("Error: Mailing List is Full\n");
        return;
    }
    struct Email newEmail;
    strcpy(newEmail.name, name);
    strcpy(newEmail.email, email);
    ml->emails[ml->count] = newEmail;
    ml->count++;
    printf("Email Added Successfully\n");
}

bool removeEmail(struct MailingList* ml, char* email) {
    for (int i=0; i < ml->count; i++) {
        if (strcmp(ml->emails[i].email, email) == 0) {
            for (int j=i; j < ml->count-1; j++) {
                ml->emails[j] = ml->emails[j+1];
            }
            ml->count--;
            printf("Email Removed Successfully\n");
            return true;
        }
    }
    printf("Error: Email not Found\n");
    return false;
}

void printMailingList(struct MailingList ml) {
    printf("Name\t\tEmail\n");
    printf("---------------------------\n");
    for (int i=0; i<ml.count; i++) {
        printf("%s\t\t%s\n", ml.emails[i].name, ml.emails[i].email);
    }
}

int main() {
    // Initialize Mailing List
    struct MailingList ml;
    ml.count = 0;
    
    // Example Usage
    addEmail(&ml, "John Doe", "johndoe@example.com");
    addEmail(&ml, "Jane Smith", "janesmith@example.com");
    addEmail(&ml, "Bob Johnson", "bobjohnson@example.com");
    printMailingList(ml);
    
    removeEmail(&ml, "janedoe@example.com");
    removeEmail(&ml, "janesmith@example.com");
    printMailingList(ml);
  
    return 0;
}