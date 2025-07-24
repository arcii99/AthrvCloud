//FormAI DATASET v1.0 Category: Digital Diary ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char title[50];
    int mood;
    char content[500];
    FILE *fptr;
    
    // Prompt user for diary entry
    printf("Welcome to your Digital Diary!\n");
    printf("What's the title of your entry?\n");
    scanf("%[^\n]%*c", title);
    printf("How are you feeling today (1-5)?\n");
    scanf("%d", &mood);
    printf("What happened today that you want to remember?\n");
    scanf("%[^\n]%*c", content);
    
    // Open file for writing
    fptr = fopen("diary.txt", "a");
    
    if(fptr == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    
    // Write entry to file
    fprintf(fptr, "Title: %s\n", title);
    fprintf(fptr, "Mood: %d\n", mood);
    fprintf(fptr, "Content: %s\n", content);
    fprintf(fptr, "--------------------------\n");
    
    printf("Entry saved to diary.txt!\n");
    fclose(fptr);
    
    return 0;
}