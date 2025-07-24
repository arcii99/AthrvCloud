//FormAI DATASET v1.0 Category: Digital Diary ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 10
#define MAX_ENTRY_LENGTH 100

typedef struct Entry {
    char text[MAX_ENTRY_LENGTH];
    time_t timestamp;
} Entry;

int main() {
    Entry diary[MAX_ENTRIES]; // create diary array
    int entry_count = 0; // track number of entries
    char input[MAX_ENTRY_LENGTH]; // for user input

    printf("Welcome to your Digital Diary!\n");

    while(1) { // infinite loop

        printf("\nEnter a new entry or 'quit' to exit: \n");
        fgets(input, MAX_ENTRY_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0; // remove newline character

        if(strcmp(input, "quit") == 0) { // exit loop if user enters "quit"
            printf("\nGoodbye!\n");
            break;
        }

        if(entry_count >= MAX_ENTRIES) { // check if diary is full
            printf("\nDiary is full! Please delete an entry before adding a new one.\n");
            continue; // go back to start of loop
        }

        // add new entry
        Entry new_entry;
        time(&new_entry.timestamp);
        strcpy(new_entry.text, input);
        diary[entry_count++] = new_entry;

        printf("\nEntry added to Digital Diary at %s\n", ctime(&new_entry.timestamp));
        
        // print all entries
        printf("\n--------------------------------------\n");
        for(int i = 0; i < entry_count; i++) {
            printf("\n%s\n%s", ctime(&diary[i].timestamp), diary[i].text);
        }
        printf("\n--------------------------------------\n");
    }

    return 0;
}