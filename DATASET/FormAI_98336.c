//FormAI DATASET v1.0 Category: Email Client ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_MSGS 100 // Maximum number of email messages allowed
#define MAX_LEN 1000 // Maximum length of a message or subject
#define MAX_EMAILS 50 // Maximum number of email addresses allowed

// Structure to hold an email message
struct email_message {
    char sender[MAX_LEN];
    char recipients[MAX_EMAILS][MAX_LEN];
    char subject[MAX_LEN];
    char message[MAX_LEN];
};

// Function to prompt user for input
void prompt_input(char* prompt, char* input, int max_len) {
    printf("%s: ", prompt);
    fgets(input, max_len, stdin);
    // Remove newline character from the end of the input
    if (input[strlen(input)-1] == '\n') {
        input[strlen(input)-1] = '\0';
    }
}

// Function to send an email
void send_email(struct email_message* messages, int num_msgs) {
    // Create a new email message
    struct email_message new_message;

    // Get the sender's email address
    prompt_input("Enter sender email address", new_message.sender, MAX_LEN);

    // Get the recipients' email addresses
    char recipient[MAX_LEN];
    int num_recipients = 0;
    do {
        prompt_input("Enter recipient email address (enter 'done' when finished)", recipient, MAX_LEN);

        // Add the recipient if it is not 'done'
        if (strcmp(recipient, "done") != 0) {
            strcpy(new_message.recipients[num_recipients], recipient);
            num_recipients++;
        }
    } while (strcmp(recipient, "done") != 0 && num_recipients < MAX_EMAILS);

    // Get the subject of the email
    prompt_input("Enter subject", new_message.subject, MAX_LEN);

    // Get the message of the email
    prompt_input("Enter message", new_message.message, MAX_LEN);

    // Add the new message to the messages array
    messages[num_msgs++] = new_message;

    printf("Email sent!\n");
}

// Function to display the inbox
void view_inbox(struct email_message* messages, int num_msgs) {
    if (num_msgs == 0) {
        printf("You have no messages in your inbox.\n");
    } else {
        printf("Your inbox:\n");
        for (int i = 0; i < num_msgs; i++) {
            printf("From: %s\n", messages[i].sender);
            printf("To: ");
            for (int j = 0; j < MAX_EMAILS && messages[i].recipients[j][0] != '\0'; j++) {
                printf("%s ", messages[i].recipients[j]);
            }
            printf("\n");
            printf("Subject: %s\n", messages[i].subject);
            printf("Message: %s\n", messages[i].message);
            printf("\n");
        }
    }
}

int main() {
    struct email_message messages[MAX_MSGS];
    int num_msgs = 0;

    printf("Welcome to the Mind-Bending Email Client!\n");

    while (1) {
        printf("1. Send email\n");
        printf("2. View inbox\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);
        getchar(); // Consume the extra newline character from scanf

        switch (choice) {
            case 1:
                send_email(messages, num_msgs);
                num_msgs++;
                break;
            case 2:
                view_inbox(messages, num_msgs);
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}