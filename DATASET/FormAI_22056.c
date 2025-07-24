//FormAI DATASET v1.0 Category: Log analysis ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char log[] = "2021-07-25 12:34:56,100 - INFO - User logged in successfully.";
  char *date;
  char *time;
  char *level;
  char *message;

  date = strtok(log, " ");
  time = strtok(NULL, " ");
  level = strtok(NULL, " ");
  message = strtok(NULL, "");

  printf("Date: %s\n", date);
  printf("Time: %s\n", time);
  printf("Level: %s\n", level);
  printf("Message: %s\n", message);

  return 0;
}