//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: realistic
#include <stdio.h>
#include <string.h>

// function to convert natural language date to standard date format
void convertDate(char input[])
{
    // split the input into words
    char* tokens[10];
    int i, j = 0;
    char* token = strtok(input, " ");
    while (token != NULL)
    {
        tokens[j] = token;
        j++;
        token = strtok(NULL, " ");
    }
    
    // extract day, month and year from input
    int day = 0, month = 0, year = 0;
    for (i = 0; i < j; i++)
    {
        // check for day
        if (strstr(tokens[i], "st") != NULL || strstr(tokens[i], "nd") != NULL || strstr(tokens[i], "rd") != NULL || strstr(tokens[i], "th") != NULL)
        {
            int len = strlen(tokens[i]);
            day = atoi(tokens[i]);
            day = day > 31 ? 0 : day;
        }
        
        // check for month
        if (strstr(tokens[i], "January") != NULL || strstr(tokens[i], "january") != NULL)
        {
            month = 1;
        }
        else if (strstr(tokens[i], "February") != NULL || strstr(tokens[i], "february") != NULL)
        {
            month = 2;
        }
        else if (strstr(tokens[i], "March") != NULL || strstr(tokens[i], "march") != NULL)
        {
            month = 3;
        }
        else if (strstr(tokens[i], "April") != NULL || strstr(tokens[i], "april") != NULL)
        {
            month = 4;
        }
        else if (strstr(tokens[i], "May") != NULL || strstr(tokens[i], "may") != NULL)
        {
            month = 5;
        }
        else if (strstr(tokens[i], "June") != NULL || strstr(tokens[i], "june") != NULL)
        {
            month = 6;
        }
        else if (strstr(tokens[i], "July") != NULL || strstr(tokens[i], "july") != NULL)
        {
            month = 7;
        }
        else if (strstr(tokens[i], "August") != NULL || strstr(tokens[i], "august") != NULL)
        {
            month = 8;
        }
        else if (strstr(tokens[i], "September") != NULL || strstr(tokens[i], "september") != NULL)
        {
            month = 9;
        }
        else if (strstr(tokens[i], "October") != NULL || strstr(tokens[i], "october") != NULL)
        {
            month = 10;
        }
        else if (strstr(tokens[i], "November") != NULL || strstr(tokens[i], "november") != NULL)
        {
            month = 11;
        }
        else if (strstr(tokens[i], "December") != NULL || strstr(tokens[i], "december") != NULL)
        {
            month = 12;
        }
        
        // check for year
        if (strstr(tokens[i], "20") != NULL)
        {
            year = atoi(tokens[i]);
        }
    }
    
    // output the converted date in standard format
    printf("%d-%d-%d", year, month, day);   
}

// main function to test the conversion function
int main()
{
    char input[100];
    printf("Enter a natural language date (eg. 1st January 2022): ");
    fgets(input, sizeof(input), stdin);
    convertDate(input);
    return 0;
}