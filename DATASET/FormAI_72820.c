//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: light-weight
#include<stdio.h>
#include<string.h>

void convertDate(char date[]);

int main()
{
    char date[11];
    printf("Enter a date in the format of MM/DD/YYYY:\n");
    scanf("%s", date);
    convertDate(date);
    return 0;
}

void convertDate(char date[])
{
    int month, day, year;
    sscanf(date, "%d/%d/%d", &month, &day, &year);
    switch(month)
    {
        case 1: printf("January %d, %d\n", day, year); break;
        case 2: printf("February %d, %d\n", day, year); break;
        case 3: printf("March %d, %d\n", day, year); break;
        case 4: printf("April %d, %d\n", day, year); break;
        case 5: printf("May %d, %d\n", day, year); break;
        case 6: printf("June %d, %d\n", day, year); break;
        case 7: printf("July %d, %d\n", day, year); break;
        case 8: printf("August %d, %d\n", day, year); break;
        case 9: printf("September %d, %d\n", day, year); break;
        case 10: printf("October %d, %d\n", day, year); break;
        case 11: printf("November %d, %d\n", day, year); break;
        case 12: printf("December %d, %d\n", day, year); break;
        default: printf("Invalid Date\n");
    }
}