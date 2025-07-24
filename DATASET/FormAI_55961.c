//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: excited
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// function to convert date from Natural Language to numeric format
int convertDate(char *month, int day, int year){

    // array of months with their equivalent numerical values
    char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int monthNum;

    // loop to check which month is inputted by user and assign respective numeric value to monthNum variable
    for(int i=0; i<12; i++){
        if(strcmp(month, months[i]) == 0){
            monthNum = i+1;
            break;
        }
    }

    // formula to convert date into numeric format yyyymmdd
    int numericDate = year*10000 + monthNum*100 + day;

    return numericDate;
}

int main(){

    //welcome message
    printf("Welcome to the Natural Language Date Converter!\n\n");

    //input date from user
    char month[10];
    int day;
    int year;

    printf("Please enter the date in the following format: Month Day, Year\n");
    scanf("%s %d, %d", month, &day, &year);

    //call convertDate function to convert date into numeric format
    int numericDate = convertDate(month, day, year);

    //output numeric date
    printf("\nThe date you entered in numeric format is: %d\n", numericDate);

    //exit message
    printf("\nThank you for using the Natural Language Date Converter!\n");

    return 0;
}