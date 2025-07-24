//FormAI DATASET v1.0 Category: Email Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char recipient[50];
  char subject[50];
  char message[500];

  printf("Welcome to the Email Client Program!\n\n");

  printf("Please enter the recipient's email address: ");
  fgets(recipient, 50, stdin);
  recipient[strcspn(recipient, "\n")] = '\0';

  printf("\nPlease enter the email subject: ");
  fgets(subject, 50, stdin);
  subject[strcspn(subject, "\n")] = '\0';

  printf("\nPlease enter your email message: ");
  fgets(message, 500, stdin);
  message[strcspn(message, "\n")] = '\0';

  // connect to email server and send email
  // for the purpose of this program, we will print a confirmation message

  printf("\n\nEmail sent to %s\nSubject: %s\nMessage:\n%s\n\n", recipient, subject, message);

  return 0;
}