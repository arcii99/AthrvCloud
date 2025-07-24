//FormAI DATASET v1.0 Category: Email Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_EMAILS 100

// Structure to hold an email
typedef struct email {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char sender[MAX_SUBJECT_LENGTH];
    char recipient[MAX_SUBJECT_LENGTH];
    int is_read;
    int is_deleted;
} Email;

// Function to print a menu and get user input
int printMenuAndGetInput() {
    int input;
    printf("\n\nEmail Client:\n");
    printf("1. Compose Email\n");
    printf("2. View Emails\n");
    printf("3. Mark Email as Read\n");
    printf("4. Delete Email\n");
    printf("5. Quit\n");
    printf("Enter Choice: ");
    scanf("%d", &input);
    return input;
}

int main() {
    Email emails[MAX_EMAILS];
    int num_emails = 0;
    int choice;
    int i;

    do {
        choice = printMenuAndGetInput();
        switch(choice) {
            case 1: // Compose Email
                if(num_emails >= MAX_EMAILS) {
                    printf("Error: Maximum Number of Emails Reached\n");
                    break;
                }

                printf("Enter Recipient's Email Address: ");
                scanf("%s", emails[num_emails].recipient);

                printf("Enter Subject: ");
                scanf(" %[^\n]s", emails[num_emails].subject);

                printf("Enter Body: ");
                scanf(" %[^\n]s", emails[num_emails].body);

                strcpy(emails[num_emails].sender, "You");
                emails[num_emails].is_read = 0;
                emails[num_emails].is_deleted = 0;

                printf("Email Sent!\n");
                num_emails++;
                break;
            case 2: // View Emails
                if(num_emails == 0) {
                    printf("No Emails Found\n");
                    break;
                }

                printf("\n\nEmails:\n");
                for(i = 0; i < num_emails; i++) {
                    if(emails[i].is_deleted == 1) {
                        continue;
                    }

                    printf("%d. From: %s, To: %s, Subject: %s, Body: %s\n",
                           i + 1, emails[i].sender, emails[i].recipient, emails[i].subject, emails[i].body);

                    if(emails[i].is_read == 1) {
                        printf("   Status: Read\n");
                    } else {
                        printf("   Status: Unread\n");
                    }
                }

                break;
            case 3: // Mark Email as Read
                if(num_emails == 0) {
                    printf("No Emails Found\n");
                    break;
                }

                printf("Enter Email Number to Mark as Read: ");
                scanf("%d", &i);
                if(i < 1 || i > num_emails || emails[i - 1].is_deleted == 1) {
                    printf("Error: Invalid Email Number\n");
                    break;
                }

                emails[i - 1].is_read = 1;
                printf("Email Marked as Read\n");
                break;
            case 4: // Delete Email
                if(num_emails == 0) {
                    printf("No Emails Found\n");
                    break;
                }

                printf("Enter Email Number to Delete: ");
                scanf("%d", &i);
                if(i < 1 || i > num_emails || emails[i - 1].is_deleted == 1) {
                    printf("Error: Invalid Email Number\n");
                    break;
                }

                emails[i - 1].is_deleted = 1;
                printf("Email Deleted\n");
                break;
            case 5: // Quit
                printf("Exiting Email Client...\n");
                break;
            default:
                printf("Error: Invalid Choice\n");
                break;
        }
    } while(choice != 5);

    return 0;
}