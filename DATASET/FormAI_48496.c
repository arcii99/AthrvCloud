//FormAI DATASET v1.0 Category: Text processing ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char input[1000];
    char* words[100];
    int wordCount = 0;

    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin); // gets the input from the user

    printf("\nYou entered: %s\n", input); // displays the input 

    char* pch = strtok(input, " "); // using strtok function to break our input string into words
    
    while(pch != NULL){
        words[wordCount++] = pch;
        pch = strtok(NULL, " ");
    }

    printf("\n Words in input: \n");

    for(int i=0;i<wordCount;i++){
        printf("%s\n", words[i]); // displaying all the words from the input
    }

    return 0;
}