//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: careful
#include <stdio.h>
#include <string.h>

int main() {
    char date[20];
    printf("Enter the date in Natural Language format: ");
    fgets(date, 20, stdin);
    
    // Convert date to lowercase
    for(int i = 0; i < strlen(date); i++) {
        date[i] = tolower(date[i]);
    }
    
    // Check for month
    int month = 0;
    if(strstr(date, "january") != NULL) {
        month = 1;
    }
    else if(strstr(date, "february") != NULL) {
        month = 2;
    }
    else if(strstr(date, "march") != NULL) {
        month = 3;
    }
    else if(strstr(date, "april") != NULL) {
        month = 4;
    }
    else if(strstr(date, "may") != NULL) {
        month = 5;
    }
    else if(strstr(date, "june") != NULL) {
        month = 6;
    }
    else if(strstr(date, "july") != NULL) {
        month = 7;
    }
    else if(strstr(date, "august") != NULL) {
        month = 8;
    }
    else if(strstr(date, "september") != NULL) {
        month = 9;
    }
    else if(strstr(date, "october") != NULL) {
        month = 10;
    }
    else if(strstr(date, "november") != NULL) {
        month = 11;
    }
    else if(strstr(date, "december") != NULL) {
        month = 12;
    }
    else {
        printf("Invalid month.\n");
        return 0;
    }
    
    // Check for day
    int day = 0;
    if(strstr(date, "first") != NULL) {
        day = 1;
    }
    else if(strstr(date, "second") != NULL) {
        day = 2;
    }
    else if(strstr(date, "third") != NULL) {
        day = 3;
    }
    else if(strstr(date, "fourth") != NULL) {
        day = 4;
    }
    else if(strstr(date, "fifth") != NULL) {
        day = 5;
    }
    else if(strstr(date, "sixth") != NULL) {
        day = 6;
    }
    else if(strstr(date, "seventh") != NULL) {
        day = 7;
    }
    else if(strstr(date, "eighth") != NULL) {
        day = 8;
    }
    else if(strstr(date, "ninth") != NULL) {
        day = 9;
    }
    else if(strstr(date, "tenth") != NULL) {
        day = 10;
    }
    else if(strstr(date, "eleventh") != NULL) {
        day = 11;
    }
    else if(strstr(date, "twelfth") != NULL) {
        day = 12;
    }
    else if(strstr(date, "thirteenth") != NULL) {
        day = 13;
    }
    else if(strstr(date, "fourteenth") != NULL) {
        day = 14;
    }
    else if(strstr(date, "fifteenth") != NULL) {
        day = 15;
    }
    else if(strstr(date, "sixteenth") != NULL) {
        day = 16;
    }
    else if(strstr(date, "seventeenth") != NULL) {
        day = 17;
    }
    else if(strstr(date, "eighteenth") != NULL) {
        day = 18;
    }
    else if(strstr(date, "nineteenth") != NULL) {
        day = 19;
    }
    else if(strstr(date, "twentieth") != NULL) {
        day = 20;
    }
    else if(strstr(date, "twenty-first") != NULL) {
        day = 21;
    }
    else if(strstr(date, "twenty-second") != NULL) {
        day = 22;
    }
    else if(strstr(date, "twenty-third") != NULL) {
        day = 23;
    }
    else if(strstr(date, "twenty-fourth") != NULL) {
        day = 24;
    }
    else if(strstr(date, "twenty-fifth") != NULL) {
        day = 25;
    }
    else if(strstr(date, "twenty-sixth") != NULL) {
        day = 26;
    }
    else if(strstr(date, "twenty-seventh") != NULL) {
        day = 27;
    }
    else if(strstr(date, "twenty-eighth") != NULL) {
        day = 28;
    }
    else if(strstr(date, "twenty-ninth") != NULL) {
        day = 29;
    }
    else if(strstr(date, "thirtieth") != NULL) {
        day = 30;
    }
    else if(strstr(date, "thirty-first") != NULL) {
        day = 31;
    }
    else {
        printf("Invalid day.\n");
        return 0;
    }
    
    // Check for year
    int year = 0;
    if(strstr(date, "twenty twenty-one") != NULL) {
        year = 2021;
    }
    else if(strstr(date, "twenty twenty-two") != NULL) {
        year = 2022;
    }
    else if(strstr(date, "twenty twenty-three") != NULL) {
        year = 2023;
    }
    else if(strstr(date, "twenty twenty-four") != NULL) {
        year = 2024;
    }
    else if(strstr(date, "twenty twenty-five") != NULL) {
        year = 2025;
    }
    else {
        printf("Invalid year.\n");
        return 0;
    }
    
    // Print result
    printf("The date entered is: %d/%d/%d\n", month, day, year);
    
    return 0;
}