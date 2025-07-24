//FormAI DATASET v1.0 Category: Digital Diary ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct entry {
    int month, day, year; // date of entry
    char title[50]; // title of entry
    char text[500]; // content of entry
};

int main() {
    time_t current_time;
    struct tm *time_info;
    char date_string[50];
    time(&current_time);
    time_info = localtime(&current_time); // get current time and date
    strftime(date_string, sizeof(date_string), "%m/%d/%Y", time_info); // format date as "MM/DD/YYYY"

    FILE *diary = fopen("digital_diary.txt", "a");
    if (diary == NULL) {
        printf("Error: Unable to open diary\n");
        return -1;
    }

    struct entry new_entry;
    printf("Welcome to your Digital Diary!\n");
    printf("Please enter a title for your entry (50 character max):\n");
    fgets(new_entry.title, 50, stdin);
    printf("Enter the content of your entry (500 character max):\n");
    fgets(new_entry.text, 500, stdin);
    new_entry.month = time_info->tm_mon + 1;
    new_entry.day = time_info->tm_mday;
    new_entry.year = time_info->tm_year + 1900;

    fprintf(diary, "%s\n", new_entry.title);
    fprintf(diary, "%s\n", date_string);
    fprintf(diary, "%s\n", new_entry.text);
    fprintf(diary, "-----\n");

    fclose(diary);

    printf("\n\nEntry added successfully!\n");

    return 0;
}