//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: modular
#include <stdio.h>

// Function to find the total number of days in a given month and year
int daysInMonth(int month, int year){
    // Array to store the number of days in each month
    int numDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Check if it is a leap year
    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){
        // February has 29 days in a leap year
        numDays[1] = 29;
    }
    // Return the number of days in the given month
    return numDays[month-1];
}

// Function to convert the input date into Julian Date
int convertToJulianDate(int day, int month, int year){
    // Calculate the total number of days from 1/1/4713 BC to 1/1/year
    int totalDays = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    // Calculate the total number of days from 1/1/year to the input date
    for(int i = 1; i < month; i++){
        totalDays += daysInMonth(i, year);
    }
    // Add the input day to the total number of days
    totalDays += day;
    // Return the Julian Date
    return totalDays;
}

// Function to convert the input Julian Date into Gregorian Date
void convertToGregorianDate(int julianDate){
    // Set the initial Gregorian Date to 1/1/1900
    int year = 1900;
    int month = 1;
    int day = 1;
    int numDays = 0;
    // Calculate the number of days from 1/1/1900 to the input Julian Date
    while(numDays < julianDate){
        numDays += daysInMonth(month, year);
        if(numDays > julianDate){
            // If the number of days exceeds the input Julian Date, decrease the month and update the number of days
            month--;
            numDays -= daysInMonth(month, year);
        }
        if(month == 0){
            // If the month becomes 0, set it to December and update the year
            month = 12;
            year--;
        }
    }
    // Calculate the input day
    day = julianDate - numDays;
    // Print the Gregorian Date
    printf("The Gregorian Date is: %d-%d-%d\n", year, month, day);
}

// Main function
int main(){
    // Input the date in natural language
    int day = 4;
    int month = 5;
    int year = 2021;
    // Convert the input date into Julian Date
    int julianDate = convertToJulianDate(day, month, year);
    // Convert the Julian Date into Gregorian Date
    convertToGregorianDate(julianDate);
    return 0;
}