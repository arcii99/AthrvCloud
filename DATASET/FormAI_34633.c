//FormAI DATASET v1.0 Category: Digital Diary ; Style: light-weight
#include <stdio.h>
#include <time.h>

// Function to get current date and time
void getCurrentTime(char *time_str)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    // Format the time string
    strftime(time_str, 50, "%Y-%m-%d %H:%M:%S", tm);
}

int main()
{
    FILE *fp;
    char filename[50], time_str[50], entry[500];

    printf("Digital Diary\n");

    // Get the current time and use it for the default filename
    getCurrentTime(time_str);
    sprintf(filename, "diary_%s.txt", time_str);

    // Get user input for the filename
    printf("Enter filename [%s]: ", filename);
    fgets(filename, 50, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    // Open the file for writing
    fp = fopen(filename, "w");

    // Get user input for the diary entry
    printf("\nEnter your diary entry (max 500 characters):\n");
    fgets(entry, 500, stdin);

    // Write the entry to the file along with the time stamp
    getCurrentTime(time_str);
    fprintf(fp, "[%s]: %s\n", time_str, entry);

    printf("\nEntry saved to %s\n", filename);

    // Close the file
    fclose(fp);

    return 0;
}