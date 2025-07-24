//FormAI DATASET v1.0 Category: Email Client ; Style: interoperable
#include <stdio.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef enum {
  false,
  true
} bool;

typedef struct {
  char from[50];
  char to[50];
  char subject[MAX_SUBJECT_LENGTH];
  char body[MAX_BODY_LENGTH];
} Email;

bool sendEmail(Email* email) {
  // Code for sending email using the SMTP protocol
  // ...
  printf("Email sent successfully!\n");
  return true;
}

int main() {
  Email email;
  printf("Enter the sender email address:\n");
  scanf("%s", email.from);
  printf("Enter the recipient email address:\n");
  scanf("%s", email.to);
  printf("Enter the email subject (max length %d):\n", MAX_SUBJECT_LENGTH);
  scanf("%s", email.subject);
  printf("Enter the email body (max length %d):\n", MAX_BODY_LENGTH);
  scanf("%[^\n]s", email.body);

  bool success = sendEmail(&email);
  if (!success) {
    printf("Error: unable to send email\n");
  }

  return 0;
}