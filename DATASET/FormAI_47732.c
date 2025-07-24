//FormAI DATASET v1.0 Category: Digital Diary ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct diary_entry{
    char title[50];
    char entry[500];
    char timestamp[50];
}diary_entry;

void main()
{
    int choice=0, num_entries=0, i;
    char filename[20];
    diary_entry *entries=NULL;
    time_t now;
    struct tm *current_time;
    char timestamp[50];

    printf("*****************Welcome to your Digital Diary*****************\n");

    //Ask user for number of entries and dynamically allocate memory for entries
    printf("How many diary entries would you like to make? ");
    scanf("%d", &num_entries);

    entries = (diary_entry*)calloc(num_entries, sizeof(diary_entry));

    //Loop to ask user for entries and save them to the file
    for(i=0; i<num_entries; i++)
    {
        printf("\n\nEntry %d:", i+1);

        //Ask user for title and entry
        printf("\nEnter a title for your entry: ");
        scanf("\n%[^\n]s", entries[i].title);

        printf("Enter your entry: ");
        scanf("\n%[^\n]s", entries[i].entry);

        //Get current time and convert it to string
        time(&now);
        current_time = localtime(&now);
        strftime(entries[i].timestamp, 50, "%m/%d/%Y %H:%M:%S", current_time);

        //Open file to save entry
        FILE *fptr;
        sprintf(filename, "entry%d.txt", i+1);
        fptr = fopen(filename, "w");

        //Save entry to file
        fprintf(fptr, "Title: %s\n\n", entries[i].title);
        fprintf(fptr, "Entry:\n%s\n\n", entries[i].entry);
        fprintf(fptr, "Time of Entry: %s\n", entries[i].timestamp);

        printf("\nEntry saved as: %s", filename);
        fclose(fptr);
    }

    //Option to view all entries in the console
    printf("\n\nWould you like to view all your entries? (1.Yes / 2.No) ");
    scanf("%d", &choice);

    if(choice==1)
    {
        printf("\n\n*******************All Entries*******************\n\n");
        for(i=0; i<num_entries; i++)
        {
            printf("Title: %s\n", entries[i].title);
            printf("Entry:\n%s\n", entries[i].entry);
            printf("Time of Entry: %s\n\n", entries[i].timestamp);
        }
    }

    //Option to delete all entries
    printf("\n\nWould you like to delete all your entries? (1.Yes / 2.No) ");
    scanf("%d", &choice);

    if(choice==1)
    {
        for(i=0; i<num_entries; i++)
        {
            sprintf(filename, "entry%d.txt", i+1);
            remove(filename);
        }

        printf("\nAll entries have been deleted.");
    }

    free(entries); //free allocated memory
    printf("\n\n*****************Thank you for using your Digital Diary*****************");
}