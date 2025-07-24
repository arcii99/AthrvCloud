//FormAI DATASET v1.0 Category: Text processing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char input[50];
    int word_count = 0;
    printf("Enter a sentence: ");
    fgets(input, 50, stdin); // Read input string from user
    
    // Count number of words in the input string
    for(int i = 0; i < strlen(input); i++){
        if(input[i] == ' '){
            word_count++;
        }
    }
    word_count++; // Add 1 to word count for last word in the string (there are no spaces after it)
    
    // Convert string to uppercase and print word count
    int i = 0;
    while(input[i]){
        putchar(toupper(input[i]));
        i++;
    }
    printf("\nNumber of words in the sentence: %d\n", word_count);
    
    return 0;
}