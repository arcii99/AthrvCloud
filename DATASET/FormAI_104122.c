//FormAI DATASET v1.0 Category: Email Client ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LEN 100
#define MAX_BODY_LEN 1000

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
    char sender[50];
    char receiver[50];
} email;

email emails[MAX_EMAILS];
int num_emails = 0;

void read_email(email *new_email) {
    printf("\nEnter email details:\n");
    printf("Subject: ");
    scanf("%99s", new_email->subject);
    printf("Body: ");
    scanf("%999s", new_email->body);
    printf("Sender: ");
    scanf("%49s", new_email->sender);
    printf("Receiver: ");
    scanf("%49s", new_email->receiver);
}

void send_email() {
    email new_email;
    read_email(&new_email);
    emails[num_emails] = new_email;
    num_emails++;
    printf("\nEmail sent!");
}

void print_emails() {
    printf("\nEmails:\n");
    for (int i = 0; i < num_emails; i++) {
        printf("Subject: %s\n", emails[i].subject);
        printf("Body: %s\n", emails[i].body);
        printf("From: %s\n", emails[i].sender);
        printf("To: %s\n", emails[i].receiver);
        printf("**********\n");
    }
}

int main() {
    printf("******** CYBER EMAIL CLIENT 3000 ********\n");
    int choice = 0;
    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Send Email\n");
        printf("2. View Emails\n");
        printf("3. Quit\n");
        printf("\nOption: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                send_email();
                break;
            case 2:
                print_emails();
                break;
            case 3:
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("\nInvalid option, please try again.\n");
        }
    }
    return 0;
}