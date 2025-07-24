//FormAI DATASET v1.0 Category: Digital Diary ; Style: happy
#include <stdio.h>

//structure template for Diary Entry
struct DiaryEntry
{
    char date[11];
    char title[101];
    char content[1001];
};

//function to print the Diary Entry
void printEntry(struct DiaryEntry entry)
{
    printf("\nDate: %s\n", entry.date);
    printf("Title: %s\n", entry.title);
    printf("Content: %s\n", entry.content);
    printf("\n");
}

int main()
{
    //declaring the Diary Entry array
    struct DiaryEntry myDiary[10];

    //looping through the array to get each entry from user
    for(int i=0; i<10; i++)
    {
        printf("Enter Date (DD/MM/YYYY): ");
        scanf("%s", myDiary[i].date);
        
        printf("Enter Title: ");
        scanf(" %[^\n]s", myDiary[i].title);
        
        printf("Enter Content: ");
        scanf(" %[^\n]s", myDiary[i].content);
        
        printf("\nEntry added successfully!\n");
    }

    //printing all the Diary Entries
    printf("\n\n***** My Digital Diary *****\n");
    for(int i=0; i<10; i++)
    {
        printEntry(myDiary[i]);
    }

    return 0;
}