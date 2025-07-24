//FormAI DATASET v1.0 Category: Digital Diary ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct Entry {
    char date[20];
    char time[20];
    char content[1000];
};

struct Diary {
    struct Entry entries[MAX_ENTRIES];
    int num_entries;
};

void add_entry(struct Diary* diary, const char* date, const char* time, const char* content) {
    if(diary->num_entries == MAX_ENTRIES) {
        printf("Diary is full\n");
        return;
    }
    
    struct Entry new_entry;
    strcpy(new_entry.date, date);
    strcpy(new_entry.time, time);
    strcpy(new_entry.content, content);
    
    diary->entries[diary->num_entries++] = new_entry;
}

void print_entry(const struct Entry* entry) {
    printf("DATE: %s\n", entry->date);
    printf("TIME: %s\n", entry->time);
    printf("CONTENT: %s\n", entry->content);
}

void view_entries(const struct Diary* diary) {
    printf("VIEW ENTRIES\n");
    printf("============\n\n");
    if(diary->num_entries == 0) {
        printf("No entries found\n");
        return;
    }
    
    for(int i = 0; i < diary->num_entries; i++) {
        printf("ENTRY %d\n", i+1);
        printf("------\n");
        print_entry(&diary->entries[i]);
        printf("\n");
    }
}

int main() {
    struct Diary diary;
    diary.num_entries = 0;
    
    add_entry(&diary, "2021-03-01", "08:00", "Woke up and had breakfast");
    add_entry(&diary, "2021-03-01", "09:00", "Started coding my Digital Diary program");
    add_entry(&diary, "2021-03-01", "13:00", "Took a break and had lunch");
    add_entry(&diary, "2021-03-01", "14:00", "Continued coding my Digital Diary program");
    add_entry(&diary, "2021-03-01", "18:00", "Finished coding and testing the program");
    
    view_entries(&diary);
    
    return 0;
}