//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: creative
#include <stdio.h>
#include <string.h>

#define MAX_LOGIN_ATTEMPTS 3
#define MAX_PASSWORD_LENGTH 15

int main(void) {
  char username[20];
  char password[MAX_PASSWORD_LENGTH + 1];
  int login_attempts = 0;
  int suspicious_activity_detected = 0;

  while (login_attempts < MAX_LOGIN_ATTEMPTS) {
    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "password123") == 0) {
      printf("Welcome, admin!\n");
      break;
    } else {
      printf("Invalid username or password!\n");
      login_attempts += 1;
    }

    if (login_attempts == 3) {
      printf("Too many login attempts. Your account is now locked.\n");
      suspicious_activity_detected = 1;
    }
  }

  if (suspicious_activity_detected) {
    printf("INTRUSION DETECTED! NOTIFICATION SENT TO ADMIN.\n");
  }

  return 0;
}