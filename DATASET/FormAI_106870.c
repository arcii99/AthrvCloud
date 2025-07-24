//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1000
#define MAX_LINES 1000

int main()
{
    char input[MAX_INPUT];
    char lines[MAX_LINES][MAX_INPUT];
    int line_count = 0;
    int i;

    printf("Enter text to analyze:\n");

    while(fgets(input, MAX_INPUT, stdin))
    {
        if(line_count == MAX_LINES)
        {
            printf("Maximum input reached. Exiting program.\n");
            exit(0);
        }

        if(strcmp(input, "exit\n") == 0)
            break;

        strcpy(lines[line_count], input);
        line_count++;
    }

    printf("Analysis results:\n");

    for(i = 0; i < line_count; i++)
    {
        if(strstr(lines[i], "sudo") != NULL)
        {
            printf("Intrusion detected: %s", lines[i]);
        }
    }

    return 0;
}