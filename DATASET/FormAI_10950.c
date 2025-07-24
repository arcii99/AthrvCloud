//FormAI DATASET v1.0 Category: Digital Diary ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

struct diary_entry {
    char* date;
    char* text;
};

struct diary {
    int num_entries;
    struct diary_entry entries[MAX_ENTRIES];
};

void add_entry(struct diary* diary, char* date, char* text) {
    if (diary->num_entries >= MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    char* new_text = (char*)malloc(strlen(text) + 1);
    strcpy(new_text, text);

    char* new_date = (char*)malloc(strlen(date) + 1);
    strcpy(new_date, date);

    diary->entries[diary->num_entries].date = new_date;
    diary->entries[diary->num_entries].text = new_text;
    diary->num_entries++;
}

void remove_entry(struct diary* diary, char* date) {
    int i;

    for (i = 0; i < diary->num_entries; i++) {
        if(strcmp(diary->entries[i].date, date) == 0) {
            free(diary->entries[i].date);
            free(diary->entries[i].text);
            diary->num_entries--;
            break;
        }
    }

    if (i == diary->num_entries) {
        printf("No entry found with that date.\n");
    } else {
        for (; i < diary->num_entries; i++) {
            diary->entries[i] = diary->entries[i+1];
        }
    }
}

void print_diary(struct diary* diary) {
    int i;

    printf("DIARY ENTRIES:\n");

    for (i = 0; i < diary->num_entries; i++) {
        printf("%s\n%s\n", diary->entries[i].date, diary->entries[i].text);
    }
}

int main() {
    struct diary my_diary;
    my_diary.num_entries = 0;

    add_entry(&my_diary, "2021-06-01", "Today I went for a walk in the park and saw a beautiful sunset.");
    add_entry(&my_diary, "2021-06-03", "I had a great dinner with my friends and we laughed a lot.");

    remove_entry(&my_diary, "2021-06-03");

    add_entry(&my_diary, "2021-06-05", "I visited my grandparents and we baked a cake together.");
    add_entry(&my_diary, "2021-06-06", "I went to the beach and swam in the ocean.");

    print_diary(&my_diary);

    return 0;
}