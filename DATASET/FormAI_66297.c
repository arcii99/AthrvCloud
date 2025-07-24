//FormAI DATASET v1.0 Category: Word Count Tool ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_LINE_LENGTH 80

int countWords(char line[]);

int main() {
    char content[MAX_SIZE];
    char* file_name = "sample.txt";
    FILE* file_pointer = fopen(file_name, "r");
    
    // Check if the file exists and can be opened
    if (file_pointer == NULL) {
       printf("Failed to open file\n");
       exit(1);
    } 
    
    // Read file contents and store in a char array
    int i = 0;
    while (fgets(content + i, MAX_LINE_LENGTH, file_pointer)) {
        i = strlen(content);
    }
    fclose(file_pointer);
    
    int wordCount = countWords(content);
    printf("Number of words in file '%s': %d\n", file_name, wordCount);
    
    return 0;
}

/* 
   Function to count number of words in a given string
   Ignores leading/trailing white spaces and considers
   consecutive white spaces as single delimiter
*/
int countWords(char line[]) {
    int wordCount = 0;
    int i = 0;
    while (line[i] != '\0') {
        // Skip leading white spaces
        while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
            i++;
        }
        
        // Count words
        if (line[i] != '\0') {
            wordCount++;
        }
        
        // Move to end of word
        while (line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != '\0') {
            i++;
        }
    }
    return wordCount;
}