//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: mind-bending
#include <stdio.h>

// converts natural language dates to MM/DD/YYYY format
void convertDate(char* input) {
    char month[3], day[3], year[5];
    int i = 0, j = 0, k = 0, count = 0;

    // iterate through the input string
    while (input[i] != '\0') {
        // if a word is found, determine if it is a month or a year and extract the values
        if (input[i] == ' ' || input[i+1] == '\0') {
            count++;
            if (count == 1) {
                if (j == 1) {
                    month[1] = input[i];
                    month[2] = '\0';
                } else {
                    month[0] = input[i-1];
                    month[1] = input[i];
                    month[2] = '\0';
                }
                j = i+1;
            } else if (count == 2) {
                if (k == 3) {
                    year[3] = input[i];
                    year[4] = '\0';
                } else {
                    year[k] = input[i];
                    k++;
                }
            } else {
                break;
            }
        // if a number is found, determine if it is a day or part of a year and extract the values
        } else if (input[i] >= '0' && input[i] <= '9') {
            if (count == 0) {
                if (j == 0) {
                    day[0] = input[i];
                    j = i+1;
                } else {
                    day[1] = input[i];
                }
            } else {
                if (k == 0) {
                    year[0] = input[i];
                    k++;
                } else if (k == 1) {
                    year[1] = input[i];
                    k++;
                } else if (k == 2) {
                    year[2] = input[i];
                    k++;
                }
            }
        }
        i++;
    }

    // output the converted date
    printf("%s/%s/%s\n", month, day, year);
}

int main() {
    char input1[] = "the 3rd of march 1999";
    char input2[] = "December 15 2022";
    char input3[] = "the twentieth of november, two thousand and five";

    printf("Input: %s\n", input1);
    printf("Output: ");
    convertDate(input1);

    printf("Input: %s\n", input2);
    printf("Output: ");
    convertDate(input2);

    printf("Input: %s\n", input3);
    printf("Output: ");
    convertDate(input3);

    return 0;
}