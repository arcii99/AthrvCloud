//FormAI DATASET v1.0 Category: Mailing list manager ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100 // Maximum number of emails

// Declaration of a struct to represent an email
typedef struct {
  int id; // Unique ID for this email
  char sender[100]; // Email sender
  char recipient[100]; // Email recipient
  char subject[200]; // Email subject
  char message[1000]; // Email message
} Email;

// Declaration of a struct to represent a mailing list
typedef struct {
  int num_emails; // Number of emails in this mailing list
  Email emails[MAX_EMAILS]; // Array to hold emails in this mailing list
} MailingList;

// Function to add an email to a mailing list
void addEmailToMailingList(MailingList* mailingList, Email email) {
  if (mailingList->num_emails < MAX_EMAILS) {
    mailingList->emails[mailingList->num_emails++] = email;
    printf("Email added to mailing list.\n");
  } else {
    printf("Mailing list is full. Cannot add email.\n");
  }
}

// Function to remove an email from a mailing list
void removeEmailFromMailingList(MailingList* mailingList, int emailId) {
  int i;
  for (i = 0; i < mailingList->num_emails; i++) {
    if (mailingList->emails[i].id == emailId) {
      // We found the email to remove
      int j;
      for (j = i; j < mailingList->num_emails - 1; j++) {
        // Shift all the emails after the removed email down by one
        mailingList->emails[j] = mailingList->emails[j + 1];
      }
      mailingList->num_emails--;
      printf("Email removed from mailing list.\n");
      return;
    }
  }
  printf("Could not find email with ID %d in mailing list.\n", emailId);
}

// Function to print an email
void printEmail(Email email) {
  printf("ID: %d\n", email.id);
  printf("Sender: %s\n", email.sender);
  printf("Recipient: %s\n", email.recipient);
  printf("Subject: %s\n", email.subject);
  printf("Message: %s\n", email.message);
}

// Function to print all emails in a mailing list
void printMailingList(MailingList* mailingList) {
  printf("Mailing list:\n");
  int i;
  for (i = 0; i < mailingList->num_emails; i++) {
    printEmail(mailingList->emails[i]);
  }
}

int main() {
  MailingList mailingList;
  mailingList.num_emails = 0;

  while (1) {
    printf("Enter command (add, remove, print, quit):\n");
    char command[10];
    scanf("%s", command);

    if (strcmp(command, "add") == 0) {
      Email email;
      email.id = mailingList.num_emails + 1;

      printf("Enter sender:\n");
      scanf("%s", email.sender);

      printf("Enter recipient:\n");
      scanf("%s", email.recipient);

      printf("Enter subject:\n");
      scanf("%s", email.subject);

      printf("Enter message:\n");
      scanf("%s", email.message);

      addEmailToMailingList(&mailingList, email);
    } else if (strcmp(command, "remove") == 0) {
      int emailId;
      printf("Enter email ID to remove:\n");
      scanf("%d", &emailId);
      removeEmailFromMailingList(&mailingList, emailId);
    } else if (strcmp(command, "print") == 0) {
      printMailingList(&mailingList);
    } else if (strcmp(command, "quit") == 0) {
      printf("Goodbye!\n");
      break;
    } else {
      printf("Invalid command.\n");
    }
  }

  return 0;
}