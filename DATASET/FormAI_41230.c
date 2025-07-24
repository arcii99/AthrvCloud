//FormAI DATASET v1.0 Category: Log analysis ; Style: authentic
#include <stdio.h>
#include <string.h>

void analyzeLogFile(FILE *logfile) {
  char line[256];
  int numWarnings = 0;
  int numErrors = 0;
  int numInfo = 0;
  int numDebug = 0;

  while (fgets(line, sizeof(line), logfile)) {
    if (strstr(line, "WARNING")) {
      numWarnings++;
    }
    else if (strstr(line, "ERROR")) {
      numErrors++;
    }
    else if (strstr(line, "INFO")) {
      numInfo++;
    }
    else if (strstr(line, "DEBUG")) {
      numDebug++;
    }
  }

  printf("\nLog Analysis:\n");
  printf("Number of warnings: %d\n", numWarnings);
  printf("Number of errors: %d\n", numErrors);
  printf("Number of info messages: %d\n", numInfo);
  printf("Number of debug messages: %d\n", numDebug);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: loganalyze log_file_name\n");
    return -1;
  }

  FILE *logfile = fopen(argv[1], "r");
  if (!logfile) {
    printf("Error: failed to open log file %s\n", argv[1]);
    return -2;
  }

  printf("Analyzing log file %s...\n", argv[1]);
  analyzeLogFile(logfile);
  fclose(logfile);

  return 0;
}