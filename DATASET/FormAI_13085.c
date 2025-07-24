//FormAI DATASET v1.0 Category: Text processing ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000 // maximum length of input line

// function to convert a string to uppercase
char* str_to_upper(char* str) {
    char* ptr = str;
    while(*ptr) {
        *ptr = toupper(*ptr);
        ptr++;
    }
    return str;
}

int main() {
    char line[MAX_LINE_LENGTH]; // buffer to store input line
    printf("Enter a string or a sentence: ");
    fgets(line, MAX_LINE_LENGTH, stdin); // read input line from user
    
    // print the original line
    printf("Original text: %s\n", line);
    
    // convert line to uppercase
    char* upper = str_to_upper(line);
    printf("Uppercase text: %s", upper);

    return EXIT_SUCCESS;
}