//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: scalable
#include<stdio.h>

//function to calculate leap year
int isLeapYear(int year){
    if(year%4==0 && year%100!=0 || year%400==0){
        return 1;
    }
    else{
        return 0;
    }
}

//function to convert the date
void convertDate(int day, int month, int year){
    int daysInMonth[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int totalDays=0;

    //calculating total days till previous month
    for(int i=1;i<month;i++){
        totalDays+=daysInMonth[i];
    }

    //adding days of current month
    totalDays+=day;

    //adding leap year day if current year is leap year and current month is after feb
    if(isLeapYear(year) && month>2){
        totalDays+=1;
    }

    printf("The converted date is: %d/%d/%d",totalDays,month,year);
}

int main(){
    int day,month,year;
    printf("Enter the date in format DD MM YYYY: ");
    scanf("%d %d %d",&day,&month,&year);
    convertDate(day,month,year);
    return 0;
}