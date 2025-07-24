//FormAI DATASET v1.0 Category: Word Count Tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWords(char* inputStr);

int main() {
    char input[1000];
    
    //get user input
    printf("Enter a sentence to count words: \n");
    fgets(input, 1000, stdin);

    //remove the trailing \n character from the user input
    input[strcspn(input, "\n")] = 0;

    //call the countWords function to count the words and display the result
    int numWords = countWords(input);
    printf("The sentence '%s' contains %d words.\n", input, numWords);

    return 0;
}

int countWords(char* inputStr) {
    int count = 0;
    int i;
    int isBreak = 0;
    
    //iterate through each character in the input string
    for (i = 0; i < strlen(inputStr); i++) {
        //if the current character is a space or a tab, and the previous character was not a space or a tab
        if ((inputStr[i] == ' ' || inputStr[i] == '\t') && !isBreak) {
            //this is the end of a word, so increment the word count
            count++;
            isBreak = 1;
        }
        else if (inputStr[i] != ' ' && inputStr[i] != '\t') {
            //this is not a space or a tab character, so we are not at the end of a word
            isBreak = 0;
        }
    }
    
    //increment the count one last time to account for the final word
    count++;

    return count;
}