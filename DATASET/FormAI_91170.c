//FormAI DATASET v1.0 Category: Word Count Tool ; Style: satisfied
#include <stdio.h>   //Required for Input and Output Functions
#include <string.h>  //Required for String Functions

int main() {
    char string[1000];    //Declare character array to store user input
    int words = 0;        //Variable to store the count of words
    int i;                //Loop Control Variable
    
    printf("Enter a sentence: ");
    scanf("%[^\n]s", string);   //Read the user input till a '\n' character is encountered
    
    //Loop to count words
    for (i = 0; i < strlen(string); i++) {
        //If current character is space, increment the word count
        if (string[i] == ' ') {
            words++;
        }   
    }
    
    //If there are no spaces (i.e., only one word), increment the word count by 1
    if (words == 0 && strlen(string) > 0) {
        words = 1;
    }
    
    //Print the word count
    if (words == 1) {
        printf("There is 1 word in the sentence.\n");
    } else {
        printf("There are %d words in the sentence.\n", words);
    }
    
    return 0;   //End of main function
}