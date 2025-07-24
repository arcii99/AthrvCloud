//FormAI DATASET v1.0 Category: Mailing list manager ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} email_t;

typedef struct {
    int count;
    email_t emails[MAX_EMAILS];
} mailing_list_t;

void add_email(mailing_list_t *mailing_list, const char *name, const char *email) {
    if (mailing_list->count < MAX_EMAILS) {
        email_t *new_email = &(mailing_list->emails[mailing_list->count]);
        strncpy(new_email->name, name, MAX_NAME_LENGTH);
        strncpy(new_email->email, email, MAX_EMAIL_LENGTH);
        mailing_list->count++;
    }
}

void print_list(mailing_list_t *mailing_list) {
    printf("Mailing List:\n");
    for (int i = 0; i < mailing_list->count; i++) {
        printf("%s <%s>\n", mailing_list->emails[i].name, mailing_list->emails[i].email);
    }
}

int main() {
    mailing_list_t mailing_list = { 0 };
    add_email(&mailing_list, "John Smith", "john.smith@example.com");
    add_email(&mailing_list, "Jackie Chan", "jackie.chan@example.com");
    add_email(&mailing_list, "Bruce Lee", "bruce.lee@example.com");
    print_list(&mailing_list);
    return 0;
}