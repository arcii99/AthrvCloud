//FormAI DATASET v1.0 Category: Text processing ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[100]; //Creating a character array to store the input string
    printf("Enter a sentence:\n");
    scanf("%[^\n]", str); //Reading a sentence with spaces, until the user hits enter
    
    int len = strlen(str); //Finding length of the input sentence
    
    //Replacing all occurrences of 'a' with 'e'
    for(int i=0; i<len; i++){
        if(str[i] == 'a'){
            str[i] = 'e';
        }
    }
    
    //Converting first letter of every word to uppercase
    for(int i=0; i<len; i++){
        if(i == 0 || str[i-1] == ' '){
            str[i] = toupper(str[i]);
        }
    }
    
    //Printing the output
    printf("Your transformed sentence is:\n");
    printf("%s\n", str);
    
    return 0;
}