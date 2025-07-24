//FormAI DATASET v1.0 Category: Email Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_BODY_LENGTH 500

struct Email {
  char recipient[MAX_EMAIL_LENGTH];
  char subject[MAX_EMAIL_LENGTH];
  char body[MAX_BODY_LENGTH];
};

void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
  char input;
  struct Email myEmail;
  printf("Welcome to MyEmail! Press C to compose a new email or Q to quit.\n");
  scanf("%c", &input);
  clearBuffer();
  while (input != 'Q') {
    if (input == 'C') {
      printf("Recipient's email: ");
      fgets(myEmail.recipient, MAX_EMAIL_LENGTH, stdin);
      printf("Subject: ");
      fgets(myEmail.subject, MAX_EMAIL_LENGTH, stdin);
      printf("Body: ");
      fgets(myEmail.body, MAX_BODY_LENGTH, stdin);
      printf("Email sent to %s with subject %s and body %s.\n", 
             myEmail.recipient, myEmail.subject, myEmail.body);
    }
    printf("What would you like to do next? Press C to compose a new email or Q to quit.\n");
    scanf("%c", &input);
    clearBuffer();
  }
  printf("Goodbye!");
  return 0;
}