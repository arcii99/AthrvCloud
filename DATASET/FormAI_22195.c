//FormAI DATASET v1.0 Category: Email Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 500

struct Email {
  char to[50];
  char from[50];
  char subject[MAX_SUBJECT_LENGTH];
  char body[MAX_BODY_LENGTH];
};

int validateInput(char* input, int maxLength) {
  if (strlen(input) == 0 || strlen(input) > maxLength) {
    return 0;
  }
  for (int i = 0; i < strlen(input); i++) {
    char c = *(input + i);
    if (!isalnum(c) && c != ' ' && c != '@' && c != '.' && c != ',') {
      return 0;
    }
  }
  return 1;
}

struct Email createEmail() {
  struct Email email;
  
  // TO recipient
  char to[50];
  printf("To: ");
  fgets(to, 50, stdin);
  while (!validateInput(to, 50)) {
    printf("Invalid email. Please enter a valid email address:\n");
    fgets(to, 50, stdin);
  }
  strncpy(email.to, to, strlen(to) - 1);
  
  // FROM sender
  char from[50];
  printf("From: ");
  fgets(from, 50, stdin);
  while (!validateInput(from, 50)) {
    printf("Invalid email. Please enter a valid email address:\n");
    fgets(from, 50, stdin);
  }
  strncpy(email.from, from, strlen(from) - 1);
  
  // SUBJECT
  char subject[MAX_SUBJECT_LENGTH];
  printf("Subject: ");
  fgets(subject, MAX_SUBJECT_LENGTH, stdin);
  while (!validateInput(subject, MAX_SUBJECT_LENGTH)) {
    printf("Invalid input. Please enter a subject (less than 100 characters):\n");
    fgets(subject, MAX_SUBJECT_LENGTH, stdin);
  }
  strncpy(email.subject, subject, strlen(subject) - 1);
  
  // BODY
  char body[MAX_BODY_LENGTH];
  printf("Body: ");
  fgets(body, MAX_BODY_LENGTH, stdin);
  while (!validateInput(body, MAX_BODY_LENGTH)) {
    printf("Invalid input. Please enter the message body (less than 500 characters):\n");
    fgets(body, MAX_BODY_LENGTH, stdin);
  }
  strncpy(email.body, body, strlen(body) - 1);
  
  return email;
}

void displayEmail(struct Email email) {
  printf("\nTo: %s\n", email.to);
  printf("From: %s\n", email.from);
  printf("Subject: %s\n", email.subject);
  printf("Body: %s\n\n", email.body);
}

int main() {
  struct Email emailList[10];
  int numOfEmails = 0;
  
  printf("Welcome to the email client!\n");
  while (1) {
    printf("\n1. Create new email\n2. View existing emails\n3. Exit\n");
    char option[10];
    fgets(option, 10, stdin);
    while (strlen(option) != 2 || (*option < '1' || *option > '3')) {
      printf("Invalid option. Please enter a valid number: ");
      fgets(option, 10, stdin);
    }
    switch (*option) {
      case '1':
        if (numOfEmails == 10) {
          printf("\nMaximum number of emails reached.\n");
          break;
        }
        struct Email newEmail = createEmail();
        emailList[numOfEmails] = newEmail;
        displayEmail(newEmail);
        numOfEmails++;
        break;
      case '2':
        if (numOfEmails == 0) {
          printf("\nNo emails to display.\n");
          break;
        }
        for (int i = 0; i < numOfEmails; i++) {
          printf("\nEmail %d:\n", i + 1);
          displayEmail(emailList[i]);
        }
        break;
      case '3':
        printf("\nThank you for using the email client.\n");
        exit(0);
    }
  }
  
  return 0;
}