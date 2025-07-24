//FormAI DATASET v1.0 Category: Word Count Tool ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to count words in a given string
int countWords(char *str){
    int count = 0;
    char *token;
    
    //Using strtok function to tokenize the string to count words
    token = strtok(str, " ");
    while(token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    
    return count;
}

int main(){
	char inputStr[500];
	printf("Enter a string: ");
	fgets(inputStr, 500, stdin);
	
	//Removing the newline character from the input string
	if(inputStr[strlen(inputStr)-1] == '\n'){
        inputStr[strlen(inputStr)-1] = '\0';
    }
    
    int wordCount = countWords(inputStr);
	printf("The number of words in the given string is: %d\n", wordCount);
	
	return 0;
}