//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: satisfied
#include <stdio.h>
#include <string.h>

void convertDate(char date[]){
    int day = (date[0] - '0') * 10 + (date[1] - '0');
    char month[15];
    strncpy(month, date+3, 3);
    month[3] = '\0'; // terminate string
    int year = (date[7] - '0') * 1000 + (date[8] - '0') * 100 + (date[9] - '0') * 10 + (date[10] - '0');
    
    //convert month to number
    int monthNum;
    if(strcmp(month, "Jan") == 0){
        monthNum = 1;
    }else if(strcmp(month, "Feb") == 0){
        monthNum = 2;
    }else if(strcmp(month, "Mar") == 0){
        monthNum = 3;
    }else if(strcmp(month, "Apr") == 0){
        monthNum = 4;
    }else if(strcmp(month, "May") == 0){
        monthNum = 5;
    }else if(strcmp(month, "Jun") == 0){
        monthNum = 6;
    }else if(strcmp(month, "Jul") == 0){
        monthNum = 7;
    }else if(strcmp(month, "Aug") == 0){
        monthNum = 8;
    }else if(strcmp(month, "Sep") == 0){
        monthNum = 9;
    }else if(strcmp(month, "Oct") == 0){
        monthNum = 10;
    }else if(strcmp(month, "Nov") == 0){
        monthNum = 11;
    }else if(strcmp(month, "Dec") == 0){
        monthNum = 12;
    }
    
    printf("Numeric Date: %d/%d/%d\n", monthNum, day, year);
}


int main() {
    char date[12];
    printf("Enter date in the format of 'DD MMM YYYY': ");
    fgets(date, sizeof(date), stdin);
    convertDate(date);
    return 0;
}