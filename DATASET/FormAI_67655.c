//FormAI DATASET v1.0 Category: Log analysis ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define structure to hold log entries */
struct LogEntry {
  char timestamp[25];
  char level[10];
  char message[100];
};

/* Function to count the number of entries in the log file */
int countEntries(FILE *logfile) {
  int count = 0;
  char line[200];

  /* Read through the file, counting each entry */
  while (fgets(line, sizeof(line), logfile)) {
    if (strlen(line) > 5 && strchr(line, ':') != NULL) {
      count++;
    }
  }

  /* Reset file pointer */
  fseek(logfile, 0L, SEEK_SET);

  return count;
}

/* Function to parse a line of log file */
void parseLine(char *line, struct LogEntry *entry) {
  char *token;
  int count = 0;

  /* Tokenize the line */
  token = strtok(line, " []");

  while (token != NULL) {
    count++;

    /* Save timestamp, level, and message */
    if (count == 1) {
      strncpy(entry->timestamp, token, sizeof(entry->timestamp));
      entry->timestamp[sizeof(entry->timestamp) - 1] = '\0';
    } else if (count == 2) {
      strncpy(entry->level, token, sizeof(entry->level));
      entry->level[sizeof(entry->level) - 1] = '\0';
    } else if (count == 3) { /* Concatenate remaining tokens to get message */
      char *message = token;
      while ((token = strtok(NULL, "")) != NULL) {
        strcat(message, token);
      }
      /* Remove newline at end of message */
      message[strcspn(message, "\n")] = '\0';
      strncpy(entry->message, message, sizeof(entry->message));
      entry->message[sizeof(entry->message) - 1] = '\0';
    }
    token = strtok(NULL, " []");
  }
}

/* Function to read the log file into a LogEntry array */
void readLog(FILE *logfile, struct LogEntry *logEntries, int count) {
  char line[200];
  int i = 0;

  while (fgets(line, sizeof(line), logfile)) {
    if (strlen(line) > 5 && strchr(line, ':') != NULL) {
      parseLine(line, &logEntries[i]);
      i++;
    }
  }
}

/* Function to print statistics for a given level */
void printStatsByLevel(struct LogEntry *logEntries, int count, char *level) {
  int i;
  int levelCount = 0;
  float levelPercent;

  /* Count number of entries for given level */
  for (i = 0; i < count; i++) {
    if (strcmp(logEntries[i].level, level) == 0) {
      levelCount++;
    }
  }

  /* Calculate percentage of entries for the given level */
  levelPercent = (float)levelCount / count * 100;

  /* Print statistics */
  printf("%d total entries in log file\n", count);
  printf("%d entries at %s level (%.2f%%)\n", levelCount, level, levelPercent);
}

int main() {
  /* Open log file */
  FILE *logfile = fopen("logfile.txt", "r");

  /* Check that log file was opened successfully */
  if (logfile == NULL) {
    printf("Error opening log file!\n");
    return 1;
  }

  /* Count number of entries in log file */
  int count = countEntries(logfile);

  /* Allocate memory for array of LogEntry structs */
  struct LogEntry *logEntries = malloc(sizeof(struct LogEntry) * count);

  /* Read log file into array */
  readLog(logfile, logEntries, count);

  /* Print statistics for each log level */
  printStatsByLevel(logEntries, count, "DEBUG");
  printStatsByLevel(logEntries, count, "INFO");
  printStatsByLevel(logEntries, count, "WARNING");
  printStatsByLevel(logEntries, count, "ERROR");
  printStatsByLevel(logEntries, count, "CRITICAL");

  /* Close log file and free memory */
  fclose(logfile);
  free(logEntries);

  return 0;
}