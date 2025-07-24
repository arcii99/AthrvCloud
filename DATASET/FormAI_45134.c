//FormAI DATASET v1.0 Category: Mailing list manager ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_EMAILS 1000

int num_emails = 0; // number of emails in the list

typedef struct {
  char *name;
  char *email;
} Contact;

Contact emails[MAX_EMAILS];

int main() {
  char option;
  while (1) {
    printf("Welcome to the Mailing List Manager!\n");
    printf("Please select an option:\n");
    printf("1. Add an email\n");
    printf("2. Remove an email\n");
    printf("3. View all emails\n");
    printf("4. Exit\n");

    option = getchar();

    // Clear input buffer
    while(getchar() != '\n');

    switch(option) {
      case '1':
        add_email(); // add an email to the list
        break;
      case '2':
        remove_email(); // remove an email from the list
        break;
      case '3':
        view_emails(); // view all emails in the list
        break;
      case '4':
        printf("Goodbye!\n"); // exit the program
        exit(0);
        break;
      default:
        printf("Invalid option.\n");
        break;
    }

    printf("\n");
  }

  return 0;
}

void add_email() {
  char *name = malloc(sizeof(char) * 50); // allocate memory for name string
  char *email = malloc(sizeof(char) * 50); // allocate memory for email string

  printf("Enter name: ");
  fgets(name, 50, stdin); // read name from stdin
  name[strcspn(name, "\n")] = 0; // remove newline character

  printf("Enter email: ");
  fgets(email, 50, stdin); // read email from stdin
  email[strcspn(email, "\n")] = 0; // remove newline character

  if (num_emails >= MAX_EMAILS) {
    printf("Error: Maximum number of emails reached.\n");
    return;
  }

  Contact new_contact = {name, email};
  emails[num_emails++] = new_contact;
}

void remove_email() {
  char *email = malloc(sizeof(char) * 50); // allocate memory for email string

  printf("Enter email to remove: ");
  fgets(email, 50, stdin); // read email from stdin
  email[strcspn(email, "\n")] = 0; // remove newline character

  int index = -1;
  for (int i = 0; i < num_emails; i++) {
    if (strcmp(emails[i].email, email) == 0) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    printf("Error: Email not found.\n");
    return;
  }

  free(emails[index].name); // free allocated memory for name
  free(emails[index].email); // free allocated memory for email

  for (int i = index; i < num_emails-1; i++) {
    emails[i] = emails[i+1]; // move all elements after removed email one index to the left
  }

  num_emails--;
}

void view_emails() {
  printf("List of Emails:\n");
  for (int i = 0; i < num_emails; i++) {
    printf("%s: %s\n", emails[i].name, emails[i].email);
  }
}