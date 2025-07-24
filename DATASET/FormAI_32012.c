//FormAI DATASET v1.0 Category: Email Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

void send_email(char* recipient, char* subject, char* message) {
    char command[MAX_LEN];
    snprintf(command, MAX_LEN, "echo \"%s\" | mail -s \"%s\" %s", message, subject, recipient);
    system(command);
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <recipient> <subject> <message>\n", argv[0]);
        return 1;
    }

    char* recipient = argv[1];
    char* subject = argv[2];
    char* message = argv[3];

    send_email(recipient, subject, message);
    printf("Email sent successfully!\n");

    return 0;
}