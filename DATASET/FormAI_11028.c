//FormAI DATASET v1.0 Category: Syntax parsing ; Style: detailed
#include <stdio.h>

int main(){
    char input[100]; //Buffer to store user input
    int i, count = 0, flag = 0; //count variable to keep track of the number of words, flag to determine if a word has started
    printf("Enter a C program: ");
    fgets(input, 100, stdin); //get user input
    
    for(i = 0; input[i] != '\0'; i++){
        if(input[i] == ' ' || input[i] == '\t' || input[i] == '\n' || input[i] == ';'){ //if a word has ended
            flag = 0; //set flag to 0 to indicate that word has ended
        } 
        else if(flag == 0){ //if a new word has started
            count++; //increment count variable
            flag = 1; //set flag to indicate that new word has started
        }
    }
    printf("Number of words in the program is: %d", count);
    return 0; //end the program
}