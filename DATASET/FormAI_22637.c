//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char date[11], month[4], year[5];
    int day, monthNum, yearNum;
    
    printf("Enter a date in natural language (e.g. January 1, 2022): ");
    scanf("%s %d, %s", month, &day, year);
    strcpy(date, strcat(month, year));
    
    // Convert month to number
    if (strcmp(month, "January") == 0)
        monthNum = 1;
    else if (strcmp(month, "February") == 0)
        monthNum = 2;
    else if (strcmp(month, "March") == 0)
        monthNum = 3;
    else if (strcmp(month, "April") == 0)
        monthNum = 4;
    else if (strcmp(month, "May") == 0)
        monthNum = 5;
    else if (strcmp(month, "June") == 0)
        monthNum = 6;
    else if (strcmp(month, "July") == 0)
        monthNum = 7;
    else if (strcmp(month, "August") == 0)
        monthNum = 8;
    else if (strcmp(month, "September") == 0)
        monthNum = 9;
    else if (strcmp(month, "October") == 0)
        monthNum = 10;
    else if (strcmp(month, "November") == 0)
        monthNum = 11;
    else // December
        monthNum = 12;
    
    yearNum = atoi(year);

    printf("\nThe equivalent date in numerical format is: %02d/%02d/%04d\n", monthNum, day, yearNum);
    
    return 0;
}