//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_INPUT_LENGTH 100
 
int main()
{
    char input[MAX_INPUT_LENGTH];
    int i, j, count;
    char dummy[1000];
    FILE *file;
 
    file = fopen("log.txt", "r");
 
    if (file == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }
 
    while (fgets(dummy, 1000, file))
    {
        count = 0;
        strcpy(input, dummy);
 
        for (i = 0; i < strlen(input); i++)
        {
            if (input[i] == ' ')
            {
                count++;
            }
 
            if (count == 3 && input[i] == '/')
            {
                for (j = i+1; j < strlen(input); j++)
                {
                    if (input[j] == '/')
                    {
                        break;
                    }
                }
 
                if (j-i <= MAX_INPUT_LENGTH)
                {
                    char command[MAX_INPUT_LENGTH+1];
                    strncpy(command, input+i+1, j-i-1);
                    command[j-i-1] = '\0';
 
                    printf("Possible intrusion detected: %s\n", command);
                }
            }
        }
    }
 
    fclose(file);
 
    return 0;
}