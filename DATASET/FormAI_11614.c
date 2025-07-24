//FormAI DATASET v1.0 Category: Digital Diary ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define ENTRY_SIZE 256

typedef struct Entry {
    char date[20];
    char time[10];
    char text[ENTRY_SIZE];
} entry;

int num_entries = 0;
entry entries[MAX_ENTRIES];

void add_entry(char* text) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(entries[num_entries].date, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    sprintf(entries[num_entries].time, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);
    strncpy(entries[num_entries].text, text, ENTRY_SIZE);
    num_entries++;
}

void print_entries() {
    for(int i = 0; i < num_entries; i++) {
        printf("%s %s\n%s\n\n", entries[i].date, entries[i].time, entries[i].text);
    }
}

int main() {
    char input[ENTRY_SIZE];
    char prompt[] = "Enter a Diary Entry (max 256 characters) (type 'exit' to quit):\n";
    while(1) {
        printf("%s", prompt);
        fgets(input, ENTRY_SIZE, stdin);
        if(strncmp(input, "exit", 4) == 0) {
            break;
        }
        add_entry(input);
    }
    printf("\nDiary Entries:\n\n");
    print_entries();
    return 0;
}