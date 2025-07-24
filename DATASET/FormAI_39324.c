//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: calm
#include <stdio.h>
#include <string.h>

#define MAX_ATTEMPTS 3

// function to check for intrusion
int detect_intrusion() {
  char username[20];
  char password[20];
  int attempt = 0;

  // prompt user for credentials
  printf("Enter your username: ");
  scanf("%s", username);
  printf("Enter your password: ");
  scanf("%s", password);

  // check credentials
  while (attempt < MAX_ATTEMPTS) {
    if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
      return 0; // no intrusion detected
    } else {
      printf("Invalid credentials. Attempts left: %d\n", MAX_ATTEMPTS - attempt - 1);
      attempt++;
      // prompt user again
      printf("Enter your username: ");
      scanf("%s", username);
      printf("Enter your password: ");
      scanf("%s", password);
    }
  }
  // intrusion detected
  printf("Intrusion detected.\n");
  return 1;
}

// main function
int main() {
  int intrusion_detected = detect_intrusion();
  if (intrusion_detected == 0) {
    printf("Welcome, admin!\n");
  }
  return 0;
}