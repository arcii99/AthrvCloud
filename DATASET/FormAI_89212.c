//FormAI DATASET v1.0 Category: Digital Diary ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    char entry[1000];
    FILE *fptr;
    time_t t;

    time(&t);

    fptr = fopen("Digital_Diary.txt", "a");

    if(fptr == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    printf("Welcome to your Digital Diary!\n");
    printf("Please enter your entry for today:\n");

    fgets(entry, sizeof(entry), stdin);

    fprintf(fptr, "\n\nEntry on %s\n", ctime(&t));
    fprintf(fptr, "%s", entry);

    printf("Your entry has been saved successfully.\n");

    fclose(fptr);

    return 0;
}