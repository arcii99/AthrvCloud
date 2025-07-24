//FormAI DATASET v1.0 Category: Digital Diary ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_LENGTH 500

struct DiaryEntry 
{
    char date[20];
    char content[MAX_LENGTH];
};

struct Diary 
{
    struct DiaryEntry entries[MAX_ENTRIES];
    int num_entries;
};

void print_menu() 
{
    printf("\n\n");
    printf("*** Digital Diary Menu ***\n");
    printf("1. Add entry\n");
    printf("2. View entry\n");
    printf("3. Edit entry\n");
    printf("4. Delete entry\n");
    printf("5. Exit\n\n");
}

void add_entry(struct Diary *d) 
{
    if (d->num_entries == MAX_ENTRIES) 
    {
        printf("Error: diary is full.\n");
        return;
    }
    printf("Enter date (DD/MM/YYYY): ");
    scanf("%s", d->entries[d->num_entries].date);
    printf("Enter content (max length %d): ", MAX_LENGTH);
    scanf(" %[^\n]s", d->entries[d->num_entries].content);
    d->num_entries++;
    printf("Entry added successfully.\n");
}

void view_entry(struct Diary *d) 
{
    if (d->num_entries == 0) 
    {
        printf("Error: diary is empty.\n");
        return;
    }
    printf("Enter date (DD/MM/YYYY): ");
    char date[20];
    scanf("%s", date);
    for (int i = 0; i < d->num_entries; i++) 
    {
        if (strcmp(d->entries[i].date, date) == 0) 
        {
            printf("\nDate: %s\n", d->entries[i].date);
            printf("Content: %s\n", d->entries[i].content);
            return;
        }
    }
    printf("Entry not found.\n");
}

void edit_entry(struct Diary *d) 
{
    if (d->num_entries == 0) 
    {
        printf("Error: diary is empty.\n");
        return;
    }
    printf("Enter date (DD/MM/YYYY): ");
    char date[20];
    scanf("%s", date);
    for (int i = 0; i < d->num_entries; i++) 
    {
        if (strcmp(d->entries[i].date, date) == 0) 
        {
            printf("\nEnter new content (max length %d): ", MAX_LENGTH);
            scanf(" %[^\n]s", d->entries[i].content);
            printf("Entry edited successfully.\n");
            return;
        }
    }
    printf("Entry not found.\n");
}

void delete_entry(struct Diary *d) 
{
    if (d->num_entries == 0) 
    {
        printf("Error: diary is empty.\n");
        return;
    }
    printf("Enter date (DD/MM/YYYY): ");
    char date[20];
    scanf("%s", date);
    for (int i = 0; i < d->num_entries; i++) 
    {
        if (strcmp(d->entries[i].date, date) == 0) 
        {
            for (int j = i; j < d->num_entries - 1; j++) 
            {
                d->entries[j] = d->entries[j+1];
            }
            d->num_entries--;
            printf("Entry deleted successfully.\n");
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() 
{
    struct Diary diary;
    diary.num_entries = 0;
    int choice = 0;
    while (choice != 5) 
    {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) 
        {
            case 1:
                add_entry(&diary);
                break;
            case 2:
                view_entry(&diary);
                break;
            case 3:
                edit_entry(&diary);
                break;
            case 4:
                delete_entry(&diary);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}