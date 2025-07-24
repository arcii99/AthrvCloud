//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: shape shifting
#include<stdio.h>
#include<string.h>

// Define constants for month names and days in month
const char* monthNames[] = {"January", "February", "March", "April", "May", "June", 
                            "July", "August", "September", "October", "November", "December"};
const int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

// Function to check if a year is a leap year
int isLeapYear(int year){
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

// Function to convert date from natural language to date value
void convertToDate(char input[]){
    // Define variables
    int month, day, year;
    char* ptr = strtok(input, " "); // Split the input by space
    
    // Parse the month
    for(int i = 0; i < 12; i++){
        if(strstr(ptr, monthNames[i])){ // Check if the month name is present in the input
            month = i + 1;
            break;
        }
    }
    ptr = strtok(NULL, " ");
    
    // Parse the day and year
    day = atoi(ptr);
    ptr = strtok(NULL, " ");
    year = atoi(ptr);
    
    // Check if the date is valid
    if(month < 1 || month > 12 || day < 1 || day > 31){
        printf("Invalid date!");
        return;
    }
    if(month == 2 && isLeapYear(year)){ // For leap years, February has 29 days
        if(day > 29){
            printf("Invalid date for leap year!");
            return;
        }
    }
    else if(day > daysInMonth[month - 1]){ // Check if the day is within the number of days in the month
        printf("Invalid date!");
        return;
    }
    
    // Print the date in standard format
    printf("%02d/%02d/%d", month, day, year);
}

int main(){
    // Example usage
    char input1[] = "June 25 2022"; // Natural language format
    char input2[] = "February 29 2021"; // Invalid date for non-leap year
    char input3[] = "February 29 2020"; // Leap year date
    
    // Call the convertToDate function with different inputs
    convertToDate(input1); // Output: 06/25/2022
    convertToDate(input2); // Output: Invalid date!
    convertToDate(input3); // Output: 02/29/2020
    return 0;
}