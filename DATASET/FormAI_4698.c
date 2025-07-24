//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: visionary
#include <stdio.h>

/*
 * The following program is a natural language date converter.
 * It takes a date in the format of YYYY-MM-DD and converts it into 
 * a more readable format in the format of Month Day, Year (ex. January 1, 2022).
 * The program uses a series of if-else statements to determine the month 
 * and then formats the output accordingly.
 */

int main() {
    int year, month, day;
    char monthStr[10];
    
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &year, &month, &day);
    
    // Determine month string
    if(month == 1) strcpy(monthStr, "January");
    else if(month == 2) strcpy(monthStr, "February");
    else if(month == 3) strcpy(monthStr, "March");
    else if(month == 4) strcpy(monthStr, "April");
    else if(month == 5) strcpy(monthStr, "May");
    else if(month == 6) strcpy(monthStr, "June");
    else if(month == 7) strcpy(monthStr, "July");
    else if(month == 8) strcpy(monthStr, "August");
    else if(month == 9) strcpy(monthStr, "September");
    else if(month == 10) strcpy(monthStr, "October");
    else if(month == 11) strcpy(monthStr, "November");
    else if(month == 12) strcpy(monthStr, "December");
    
    printf("%s %d, %d", monthStr, day, year);
    
    return 0;
}