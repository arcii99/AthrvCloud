//FormAI DATASET v1.0 Category: Mailing list manager ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_LEN 50

// Mailing List Struct
struct MailingList {
  char name[MAX_LEN];
  char emails[MAX_EMAILS][MAX_LEN];
  int numEmails;
};

// Function to add email to mailing list
void addEmail(struct MailingList *list, char email[MAX_LEN]) {
  if (list->numEmails == MAX_EMAILS) {
    printf("Mailing list is full, cannot add email.\n");
    return;
  }
  strcpy(list->emails[list->numEmails], email);
  list->numEmails++;
}

// Function to print all emails in mailing list
void viewEmails(struct MailingList *list) {
  printf("Emails in mailing list %s:\n", list->name);
  for (int i = 0; i < list->numEmails; i++) {
    printf("%d. %s\n", i+1, list->emails[i]);
  }
}

int main() {
  // Initialize mailing list
  struct MailingList mylist = {"Tech Lovers", {}, 0};

  printf("Welcome to the Mailing List Manager. You are managing the mailing list %s\n", mylist.name);

  while (1) {
    printf("What would you like to do? (add email, view emails): ");

    char input[MAX_LEN];
    scanf("%s", input);

    if (strcmp(input, "add") == 0 || strcmp(input, "add email") == 0) {
      printf("Please enter email to add: ");

      char email[MAX_LEN];
      scanf("%s", email);

      addEmail(&mylist, email);
    } else if (strcmp(input, "view") == 0 || strcmp(input, "view emails") == 0) {
      viewEmails(&mylist);
    } else {
      printf("Invalid input, please try again.\n");
    }
  }

  return 0;
}