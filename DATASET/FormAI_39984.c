//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>

int main()
{
    // Displaying welcome message
    printf("Welcome to Post-Apocalyptic C Antivirus Scanner\n");

    // Declaring variables
    char curr_char, prev_char=' ';
    int virus_count=0, line_count=0;

    // Opening the file to scan
    FILE *file_ptr;
    file_ptr = fopen("scandisk.iso","r");

    // Checking if file exists
    if(file_ptr == NULL)
    {
        printf("File not found!\n");
        exit(1);
    }

    // Scanning the file
    while((curr_char=fgetc(file_ptr)) != EOF)
    {
        // Checking for virus signature
        if(curr_char=='v' && prev_char=='i')
        {
            curr_char=fgetc(file_ptr);
            if(curr_char=='r')
            {
                curr_char=fgetc(file_ptr);
                if(curr_char=='u')
                {
                    curr_char=fgetc(file_ptr);
                    if(curr_char=='s')
                    {
                        virus_count++;
                        printf("Virus found at line %d.\n",line_count);
                        break;
                    }
                }
            }
        }

        // Updating previous character and line count
        if(curr_char == '\n')
        {
            line_count++;
        }
        prev_char = curr_char;
    }

    // Displaying end message
    printf("Scanning completed!\n");
    printf("Number of viruses found: %d\n",virus_count);

    // Closing the file
    fclose(file_ptr);

    return 0;
}