//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert a date from natural language to a numerical format
void convert_date(char *input) {
    // define arrays for month and day strings
    char *months[] = {"January", "February", "March", "April", "May",
                      "June", "July", "August", "September", "October",
                      "November", "December"};
    char *days[] = {"first", "second", "third", "fourth", "fifth",
                    "sixth", "seventh", "eighth", "ninth", "tenth",
                    "eleventh", "twelfth", "thirteenth", "fourteenth",
                    "fifteenth", "sixteenth", "seventeenth", "eighteenth",
                    "nineteenth", "twentieth", "twenty-first", "twenty-second",
                    "twenty-third", "twenty-fourth", "twenty-fifth", "twenty-sixth",
                    "twenty-seventh", "twenty-eighth", "twenty-ninth", "thirtieth",
                    "thirty-first"};
    
    // tokenize input string by spaces
    char *token = strtok(input, " ");
    
    // initialize variables for year, month, and day
    int year = 0, month = 0, day = 0;
    
    // loop through tokens and extract year, month, and day
    while (token != NULL) {
        // check if token is a number
        if (atoi(token) != 0) {
            if (year == 0) year = atoi(token);
            else if (day == 0) day = atoi(token);
        }
        // check if token is a month string
        else {
            for (int i = 0; i < 12; i++) {
                if (strcmp(token, months[i]) == 0) {
                    month = i + 1;
                    break;
                }
            }
            // check if token is a day string
            if (month != 0) {
                token = strtok(NULL, " ");
                for (int i = 0; i < 31; i++) {
                    if (strcmp(token, days[i]) == 0) {
                        day = i + 1;
                        break;
                    }
                }
            }
        }
        token = strtok(NULL, " ");
    }
    
    // print out converted date
    printf("%04d-%02d-%02d\n", year, month, day);
}

// main function to read input from user and call convert_date function
int main() {
    // prompt user for input
    printf("Please enter a date in natural language (e.g. 'January twenty-first two thousand twenty'):\n");
    char input[100];
    fgets(input, sizeof(input), stdin);
    
    // call convert_date function
    convert_date(input);
    
    return 0;
}