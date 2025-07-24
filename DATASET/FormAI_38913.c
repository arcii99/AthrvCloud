//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: artistic
#include<stdio.h>
#include<ctype.h>
int main()
{
    int day, month, year;
    char monthName[20];
    printf("Welcome to the Natural Language Date Converter!\nPlease enter a date in the format <month name><space><day>,<space><year> :\n");
    scanf("%s %d, %d", monthName, &day, &year);
    for(int i = 0; monthName[i]; i++)
        monthName[i] = tolower(monthName[i]);
    if(strcmp(monthName, "january") == 0)
        month = 1;
    else if(strcmp(monthName, "february") == 0)
        month = 2;
    else if(strcmp(monthName, "march") == 0)
        month = 3;
    else if(strcmp(monthName, "april") == 0)
        month = 4;
    else if(strcmp(monthName, "may") == 0)
        month = 5;
    else if(strcmp(monthName, "june") == 0)
        month = 6;
    else if(strcmp(monthName, "july") == 0)
        month = 7;
    else if(strcmp(monthName, "august") == 0)
        month = 8;
    else if(strcmp(monthName, "september") == 0)
        month = 9;
    else if(strcmp(monthName, "october") == 0)
        month = 10;
    else if(strcmp(monthName, "november") == 0)
        month = 11;
    else if(strcmp(monthName, "december") == 0)
        month = 12;
    else
    {
        printf("Invalid input\n");
        return 0;
    }
    printf("You entered: %d-%d-%d\n", year, month, day);
    return 0;
}