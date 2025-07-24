//FormAI DATASET v1.0 Category: Word Count Tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wordCount(char *str) {
    int count = 0;
    int index = 0;
    int state = 0;
    
    // while loop that iterates through the entire string
    while(str[index] != '\0') {
        
        // checks for spaces, tabs, and newlines
        if (str[index] == ' ' || str[index] == '\t' || str[index] == '\n') {
            state = 0;
        }
        
        // if there is a word and we are currently not in a word (state = 0)
        else if (state == 0) {
            state = 1;
            count++;
        }
        
        index++;
    }
    
    return count;
}

int main() {
    char string[1000];
    printf("Enter your string: ");
    fgets(string, 1000, stdin);
    
    //remove newline character from input
    string[strcspn(string, "\n")] = 0;
    
    int count = wordCount(string);
    
    printf("\nTotal words in entered string: %d\n", count);
    
    return 0;
}