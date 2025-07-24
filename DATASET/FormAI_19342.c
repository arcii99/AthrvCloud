//FormAI DATASET v1.0 Category: Email Client ; Style: surprised
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

int main() {
  char username[BUFFER_SIZE];
  char password[BUFFER_SIZE];
  char recipient[BUFFER_SIZE];
  char subject[BUFFER_SIZE];
  char message[BUFFER_SIZE*10];

  printf("Welcome to SurpriseMail!\n");
  printf("========================\n");

  printf("Enter your username: ");
  scanf("%s", username);

  printf("Enter your password: ");
  scanf("%s", password);

  printf("Enter recipient's email address: ");
  scanf("%s", recipient);

  printf("Enter email subject: ");
  scanf("%s", subject);

  printf("Compose your message: \n");
  scanf(" %[^\n]s", message);

  printf("\n\n\n");

  printf("Connecting to mail server...\n");
  printf("Authenticating %s...\n", username);
  printf("Sending message to %s...\n", recipient);
  printf("\n\n\n");

  printf("\t\t\t\tSurpriseMail\n");
  printf("\t\t\t\t===========\n\n");
  printf("From: %s\nTo: %s\nSubject: %s\n\n", username, recipient, subject);
  printf("%s\n\n", message);
  printf("Thank you for using SurpriseMail!\n");

  return 0;
}