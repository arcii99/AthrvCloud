//FormAI DATASET v1.0 Category: Email Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ADDRESS_LENGTH 100
#define MAX_SUBJECT_LENGTH 200
#define MAX_BODY_LENGTH 1000

typedef struct {
    char from[MAX_ADDRESS_LENGTH];
    char to[MAX_ADDRESS_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

void read_input(char *buffer, int buffer_size) {
    char *pos;
    fgets(buffer, buffer_size, stdin);
    if ((pos = strchr(buffer, '\n')) != NULL) {
        *pos = '\0';
    }
}

void write_email(Email e) {
    printf("From: %s\n", e.from);
    printf("To: %s\n", e.to);
    printf("Subject: %s\n", e.subject);
    printf("Body:\n%s\n", e.body);
}

int main() {
    Email e;
    printf("Welcome to MyEmail!\n");

    printf("From: ");
    read_input(e.from, MAX_ADDRESS_LENGTH);
    printf("To: ");
    read_input(e.to, MAX_ADDRESS_LENGTH);
    printf("Subject: ");
    read_input(e.subject, MAX_SUBJECT_LENGTH);
    printf("Body:\n");
    read_input(e.body, MAX_BODY_LENGTH);

    bool send_email = true;
    printf("Do you want to send this email? (y/n) ");
    char answer[10];
    read_input(answer, 10);
    if (strcmp(answer, "y") != 0) {
        send_email = false;
    }

    if (send_email) {
        printf("Email sent!\n");
    } else {
        printf("Email not sent.\n");
    }

    return 0;
}