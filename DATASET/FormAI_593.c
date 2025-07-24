//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: artistic
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int isLeapYear(int year) //Function to check whether a given year is a leap year or not
{
    if((year%4==0 && year%100!=0) || year%400==0) //Condition to check for leap year
        return 1;
    else
        return 0;
}

int daysInMonth(int month, int year) //Function to find the number of days in a given month of a year
{
    int days;
    int leap = isLeapYear(year); //Checking Leap year
    switch(month)   //Switch Case
    {
        case 1: days = 31;            //Jan
            break;
        case 2: days = 28 + leap;     //Feb
            break;
        case 3: days = 31;            //Mar
            break;
        case 4: days = 30;            //Apr
            break;
        case 5: days = 31;            //May
            break;
        case 6: days = 30;            //Jun
            break;
        case 7: days = 31;            //Jul
            break;
        case 8: days = 31;            //Aug
            break;
        case 9: days = 30;            //Sep
            break;
        case 10: days = 31;           //Oct
            break;
        case 11: days = 30;           //Nov
            break;
        case 12: days = 31;
            break;
        default: days = 0;            //In case of invalid month
    }
    return days;                     //Return number of days
}

void dateToDayOfYear(int day, int month, int year) //Function to convert date to day of the year
{
    int i, dayOfYear = 0;
    for(i=1; i<month; ++i) //Loop to calculate day of year
        dayOfYear += daysInMonth(i, year);
    dayOfYear += day;
    printf("Day of Year: %d\n", dayOfYear);
}

void dayOfYearToDate(int dayOfYear, int year) //Function to convert day of the year to date
{
    int i, days;
    for(i=1; i<=12; ++i) //Loop to calculate the month
    {
        days = daysInMonth(i, year);
        if(dayOfYear <= days)
            break;
        dayOfYear -= days;
    }
    printf("Date: %d/%d/%d\n", dayOfYear, i, year); //Printing the date
}

int main()
{
    char input[25];
    int day, month, year, dayOfYear;

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Enter date in either 'dd/mm/yyyy' or 'day month year' format: ");
    fgets(input, 25, stdin); //Getting input from user

    if(isdigit(input[0])) //Checking if input is in "dd/mm/yyyy" format
    {
        sscanf(input, "%d/%d/%d", &day, &month, &year); //Parsing the date
        dateToDayOfYear(day, month, year); //Converting date to day of the year
    }
    else //If input is in "day month year" format
    {
        char* token = strtok(input, " "); //Tokenizing the input
        day = atoi(token); //Converting first token to integer
        token = strtok(NULL, " "); //Getting the second token
        month = 0;
        if(strcasecmp(token, "january")==0 || strcasecmp(token, "jan")==0) //Converting month string to integer
            month = 1;
        else if(strcasecmp(token, "february")==0 || strcasecmp(token, "feb")==0)
            month = 2;
        else if(strcasecmp(token, "march")==0 || strcasecmp(token, "mar")==0)
            month = 3;
        else if(strcasecmp(token, "april")==0 || strcasecmp(token, "apr")==0)
            month = 4;
        else if(strcasecmp(token, "may")==0)
            month = 5;
        else if(strcasecmp(token, "june")==0 || strcasecmp(token, "jun")==0)
            month = 6;
        else if(strcasecmp(token, "july")==0 || strcasecmp(token, "jul")==0)
            month = 7;
        else if(strcasecmp(token, "august")==0 || strcasecmp(token, "aug")==0)
            month = 8;
        else if(strcasecmp(token, "september")==0 || strcasecmp(token, "sep")==0)
            month = 9;
        else if(strcasecmp(token, "october")==0 || strcasecmp(token, "oct")==0)
            month = 10;
        else if(strcasecmp(token, "november")==0 || strcasecmp(token, "nov")==0)
            month = 11;
        else if(strcasecmp(token, "december")==0 || strcasecmp(token, "dec")==0)
            month = 12;
        else
        {
            printf("Invalid month entered.\n"); //Printing error message for invalid month
            return 0;
        }
        token = strtok(NULL, " "); //Getting the third token
        year = atoi(token); //Converting the third token to integer

        dayOfYear = 0;
        int leap = isLeapYear(year); //Checking Leap year
        for(int i=1; i<month; ++i) //Calculating days till the previous month
            dayOfYear += daysInMonth(i, year);

        dayOfYear += day; //Adding current day of the current month

        if((leap==0 && dayOfYear>365) || (leap==1 && dayOfYear>366)) //Checking for invalid day of the year
        {
            printf("Invalid date entered.\n");
            return 0;
        }

        dayOfYearToDate(dayOfYear, year); //Converting day of the year to date
    }

    printf("Thank you for using the Natural Language Date Converter!\n");
    return 0;
}