//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: invasive
#include<stdio.h>
#include<string.h>

int main(){

    //Welcome message
    printf("Welcome to Date Converter! ");

    //Declaring variables
    int day, month, year;
    char delimiter;

    //Ask user for date 
    printf("\nEnter a date in this format - dd/mm/yyyy: ");
    scanf("%d%c%d%c%d", &day,&delimiter,&month,&delimiter,&year);

    //Check if the date entered is valid
    if((day <= 0 || day > 31) || (month <= 0 || month > 12) || (year <= 0)){
        printf("\nInvalid date entered!");
        return 0;
    }

    //Printing the date entered by the user
    printf("\nYou entered the date: %02d/%02d/%04d", day, month, year);

    //Converting the month into words
    char month_name[12][10] = {"January", "February", "March", "April", "May", "June", "July",
                         "August", "September", "Octomber", "November", "December"};
    char month_ascii[3];
    sprintf(month_ascii, "%s", month_name[month-1]);

    //Printing the date in natural language format
    printf("\nThe date in natural language is: %s %02d, %04d", month_ascii, day, year);

    return 0;
}