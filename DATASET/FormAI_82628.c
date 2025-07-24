//FormAI DATASET v1.0 Category: Syntax parsing ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) {

    // Check if correct number of arguments passed
    if(argc != 2) {
        printf("Error! Please provide C program file name\n");
        return 1;
    }

    // Open the file in read mode
    FILE *fp = fopen(argv[1], "r");

    // Check if file exists
    if(fp == NULL) {
        printf("Error! File not found!\n");
        return 1;
    }

    char line[1000]; // Array to store each line of file
    int line_num = 1; // Counter to keep track of line number
    int bracket_count = 0; // Counter to keep track of brackets
    int error = 0; // Error flag 

    // Loop through each line of file and parse
    while(fgets(line, 1000, fp)) {
        int len = strlen(line);

        // Loop through each character of line and parse
        for(int i=0; i<len; i++) {
            // Check for open braces and increment bracket_count
            if(line[i] == '{')
                bracket_count++;
            // Check for close braces and decrement bracket_count
            if(line[i] == '}')
                bracket_count--;
            // Check if opening and closing braces match
            if(bracket_count < 0) {
                error = 1; // Set error flag
                break;
            }
        }

        if(error) // Exit loop
            break;

        line_num++; // Increment line number
    }

    fclose(fp); // Close file

    // Check for matching brackets
    if(bracket_count == 0)
        printf("Syntax OK!\n");
    else
        printf("Syntax error on line %d\n", line_num);

    return 0;
}