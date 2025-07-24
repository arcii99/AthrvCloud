//FormAI DATASET v1.0 Category: Digital Diary ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Entry {
    char date[11];
    char time[9];
    char title[50];
    char content[500];
};

int main() {
    struct Entry diaryEntry;
    FILE *fp;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(diaryEntry.date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    sprintf(diaryEntry.time, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);

    printf("Welcome to your digital diary!\n\n");

    printf("Enter title: ");
    fgets(diaryEntry.title, 50, stdin);

    printf("Enter content: ");
    fgets(diaryEntry.content, 500, stdin);

    fp = fopen("diary.txt", "a");

    if (fp == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    fprintf(fp, "%s | %s | %s | %s\n", diaryEntry.date, diaryEntry.time, diaryEntry.title, diaryEntry.content);
    fclose(fp);

    printf("\nEntry saved to diary.txt\n");

    return 0;
}