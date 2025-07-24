//FormAI DATASET v1.0 Category: Digital Diary ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRY_LENGTH 100

int main()
{
    FILE *fp;
    char entry[MAX_ENTRY_LENGTH];
    struct tm* tm_info;
    time_t raw_time;
    char date[20];

    printf("Welcome to your digital diary!\n");

    fp = fopen("diary.txt", "a+");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    time(&raw_time);
    tm_info = localtime(&raw_time);
    strftime(date, 20, "%Y-%m-%d %H:%M:%S", tm_info);

    printf("Enter your thoughts for today (max %d characters):\n", MAX_ENTRY_LENGTH);
    fgets(entry, MAX_ENTRY_LENGTH, stdin);

    fprintf(fp, "%s: %s", date, entry);
    fclose(fp);

    printf("Your entry has been saved to your diary file.\n");

    return 0;
}