//FormAI DATASET v1.0 Category: System event logger ; Style: mind-bending
#include <stdio.h>
#include <time.h>

int main() {
  FILE *logfile;
  time_t rawtime;
  struct tm *timeinfo;
  char buffer[80], event[100];

  logfile = fopen("event_log.txt", "a");
  if (logfile == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  printf("Enter the event description:\n");
  fgets(event, 100, stdin);

  rawtime = time(NULL);
  timeinfo = localtime(&rawtime);
  strftime(buffer, 80, "%x - %I:%M%p", timeinfo);

  printf("\nLogging event...\n");
  fprintf(logfile, "[%s] %s\n", buffer, event);

  fclose(logfile);

  printf("\nEvent logged successfully! Check event_log.txt for details.\n");

  return 0;
}