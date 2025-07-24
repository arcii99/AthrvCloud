//FormAI DATASET v1.0 Category: Email Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 50
#define MAX_EMAILS 100

// Define a struct for holding the details of an email
typedef struct {
  char sender[MAX_STRING_LEN];
  char recipient[MAX_STRING_LEN];
  char subject[MAX_STRING_LEN];
  char body[MAX_STRING_LEN * 10]; // Assume max body length of 500
} Email;

// Define a struct for holding the details of the email client
typedef struct {
  char username[MAX_STRING_LEN];
  Email inbox[MAX_EMAILS];
  int num_emails;
} EmailClient;

// Function declarations
void print_menu();
void read_string(char string[], int max_len);
void add_email(EmailClient *client);
void view_emails(EmailClient *client);

int main() {
  EmailClient client;
  client.num_emails = 0; // Initialize number of emails to 0
  printf("Welcome to your C email client!\n");
  printf("Please enter your username: ");
  read_string(client.username, MAX_STRING_LEN);
  while (1) {
    print_menu();
    char choice;
    scanf(" %c", &choice);
    printf("\n");
    if (choice == '1') {
      add_email(&client);
    } else if (choice == '2') {
      view_emails(&client);
    } else if (choice == '3') {
      printf("Thank you for using the email client. Goodbye!\n");
      break;
    } else {
      printf("Invalid choice. Please try again.\n");
    }
  }
  return 0;
}

// Function to print the main menu
void print_menu() {
  printf("\nPlease choose an option:\n");
  printf("1) Add email\n");
  printf("2) View emails\n");
  printf("3) Quit\n");
  printf("Choice: ");
}

// Function to read a string from the user
void read_string(char string[], int max_len) {
  fgets(string, max_len, stdin);
  // Remove newline character if present
  if (string[strlen(string) - 1] == '\n') {
    string[strlen(string) - 1] = '\0';
  }
}

// Function to add an email to the client's inbox
void add_email(EmailClient *client) {
  if (client->num_emails == MAX_EMAILS) {
    printf("Inbox is full. Cannot add any more emails.\n");
    return;
  }
  printf("Please enter details of the email:\n");
  printf("Sender: ");
  read_string(client->inbox[client->num_emails].sender, MAX_STRING_LEN);
  printf("Recipient: ");
  read_string(client->inbox[client->num_emails].recipient, MAX_STRING_LEN);
  printf("Subject: ");
  read_string(client->inbox[client->num_emails].subject, MAX_STRING_LEN);
  printf("Body: ");
  read_string(client->inbox[client->num_emails].body, MAX_STRING_LEN * 10);
  printf("Email has been added to the inbox.\n");
  client->num_emails++;
}

// Function to view the emails in the client's inbox
void view_emails(EmailClient *client) {
  if (client->num_emails == 0) {
    printf("No emails in inbox.\n");
    return;
  }
  printf("You have %d email(s) in your inbox:\n", client->num_emails);
  for (int i = 0; i < client->num_emails; i++) {
    printf("Email %d:\n", i + 1);
    printf("  Sender: %s\n", client->inbox[i].sender);
    printf("  Recipient: %s\n", client->inbox[i].recipient);
    printf("  Subject: %s\n", client->inbox[i].subject);
    printf("  Body: %s\n", client->inbox[i].body);
  }
}