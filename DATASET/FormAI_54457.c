//FormAI DATASET v1.0 Category: Text processing ; Style: creative
/* 
The following program takes a text file as input and processes it in the following way:
- Remove any extra whitespaces
- Convert all letters to uppercase
- Replace any number between 0 and 9 with its corresponding word
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* numToWord(int num);

int main() {
    FILE* fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 0;
    }
    char c, prev = ' ';
    while ((c = fgetc(fp)) != EOF) {
        if (isspace(c)) {   // Removing extra whitespaces
            if (!isspace(prev)) printf(" ");
        } else {
            c = toupper(c); // Converting all letters to uppercase
            if (isdigit(c)) {
                printf("%s", numToWord(c - 48)); // Replacing number with word
            } else {
                printf("%c", c);
            }
        }
        prev = c;
    }
    fclose(fp);
    return 0;
}

char* numToWord(int num) {
    static char* words[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"}; // words corresponding to numbers 0 to 9
    return words[num];
}