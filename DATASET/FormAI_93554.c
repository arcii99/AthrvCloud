//FormAI DATASET v1.0 Category: Email Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 500
#define MAX_INBOX_SIZE 100

// Declare structs for Email, Inbox, and Email Client
typedef struct {
    char sender[MAX_EMAIL_LENGTH];
    char recipient[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
} Email;

typedef struct {
    Email emails[MAX_INBOX_SIZE];
    int size;
} Inbox;

typedef struct {
    Inbox inbox;
    char username[MAX_EMAIL_LENGTH];
} EmailClient;

// Declare functions for EmailClient
void printOptions();
void signUp(EmailClient*);
void login(EmailClient*);
void logout(EmailClient*);
void sendEmail(EmailClient*);
void viewInbox(EmailClient*);
void deleteEmail(EmailClient*);

int main() {
    // Initialize EmailClient
    EmailClient client;
    client.inbox.size = 0;
    strcpy(client.username, "");

    // Initialize user input variable
    char input[10];

    // Keep running program until user decides to quit
    while (strcmp(input, "quit") != 0) {
        // Print options for user to choose
        printOptions();

        // Collect user input for desired operation
        printf("Enter selection: ");
        fgets(input, sizeof(input), stdin);

        // Clean up input by removing newline character
        input[strcspn(input, "\n")] = 0;

        // Perform desired operation based on user input
        if (strcmp(input, "signup") == 0) {
            signUp(&client);
        } else if (strcmp(input, "login") == 0) {
            login(&client);
        } else if (strcmp(input, "logout") == 0) {
            logout(&client);
        } else if (strcmp(input, "send") == 0) {
            sendEmail(&client);
        } else if (strcmp(input, "inbox") == 0) {
            viewInbox(&client);
        } else if (strcmp(input, "delete") == 0) {
            deleteEmail(&client);
        } else if (strcmp(input, "quit") != 0) {
            printf("Invalid selection. Please try again.\n");
        }
    }

    return 0;
}

void printOptions() {
    printf("\n");
    printf("Select an operation to perform:\n");
    printf("\tsignup - create a new email account\n");
    printf("\tlogin - log into your email account\n");
    printf("\tlogout - log out of your email account\n");
    printf("\tsend - send an email to a recipient\n");
    printf("\tinbox - view your inbox\n");
    printf("\tdelete - delete an email from your inbox\n");
    printf("\tquit - quit the email client program\n");
    printf("\n");
}

void signUp(EmailClient* client) {
    // Check if user is already logged in
    if (strcmp(client->username, "") != 0) {
        printf("You must log out before creating a new account.\n");
        return;
    }

    // Collect user input for desired email username
    printf("Enter desired email username: ");
    fgets(client->username, sizeof(client->username), stdin);

    // Clean up input by removing newline character
    client->username[strcspn(client->username, "\n")] = 0;

    // Print confirmation message
    printf("Email account created for %s.\n", client->username);
}

void login(EmailClient* client) {
    // Check if user is already logged in
    if (strcmp(client->username, "") != 0) {
        printf("You are already logged into an email account.\n");
        return;
    }

    // Collect user input for email username
    char username[MAX_EMAIL_LENGTH];
    printf("Enter email username: ");
    fgets(username, sizeof(username), stdin);

    // Clean up input by removing newline character
    username[strcspn(username, "\n")] = 0;

    // Check if email username exists
    if (strcmp(client->username, username) != 0) {
        printf("Email username not found. Please try again or create a new account.\n");
        return;
    }

    // Print confirmation message
    printf("You are now logged in as %s.\n", client->username);
}

void logout(EmailClient* client) {
    // Check if user is logged in
    if (strcmp(client->username, "") == 0) {
        printf("You must log in before logging out.\n");
        return;
    }

    // Set email username to empty string
    strcpy(client->username, "");

    // Print confirmation message
    printf("You are now logged out.\n");
}

void sendEmail(EmailClient* client) {
    // Check if user is logged in
    if (strcmp(client->username, "") == 0) {
        printf("You must log in before sending an email.\n");
        return;
    }

    // Check if inbox is full
    if (client->inbox.size == MAX_INBOX_SIZE) {
        printf("Inbox is full. Please delete unneeded emails before sending a new one.\n");
        return;
    }

    // Collect user input for email recipient
    char recipient[MAX_EMAIL_LENGTH];
    printf("Enter email recipient: ");
    fgets(recipient, sizeof(recipient), stdin);

    // Clean up input by removing newline character
    recipient[strcspn(recipient, "\n")] = 0;

    // Collect user input for email subject
    char subject[MAX_SUBJECT_LENGTH];
    printf("Enter email subject: ");
    fgets(subject, sizeof(subject), stdin);

    // Clean up input by removing newline character
    subject[strcspn(subject, "\n")] = 0;

    // Collect user input for email body
    char body[MAX_BODY_LENGTH];
    printf("Enter email body: ");
    fgets(body, sizeof(body), stdin);

    // Clean up input by removing newline character
    body[strcspn(body, "\n")] = 0;

    // Create new email structure with user input
    Email newEmail;
    strcpy(newEmail.sender, client->username);
    strcpy(newEmail.recipient, recipient);
    strcpy(newEmail.subject, subject);
    strcpy(newEmail.body, body);
    newEmail.timestamp = time(NULL);

    // Add new email to inbox and increment size
    client->inbox.emails[client->inbox.size] = newEmail;
    client->inbox.size++;

    // Print confirmation message
    printf("Email sent successfully.\n");
}

void viewInbox(EmailClient* client) {
    // Check if user is logged in
    if (strcmp(client->username, "") == 0) {
        printf("You must log in before viewing your inbox.\n");
        return;
    }

    // Check if inbox is empty
    if (client->inbox.size == 0) {
        printf("Inbox is empty.\n");
        return;
    }

    // Print header for inbox
    printf("%-20s %-20s %-20s %-50s\n", "Timestamp", "Sender", "Recipient", "Subject");

    // Loop through all emails in inbox and print their metadata
    for (int i = 0; i < client->inbox.size; i++) {
        Email currentEmail = client->inbox.emails[i];
        char timestampStr[100];
        strftime(timestampStr, sizeof(timestampStr), "%Y-%m-%d %H:%M:%S", localtime(&currentEmail.timestamp));
        printf("%-20s %-20s %-20s %-50s\n", timestampStr, currentEmail.sender, currentEmail.recipient, currentEmail.subject);
    }
}

void deleteEmail(EmailClient* client) {
    // Check if user is logged in
    if (strcmp(client->username, "") == 0) {
        printf("You must log in before deleting an email.\n");
        return;
    }

    // Check if inbox is empty
    if (client->inbox.size == 0) {
        printf("Inbox is empty. No emails to delete.\n");
        return;
    }

    // Collect user input for index of email to delete
    char indexStr[10];
    printf("Enter index of email to delete: ");
    fgets(indexStr, sizeof(indexStr), stdin);

    // Clean up input by removing newline character
    indexStr[strcspn(indexStr, "\n")] = 0;

    // Convert index string to integer
    int index = atoi(indexStr);

    // Check if index is valid
    if (index < 1 || index > client->inbox.size) {
        printf("Invalid index. Please enter a valid index.\n");
        return;
    }

    // Shift all emails after deleted email back by one
    for (int i = index-1; i < client->inbox.size-1; i++) {
        client->inbox.emails[i] = client->inbox.emails[i+1];
    }

    // Decrement size of inbox
    client->inbox.size--;

    // Print confirmation message
    printf("Email deleted successfully.\n");
}