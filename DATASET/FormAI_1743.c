//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: curious
#include <stdio.h>

int main() {
    printf("Welcome to the Curious C Natural Language Date Converter!\n");
    printf("Please enter a date in natural language (e.g. \"April 25, 2022\")\n");

    //Read the user input
    char month[10], comma[2];
    int day, year;
    scanf("%s %d %c %d", month, &day, comma, &year);

    //Convert month into numeric format
    int numMonth;
    if(strcmp(month, "January") == 0) {
        numMonth = 1;
    } else if(strcmp(month, "February") == 0) {
        numMonth = 2;
    } else if(strcmp(month, "March") == 0) {
        numMonth = 3;
    } else if(strcmp(month, "April") == 0) {
        numMonth = 4;
    } else if(strcmp(month, "May") == 0) {
        numMonth = 5;
    } else if(strcmp(month, "June") == 0) {
        numMonth = 6;
    } else if(strcmp(month, "July") == 0) {
        numMonth = 7;
    } else if(strcmp(month, "August") == 0) {
        numMonth = 8;
    } else if(strcmp(month, "September") == 0) {
        numMonth = 9;
    } else if(strcmp(month, "October") == 0) {
        numMonth = 10;
    } else if(strcmp(month, "November") == 0) {
        numMonth = 11;
    } else if(strcmp(month, "December") == 0) {
        numMonth = 12;
    } else {
        printf("Sorry, I couldn't understand the month you entered.");
        return 0;
    }

    //Print the converted date
    printf("Converted Date: %d/%d/%d", numMonth, day, year);
    return 0;
}