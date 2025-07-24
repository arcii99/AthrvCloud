//FormAI DATASET v1.0 Category: Email Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 1000
#define MAX_EMAILS 100

typedef struct Email {
    char sender[50];
    char recipient[50];
    char subject[100];
    char message[MAX_MSG_LEN];
} Email;

typedef struct EmailClient {
    char username[50];
    Email inbox[MAX_EMAILS];
    int num_emails;
} EmailClient;

void read_input(char *input);
EmailClient *login();
void print_menu();
void receive_email(EmailClient *client);
void send_email(EmailClient *client);
void view_inbox(EmailClient *client);
void logout(EmailClient *client);

int main() {
    EmailClient *client = login();
    
    char input[50];
    int choice;
    
    do {
        print_menu();
        read_input(input);
        choice = atoi(input);
        
        switch(choice) {
            case 1:
                receive_email(client);
                break;
            case 2:
                send_email(client);
                break;
            case 3:
                view_inbox(client);
                break;
            case 4:
                logout(client);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 4);
    
    free(client);
    
    return 0;
}

void read_input(char *input) {
    fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = '\0';
}

EmailClient *login() {
    EmailClient *client = (EmailClient *)malloc(sizeof(EmailClient));
    
    printf("Welcome to Introspective Email Client!\n");
    printf("Please enter your username: ");
    read_input(client->username);
    printf("Login successful.\n");
    
    return client;
}

void print_menu() {
    printf("\nWhat would you like to do?\n");
    printf("1. Receive email\n");
    printf("2. Send email\n");
    printf("3. View inbox\n");
    printf("4. Logout\n");
    printf("Please enter your choice: ");
}

void receive_email(EmailClient *client) {
    if(client->num_emails == MAX_EMAILS) {
        printf("Inbox is full. Cannot receive any more emails.\n");
        return;
    }
    
    Email new_email;
    printf("Enter sender's email address: ");
    read_input(new_email.sender);
    printf("Enter subject: ");
    read_input(new_email.subject);
    printf("Enter message:\n");
    fgets(new_email.message, MAX_MSG_LEN, stdin);
    new_email.message[strcspn(new_email.message, "\n")] = '\0';
    
    strcpy(new_email.recipient, client->username);
    
    client->inbox[client->num_emails++] = new_email;
    
    printf("\nEmail received successfully!\n");
}

void send_email(EmailClient *client) {
    Email new_email;
    printf("Enter recipient's email address: ");
    read_input(new_email.recipient);
    printf("Enter subject: ");
    read_input(new_email.subject);
    printf("Enter message:\n");
    fgets(new_email.message, MAX_MSG_LEN, stdin);
    new_email.message[strcspn(new_email.message, "\n")] = '\0';
    
    strcpy(new_email.sender, client->username);
    
    // Code for sending email...
    
    printf("\nEmail sent successfully!\n");
}

void view_inbox(EmailClient *client) {
    if(client->num_emails == 0) {
        printf("Inbox is empty.\n");
        return;
    }
    
    printf("\nInbox (%d emails):\n\n", client->num_emails);
    for(int i = 0; i < client->num_emails; i++) {
        printf("From: %s\n", client->inbox[i].sender);
        printf("Subject: %s\n", client->inbox[i].subject);
        printf("Message: %s\n\n", client->inbox[i].message);
    }
}

void logout(EmailClient *client) {
    printf("Goodbye, %s!\n", client->username);
}