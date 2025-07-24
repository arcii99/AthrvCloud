//FormAI DATASET v1.0 Category: Email Client ; Style: invasive
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUFFER_SIZE 1024

/*
 * Email structure
 * The email has a sender, a recipient, a subject and message body
 */
struct Email {
    char sender[MAX_BUFFER_SIZE];
    char recipient[MAX_BUFFER_SIZE];
    char subject[MAX_BUFFER_SIZE];
    char message[MAX_BUFFER_SIZE];
};

/*
 * Function to display the menu options to the user
 */
void display_menu() {
    printf("\n=== C Email Client ===\n");
    printf("1. Compose Email\n");
    printf("2. View Inbox\n");
    printf("3. View Sent\n");
    printf("4. Exit\n");
}

/*
 * Function to get user input and validate it
 */
void get_input(char *input) {
    do {
        printf("> ");
        fgets(input, MAX_BUFFER_SIZE, stdin);
        input[strcspn(input, "\n")] = 0; // remove newline character
    } while (strlen(input) == 0);
}

/*
 * Function to compose a new email
 */
void compose_email(struct Email *email) {
    printf("\n=== Compose Email ===\n");
    printf("Enter Sender Email Address: ");
    get_input(email->sender);
    printf("Enter Recipient Email Address: ");
    get_input(email->recipient);
    printf("Enter Email Subject: ");
    get_input(email->subject);
    printf("Enter Email Message:\n");
    get_input(email->message);
    printf("Email sent!\n");
}

/*
 * Function to display a list of emails
 */
void display_emails(const char *folder_name, bool show_recipient, const char *column_name,
                    const char *header_text, struct Email *emails, int email_count) {
    printf("\n=== %s ===\n", header_text);
    printf("%-30s | %-30s | %s\n", "Sender", column_name, "Subject");
    printf("-----------------------------------------------------------------\n");

    for (int i = 0; i < email_count; i++) {
        printf("%-30s | %-30s | %s\n", emails[i].sender, show_recipient ? emails[i].recipient : folder_name, emails[i].subject);
    }
}

/*
 * Main function
 */
int main() {
    int choice = 0;
    struct Email inbox[10], sent[10];
    int inbox_count = 0, sent_count = 0;

    while (choice != 4) {
        display_menu();

        char input[MAX_BUFFER_SIZE];
        get_input(input);

        choice = atoi(input);

        switch (choice) {
            case 1:
                struct Email email;
                compose_email(&email);
                sent[sent_count++] = email;
                break;
            case 2:
                display_emails("Inbox", false, "Recipient", "Inbox", inbox, inbox_count);
                break;
            case 3:
                display_emails("Sent", true, "Recipient", "Sent Emails", sent, sent_count);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}