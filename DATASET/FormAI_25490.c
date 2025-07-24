//FormAI DATASET v1.0 Category: Log analysis ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000
#define MAX_NUM_LINES 5000
#define MAX_TIME_DIFF 10

typedef struct {
    char timestamp[20];
    char tag[10];
    char message[MAX_LINE_LEN];
} LogLine;

int main() {
    FILE *fp;
    char line[MAX_LINE_LEN];
    LogLine lines[MAX_NUM_LINES];
    int i = 0, j = 0, k = 0, lineCount = 0;
    int timeDiffs[MAX_NUM_LINES];
    char *tempStr;
    char *tempPtr1, *tempPtr2;
    int tempDiff;

    // Open file for reading
    fp = fopen("log.txt", "r");
    if (fp == NULL) {
        printf("Error opening log file!\n");
        exit(1);
    }

    // Read in log file line by line and parse into LogLine struct
    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        sscanf(line, "%s %s %[^\n]%*c", lines[i].timestamp, lines[i].tag, lines[i].message);
        i++;
        lineCount++;
    }

    // Close file
    fclose(fp);

    // Calculate time differences between log entries
    for (i = 0; i < lineCount; i++) {
        tempStr = strtok(lines[i].timestamp, ".");
        tempPtr1 = strptime(tempStr, "%Y-%m-%d %H:%M:%S", NULL);
        tempPtr2 = strptime(lines[i-1].timestamp, "%Y-%m-%d %H:%M:%S", NULL);
        tempDiff = (mktime(tempPtr1) - mktime(tempPtr2));
        timeDiffs[j] = tempDiff;
        if (abs(tempDiff) > MAX_TIME_DIFF) j++;
    }

    // Print log entries with time differences greater than MAX_TIME_DIFF
    for (k = 0; k < j; k++) {
        printf("Timestamp 1: %s, Timestamp 2: %s, Time Difference: %d\n", lines[k+1].timestamp, lines[k].timestamp, timeDiffs[k]);
        printf("Tag: %s, Message: %s\n", lines[k+1].tag, lines[k+1].message);
    }

    return 0;
}