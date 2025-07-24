//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    int day, month, year;
    char date[15];
    char *months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    
    // Get user input
    printf("Enter date in format dd/mm/yyyy: ");
    scanf("%s", date);
    
    // Convert date to integer values
    day = atoi(strtok(date, "/"));
    month = atoi(strtok(NULL, "/"));
    year = atoi(strtok(NULL, "/"));
    
    // Ensure input is valid
    if(day<1 || day>31 || month<1 || month>12)
    {
        printf("Invalid input\n");
        return 0;
    }
    
    // Print the converted date
    printf("%d %s %d\n", day, months[month-1], year);
    
    return 0;
}