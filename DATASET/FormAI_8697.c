//FormAI DATASET v1.0 Category: Email Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char menu[255] = "";
  char email[255] = "";
  char subject[255] = "";
  char content[1024] = "";
  char recipient[255] = "";

  printf("Welcome to Shape Shifting Email Client!\n");

  while(strcmp(menu, "exit") != 0) {
    printf("Please choose an option:\n");
    printf("- Compose email (compose)\n");
    printf("- View inbox (inbox)\n");
    printf("- Exit (exit)\n");
    scanf("%s", menu);

    if(strcmp(menu, "compose") == 0) {
      printf("Please enter recipient email address:\n");
      scanf("%s", recipient);
      printf("Please enter email subject:\n");
      scanf("%s", subject);
      printf("Please enter email content:\n");
      scanf("%s", content);
      printf("Email sent to %s\n", recipient);
    } else if(strcmp(menu, "inbox") == 0) {
      printf("Loading inbox...\n");
      printf("You have no messages\n");
    } else if(strcmp(menu, "exit") != 0) {
      printf("Invalid option. Please try again.\n");
    }
  }

  printf("Goodbye!\n");
  return 0;
}