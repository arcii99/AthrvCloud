//FormAI DATASET v1.0 Category: Word Count Tool ; Style: innovative
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
    char input[1000];
    int words = 0, letters = 0;

    printf("Enter a string: ");
    fgets(input, 1000, stdin); // Taking input from user
 
    for(int i = 0; input[i] != '\0'; i++){
        if(isalpha(input[i])){
            letters++;
        }
        if(input[i] == ' ' && input[i-1] != ' '){
            words++;     
        }
    }
    words++;

    printf("\nNumber of words: %d\nNumber of letters: %d", words, letters);

    return 0;
}