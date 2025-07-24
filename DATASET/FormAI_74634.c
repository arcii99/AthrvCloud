//FormAI DATASET v1.0 Category: Digital Diary ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRY_LENGTH 100
#define MAX_FILEPATH_LENGTH 50
#define DATE_LENGTH 11
#define TIME_LENGTH 6

void getDate(char *date) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

void getTime(char *timeStr) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(timeStr, "%02d:%02d", tm.tm_hour, tm.tm_min);
}

void viewDiary(char *filePath) {
    FILE *filePtr = fopen(filePath, "r");
    if (filePtr == NULL) {
        printf("ERROR: Unable to open file!\n");
        return;
    }

    char entry[MAX_ENTRY_LENGTH];
    char date[DATE_LENGTH];
    char timeStr[TIME_LENGTH];

    printf("Entries:\n");
    while (fgets(entry, MAX_ENTRY_LENGTH, filePtr) != NULL) {
        fgets(date, DATE_LENGTH, filePtr);
        fgets(timeStr, TIME_LENGTH, filePtr);

        printf("> %s\n", entry);
        printf("  %s %s\n", date, timeStr);
    }

    fclose(filePtr);
}

void createEntry(char *filePath) {
    char entry[MAX_ENTRY_LENGTH];
    char date[DATE_LENGTH];
    char timeStr[TIME_LENGTH];

    printf("Enter your entry:");
    fgets(entry, MAX_ENTRY_LENGTH, stdin);

    getDate(date);
    getTime(timeStr);

    FILE *filePtr = fopen(filePath, "a");
    fprintf(filePtr, "%s", entry);
    fprintf(filePtr, "%s\n", date);
    fprintf(filePtr, "%s\n", timeStr);
    fclose(filePtr);
}

int main() {
    char option;
    char filePath[MAX_FILEPATH_LENGTH];
    char fileName[] = "diary.txt";

    printf("Welcome to your digital diary!\n");

    size_t fileNameLength = strlen(fileName);
    strcpy(filePath, getenv("HOME"));
    strcat(filePath, "/");
    strcat(filePath, fileName);

    FILE *filePtr = fopen(filePath, "a");
    if (filePtr == NULL) {
        printf("ERROR: Unable to create file!\n");
        return 1;
    }
    fclose(filePtr);

    do {
        printf("Choose an option:\n");
        printf("1. Create an entry\n");
        printf("2. View entries\n");
        printf("3. Exit\n");

        scanf(" %c", &option);
        getchar(); // Capture the newline character after scanning in option

        switch (option) {
            case '1':
                createEntry(filePath);
                break;
            case '2':
                viewDiary(filePath);
                break;
            case '3':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    } while (option != '3');

    return 0;
}