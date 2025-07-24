//FormAI DATASET v1.0 Category: Digital Diary ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000

typedef struct {
    char date[20];
    char time[20];
    char subject[100];
    char entry[10000];
} diary_entry;

diary_entry diary[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    char date[20];
    char time[20];

    sprintf(date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    sprintf(time, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);

    diary_entry new_entry;

    strcpy(new_entry.date, date);
    strcpy(new_entry.time, time);

    printf("Subject: ");
    fflush(stdout); // Making sure the prompt outputs before accepting user input
    fgets(new_entry.subject, 100, stdin);
    new_entry.subject[strcspn(new_entry.subject, "\n")] = 0; // Removing the trailing newline character

    printf("Entry: ");
    fflush(stdout);
    fgets(new_entry.entry, 10000, stdin);
    new_entry.entry[strcspn(new_entry.entry, "\n")] = 0;

    diary[num_entries++] = new_entry;

    printf("\nEntry added.\n");
}

void view_entries() {
    printf("\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s - %s\n", diary[i].date, diary[i].time, diary[i].subject);
        printf("%s\n", diary[i].entry);
        printf("\n");
    }
}

void save_entries() {
    FILE *fp = fopen("diary.txt", "w");

    for (int i = 0; i < num_entries; i++) {
        fprintf(fp, "%s %s - %s\n", diary[i].date, diary[i].time, diary[i].subject);
        fprintf(fp, "%s\n", diary[i].entry);
        fprintf(fp, "\n");
    }

    fclose(fp);

    printf("\nEntries saved to file.\n");
}

int main() {
    printf("Digital Diary\n");

    while (1) {
        printf("\n1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Save entries to file\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");

        int choice = 0;
        scanf("%d", &choice);
        getchar(); // Remove the newline from the input buffer

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                save_entries();
                break;
            case 4:
                printf("\nExiting...\n");
                return 0;
            default:
                printf("\nInvalid choice.\n");
        }
    }
}