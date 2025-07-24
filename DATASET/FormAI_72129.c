//FormAI DATASET v1.0 Category: System event logger ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* eventName, char* eventType, char* eventDescription, char* userName) {
  FILE *fp;
  time_t now;
  char timestamp[20];

  // Get current time
  time(&now);
  strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));

  // Open log file in append mode
  fp = fopen("event.log", "a");

  // Log event details to file
  fprintf(fp, "[%s] Event: %s, Type: %s, Description: %s, User: %s\n", timestamp, eventName, eventType, eventDescription, userName);

  // Close file
  fclose(fp);
}

int main() {
  // Simulate event log examples
  logEvent("File Uploaded", "Upload", "User uploaded new file", "John Doe");
  logEvent("Login Attempt", "Login", "User attempted to login with incorrect credentials", "Jane Smith");
  logEvent("Account Creation", "Registration", "New user account created successfully", "Bob Johnson");

  return 0;
}