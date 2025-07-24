//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int days_in_month(int month, int year) { //function to get the number of days in a month
    switch(month) {
        case 2: //February
            if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                return 29; //leap year
            else
                return 28;
        case 4: //April
        case 6: //June
        case 9: //September
        case 11: //November
            return 30;
        default: //all other months
            return 31;
    }
}

int main() {
    char date[20];
    int day, month, year;

    printf("Enter date in natural language (example: January 1st, 2022): ");
    fgets(date, 20, stdin); //read input from user

    char *token = strtok(date, " ,"); //tokenize the input string by space and comma
    int counter = 1; //counter to keep track of which token we are processing

    while(token != NULL) {
        if(counter == 1) { //month
            if(strcmp(token, "January") == 0)
                month = 1;
            else if(strcmp(token, "February") == 0)
                month = 2;
            //and so on for March to December
        }
        else if(counter == 2) { //day
            day = atoi(token); //convert string to integer
        }
        else if(counter == 3) { //year
            year = atoi(token); //convert string to integer
        }

        token = strtok(NULL, " ,"); //move to next token
        counter++;
    }

    //calculate number of days since January 1, 0000
    int total_days = 0;
    for(int y = 0; y < year; y++) {
        if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
            total_days += 366; //leap year has 366 days
        else
            total_days += 365;
    }

    for(int m = 1; m < month; m++) {
        total_days += days_in_month(m, year);
    }

    total_days += day - 1; //subtract 1 since our base date is January 1, 0000

    printf("Number of days since January 1, 0000: %d\n", total_days);

    return 0;
}