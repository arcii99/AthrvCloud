//FormAI DATASET v1.0 Category: System event logger ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char* event) {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  char filename[100];
  sprintf(filename, "logs/%d-%02d-%02d.log", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
  FILE *file = fopen(filename, "a");
  if (file == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }
  fprintf(file, "%02d:%02d:%02d %s\n", tm.tm_hour, tm.tm_min, tm.tm_sec, event);
  fclose(file);
}

int main() {
  log_event("System started");
  printf("Hello, world!\n");
  log_event("Greeting displayed");
  int x = 5;
  int y = 7;
  int sum = x + y;
  printf("The sum of %d and %d is %d\n", x, y, sum);
  log_event("Calculation performed");
  return 0;
}