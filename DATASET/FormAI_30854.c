//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[50];
    int day, month, year;

    printf("Welcome to the Date Converter!\n\n");
    printf("Enter a date in natural language (e.g. January 1st, 2022):\n");
    fgets(input, 50, stdin);

    char *month_str[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    char *day_str[31] = {"first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth", "tenth", "eleventh", "twelfth", "thirteenth", "fourteenth", "fifteenth", "sixteenth", "seventeenth", "eighteenth", "nineteenth", "twentieth", "twenty-first", "twenty-second", "twenty-third", "twenty-fourth", "twenty-fifth", "twenty-sixth", "twenty-seventh", "twenty-eighth", "twenty-ninth", "thirtieth", "thirty-first"};

    char *suffix_str[4] = {"st", "nd", "rd", "th"};

    char *delim = " ,";
    char *token = strtok(input, delim);

    while (token != NULL)
    {
        if (isdigit(token[0]) && strlen(token) == 4)
        {
            year = atoi(token);
            break;
        }

        for (int i = 0; i < 12; i++)
        {
            if (strcmp(token, month_str[i]) == 0)
            {
                month = i + 1;
                break;
            }
        }

        for (int i = 0; i < 31; i++)
        {
            if (strcmp(token, day_str[i]) == 0)
            {
                day = i + 1;
                break;
            }
        }

        if (strstr(token, suffix_str[0]) != NULL)
        {
            day = 1;
        }
        else if (strstr(token, suffix_str[1]) != NULL)
        {
            day = 2;
        }
        else if (strstr(token, suffix_str[2]) != NULL)
        {
            day = 3;
        }
        else if (strstr(token, suffix_str[3]) != NULL)
        {
            token[strlen(token) - 2] = '\0';
            day = atoi(token);
        }

        token = strtok(NULL, delim);
    }

    printf("\nYour input was: %s", input);
    printf("The converted date is: %04d/%02d/%02d", year, month, day);

    return 0;
}