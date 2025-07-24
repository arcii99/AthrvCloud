//FormAI DATASET v1.0 Category: Email Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100

typedef struct {
    char sender[50];
    char receiver[50];
    char subject[200];
    char body[500];
} Email;

int main() {
    Email inbox[MAX_EMAILS];
    int email_count = 0;
    FILE *fp;

    // Read the emails from the file
    fp = fopen("emails.txt", "r");
    if (fp == NULL) {
        printf("Error: Failed to open the file!\n");
        return 1;
    }

    while (fgets(inbox[email_count].sender, sizeof(inbox[email_count].sender), fp) 
           && fgets(inbox[email_count].receiver, sizeof(inbox[email_count].receiver), fp)
           && fgets(inbox[email_count].subject, sizeof(inbox[email_count].subject), fp)
           && fgets(inbox[email_count].body, sizeof(inbox[email_count].body), fp)) {
        // Remove the newline character at the end of each string
        inbox[email_count].sender[strcspn(inbox[email_count].sender, "\n")] = '\0';
        inbox[email_count].receiver[strcspn(inbox[email_count].receiver, "\n")] = '\0';
        inbox[email_count].subject[strcspn(inbox[email_count].subject, "\n")] = '\0';
        inbox[email_count].body[strcspn(inbox[email_count].body, "\n")] = '\0';
        email_count++;
    }

    fclose(fp);

    // Print the emails
    printf("You have %d new emails:\n\n", email_count);

    for (int i = 0; i < email_count; i++) {
        printf("Sender: %s\n", inbox[i].sender);
        printf("Subject: %s\n", inbox[i].subject);
        printf("Message: %s\n\n", inbox[i].body);
    }

    return 0;
}