//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function signature
void printDate(int month, int day, int year);

int main() {
    char input[20];
    int month, day, year;
    printf("Enter a date in natural language (e.g. February 25, 2022): ");
    fgets(input, 20, stdin); // get user input

    // parse user input
    char *token = strtok(input, " ,\n"); // tokenize input by space, comma and newline
    char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // get month
    while (token != NULL) {
        for (int i = 0; i < 12; i++) {
            if (strcmp(token, months[i]) == 0) {
                month = i + 1;
                break;
            }
        }
        token = strtok(NULL, " ,\n"); // move to next token
    }

    // get day
    token = strtok(input, " ,\n"); // reset token
    while (token != NULL) {
        if (atoi(token) != 0) { // check if token is a number
            day = atoi(token);
            break;
        }
        token = strtok(NULL, " ,\n"); // move to next token
    }

    // get year
    token = strtok(input, " ,\n"); // reset token
    while (token != NULL) {
        if (atoi(token) != 0) { // check if token is a number
            year = atoi(token);
            break;
        }
        token = strtok(NULL, " ,\n"); // move to next token
    }

    // print date in standard format
    printDate(month, day, year);

    return 0;
}

void printDate(int month, int day, int year) {
    printf("%02d/%02d/%04d\n", month, day, year); // print date in standard format
}