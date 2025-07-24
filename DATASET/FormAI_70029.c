//FormAI DATASET v1.0 Category: Email Client ; Style: intelligent
#include<stdio.h>  // Standard Input Output Library
#include<stdlib.h> // Standard Library
#include<ctype.h>  // Character Type Library
#include<string.h> // String Library

#define MAX_EMAIL_LENGTH 200
#define MAX_NAME_LENGTH 50
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 2000

struct Email { // Email structure
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
};

void strip_newline(char* str) { // Function to remove newline character from string
    str[strcspn(str, "\n\r")] = 0;
}

void input_string(char* str, int max_length) { // Function to input string
    fgets(str, max_length, stdin);
    strip_newline(str);
}

int validate_email(char* email) { // Function to validate email
    int email_length = strlen(email);
    int at_position = -1;
    int dot_position = -1;
    for (int i = 0; i < email_length; i++) {
        if (email[i] == '@') {
            at_position = i;
        }
        else if (email[i] == '.') {
            dot_position = i;
        }
    }
    if (at_position == -1 || dot_position == -1) {
        return 0;
    }
    else if (dot_position < at_position) {
        return 0;
    }
    else if (email_length - dot_position <= 1) {
        return 0;
    }
    else {
        return 1;
    }
}

int main() {
    printf("\n\n\t\tC EMAIL CLIENT\n\n");

    struct Email email;

    printf("Name: ");
    input_string(email.name, MAX_NAME_LENGTH);

    do {
        printf("Email: ");
        input_string(email.email, MAX_EMAIL_LENGTH);
    } while (!validate_email(email.email));

    printf("Subject: ");
    input_string(email.subject, MAX_SUBJECT_LENGTH);

    printf("Message: ");
    input_string(email.message, MAX_MESSAGE_LENGTH);

    printf("\n\nSending Email...\n\n");

    // Code to send email will go here

    printf("Email Sent Successfully!\n");

    return 0;
}