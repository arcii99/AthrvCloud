//FormAI DATASET v1.0 Category: Digital Diary ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Async function to get user input
void getUserInput(char* userInput, int* length)
{
    printf("Enter contents of diary: ");
    fgets(userInput, 500, stdin);
    *length = strlen(userInput);
}

// Async function to write to the diary
void writeToDiary(char* userInput, int length)
{
    time_t current_time;
    char* timestamp;

    // Get current time
    current_time = time(NULL);

    // Convert to local time
    timestamp = ctime(&current_time);

    // Remove newline character from timestamp
    timestamp[strlen(timestamp) - 1] = '\0';

    // Write to diary file
    FILE *fp;
    fp = fopen("diary.txt", "a");
    fprintf(fp, "[%s] %s\n", timestamp, userInput);
    fclose(fp);

    printf("Successfully added to diary.\n");
}

int main()
{
    char userInput[500];
    int length = 0;

    // Get user input asynchronously
    getUserInput(userInput, &length);

    // Write to diary asynchronously
    writeToDiary(userInput, length);

    return 0;
}