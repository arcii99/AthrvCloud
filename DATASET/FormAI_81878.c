//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct date {
    int day;
    int month;
    int year;
};

// Function to determine if a year is a leap year
int isLeapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

// Function to convert a date from Julian to Gregorian calendar
struct date julianToGregorian(int jdn)
{
    int a, b, c, d, e, month, day, year;

    // Conversion factors for Julian calendar
    a = jdn + 32044;
    b = (4 * a + 3) / 146097;
    c = a - (b * 146097)/4;
    d = (4 * c + 3) / 1461;
    e = c - (1461 * d)/4;
    month = (5 * e + 2) / 153;
    day = e - (153 * month + 2)/5 + 1;
    year = (100 * b) + d - 4800 + (month / 10);

    struct date gregorianDate = {day, month, year};
    return gregorianDate;
}

// Function to convert a date from Gregorian to Julian calendar
int gregorianToJulian(struct date gregorianDate)
{
    int a, b, c, JulianDayNumber, y, m, d;

    y = gregorianDate.year;
    m = gregorianDate.month;
    d = gregorianDate.day;

    a = (14 - m) / 12;
    b = y + 4800 - a;
    c = m + (12 * a) - 3;
    JulianDayNumber = d + ((153 * c + 2) / 5) + (365 * b) + (b / 4) - (b /100) + (b / 400);

    return JulianDayNumber;
}

// Function to add or subtract a specified number of days from a date
struct date addDays(struct date originalDate, int daysToAdd)
{
    int JulianDayNumber, newJulianDayNumber;
    struct date newDate;

    JulianDayNumber = gregorianToJulian(originalDate);
    newJulianDayNumber = JulianDayNumber + daysToAdd;
    newDate = julianToGregorian(newJulianDayNumber);

    return newDate;
}

// Function to print a date in the format day/month/year
void printDate(struct date theDate)
{
    printf("%d/%d/%d\n", theDate.day, theDate.month, theDate.year);
}

int main() 
{
    printf("Welcome to the Date Converter game!\n\n");
    printf("Instructions:\n");
    printf("1. The first player enters a date in the format dd/mm/yyyy\n");
    printf("2. The second player enters a number N - the number of days to add to the date\n");
    printf("3. The first player then enters the new date in the format dd/mm/yyyy\n");
    printf("4. The second player then enters the number of days to add to this date\n");
    printf("5. The game continues for as many rounds as the players choose\n");
    printf("6. The winner is the player who correctly calculates the final date first!\n\n");

    // Set up variables to store the current date and number of days
    struct date currentDate;
    int numberOfDays;

    // Ask the first player for the starting date
    printf("Player 1, enter the starting date as dd/mm/yyyy: ");
    scanf("%d/%d/%d", &currentDate.day, &currentDate.month, &currentDate.year);

    // Ask the second player for the number of days to add
    printf("Player 2, enter the number of days to add: ");
    scanf("%d", &numberOfDays);

    // Add the number of days to the date
    currentDate = addDays(currentDate, numberOfDays);

    // Ask the first player for the updated date
    printf("Player 1, enter the updated date as dd/mm/yyyy: ");
    scanf("%d/%d/%d", &currentDate.day, &currentDate.month, &currentDate.year);

    // Ask the second player for the number of days to add
    printf("Player 2, enter the number of days to add: ");
    scanf("%d", &numberOfDays);

    int count = 1;

    // Keep playing rounds until the players decide to stop
    while (1)
    {
        // Add the number of days to the date
        currentDate = addDays(currentDate, numberOfDays);

        // Ask the first player for the updated date
        printf("Round %d: Player 1, enter the updated date as dd/mm/yyyy: ", count);
        scanf("%d/%d/%d", &currentDate.day, &currentDate.month, &currentDate.year);

        // Check if the first player has correctly calculated the final date
        if (gregorianToJulian(currentDate) == gregorianToJulian(addDays(currentDate, numberOfDays)))
        {
            printf("Congratulations, Player 1 has correctly calculated the final date!\n");
            break;
        }

        // Ask the second player for the number of days to add
        printf("Round %d: Player 2, enter the number of days to add: ", count+1);
        scanf("%d", &numberOfDays);

        // Add the number of days to the date
        currentDate = addDays(currentDate, numberOfDays);

        // Ask the first player for the updated date
        printf("Round %d: Player 2, enter the updated date as dd/mm/yyyy: ", count+1);
        scanf("%d/%d/%d", &currentDate.day, &currentDate.month, &currentDate.year);

        // Check if the second player has correctly calculated the final date
        if (gregorianToJulian(currentDate) == gregorianToJulian(addDays(currentDate, numberOfDays)))
        {
            printf("Congratulations, Player 2 has correctly calculated the final date!\n");
            break;
        }

        count++;
    }

    return 0;
}