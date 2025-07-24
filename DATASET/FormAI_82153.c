//FormAI DATASET v1.0 Category: Digital Diary ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct DiaryEntry {
    char date[11];
    char time[10];
    char title[50];
    char content[250];
};

int main() {
    struct DiaryEntry entry;
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    strftime(entry.date, sizeof(entry.date), "%m/%d/%Y", tm);
    strftime(entry.time, sizeof(entry.time), "%I:%M:%S %p", tm);
    printf("Welcome to your Digital Diary!\n\n");
    FILE* diary = fopen("Diary.txt", "a+");
    if(diary == NULL) {
        printf("Error opening diary file!\n");
        return 0;
    }
    printf("Enter title for today's diary entry (50 character limit):\n");
    fgets(entry.title, sizeof(entry.title), stdin);
    printf("Enter diary content for today (250 character limit):\n");
    fgets(entry.content, sizeof(entry.content), stdin);
    fprintf(diary, "\nDate: %s\nTime: %s\nTitle: %s\nContent: %s\n", entry.date, entry.time, entry.title, entry.content);
    printf("\nEntry added successfully!\n");
    fclose(diary);
    return 0;
}