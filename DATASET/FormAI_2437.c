//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdbool.h>

// Function to check if the year is a leap year
bool isLeapYear(int year){
    if(year % 4 == 0){
        if(year % 100 == 0){
            if(year % 400 == 0){
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

// Function to get the number of days in a given month and year
int getDaysInMonth(int month, int year){
    // Handle February separately for leap year
    if(month == 2){
        if(isLeapYear(year)){
            return 29;
        }
        return 28;
    }
    
    // Calculate days for other months
    switch(month){
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

// Function to convert a date from natural language to standard date format
void convertDate(char dateText[]){
    // Declare variables to store day, month and year
    int day, month, year;
    
    // Declare variables to store word indices
    int dayStartIndex = -1, monthStartIndex = -1, yearStartIndex = -1;
    int dayEndIndex = -1, monthEndIndex = -1, yearEndIndex = -1;
    
    // Find the start and end indices of the words representing day, month and year
    for(int i = 0; dateText[i] != '\0'; i++){
        if(dateText[i] == ' '){
            continue;
        }
        
        if(dayStartIndex == -1){
            dayStartIndex = i;
        }
        
        if(monthStartIndex == -1){
            monthStartIndex = i;
        }
        
        if(yearStartIndex == -1){
            yearStartIndex = i;
        }
        
        for(int j = i+1; dateText[j] != ' ' && dateText[j] != '\0'; j++){
            if(dayEndIndex == -1){
                if(dateText[i] >= '0' && dateText[i] <= '9'){
                    dayEndIndex = j;
                    i = j;
                    continue;
                }
            }
            
            if(monthEndIndex == -1){
                if(dateText[i] >= 'a' && dateText[i] <= 'z' && dateText[j] >= 'a' && dateText[j] <= 'z'){
                    monthEndIndex = j;
                    i = j;
                    continue;
                }
            }
            
            if(yearEndIndex == -1){
                if(dateText[i] >= '0' && dateText[i] <= '9' && dateText[j] >= '0' && dateText[j] <= '9'){
                    yearEndIndex = j;
                    i = j;
                    continue;
                }
            }
        }
    }
    
    // Extract the day, month and year from the given text
    char dayText[dayEndIndex - dayStartIndex + 2];
    for(int i = 0; i <= dayEndIndex - dayStartIndex; i++){
        dayText[i] = dateText[dayStartIndex + i];
        dayText[i+1] = '\0';
    }
    day = atoi(dayText);
    
    char monthText[monthEndIndex - monthStartIndex + 2];
    for(int i = 0; i <= monthEndIndex - monthStartIndex; i++){
        monthText[i] = dateText[monthStartIndex + i];
        monthText[i+1] = '\0';
    }
    
    if(monthText[0] == 'j' || monthText[0] == 'J'){
        if(monthText[1] == 'a' || monthText[1] == 'A'){
            month = 1;
        } else if(monthText[2] == 'n' || monthText[2] == 'N'){
            month = 6;
        } else {
            month = 7;
        }
    } else if(monthText[0] == 'f' || monthText[0] == 'F'){
        month = 2;
    } else if(monthText[0] == 'm' || monthText[0] == 'M'){
        if(monthText[2] == 'r' || monthText[2] == 'R'){
            month = 3;
        } else {
            month = 5;
        }
    } else if(monthText[0] == 'a' || monthText[0] == 'A'){
        if(monthText[1] == 'p' || monthText[1] == 'P'){
            month = 4;
        } else {
            month = 8;
        }
    } else if(monthText[0] == 's' || monthText[0] == 'S'){
        month = 9;
    } else if(monthText[0] == 'o' || monthText[0] == 'O'){
        month = 10;
    } else if(monthText[0] == 'n' || monthText[0] == 'N'){
        month = 11;
    } else {
        month = 12;
    }
    
    char yearText[yearEndIndex - yearStartIndex + 2];
    for(int i = 0; i <= yearEndIndex - yearStartIndex; i++){
        yearText[i] = dateText[yearStartIndex + i];
        yearText[i+1] = '\0';
    }
    year = atoi(yearText);
    
    // Check if the given date is valid
    if(day < 1 || day > getDaysInMonth(month, year)){
        printf("Invalid day\n");
        return;
    }
    
    // Print the standard format of the given date
    printf("%02d/%02d/%d\n", month, day, year);
}

int main(){
    char dateText1[] = "January 1st 2022";
    char dateText2[] = "February 29th 2021";
    char dateText3[] = "Mar 31st 2023";
    char dateText4[] = "4 Apr 2020";
    char dateText5[] = "5/31/2024";
    
    convertDate(dateText1); // Expected output: 01/01/2022
    convertDate(dateText2); // Expected output: Invalid day
    convertDate(dateText3); // Expected output: 03/31/2023
    convertDate(dateText4); // Expected output: 04/04/2020
    convertDate(dateText5); // Expected output: Invalid month
    return 0;
}