//FormAI DATASET v1.0 Category: Digital Diary ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// define maximum input length
#define MAX_INPUT_LENGTH 100

int main()
{
    char entry[MAX_INPUT_LENGTH]; // array to hold diary entry
    FILE *file;

    printf("Welcome to your Digital Diary\n");
    printf("Enter 'exit' to quit the program\n");

    while (1) // infinite loop
    {
        printf("\nEnter your thoughts for the day: ");

        fgets(entry, MAX_INPUT_LENGTH, stdin); // get input from user

        if (strcmp(entry, "exit\n") == 0) // check for exit command
        {
            printf("\nExiting the program...\n\n");
            break; // exit the loop
        }
        else
        {
            file = fopen("diary.txt", "a"); // open file in append mode

            if (file == NULL) // check for file opening error
            {
                printf("Error opening file!\n");
                exit(1);
            }

            fprintf(file, "%s\n", entry); // write entry to file

            fclose(file); // close file

            printf("Entry saved!\n");
        }
    }

    return 0;
}