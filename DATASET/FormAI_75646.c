//FormAI DATASET v1.0 Category: Weather simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temperature[12], rainfall[12];
    int i, j;
    srand(time(NULL)); //Initializing random number generator

    printf("Month\tTemperature (C)\tRainfall (mm)\n");

    for(i = 0; i < 12; i++)
    {
        temperature[i] = rand() % 20 + 10; //Generating random temperature between 10 and 30 degrees Celsius
        rainfall[i] = rand() % 50 + 50; //Generating random rainfall between 50 and 100 millimeters

        switch(i)
        {
            case 0: printf("Jan\t"); break;
            case 1: printf("Feb\t"); break;
            case 2: printf("Mar\t"); break;
            case 3: printf("Apr\t"); break;
            case 4: printf("May\t"); break;
            case 5: printf("Jun\t"); break;
            case 6: printf("Jul\t"); break;
            case 7: printf("Aug\t"); break;
            case 8: printf("Sep\t"); break;
            case 9: printf("Oct\t"); break;
            case 10: printf("Nov\t"); break;
            case 11: printf("Dec\t"); break;
        }

        printf("%d\t\t%d\n", temperature[i], rainfall[i]); //Printing temperature and rainfall for each month
    }

    printf("\n");

    //Finding the hottest month
    int hottest_month = 0;
    for(i = 1; i < 12; i++)
    {
        if(temperature[i] > temperature[hottest_month])
        {
            hottest_month = i;
        }
    }
    printf("The hottest month was ");
    switch(hottest_month)
    {
        case 0: printf("January"); break;
        case 1: printf("February"); break;
        case 2: printf("March"); break;
        case 3: printf("April"); break;
        case 4: printf("May"); break;
        case 5: printf("June"); break;
        case 6: printf("July"); break;
        case 7: printf("August"); break;
        case 8: printf("September"); break;
        case 9: printf("October"); break;
        case 10: printf("November"); break;
        case 11: printf("December"); break;
    }
    printf(", with an average temperature of %d degrees Celsius.\n", temperature[hottest_month]);

    //Finding the wettest month
    int wettest_month = 0;
    for(i = 1; i < 12; i++)
    {
        if(rainfall[i] > rainfall[wettest_month])
        {
            wettest_month = i;
        }
    }
    printf("The wettest month was ");
    switch(wettest_month)
    {
        case 0: printf("January"); break;
        case 1: printf("February"); break;
        case 2: printf("March"); break;
        case 3: printf("April"); break;
        case 4: printf("May"); break;
        case 5: printf("June"); break;
        case 6: printf("July"); break;
        case 7: printf("August"); break;
        case 8: printf("September"); break;
        case 9: printf("October"); break;
        case 10: printf("November"); break;
        case 11: printf("December"); break;
    }
    printf(", with an average rainfall of %d millimeters.\n", rainfall[wettest_month]);

    return 0;
}