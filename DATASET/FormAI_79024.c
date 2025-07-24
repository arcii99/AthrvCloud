//FormAI DATASET v1.0 Category: Word Count Tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to count words in a string
int countWords(char* string){
    int count = 0;
    int i = 0;
    int len = strlen(string);

    // loop through the string
    while(i<len){
        // if current character is not a space, it's a new word
        if(string[i] != ' '){
            count++;

            // skip ahead to end of current word
            while(string[i] != ' ' && i < len){
                i++;
            }
        } else {
            // if current character is a space, skip to next character
            i++;
        }
    }
    return count;
}

int main(){
    char* string = (char*)malloc(sizeof(char) * 1000);

    printf("Enter a string: ");
    fgets(string, 1000, stdin);

    printf("Word count: %d\n", countWords(string));

    free(string);

    return 0;
}