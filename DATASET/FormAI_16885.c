//FormAI DATASET v1.0 Category: Digital Diary ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

struct DiaryEntry 
{
    time_t timestamp;
    char text[256];
};

struct Diary 
{
    struct DiaryEntry entries[MAX_ENTRIES];
    int count;
};

void print_entry(struct DiaryEntry *entry) 
{
    char *time_str = ctime(&entry->timestamp);
    time_str[strlen(time_str) - 1] = '\0';  // remove newline character from the end
    printf("Date/Time: %s\n", time_str);
    printf("Text: %s\n", entry->text);
}

void view_entries(struct Diary *diary) 
{
    printf("Total entries: %d\n", diary->count);
    for (int i = 0; i < diary->count; i++) 
    {
        printf("---- Entry %d ----\n", i + 1);
        print_entry(&diary->entries[i]);
    }
}

void add_entry(struct Diary *diary, const char *text) 
{
    if (diary->count >= MAX_ENTRIES) 
    {
        printf("Diary is full!\n");
        return;
    }
    time(&diary->entries[diary->count].timestamp);
    strcpy(diary->entries[diary->count].text, text);
    diary->count++;
    printf("Entry added successfully!\n");
}

int main() 
{
    struct Diary my_diary = {0};  // initialize all entries to 0
    
    printf("Welcome to your digital diary!\n");
    printf("Commands:\n");
    printf("  view - view all diary entries\n");
    printf("  add <text> - add a new diary entry\n");
    printf("  exit - exit the program\n");
    
    char input[256];
    while (1) 
    {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "exit\n") == 0) 
        {
            printf("Exiting program...\n");
            break;
        } 
        else if (strcmp(input, "view\n") == 0) 
        {
            view_entries(&my_diary);
        } 
        else if (strncmp(input, "add ", 4) == 0) 
        {
            add_entry(&my_diary, &input[4]);
        } 
        else 
        {
            printf("Invalid command!\n");
        }
    }
    
    return 0;
}