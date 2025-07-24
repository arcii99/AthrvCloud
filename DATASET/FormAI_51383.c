//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if year is leap year
int isLeapYear(int year){
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to calculate the number of days in a month
int getDaysInMonth(int month, int year){
    if (month == 2) {
        if (isLeapYear(year)) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11){
        return 30;
    }
    else{
        return 31;
    }
}

int main(){
    int day, month, year;
    char date[50];
    printf("Welcome to the Natural Language Date Converter!\n");

    while(1){
        printf("Enter a date (e.g. January 1, 2000): ");
        fgets(date, sizeof(date), stdin); // read input
        date[strcspn(date, "\n")] = '\0'; // remove newline character from input

        // tokenizing input
        char *token = strtok(date, " ,");
        month = -1;
        day = -1;
        year = -1;

        // parsing input
        while(token != NULL){
            if(strcmp(token, "January") == 0){
                month = 1;
            }
            else if(strcmp(token, "February") == 0){
                month = 2;
            }
            else if(strcmp(token, "March") == 0){
                month = 3;
            }
            else if(strcmp(token, "April") == 0){
                month = 4;
            }
            else if(strcmp(token, "May") == 0){
                month = 5;
            }
            else if(strcmp(token, "June") == 0){
                month = 6;
            }
            else if(strcmp(token, "July") == 0){
                month = 7;
            }
            else if(strcmp(token, "August") == 0){
                month = 8;
            }
            else if(strcmp(token, "September") == 0){
                month = 9;
            }
            else if(strcmp(token, "October") == 0){
                month = 10;
            }
            else if(strcmp(token, "November") == 0){
                month = 11;
            }
            else if(strcmp(token, "December") == 0){
                month = 12;
            }
            else if(atoi(token) != 0){
                if(day == -1){
                    day = atoi(token);
                }
                else{
                    year = atoi(token);
                }
            }
            token = strtok(NULL, " ,");
        }

        // checking if input is valid
        if(day == -1 || month == -1 || year == -1){
            printf("Invalid input! Try again.\n");
            continue;
        }

        // checking if input is in valid range
        if(year < 0){
            printf("Year cannot be negative! Try again.\n");
            continue;
        }
        else if(month < 1 || month > 12){
            printf("Invalid month! Try again.\n");
            continue;
        }
        else if(day < 1 || day > getDaysInMonth(month, year)){
            printf("Invalid day! Try again.\n");
            continue;
        }
        
        // printing converted date
        printf("\nThe natural language date you entered is:\n\n");
        switch(month){
            case 1:
                printf("January");
                break;
            case 2:
                printf("February");
                break;
            case 3:
                printf("March");
                break;
            case 4:
                printf("April");
                break;
            case 5:
                printf("May");
                break;
            case 6:
                printf("June");
                break;
            case 7:
                printf("July");
                break;
            case 8:
                printf("August");
                break;
            case 9:
                printf("September");
                break;
            case 10:
                printf("October");
                break;
            case 11:
                printf("November");
                break;
            case 12:
                printf("December");
                break;
        }
        printf(" %d", day);
        switch(day){
            case 1:
            case 21:
            case 31:
                printf("st");
                break;
            case 2:
            case 22:
                printf("nd");
                break;
            case 3:
            case 23:
                printf("rd");
                break;
            default:
                printf("th");
                break;
        }
        printf(", %d\n\n", year);
    }
    return 0;
}