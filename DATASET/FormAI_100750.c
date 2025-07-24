//FormAI DATASET v1.0 Category: Digital Diary ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

struct entry {
    char date[12];
    char note[100];
};

int main(void) {
    struct entry diary[MAX_ENTRIES];
    int num_entries = 0;
    char input[100];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(diary[num_entries].date, sizeof(diary[num_entries].date), "%m/%d/%Y", t);

    printf("Welcome to your retro-style digital diary.\n");

    while (1) {
        printf("What would you like to do today?\n");
        printf("1. Write a new entry.\n");
        printf("2. View previous entries.\n");
        printf("3. Exit.\n");

        fgets(input, sizeof(input), stdin);

        if (input[0] == '1') {
            if (num_entries < MAX_ENTRIES) {
                printf("Write your entry (limit 100 characters):\n");

                fgets(diary[num_entries].note, sizeof(diary[num_entries].note), stdin);

                num_entries++;

                printf("Entry added! Thank you for sharing your thoughts with me.\n");
            } else {
                printf("Sorry, you have reached the maximum number of entries for this diary.\n");
            }
        } else if (input[0] == '2') {
            printf("Here are your previous entries:\n");

            for (int i = 0; i < num_entries; i++) {
                printf("%s: %s\n", diary[i].date, diary[i].note);
            }
        } else if (input[0] == '3') {
            printf("Goodbye!\n");
            return 0;
        } else {
            printf("Sorry, I didn't understand your input.\n");
        }
    }

    return 0;
}