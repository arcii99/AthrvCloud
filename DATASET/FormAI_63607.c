//FormAI DATASET v1.0 Category: Digital Diary ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    FILE *file;
    char diaryEntry[1000];
    time_t current_time;
    char* c_time_string;

    file = fopen("digital_diary.txt", "a");

    if (file == NULL)
    {
        printf("Error creating file!\n");
        exit(1);
    }

    printf("Create a new diary entry:\n");
    fgets(diaryEntry,1000,stdin);

    current_time = time(NULL);
    c_time_string = ctime(&current_time);

    fprintf(file, "Date/Time: %s\n", c_time_string);
    fprintf(file, "Entry: %s\n\n", diaryEntry);
    printf("Entry successfully recorded in digital diary!\n");

    fclose(file);

    return 0;
}