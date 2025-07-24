//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Ken Thompson
#include<stdio.h>
#include<string.h>

char username[20];
char password[20];
char command[100];

int main() {
  printf("Enter username: ");
  scanf("%s", &username);

  printf("Enter password: ");
  scanf("%s", &password);

  if(strcmp(username, "admin") == 0 && strcmp(password, "password123") == 0) {
    printf("Welcome Admin!\n");

    while(1) {
      printf("Enter command: ");
      scanf("%s", &command);

      if(strcmp(command, "rm -rf /") == 0) {
        printf("Intrusion attempt detected. Aborting command.\n");
      }
      else {
        printf("Command executed.\n");
        system(command);
      }
    }
  }
  else {
    printf("Invalid credentials.");
  }

  return 0;
}