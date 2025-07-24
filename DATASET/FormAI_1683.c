//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: invasive
#include <stdio.h> //header file for standard input and output operations

int main()
{
    char word[20]; //variable to store the input word
    int i; //variable for loop iteration
    
    //instructions for the user
    printf("Welcome to the C Cat Language Translator!\n");
    printf("Enter an English word to translate to Cat language:\n");
    scanf("%s", word); //read input word from the user
    
    //translation process
    printf("Cat language translation: ");
    for(i=0; word[i]!='\0'; i++)
    {
        switch(word[i])
        {
            case 'a': printf("meow"); break;
            case 'b': printf("purr"); break;
            case 'c': printf("hiss"); break;
            //and so on for all letters of the alphabet
            default: printf("%c", word[i]); //if letter not found, print the same character
        }
    }
    printf("\n"); //new line
    
    return 0; //exit program
}