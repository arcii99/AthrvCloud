//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int month_to_days(int month){
    switch(month){
        case 1: return 31;
        case 2: return 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 0;
    }
}

void date_converter(char *date_str){
    int day, month, year;
    char month_str[15];

    sscanf(date_str, "%d-%s-%d", &year, month_str, &day);

    if(strcmp(month_str, "January") == 0){
        month = 1;
    }else if(strcmp(month_str, "February") == 0){
        month = 2;
    }else if(strcmp(month_str, "March") == 0){
        month = 3;
    }else if(strcmp(month_str, "April") == 0){
        month = 4;
    }else if(strcmp(month_str, "May") == 0){
        month = 5;
    }else if(strcmp(month_str, "June") == 0){
        month = 6;
    }else if(strcmp(month_str, "July") == 0){
        month = 7;
    }else if(strcmp(month_str, "August") == 0){
        month = 8;
    }else if(strcmp(month_str, "September") == 0){
        month = 9;
    }else if(strcmp(month_str, "October") == 0){
        month = 10;
    }else if(strcmp(month_str, "November") == 0){
        month = 11;
    }else if(strcmp(month_str, "December") == 0){
        month = 12;
    }

    int total_days = 0;
    for(int i = 1; i < month; i++){
        total_days += month_to_days(i);
    }

    total_days += day;

    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) && month > 2){
        total_days += 1;
    }

    printf("%d-%02d-%02d\n", year, month, day);
    printf("Day of the year: %d\n", total_days);
}

int main(){
    char date_str[20];
    printf("Enter date (YYYY-Month-DD): ");
    fgets(date_str, 20, stdin);

    date_converter(date_str);

    return 0;
}