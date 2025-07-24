//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Months array
char *months[] = {"January", "February", "March", "April", "May", "June", 
                    "July", "August", "September", "October", "November", "December"};

// Function to convert date string to integer format
int convertDateToInt(char *date) {
    char *token;
    token = strtok(date, "/");
    int day = atoi(token);
    token = strtok(NULL, "/");
    int month = atoi(token);
    token = strtok(NULL, "/");
    int year = atoi(token);
    return year*10000 + month*100 + day;
}

// Function to convert integer format to date string
char* convertIntToDate(int date) {
    char *dateString = malloc(11*sizeof(char));
    int year = date/10000;
    int month = (date - year*10000)/100;
    int day = date - year*10000 - month*100;
    sprintf(dateString, "%02d/%02d/%04d", day, month, year);
    return dateString;
}

int main() {
    char date[11];
    printf("Enter date in C Natural Language (dd/mm/yyyy): ");
    scanf("%s", date);
    
    // Convert C Natural Language Date to Integer format
    int dateInt = convertDateToInt(date);
    printf("\nDate in integer format: %d", dateInt);
    
    // Convert Integer format back to C Natural Language Date
    char *dateString = convertIntToDate(dateInt);
    printf("\nDate in C Natural Language: %s", dateString);
    free(dateString);
    return 0;
}