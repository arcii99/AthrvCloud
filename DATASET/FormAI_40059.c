//FormAI DATASET v1.0 Category: Digital Diary ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Get the date and time
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);

    // Create a file for today's entries
    char filename[50];
    sprintf(filename, "%d-%02d-%02d_diary.txt", current_time->tm_year + 1900, current_time->tm_mon + 1, current_time->tm_mday);
    FILE *file = fopen(filename, "a");

    // Check if the file was successfully created
    if (file == NULL)
    {
        printf("Error creating file!\n");
        return 1;
    }

    // Ask the user for their entry
    printf("Enter your diary entry for today:\n");
    char entry[1000];
    fgets(entry, sizeof(entry), stdin);

    // Print the date and entry to the file
    fprintf(file, "%d-%02d-%02d:\n%s\n", current_time->tm_year + 1900, current_time->tm_mon + 1, current_time->tm_mday, entry);

    // Close the file
    fclose(file);

    return 0;
}