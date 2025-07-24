//FormAI DATASET v1.0 Category: Text processing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000 // Maximum length of a line in a file

// Function to reverse a string
char* reverseString(char* str) {
    int len = strlen(str);
    char* reversed = calloc(len + 1, sizeof(char));
    for(int i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }
    return reversed;
}

int main() {
    char filename[50];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE* input = fopen(filename, "r");
    if(input == NULL) {
        printf("Unable to open file: %s\n", filename);
        exit(1);
    }
    
    char line[MAX_LINE_LENGTH]; // Buffer to read line from file
    char temp[MAX_LINE_LENGTH]; // Buffer to hold reversed line
    while(fgets(line, MAX_LINE_LENGTH, input) != NULL) {
        strcpy(temp, line);
        char* reversed = reverseString(temp);
        printf("%s %s", line, reversed); // Print original and reversed line
        free(reversed);
    }

    fclose(input);
    return 0;
}