//FormAI DATASET v1.0 Category: Word Count Tool ; Style: light-weight
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() {
    char input[MAX_LENGTH];
    
    fgets(input, MAX_LENGTH, stdin); // read input from user
    
    int length = strlen(input);
    int word_count = 1; // start with 1 because there will always be at least one word
    int i;
    
    for (i = 0; i < length; i++) {
        // if character is a space, increase word_count
        if (input[i] == ' ') {
            word_count++;
        }
    }
    
    printf("Number of words in input: %d", word_count);
    
    return 0;
}