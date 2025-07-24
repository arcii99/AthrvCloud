//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: intelligent
#include <stdio.h>

#define MAX_COMMAND_LENGTH 20
#define MAX_HISTORY_LENGTH 10

void executeCommand(char *command);
void displayHistory();

char history[MAX_HISTORY_LENGTH][MAX_COMMAND_LENGTH];
int historyLength = 0;

int main() {
  char input[MAX_COMMAND_LENGTH];
  
  printf("***C Drone Remote Control***\n\n");
  printf("Enter commands:\n");
  
  while (1) {
    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    
    // Remove newline character from input
    int i;
    for (i = 0; input[i] != '\n'; i++);
    input[i] = '\0';
    
    // Save command to history
    if (historyLength < MAX_HISTORY_LENGTH) {
      strcpy(history[historyLength], input);
      historyLength++;
    } else {
      // Shift history array to remove oldest command
      for (i = 1; i < MAX_HISTORY_LENGTH; i++) {
        strcpy(history[i-1], history[i]);
      }
      strcpy(history[MAX_HISTORY_LENGTH-1], input);
    }
    
    executeCommand(input);
  }
  
  return 0;
}

void executeCommand(char *command) {
  if (strcmp(command, "takeoff") == 0) {
    printf("Taking off...\n");
  } else if (strcmp(command, "land") == 0) {
    printf("Landing...\n");
  } else if (strcmp(command, "up") == 0) {
    printf("Ascending...\n");
  } else if (strcmp(command, "down") == 0) {
    printf("Descending...\n");
  } else if (strcmp(command, "forward") == 0) {
    printf("Moving forward...\n");
  } else if (strcmp(command, "back") == 0) {
    printf("Moving backward...\n");
  } else if (strcmp(command, "left") == 0) {
    printf("Moving left...\n");
  } else if (strcmp(command, "right") == 0) {
    printf("Moving right...\n");
  } else if (strcmp(command, "flip") == 0) {
    printf("Performing a flip...\n");
  } else if (strcmp(command, "history") == 0) {
    displayHistory();
  } else if (strcmp(command, "exit") == 0) {
    printf("Exiting...\n");
    exit(0);
  } else {
    printf("Invalid command\n");
  }
}

void displayHistory() {
  if (historyLength == 0) {
    printf("No commands in history\n");
  } else {
    printf("Recent commands:\n");
    int i;
    for (i = 0; i < historyLength; i++) {
      printf("%s\n", history[i]);
    }
  }
}