//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void remove_punct(char *str) {
    for(int i = 0; str[i]; i++){
        if(ispunct(str[i])){ //check if the character is a punctuation mark
            for(int j = i; str[j]; j++){
                str[j] = str[j+1]; //shift all characters to the left
            }
            i--; //adjust the index since we shifted characters to the left
        }
    }
}

int main() {
    char text[1000];
    printf("Enter some text: ");
    fgets(text, 1000, stdin);
    
    remove_punct(text); //remove punctuation
    
    char *token = strtok(text, " "); //split the text into words
    
    int c_count = 0;
    while(token != NULL){
        if(tolower(token[0]) == 'c'){ 
            c_count++; //count words starting with 'c'
        }
        token = strtok(NULL, " ");
    }
    
    printf("\n");
    printf("The frequency of words starting with 'c' is %d.", c_count);
    return 0;
}