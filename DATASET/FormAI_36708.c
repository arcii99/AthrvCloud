//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: systematic
#include<stdio.h>

//Function to check if the given year is a leap year
int isLeapYear(int year){
    if(year%4==0 && year%100!=0 || year%400==0){
        return 1;
    }
    else{
        return 0;
    }
}

//Function to convert given month and day to the corresponding day of the year
int dayOfYear(int month, int day, int leap){
    int days=0, i;
    for(i=1; i<month; i++){
        if(i==2 && leap==1){
            days += 29;
        }
        else if(i==2 && leap==0){
            days += 28;
        }
        else if(i==4 || i==6 || i==9 || i==11){
            days += 30;
        }
        else{
            days += 31;  
        }
    }
    days += day;
    return days;
}

int main(){

    int year, month, day, ndays;
    printf("Enter the date in natural language form: ");
    scanf("%d %d, %d", &month, &day, &year);
    
    //Checking for leap year
    int leap = isLeapYear(year);
    
    //Converting given month and day to day of the year
    int days = dayOfYear(month, day, leap);

    printf("The day of the year for the given date is: %d\n", days);
    return 0;
}