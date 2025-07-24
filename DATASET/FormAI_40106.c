//FormAI DATASET v1.0 Category: Digital Diary ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_FILE "my_diary.txt"
#define MAX_LINE_LENGTH 1000

int main() {
    char entry[MAX_LINE_LENGTH];
    char date[20];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(date, sizeof(date), "%d/%m/%Y", t);
    FILE *fp;

    printf("Welcome to your digital diary! What would you like to write about today?\n");

    fgets(entry, MAX_LINE_LENGTH, stdin);
    entry[strlen(entry) - 1] = '\0';

    fp = fopen(DIARY_FILE, "a");
    if (fp == NULL) {
        printf("Error opening file %s\n", DIARY_FILE);
        exit(1);
    }

    fprintf(fp, "%s - %s\n", date, entry);
    fclose(fp);

    printf("\nEntry recorded! Here's what you wrote:\n%s - %s\n", date, entry);

    return 0;
}