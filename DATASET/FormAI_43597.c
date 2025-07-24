//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: statistical
/*
* User Input Sanitizer Example Program
* By: [Insert Name Here]
* Date: [Insert Date Here]
* 
* This program is designed to demonstrate a unique way of sanitizing user input
* in a C program. It uses a statistical approach to determine if the input is
* valid based on the average value and standard deviation of the characters
* in the input string.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

/* Function declarations */
double calc_mean(char *str);
double calc_std_dev(char *str, double mean);

int main() {
    char input[256];
    double mean, std_dev;
    int check = 0;

    /* Loop until valid input is entered */
    while(check == 0) {
        printf("Enter a string: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;  /* Remove newline from end of string */

        /* Calculate statistics */
        mean = calc_mean(input);
        std_dev = calc_std_dev(input, mean);

        /* Check if input is valid */
        if(std_dev <= 3.0) {
            printf("Valid input\n");
            check = 1;
        }
        else {
            printf("Invalid input\n");
        }
    }

    return 0;
}

/* Function to calculate the mean value of a string */
double calc_mean(char *str) {
    double sum = 0.0;
    int count = 0;
    int i;

    for(i = 0; i < strlen(str); i++) {
        if(isalpha(str[i])) {
            sum += (double)tolower(str[i]) - 96;
            count++;
        }
    }

    return sum / (double)count;
}

/* Function to calculate the standard deviation of a string */
double calc_std_dev(char *str, double mean) {
    double sum = 0.0;
    int count = 0;
    int i;

    for(i = 0; i < strlen(str); i++) {
        if(isalpha(str[i])) {
            sum += pow(((double)tolower(str[i]) - 96 - mean), 2.0);
            count++;
        }
    }

    return sqrt(sum / (double)count);
}