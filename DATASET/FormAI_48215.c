//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 100

// Struct to hold log entries
typedef struct {
   char timestamp[20];
   char source_ip[16];
   char message[MAX_LOG_ENTRY_LENGTH];
} LogEntry;

// Struct to hold an array of log entries
typedef struct {
   LogEntry entries[MAX_LOG_ENTRIES];
   int size;
} Log;

// Struct to hold a threshold value for number of log entries per minute
typedef struct {
   int value;
} Threshold;

// Function to parse a log entry
void parse_log_entry(char *line, LogEntry *entry) {
   char timestamp[20];
   char source_ip[16];
   char message[MAX_LOG_ENTRY_LENGTH];
   sscanf(line, "%[^,],%[^,],%[^\n]", timestamp, source_ip, message);
   strcpy(entry->timestamp, timestamp);
   strcpy(entry->source_ip, source_ip);
   strcpy(entry->message, message);
}

// Function to log an entry to a file
void log_entry(LogEntry entry) {
   FILE *fp = fopen("log.txt", "a");
   fprintf(fp, "%s,%s,%s\n", entry.timestamp, entry.source_ip, entry.message);
   fclose(fp);
}

// Function to read the log file and populate a Log struct
void read_log(Log *log) {
   FILE *fp = fopen("log.txt", "r");
   char line[MAX_LOG_ENTRY_LENGTH+37];
   while (fgets(line, sizeof(line), fp) != NULL) {
      LogEntry entry;
      parse_log_entry(line, &entry);
      log->entries[log->size] = entry;
      log->size++;
   }
   fclose(fp);
}

// Function to check the number of log entries per minute
int check_threshold(Log *log, Threshold threshold) {
   int count = 0;
   time_t current_time = time(NULL);
   for (int i=0; i<log->size; i++) {
      struct tm *entry_time = localtime(&current_time);
      sscanf(log->entries[i].timestamp, "%02d:%02d:%02d", &entry_time->tm_hour, &entry_time->tm_min, &entry_time->tm_sec);
      time_t entry_unix_time = mktime(entry_time);
      if (current_time - entry_unix_time <= 60) {
         count++;
      }
   }
   return (count > threshold.value);
}

int main() {
   Log log;
   Threshold threshold = {5};
   read_log(&log);
   if (check_threshold(&log, threshold)) {
      printf("Possible intrusion detected!\n");
      LogEntry entry = {
         "00:00:00",
         "192.168.1.1",
         "Possible intrusion detected"
      };
      log_entry(entry);
   }
   else {
      printf("No intrusion detected\n");
   }
   return 0;
}