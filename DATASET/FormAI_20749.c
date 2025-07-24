//FormAI DATASET v1.0 Category: Mailing list manager ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

#define MAX_EMAILS 1000

int main() {
  printf("Welcome to the Mailing List Manager!\n");

  // initialize mailing list
  char emails[MAX_EMAILS][100];
  int num_emails = 0;

  // main program loop
  char input[100];
  while (1) {
    // get user input
    printf("\nEnter a command (\"add\", \"remove\", or \"list\"): ");
    fgets(input, 100, stdin);

    // remove newline character from input
    input[strcspn(input, "\n")] = 0;

    // check command
    if (strcmp(input, "add") == 0) {
      // add email to mailing list
      if (num_emails < MAX_EMAILS) {
        printf("Enter email address: ");
        fgets(emails[num_emails], 100, stdin);
        emails[num_emails][strcspn(emails[num_emails], "\n")] = 0; // remove newline character
        num_emails++;
        printf("Email added to mailing list!\n");
      } else {
        printf("Mailing list is full!\n");
      }
    } else if (strcmp(input, "remove") == 0) {
      // remove email from mailing list
      printf("Enter email address to remove: ");
      char remove_email[100];
      fgets(remove_email, 100, stdin);
      remove_email[strcspn(remove_email, "\n")] = 0; // remove newline character
      
      // search for email in mailing list
      int found_index = -1;
      for (int i = 0; i < num_emails; i++) {
        if (strcmp(emails[i], remove_email) == 0) {
          found_index = i;
          break;
        }
      }

      if (found_index == -1) {
        printf("Email not found in mailing list!\n");
      } else {
        // shift emails after found email to fill gap
        for (int i = found_index; i < num_emails - 1; i++) {
          strcpy(emails[i], emails[i+1]);
        }
        num_emails--;
        printf("Email removed from mailing list!\n");
      }
    } else if (strcmp(input, "list") == 0) {
      // print mailing list
      printf("Mailing list:\n");
      for (int i = 0; i < num_emails; i++) {
        printf("%d. %s\n", i + 1, emails[i]);
      }
    } else {
      printf("Invalid command!\n");
    }
  }

  return 0;
}