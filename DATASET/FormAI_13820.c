//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  int i;
  int attempts = 0;
  char password[10];
  char attempt[10];
  srand(time(NULL));
  for (i = 0; i < 10; i++) {
    password[i] = (rand() % 26) + 97;
  }
  printf("Welcome to the Intrusion Detection System!\n");
  printf("The password is a 10 character string consisting of lowercase letters.\n");
  while (1) {
    printf("Please enter the password: ");
    scanf("%s", attempt);
    attempts++;
    if (strcmp(password, attempt) == 0) {
      printf("Access granted after %d attempts.\n", attempts);
      break;
    } else {
      printf("Incorrect password. Please try again.\n");
      if (attempts % 3 == 0) {
        printf("Intruder alert! The system administrator has been notified.\n");
      }
    }
  }
  return 0;
}