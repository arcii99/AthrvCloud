//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *monthName(int month)
{
    static char *months[] = {"January", "February", "March", "April", "May", "June",
                             "July", "August", "September", "October", "November", "December"};
    return months[month - 1];
}

void convertDate(char *input)
{
    char *date, *month, *year;
    int d, m, y;
    char *delim = "-";
    date = strtok(input, delim);
    month = strtok(NULL, delim);
    year = strtok(NULL, delim);
    d = atoi(date);
    m = atoi(month);
    y = atoi(year);
    printf("%s %d, %d", monthName(m), d, y);
}

int main()
{
    char input[20];
    printf("Enter date in format dd-mm-yyyy: ");
    scanf("%s", input);
    printf("Converted Date: ");
    convertDate(input);
    return 0;
}