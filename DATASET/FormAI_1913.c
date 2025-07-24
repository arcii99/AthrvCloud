//FormAI DATASET v1.0 Category: Digital Diary ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char entry[200];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("Welcome to your Digital Diary.\n");
    printf("You are the only survivor of the apocalypse.\n");
    printf("Please enter a day's entry below:\n");

    fgets(entry, 200, stdin);

    FILE *fp;
    fp = fopen("diary.txt", "a");
    if (fp == NULL) {
        printf("Error opening diary file.\n");
        exit(1);
    }
    fprintf(fp, "%d-%02d-%02d: %s", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, entry);

    fclose(fp);

    printf("\nEntry saved.\n");

    return 0;
}