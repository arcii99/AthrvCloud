//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char input[100];
  int detected = 0;

  printf("Welcome to our cheerful intrusion detection system!\n");
  printf("Please enter your password to continue: ");

  fgets(input, 100, stdin);
  input[strcspn(input, "\n")] = 0;  // remove newline character

  if (strcmp(input, "password123") != 0) {
    printf("Error: Incorrect password!\n");
    exit(1);
  }

  printf("You have successfully logged in.\n");

  while (1)
  {
    printf("\nEnter a command: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;  // remove newline character

    if (strstr(input, "rm -rf") != NULL) {
      printf("Error: Command not allowed!\n");
      detected = 1;
    }
  
    if (strstr(input, "sudo") != NULL) {
      printf("Error: Command not allowed!\n");
      detected = 1;
    }

    if (detected) {
      printf("Intrusion detected! Closing program.\n");
      exit(1);
    }
  }

  return 0;
}