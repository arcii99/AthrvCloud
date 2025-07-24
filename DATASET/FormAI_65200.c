//FormAI DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    char diary[1000];
    char date[20];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    FILE *fp;

    printf("Welcome to my Digital Diary!\n");

    fp = fopen("diary.txt", "a+");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Today's date is: %s\n", date);

    printf("Please enter your diary entry for today:\n");
    fgets(diary, 1000, stdin);

    fprintf(fp, "%s: %s\n", date, diary);

    printf("Your entry has been added to the diary!\n");

    fclose(fp);

    return 0;
}