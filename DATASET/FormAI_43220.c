//FormAI DATASET v1.0 Category: System event logger ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(const char* event) {
  FILE *fp;

  fp = fopen("/var/log/myapp.log", "a+");

  if (fp == NULL) {
      printf("Error opening log file!\n");
      exit(1);
  }

  time_t now = time(NULL);
  char* time_str = ctime(&now);
  time_str[strlen(time_str)-1] = '\0'; // Remove newline from ctime output

  fprintf(fp, "[%s] %s\n", time_str, event);

  fclose(fp);
}

int main() {
  logEvent("Starting program");

  // Some code to execute here...

  logEvent("Program executed successfully");
  return 0;
}