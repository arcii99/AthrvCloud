//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE_LENGTH 20

int main()
{
    char date[MAX_DATE_LENGTH];
    int day, month, year;

    printf("Enter a date in natural language (e.g. January 1st, 2022): ");
    fgets(date, MAX_DATE_LENGTH, stdin);

    char *token = strtok(date, " ,\n");
    char *word_list[3];
    int i = 0;

    while (token != NULL)
    {
        word_list[i++] = token;
        token = strtok(NULL, " ,\n");
    }

    if (i != 3)
    {
        printf("Whoopsie daisy, that's not a valid date format. Better luck next time!");
        return 1;
    }

    char *month_str = word_list[0];
    char *day_str = word_list[1];
    char *year_str = word_list[2];

    if (strncmp(month_str, "January", 7) == 0)
    {
        month = 1;
    }
    else if (strncmp(month_str, "February", 8) == 0)
    {
        month = 2;
    }
    else if (strncmp(month_str, "March", 5) == 0)
    {
        month = 3;
    }
    else if (strncmp(month_str, "April", 5) == 0)
    {
        month = 4;
    }
    else if (strncmp(month_str, "May", 3) == 0)
    {
        month = 5;
    }
    else if (strncmp(month_str, "June", 4) == 0)
    {
        month = 6;
    }
    else if (strncmp(month_str, "July", 4) == 0)
    {
        month = 7;
    }
    else if (strncmp(month_str, "August", 6) == 0)
    {
        month = 8;
    }
    else if (strncmp(month_str, "September", 9) == 0)
    {
        month = 9;
    }
    else if (strncmp(month_str, "October", 7) == 0)
    {
        month = 10;
    }
    else if (strncmp(month_str, "November", 8) == 0)
    {
        month = 11;
    }
    else if (strncmp(month_str, "December", 8) == 0)
    {
        month = 12;
    }
    else
    {
        printf("Whoopsie daisy, that's not a valid month. Better luck next time!");
        return 2;
    }

    day = atoi(day_str);

    if (day < 1 || day > 31)
    {
        printf("Whoopsie daisy, that's not a valid day. Better luck next time!");
        return 3;
    }

    year = atoi(year_str);

    if (year < 1)
    {
        printf("Whoopsie daisy, that's not a valid year. Better luck next time!");
        return 4;
    }

    printf("The date in standard format is: %d/%d/%d\n", month, day, year);

    return 0;
}