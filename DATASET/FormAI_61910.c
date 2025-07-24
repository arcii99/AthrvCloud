//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: shape shifting
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char date[20];
    printf("This program converts dates from natural language to yyyy-mm-dd format.\n");
    printf("\nEnter the date in natural language format (e.g. August 12, 2022): ");
    fgets(date, 20, stdin);
    int len = strlen(date);
    
    // Remove trailing newline character
    if (date[len-1] == '\n')
    {
        date[len-1] = '\0';
    }
    
    // Convert month to numeric value
    char month[12][5] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
    char* token = strtok(date, " ,");
    int m;
    while (token != NULL)
    {
        *token = tolower(*token);
        if (isalpha(*token))
        {
            for (int i=0; i<12; i++)
            {
                if (strncmp(month[i], token, 3) == 0)
                {
                    m = i+1;
                    break;
                }
            }
        }
        else if (isdigit(*token))
        {
            int d = atoi(token);
            token = strtok(NULL, " ,");
            int y = atoi(token);
            // Output in yyyy-mm-dd format
            printf("\nThe date in yyyy-mm-dd format is: %04d-%02d-%02d", y, m, d);
            break;
        }
        token = strtok(NULL, " ,");
    }
    return 0;
}