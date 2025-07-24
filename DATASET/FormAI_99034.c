//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 128

int main() {
    char date[BUFFER_SIZE], converted[BUFFER_SIZE];
    int month, day, year;

    printf("Welcome to the Natural Language Date Converter Game!\n");
    printf("How to play: You will input a date in natural language (ex: January 1, 2022) and the program will convert it to a standard date format (ex: 01/01/2022)\n");
    printf("Let's begin! Enter a date in natural language (ex: January 1, 2022): ");

    fgets(date, BUFFER_SIZE, stdin);
    
    // Convert input to standard date format
    if (sscanf(date, "%d %*c %d %*c %d", &month, &day, &year) == 3) {
        sprintf(converted, "%02d/%02d/%d", month, day, year);
        printf("Converted: %s\n", converted);
    } else {
        printf("Error: Invalid input\n");
        return 1;
    }

    return 0;
}