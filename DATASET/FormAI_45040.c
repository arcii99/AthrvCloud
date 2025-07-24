//FormAI DATASET v1.0 Category: Email Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 500

typedef struct {
    char sender[50];
    char recipient[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

typedef struct {
    Email emails[MAX_EMAILS];
    int count;
} EmailList;

void print_menu() {
    printf("================= MENU =================\n");
    printf("| 1. Compose Email                     |\n");
    printf("| 2. View Inbox                        |\n");
    printf("| 3. View Sent Items                   |\n");
    printf("| 4. Exit Program                      |\n");
    printf("========================================\n\n");
}

void save_email_to_sent_items(FILE* fp, Email email) {
  if (fp != NULL) {
    fprintf(fp, "From: %s\n", email.sender);
    fprintf(fp, "To: %s\n", email.recipient);
    fprintf(fp, "Subject: %s\n", email.subject);
    fprintf(fp, "%s\n\n", email.body);
  }
}

void send_email(EmailList* sent_items, Email email) {
    FILE* fp;
    fp = fopen("sent_items.txt", "a");
    if (fp != NULL) {
        save_email_to_sent_items(fp, email);
        fclose(fp);
        printf("Email sent and saved to Sent Items successfully!\n\n");
        sent_items->emails[sent_items->count] = email;
        sent_items->count++;
    } else {
        printf("Could not open file to save email to Sent Items...\n\n");
    }
}

void print_emails(EmailList email_list) {
    for (int i = 0; i < email_list.count; i++) {
        printf("From: %s\n", email_list.emails[i].sender);
        printf("To: %s\n", email_list.emails[i].recipient);
        printf("Subject: %s\n", email_list.emails[i].subject);
        printf("%s\n\n", email_list.emails[i].body);
    }
}

void view_inbox(EmailList inbox) {
    if (inbox.count > 0) {
        printf("You have %d email%s in your inbox:\n", inbox.count, inbox.count > 1 ? "s" : "");
        print_emails(inbox);
    } else {
        printf("Your inbox is empty.\n\n");
    }
}

void view_sent_items(EmailList sent_items) {
    if (sent_items.count > 0) {
        printf("You have sent %d email%s:\n", sent_items.count, sent_items.count > 1 ? "s" : "");
        print_emails(sent_items);
    } else {
        printf("You have not sent any emails yet.\n\n");
    }
}

void compose_email(EmailList* sent_items, EmailList* inbox) {
    Email email;
    printf("Compose Email\n");
    printf("=================\n");
    printf("Sender: ");
    scanf("%s", email.sender);
    printf("Recipient: ");
    scanf("%s", email.recipient);
    printf("Subject: ");
    getchar();
    fgets(email.subject, MAX_SUBJECT_LENGTH, stdin);
    printf("Body: ");
    fgets(email.body, MAX_BODY_LENGTH, stdin);
    send_email(sent_items, email);
    inbox->emails[inbox->count] = email;
    inbox->count++;
}

void load_inbox_from_file(char* filename, EmailList* inbox) {
    FILE* fp;
    fp = fopen(filename, "r");
    if (fp != NULL) {
        char line[100];
        Email email;
        while (fgets(line, 100, fp) != NULL) {
            if (strcmp(line, "\n") == 0) {
                inbox->emails[inbox->count] = email;
                inbox->count++;
            } else if (strncmp(line, "From: ", 6) == 0) {
                strtok(line, " ");
                strcpy(email.sender, strtok(NULL, "\n"));
            } else if (strncmp(line, "To: ", 4) == 0) {
                strtok(line, " ");
                strcpy(email.recipient, strtok(NULL, "\n"));
            } else if (strncmp(line, "Subject: ", 9) == 0) {
                strcpy(email.subject, strtok(line, "\n"));
            } else {
                strcat(email.body, line);
            }
        }
        fclose(fp);
    } else {
        printf("Could not open file to load inbox...\n");
    }
}

int main() {
    EmailList sent_items = { .count = 0 };
    EmailList inbox = { .count = 0 };
    load_inbox_from_file("inbox.txt", &inbox);
    int choice;
    do {
        print_menu();
        printf("Select an option by entering the corresponding number [1-4]: ");
        scanf("%d", &choice);
        printf("=============================\n\n");
        switch (choice) {
            case 1:
                compose_email(&sent_items, &inbox);
                break;
            case 2:
                view_inbox(inbox);
                break;
            case 3:
                view_sent_items(sent_items);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n\n");
        }
    } while (choice != 4);
    return 0;
}