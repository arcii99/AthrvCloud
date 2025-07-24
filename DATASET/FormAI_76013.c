//FormAI DATASET v1.0 Category: Email Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBJECT 100
#define MAX_BODY 1000
#define MAX_EMAILS 100

typedef struct {
    char subject[MAX_SUBJECT];
    char body[MAX_BODY];
    char sender[MAX_SUBJECT];
    char recipient[MAX_SUBJECT];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void display_menu();
void send_email();
void view_emails();

int main(void) {
    char choice;

    do {
        display_menu();
        printf("\nEnter choice: ");
        choice = getchar();
        getchar(); // consume newline character

        switch (toupper(choice)) {
            case 'S': send_email(); break;
            case 'V': view_emails(); break;
            case 'Q': break;
            default: printf("Invalid choice. Please try again.\n"); break;
        }
    } while (toupper(choice) != 'Q');

    printf("Program has ended. Goodbye!\n");

    return 0;
}

void display_menu() {
    printf("\n========== C Email Client ==========\n");
    printf("S: Send an email\n");
    printf("V: View emails\n");
    printf("Q: Quit Program\n");
    printf("====================================\n");
}

void send_email() {
    char subject[MAX_SUBJECT], body[MAX_BODY], sender[MAX_SUBJECT], recipient[MAX_SUBJECT];

    printf("Enter sender email: ");
    fgets(sender, sizeof(sender), stdin);
    sender[strcspn(sender, "\n")] = 0; // remove newline character

    printf("Enter recipient email: ");
    fgets(recipient, sizeof(recipient), stdin);
    recipient[strcspn(recipient, "\n")] = 0; // remove newline character

    printf("Enter subject: ");
    fgets(subject, sizeof(subject), stdin);
    subject[strcspn(subject, "\n")] = 0; // remove newline character

    printf("Enter body: ");
    fgets(body, sizeof(body), stdin);
    body[strcspn(body, "\n")] = 0; // remove newline character

    // save email to array of emails
    Email new_email = {0};
    strcpy(new_email.subject, subject);
    strcpy(new_email.body, body);
    strcpy(new_email.sender, sender);
    strcpy(new_email.recipient, recipient);
    emails[num_emails++] = new_email;

    printf("Email sent successfully!\n");
}

void view_emails() {
    if (num_emails == 0) {
        printf("You have no emails to view.\n");
        return;
    }

    printf("You have %d email(s) to view.\n", num_emails);

    for (int i = 0; i < num_emails; i++) {
        printf("\n========== Email %d ==========\n", i+1);
        printf("Sender: %s\n", emails[i].sender);
        printf("Recipient: %s\n", emails[i].recipient);
        printf("Subject: %s\n", emails[i].subject);
        printf("Body: %s\n", emails[i].body);
        printf("===============================\n");
    }
}