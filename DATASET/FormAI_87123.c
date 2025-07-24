//FormAI DATASET v1.0 Category: Email Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LEN 100
#define MAX_BODY_LEN 1000

typedef struct Email {
    char sender[50];
    char recipient[50];
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
    int isRead; // 0 if unread, 1 if read
} Email;

typedef struct EmailClient {
    char username[50];
    char password[50];
    Email emails[MAX_EMAILS];
    int numEmails;
} EmailClient;

// Function prototypes
void readEmailsFromFile(EmailClient *client, const char *filename);
void displayEmails(EmailClient *client);
void composeEmail(EmailClient *client);
void saveEmailsToFile(EmailClient *client, const char *filename);

int main() {
    EmailClient client;
    client.numEmails = 0;

    // Ask user to login with their username and password
    printf("Please login with your email address and password.\n");
    printf("Email: ");
    scanf("%s", client.username);
    printf("Password: ");
    scanf("%s", client.password);

    // Read the user's emails from file
    readEmailsFromFile(&client, "emails.txt");

    // Display the user's emails
    displayEmails(&client);

    // Compose a new email
    composeEmail(&client);

    // Save the emails back to file
    saveEmailsToFile(&client, "emails.txt");

    return 0;
}

void readEmailsFromFile(EmailClient *client, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: unable to open file %s\n", filename);
        exit(1);
    }

    char line[MAX_BODY_LEN];
    while (fgets(line, MAX_BODY_LEN, fp) != NULL) {
        // Parse the line into an email
        Email email;
        sscanf(line, "%s %s %s %s %d", email.sender, email.recipient, email.subject, email.body, &email.isRead);

        // Add the email to the client's array
        client->emails[client->numEmails] = email;
        client->numEmails++;
    }

    fclose(fp);
}

void displayEmails(EmailClient *client) {
    printf("\n\nYou have %d emails.\n", client->numEmails);
    printf("---------------------------------------------\n");
    for (int i = 0; i < client->numEmails; i++) {
        if (client->emails[i].isRead == 0) {
            printf("(unread) ");
        }
        printf("From: %s\nTo: %s\nSubject: %s\nBody: %s\n\n", client->emails[i].sender, client->emails[i].recipient, client->emails[i].subject, client->emails[i].body);
    }
}

void composeEmail(EmailClient *client) {
    printf("Compose a new email:\n");

    // Get the recipient's email address
    char recipientEmail[50];
    printf("Recipient: ");
    scanf("%s", recipientEmail);

    // Get the subject of the email
    char subject[MAX_SUBJECT_LEN];
    printf("Subject: ");
    scanf("%s", subject);

    // Get the body of the email
    char body[MAX_BODY_LEN];
    printf("Body: ");
    scanf("%s", body);

    // Create the new email and add it to the client's array
    Email newEmail;
    strcpy(newEmail.sender, client->username);
    strcpy(newEmail.recipient, recipientEmail);
    strcpy(newEmail.subject, subject);
    strcpy(newEmail.body, body);
    newEmail.isRead = 0;

    client->emails[client->numEmails] = newEmail;
    client->numEmails++;

    printf("Email sent successfully.\n");
}

void saveEmailsToFile(EmailClient *client, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: unable to open file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < client->numEmails; i++) {
        fprintf(fp, "%s %s %s %s %d\n", client->emails[i].sender, client->emails[i].recipient, client->emails[i].subject, client->emails[i].body, client->emails[i].isRead);
    }

    fclose(fp);
}