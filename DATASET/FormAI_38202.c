//FormAI DATASET v1.0 Category: Word Count Tool ; Style: automated
#include <stdio.h>
#include <stdlib.h>

//Function to count number of words in a string
int countWords(char *str) {
    int state = 0;
    int wordCount = 0;
    
    //Loop to iterate through the string
    for(int i=0; str[i]!= '\0';i++) {
        
        //If current character is a space or newline
        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            state = 0; 
        }
        else if(state == 0) {
            state = 1;
            wordCount++;
        }
    }
    return wordCount;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    //Function call to count number of words
    int wordCount = countWords(str);

    printf("\nTotal words: %d", wordCount);
    return 0;
}