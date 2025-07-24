//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: automated
#include<stdio.h>
#include<string.h>

// Define months in an array
char months[12][10] = {"January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December"};

// Function to convert full month name to month number
int month_converter(char month[])
{
    for(int i=0;i<12;i++)
    {
        if(strcmp(month, months[i]) == 0)
        {
            // Return index + 1 as the month number
            return (i+1);
        }
    }

    // In case of invalid month name, return 0
    return 0;
}

int main()
{
    // Get input string from user
    printf("Enter a date in format DD Month YYYY: ");
    char input[20];
    fgets(input, sizeof(input), stdin);

    // Convert input string to individual elements
    int day, month, year;
    sscanf(input, "%d %s %d", &day, months[month-1], &year);

    // Convert month name to month number
    month = month_converter(months[month-1]);

    // Print the converted date
    printf("The converted date is: %d/%d/%d", month, day, year);

    return 0;
}