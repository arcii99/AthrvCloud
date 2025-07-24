//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: energetic
// Welcome to the C Cat Language Translator!

#include<stdio.h> // include standard input-output header file
#include<string.h> // include string header file
#include<ctype.h> // include ctype header file
#define MAX_LENGTH 100 // define maximum length of input 

void translate(char input[MAX_LENGTH]);

int main(){
    char input[MAX_LENGTH]; // declare input array
    printf("Hello! I'm the C Cat Language Translator!\n");
    printf("Please enter a sentence in C Cat Language: ");
    fgets(input, MAX_LENGTH, stdin); // take input from user
    printf("Your sentence in Human Language is: ");
    translate(input); // call translate function
    printf("\nMeow-meow, thanks for using the C Cat Language Translator!");
    return 0;
}

void translate(char input[MAX_LENGTH]){
    char output[MAX_LENGTH]; // declare output array
    int length = strlen(input); // calculate length of input
    
    // iterate through each character of input
    for(int i=0; i<length; i++){
        char c = tolower(input[i]); // convert to lower case
        
        switch(c){
            case 'm':
                output[i] = 'a'; // replace 'm' with 'a'
                break;
            case 'e':
                output[i] = 'e'; // 'e' remains the same
                break;
            case 'w':
                output[i] = 'i'; // replace 'w' with 'i'
                break;
            case 'o':
                output[i] = 'o'; // 'o' remains the same
                break;
            case ' ':
                output[i] = ' '; // space remains the same
                break;
            case '\n':
                output[i] = '\n'; // newline remains the same
                break;
            default:
                output[i] = c; // all other characters remain the same
        }
    }
    printf("%s", output); // print translated output
}