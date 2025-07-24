//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 200
#define MAX_LOGIN_ATTEMPTS 3
#define MAX_FAILED_LOGINS 5

int main() {
  char line[MAX_LINE_LENGTH];
  char user[MAX_LINE_LENGTH];
  char password[MAX_LINE_LENGTH];
  int failedLogins = 0;
  int loginAttempts = 0;
  FILE *file;

  file = fopen("access.log", "r");

  while (fgets(line, MAX_LINE_LENGTH, file)) {
    if (strstr(line, "Failed password for")) {
      loginAttempts++;
      sscanf(line, "%*s %*s %*s %s", user);
      sscanf(line, "%*s %*s %*s %*s %*s %*s %s", password);

      if (loginAttempts >= MAX_LOGIN_ATTEMPTS) {
        printf("INTRUSION DETECTED: Too many login attempts from %s\n", user);
        failedLogins++;
        loginAttempts = 0;
      }
    } else if (strstr(line, "Accepted password for")) {
      loginAttempts = 0;
    }

    if (failedLogins >= MAX_FAILED_LOGINS) {
      printf("INTRUSION DETECTED: Too many failed logins\n");
      exit(0);
    }
  }

  printf("No intrusion detected\n");
  fclose(file);
  return 0;
}