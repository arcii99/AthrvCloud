//FormAI DATASET v1.0 Category: Email Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

// Struct for an email
typedef struct {
  char subject[MAX_SUBJECT_LENGTH];
  char body[MAX_BODY_LENGTH];
  char to_email[MAX_SUBJECT_LENGTH];
} Email;

// Function to send email
void send_email(Email* email) {
  // Code to send email goes here
  printf("Email sent to %s!\nSubject: %s\nBody: %s\n", email->to_email, email->subject, email->body);
}

int main() {
  Email* email = (Email*) malloc(sizeof(Email));

  printf("Welcome to MyEmailClient! \n");

  // Prompt for email details
  printf("Enter To email address: ");
  fgets(email->to_email, MAX_SUBJECT_LENGTH, stdin);

  printf("Enter email subject: ");
  fgets(email->subject, MAX_SUBJECT_LENGTH, stdin);

  printf("Enter email body: ");
  fgets(email->body, MAX_BODY_LENGTH, stdin);

  // Remove newline characters from user input
  email->to_email[strcspn(email->to_email, "\n")] = 0;
  email->subject[strcspn(email->subject, "\n")] = 0;
  email->body[strcspn(email->body, "\n")] = 0;

  // Send email
  send_email(email);

  // Free allocated memory
  free(email);

  return 0;
}