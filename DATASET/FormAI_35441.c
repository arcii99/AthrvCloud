//FormAI DATASET v1.0 Category: Digital Diary ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRY_SIZE 1000

int main() {
    char entry[MAX_ENTRY_SIZE];
    time_t currentTime;
    struct tm* timeInfo;
    char fileName[20];
    FILE *fp;

    // Get current time
    time(&currentTime);
    timeInfo = localtime(&currentTime);

    // Create file name with current date
    sprintf(fileName, "%d-%02d-%02d.txt", timeInfo->tm_year + 1900, timeInfo->tm_mon + 1, timeInfo->tm_mday);

    // Open file for writing
    fp = fopen(fileName, "a");

    if (fp == NULL) {
        printf("Error: could not open file %s\n", fileName);
        return 1;
    }

    // Get user input and write to file
    printf("Please enter today's diary entry (max %d characters):\n", MAX_ENTRY_SIZE);
    fgets(entry, MAX_ENTRY_SIZE, stdin);

    fprintf(fp, "%02d:%02d:%02d - %s", timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec, entry);

    fclose(fp);

    printf("\nEntry has been saved to %s.\n", fileName);

    return 0;
}