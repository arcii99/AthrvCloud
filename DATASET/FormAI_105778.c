//FormAI DATASET v1.0 Category: Email Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void read_email(char *subject, char *message) {
    printf("Enter the subject of the email: ");
    fgets(subject, MAX_LEN, stdin);
    printf("Enter the message of the email: ");
    fgets(message, MAX_LEN, stdin);
}

void send_email(char *to, char *subject, char *message) {
    printf("Sending email to %s with subject \"%s\" and message \"%s\"\n", to, subject, message);
}

int main() {
    char to[MAX_LEN], subject[MAX_LEN], message[MAX_LEN];
    printf("Enter the recipient of the email: ");
    fgets(to, MAX_LEN, stdin);
    read_email(subject, message);
    send_email(to, subject, message);
    return 0;
}