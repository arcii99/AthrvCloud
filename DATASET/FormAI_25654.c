//FormAI DATASET v1.0 Category: Email Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSGS 100
#define MAX_MSG_LENGTH 1000

// Basic structure for emails
typedef struct Email {
    char sender[100];
    char recipient[100];
    char subject[100];
    char message[MAX_MSG_LENGTH];
} Email;

int num_msgs = 0;
Email emails[MAX_MSGS];

// Functions for handling emails

void add_email(Email e) {
    emails[num_msgs] = e;
    num_msgs++;
}

void delete_email(int index) {
    if (index >= num_msgs) {
        printf("Error: invalid email index\n");
        return;
    }
    for (int i = index; i < num_msgs - 1; i++) {
        emails[i] = emails[i+1];
    }
    num_msgs--;
}

void list_emails() {
    printf("List of emails:\n");
    for (int i = 0; i < num_msgs; i++) {
        printf("%d. From: %s, To: %s, Title: %s\n", i+1, emails[i].sender, emails[i].recipient, emails[i].subject);
    }
}

void view_email(int index) {
    if (index >= num_msgs) {
        printf("Error: invalid email index\n");
        return;
    }
    printf("From: %s\n", emails[index].sender);
    printf("To: %s\n", emails[index].recipient);
    printf("Title: %s\n", emails[index].subject);
    printf("Message:\n%s\n", emails[index].message);
}

// Basic CLI for interacting with emails

void print_help() {
    printf("Commands:\n");
    printf("new - Create a new email\n");
    printf("list - List emails\n");
    printf("view [index] - View email at index\n");
    printf("delete [index] - Delete email at index\n");
    printf("quit - Exit program\n");
}

void get_input(char *buf) {
    printf("> ");
    fgets(buf, MAX_MSG_LENGTH, stdin);

    // Remove trailing newline character
    int len = strlen(buf);
    if (len > 0 && buf[len-1] == '\n') {
        buf[len-1] = '\0';
    }
}

int main() {
    char buf[MAX_MSG_LENGTH];
    printf("Ken's Email Client\n");
    print_help();

    while (1) {
        get_input(buf);
        char *tok = strtok(buf, " ");
        if (!tok) {
            continue;
        }
        if (strcmp(tok, "new") == 0) {
            Email e;
            printf("To: ");
            get_input(e.recipient);
            printf("From: ");
            get_input(e.sender);
            printf("Title: ");
            get_input(e.subject);
            printf("Message: ");
            get_input(e.message);
            add_email(e);
        } else if (strcmp(tok, "list") == 0) {
            list_emails();
        } else if (strcmp(tok, "view") == 0) {
            tok = strtok(NULL, " ");
            if (!tok) {
                printf("Error: expected index argument\n");
                continue;
            }
            int index = atoi(tok) - 1;
            view_email(index);
        } else if (strcmp(tok, "delete") == 0) {
            tok = strtok(NULL, " ");
            if (!tok) {
                printf("Error: expected index argument\n");
                continue;
            }
            int index = atoi(tok) - 1;
            delete_email(index);
        } else if (strcmp(tok, "quit") == 0) {
            break;
        } else {
            printf("Error: invalid command\n");
            print_help();
        }
    }

    printf("Bye!\n");
    return 0;
}