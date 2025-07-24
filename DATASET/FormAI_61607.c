//FormAI DATASET v1.0 Category: Email Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store email information
struct Email {
  char* sender;
  char* recipient;
  char* subject;
  char* body;
};

// Define a function to send an email
void send_email(struct Email email) {
  printf("From: %s\n", email.sender);
  printf("To: %s\n", email.recipient);
  printf("Subject: %s\n", email.subject);
  printf("Body: %s\n", email.body);
}

int main() {
  // Prompt the user for email information
  char sender[50], recipient[50], subject[50], body[200];
  printf("Enter sender email address: ");
  fgets(sender, sizeof(sender), stdin);
  printf("Enter recipient email address: ");
  fgets(recipient, sizeof(recipient), stdin);
  printf("Enter email subject: ");
  fgets(subject, sizeof(subject), stdin);
  printf("Enter email body: ");
  fgets(body, sizeof(body), stdin);

  // Strip newline characters from input strings
  sender[strcspn(sender, "\n")] = 0;
  recipient[strcspn(recipient, "\n")] = 0;
  subject[strcspn(subject, "\n")] = 0;
  body[strcspn(body, "\n")] = 0;

  // Construct an email struct and send the email
  struct Email email = {sender, recipient, subject, body};
  send_email(email);

  return 0;
}