//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_NUMBER_OF_LINES 1000
#define MAX_NUMBER_OF_KEYWORDS 10

char* keywords[MAX_NUMBER_OF_KEYWORDS] = {"attack", "hack", "intrude", "malware", "virus", "exploit", "phishing", "backdoor", "trojan", "spyware"};

int main()
{
    char line[MAX_LINE_LENGTH];
    char file[MAX_NUMBER_OF_LINES][MAX_LINE_LENGTH];
    int lineCounter = 0;
    int i, j, k;
    int isKeywordFound = 0;

    printf("Enter file lines: \n");

    while(fgets(line, MAX_LINE_LENGTH, stdin))
    {
        if(lineCounter >= MAX_NUMBER_OF_LINES)
        {
            printf("Exceeded maximum number of lines!\n");
            break;
        }

        strcpy(file[lineCounter], line);
        lineCounter++;
    }

    printf("\n");

    for(i = 0; i < lineCounter; i++)
    {
        for(j = 0; j < MAX_NUMBER_OF_KEYWORDS; j++)
        {
            if(strstr(file[i], keywords[j]) != NULL)
            {
                printf("Keyword '%s' found in line %d.\n", keywords[j], i+1);
                isKeywordFound = 1;
            }
        }

        if(isKeywordFound == 1)
        {
            printf("Possible intrusion detected in line %d: %s", i+1, file[i]);
            isKeywordFound = 0;
        }
    }

    return 0;
}