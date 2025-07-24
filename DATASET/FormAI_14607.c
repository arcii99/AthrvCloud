//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: intelligent
#include <stdio.h>

//Function to convert ordinal dates to calendar dates
void ordinalToDate(int year, int ordinal_date){

    int month_day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //Number of days in each month of a non-leap year
    int i, temp_sum = 0, month, day;
    if((year%4==0 && year%100!=0) || year%400==0) //Checking if the year is leap year or not
        month_day[1] = 29; //If the year is leap year, then February month will have 29 days
    for(i=0;i<12;i++){
        temp_sum += month_day[i]; //Calculating total number of days till particular month
        if(ordinal_date-temp_sum <= month_day[i]){
            month = i+1; //Storing month of the given ordinal date
            day = ordinal_date-temp_sum; //Storing day of the given ordinal date
            break;
        }
    }
    printf("The date of %dth day of year %d is %d-%d-%d\n", ordinal_date, year, year, month, day);
}

int main(){
    int year, ordinal_date;
    printf("Enter the year: ");
    scanf("%d", &year);
    printf("Enter the ordinal date: ");
    scanf("%d", &ordinal_date);

    ordinalToDate(year, ordinal_date); //Calling the function to get corresponding calendar date

    return 0;
}