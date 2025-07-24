//FormAI DATASET v1.0 Category: Digital Diary ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define MAX_ENTRIES 100
 
struct diary_entry {
    char contents[200];
    char date[11];
};
 
int main() {
    struct diary_entry entries[MAX_ENTRIES];
    int num_entries = 0;
    int choice;
 
    do {
        printf("Digital Diary Menu\n");
        printf("1. Add new entry\n");
        printf("2. View entries\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                // get current date and time
                time_t now = time(NULL);
                struct tm *t = localtime(&now);
                strftime(entries[num_entries].date, 11, "%d/%m/%Y", t);
 
                // get entry contents from user
                printf("Enter the contents of the new entry:\n");
                fflush(stdin);
                fgets(entries[num_entries].contents, 200, stdin);
                num_entries++;
                break;
            case 2:
                // loop through all entries and print them out
                printf("All diary entries:\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("%s: %s", entries[i].date, entries[i].contents);
                }
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);
 
    return 0;
}