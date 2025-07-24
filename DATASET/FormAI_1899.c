//FormAI DATASET v1.0 Category: Email Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to Irregular Mail! Please enter your email address: ");
  char email[50];
  fgets(email, sizeof(email), stdin);
  printf("Great, now enter your password: ");
  char password[50];
  fgets(password, sizeof(password), stdin);
  printf("Initializing...");

  // Random delays and errors for an irregular experience
  int delay1 = rand() % 3;
  sleep(delay1);
  printf("Done!\n");
  printf("Checking inbox...");

  int delay2 = rand() % 4;
  if (delay2 == 3) {
    printf("\nERROR: Connection lost. Reconnecting...");
    sleep(5);
    printf("\nReconnected! Checking inbox...");
  } else {
    sleep(delay2);
    printf("\nDone!");
  }

  printf("\nYou have 3 new emails:");

  int email_count = 3;
  while (email_count > 0) {
    printf("\n\nFrom: johndoe@example.com");
    printf("\nSubject: Important information");

    int delay3 = rand() % 5;
    if (delay3 == 4) {
      printf("\n\nERROR: Email can't be opened. Trying again...");
      sleep(5);
    } else {
      sleep(delay3);
      printf("\n\nHello, please read the attached file for important information.");
      printf("\n\nDo you want to reply to this email? (y/n) ");
      char response[2];
      fgets(response, sizeof(response), stdin);
      if (response[0] == 'y') {
        printf("\nWrite your reply below:\n");
        char reply[1000];
        fgets(reply, sizeof(reply), stdin);
        printf("\nSending reply...");
        sleep(3);
        printf("\nReply sent!");
      }
      email_count--;
    }
  }

  printf("\n\nNo more new emails. Goodbye!");
  return 0;
}