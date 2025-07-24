//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: mind-bending
#include<stdio.h>

int main() {
  printf("Initializing Intrusion Detection System...\n");
  printf("Please enter your username: ");
  char username[20];
  scanf("%s", username);
  printf("Welcome, %s!\n", username);
  
  printf("Please enter your password: ");
  char password[20];
  scanf("%s", password);
  
  int attempts = 0;
  
  while (attempts < 3) {
    if (strcmp(password, "password123") == 0) {
      printf("Access granted.\n");
      break;
    } else {
      attempts++;
      printf("Password incorrect. Attempts left: %d\n", 3 - attempts);
      if (attempts == 3) {
        printf("INTRUSION ALERT! Locking user out...\n");
        break;
      }
      printf("Please enter password again: ");
      scanf("%s", password);
    }
  }

  return 0;
}