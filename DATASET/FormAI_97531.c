//FormAI DATASET v1.0 Category: Log analysis ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_LOG_LEVELS 5

// Define a structure to store a log entry
struct LogEntry {
    char level[MAX_LINE_LENGTH];
    char message[MAX_LINE_LENGTH];
};

// Define a function to parse a log file and return an array of LogEntry structures
int parseLog(char* filename, struct LogEntry entries[]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }
    
    char line[MAX_LINE_LENGTH];
    int num_entries = 0;
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        char* level = strtok(line, " ");
        char* message = strtok(NULL, "\n");
        
        if (level != NULL && message != NULL) {
            struct LogEntry entry;
            strncpy(entry.level, level, MAX_LINE_LENGTH);
            strncpy(entry.message, message, MAX_LINE_LENGTH);
            entries[num_entries++] = entry;
        }
    }
    
    fclose(file);
    return num_entries;
}

// Define a function to print a summary of the log file
void printSummary(struct LogEntry entries[], int num_entries) {
    printf("Log file summary:\n");
    
    int counts[MAX_LOG_LEVELS] = { 0 };
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].level, "INFO") == 0) {
            counts[0]++;
        } else if (strcmp(entries[i].level, "WARN") == 0) {
            counts[1]++;
        } else if (strcmp(entries[i].level, "ERROR") == 0) {
            counts[2]++;
        } else if (strcmp(entries[i].level, "DEBUG") == 0) {
            counts[3]++;
        } else {
            counts[4]++;
        }
    }
    
    printf("INFO: %d\n", counts[0]);
    printf("WARN: %d\n", counts[1]);
    printf("ERROR: %d\n", counts[2]);
    printf("DEBUG: %d\n", counts[3]);
    printf("OTHER: %d\n", counts[4]);
}

// Define the main function to run the program
int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./log_analysis <file>\n");
        return 0;
    }
    
    char* filename = argv[1];
    struct LogEntry entries[MAX_LINE_LENGTH];
    int num_entries = parseLog(filename, entries);
    if (num_entries < 0) {
        return 0;
    }
    
    printSummary(entries, num_entries);
    
    return 0;
}