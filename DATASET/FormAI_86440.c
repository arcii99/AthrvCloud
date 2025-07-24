//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: careful
#include <stdio.h>
#include <string.h>

/* C Cat Language Dictionary */
char cCatDict[][10] = {
    "meow", "int", 
    "purr", "float", 
    "hiss", "char", 
    "scratches", "void",
    "whiskers", "struct",
    "claws", "enum",
    "tail", "typedef",
    "feline", "union"
};

int main()
{
    char cCatInput[100]; //input from user
    int dictSize = sizeof(cCatDict) / sizeof(cCatDict[0]); //size of dictionary
    char cCatOutput[100] = ""; //output in C language format
    char *token; //tokenize the input
    
    printf("Welcome to the C Cat Language Translator!\n");
    printf("Enter a sentence in C Cat language: ");
    fgets(cCatInput, sizeof(cCatInput), stdin); //get the input from user
    
    // Tokenize the input by space character
    token = strtok(cCatInput, " ");
    
    // Loop through the tokens and convert to C language format
    while(token != NULL)
    {
        // Loop through the dictionary for the matching word
        for(int i = 0; i < dictSize; i += 2)
        {
            if(strcmp(token, cCatDict[i]) == 0)
            {
                strcat(cCatOutput, cCatDict[i+1]); //add the C language equivalent
                strcat(cCatOutput, " "); //add a space after each word
                break; //exit the loop once found
            }
        }
        token = strtok(NULL, " ");
    }   

    printf("\nTranslated sentence in C language: %s\n",cCatOutput); //print output
    return 0;
}