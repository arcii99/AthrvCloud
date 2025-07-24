//FormAI DATASET v1.0 Category: Word Count Tool ; Style: ultraprecise
#include<stdio.h>
#include<string.h>

int main(){
    char str[1000] = ""; //initialize array for input
    int wordCount = 0, charCount = 0; //initialize variables for word count and character count
    
    printf("Enter a string:\n");
    fgets(str, 1000, stdin); //get input from user
    
    if(str[strlen(str) -1] == '\n'){ //remove newline character
        str[strlen(str) -1] = '\0';
    }
    
    for(int i = 0; i < strlen(str); i++){ //iterate through string
        if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'){ //check if current character is a space, tab or newline
            wordCount++; //if so, increment word count
        }
        else{
            charCount++; //if not, increment character count
        }
    }
    
    if(charCount > 0){ //if there are characters in the string
        wordCount++; //increment word count to account for last word
    }
    
    printf("\nNumber of words in string: %d\n", wordCount); //print the word count
    printf("Number of characters in string: %d\n", charCount); //print the character count
    
    return 0; //end program
}