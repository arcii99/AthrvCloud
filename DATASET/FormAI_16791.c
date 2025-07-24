//FormAI DATASET v1.0 Category: Text processing ; Style: enthusiastic
// Welcome to my exciting C Text Processing program!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 1000  // define maximum input line length

int main()
{
    printf("Hello there! Welcome to my C Text Processing program!\n");
    char line[MAX_LINE];  // input line buffer
    char word[MAX_LINE];  // word buffer
    int count = 0;        // word count
    int i, j;             // counters
    
    printf("Please enter some text for me to process:\n");
    fgets(line, MAX_LINE, stdin);   // get input line from user

    for (i = 0; i < strlen(line); i++) {
        if (isalpha(line[i])) {           // if the character is a letter
            word[count] = tolower(line[i]);   // add it to the current word in lower case
            count++;
        } else if (count > 0) {          // if we've reached the end of a word
            word[count] = '\0';          // null terminate the string
            printf("%s ", word);        // print the word
            count = 0;                  // reset the word count
            word[0] = '\0';             // clear the word buffer
        }
    }

    // print the last word, if there is one
    if (count > 0) {
        word[count] = '\0';
        printf("%s", word);
    }

    printf("\n\nThanks for using my program! Goodbye!\n");

    return 0;
}