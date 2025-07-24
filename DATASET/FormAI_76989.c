//FormAI DATASET v1.0 Category: Text processing ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to reverse a string using pointers
void reverseString(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;

    // Swap characters from start and end of string
    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    FILE *file = fopen("input.txt", "r");
    
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read each line from file
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        // Remove newline character from end of line
        line[strcspn(line, "\n")] = '\0';

        // Split line into words and print in reverse order
        char *word = strtok(line, " ");
        while (word != NULL) {
            reverseString(word);
            printf("%s ", word);
            word = strtok(NULL, " ");
        }
        printf("\n");
    }

    fclose(file);
    return 0;
}