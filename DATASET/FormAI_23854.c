//FormAI DATASET v1.0 Category: Word Count Tool ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
    char c, prev = ' ';
    int word_count = 0;
    
    printf("Enter your string: ");
    
    // Read input string and count words
    while((c = getchar()) != '\n') {
        if(c == ' ' && prev != ' ') {
            word_count++;
        }
        prev = c;
    }
    
    // Count last word if string did not end with a space
    if(prev != ' ') {
        word_count++;
    }
    
    printf("Total number of words in the string: %d", word_count);
    return 0;
}