//FormAI DATASET v1.0 Category: Digital Diary ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Entry {
    char date[11];
    char time[6];
    char content[250];
} Entry;

int main() {
    char filename[20], input[10], content[250];
    FILE *fp;
    int choice, i, num_entries = 0;
    Entry entries[100];

    printf("Welcome to My Digital Diary!\n\n");
    printf("Enter a filename to store your entries (max 20 characters): ");
    scanf("%s", filename);
    strcat(filename, ".txt"); // add .txt extension to filename

    fp = fopen(filename, "r");
    if (fp != NULL) { // file already exists, load entries
        while (fscanf(fp, "%s %s %[^\n]", entries[num_entries].date, entries[num_entries].time, entries[num_entries].content) == 3) {
            num_entries++;
        }
        fclose(fp);
    }

    do {
        printf("\n1. View all entries\n2. Add a new entry\n3. Search for entries on a specific date\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // view all entries
                if (num_entries > 0) {
                    for (i = 0; i < num_entries; i++) {
                        printf("\nDate: %s, Time: %s, Content: %s\n", entries[i].date, entries[i].time, entries[i].content);
                    }
                } else {
                    printf("\nNo entries found.\n");
                }
                break;
            case 2: // add a new entry
                time_t now = time(NULL);
                struct tm *t = localtime(&now);
                sprintf(entries[num_entries].date, "%d-%02d-%02d", t->tm_year+1900, t->tm_mon+1, t->tm_mday);
                sprintf(entries[num_entries].time, "%02d:%02d", t->tm_hour, t->tm_min);
                printf("Enter your entry (max 250 characters): ");
                scanf(" %[^\n]", entries[num_entries].content);
                num_entries++;
                printf("\nEntry saved.\n");
                break;
            case 3: // search for entries on a specific date
                printf("Enter date to search for (YYYY-MM-DD): ");
                scanf("%s", input);
                for (i = 0; i < num_entries; i++) {
                    if (strcmp(entries[i].date, input) == 0) {
                        printf("\nDate: %s, Time: %s, Content: %s\n", entries[i].date, entries[i].time, entries[i].content);
                    }
                }
                break;
            case 4: // exit
                fp = fopen(filename, "w");
                for (i = 0; i < num_entries; i++) {
                    fprintf(fp, "%s %s %s\n", entries[i].date, entries[i].time, entries[i].content);
                }
                fclose(fp);
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}