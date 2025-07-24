//FormAI DATASET v1.0 Category: Digital Diary ; Style: Machiavellien
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char entry[1000];
    FILE *fp;
    time_t now;
    struct tm *local_time;

    time(&now);
    local_time = localtime(&now);

    printf("Welcome to your Machiavellian Digital Diary\n\n");
    printf("Please enter your entry for today:\n");

    fgets(entry, 1000, stdin);

    int length = strlen(entry);
    if (entry[length - 1] == '\n') {
        entry[length - 1] = '\0';
    }

    fp = fopen("diary.txt", "a");

    if (fp == NULL) {
        printf("Error opening file! Exiting...\n");
        exit(1);
    }

    fprintf(fp, "\n---Entry for %d/%d/%d %d:%d:%d---\n%s", 
            local_time->tm_year + 1900, local_time->tm_mon + 1, local_time->tm_mday,
            local_time->tm_hour, local_time->tm_min, local_time->tm_sec, entry);

    printf("\nEntry added successfully!\n");

    fclose(fp);

    return 0;
}