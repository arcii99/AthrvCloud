//FormAI DATASET v1.0 Category: Word Count Tool ; Style: satisfied
#include <stdio.h>
#include <string.h>

// Function to count words in a string
int wordCount(char * str) {

    int count = 0, i, len;

    len = strlen(str);

    // Count words until end of string is reached
    for (i = 0; i < len; i++) {

        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            
            // Ignore consecutive white spaces
            if (i > 0 && (str[i - 1] != ' ' && str[i - 1] != '\n' && str[i - 1] != '\t')) {
                count++;
            }
        } else {
            // If a word is not finished count it as a word
            if (i == len - 1 && str[i] != ' ' && str[i] != '\n' && str[i] != '\t') {
                count++;
            }
        }
    }

    // Return the word count
    return count;
}

int main() {

    // Input sample string
    char str[] = "This is a sample string.";

    // Count the words in the string
    int count = wordCount(str);

    printf("The word count of the given string is %d.", count);

    return 0;
}