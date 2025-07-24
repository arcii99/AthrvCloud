//FormAI DATASET v1.0 Category: Log analysis ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    // Open & read Log file
    FILE *fp;
    char filepath[100] = "sample.log"; //Replace this with your log file path
    char ch;
    int len=0;
    fp=fopen(filepath,"r");
    if(fp == NULL)
    {
        printf("\nFile unable to open ");
        exit(0);
    }
    
    // Calculate number of lines and length of longest line
    int linecount = 0;
    int maxLength = 0;
    int tempLength = 0;
    char buffer[1024];
    while(!feof(fp))
    {
        ch= fgetc(fp);
        if(ch == '\n')
        {
            linecount++;
            tempLength = strlen(buffer);
            if(tempLength > maxLength)
            {
                maxLength = tempLength;
            }
            memset(buffer, '\0', sizeof(buffer));
            len = 0;
        }
        else 
        {
            buffer[len] = ch;
            len++;
        }
    }

    // Rewind file to the beginning
    rewind(fp);

    // Display number of lines and longest line length
    printf("Number of lines: %d\n", linecount);
    printf("Max length: %d\n", maxLength);

    // Read each line and display it
    char line[maxLength];
    int i = 1;
    while(fgets(line, maxLength, fp))
    {
        printf("\nLine #%d: %s", i, line);
        i++;
    }

    // Close file
    fclose(fp);
    return 0;
}