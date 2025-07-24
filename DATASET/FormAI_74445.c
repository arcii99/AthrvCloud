//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: interoperable
/* 
    The following program is a C Cat Language Translator.
    It takes input in English language and translates it into Cat Language.
    The Cat Language consists of replacing every space with a "meow".
    For example, "Hello World" becomes "Hello meow World meow"
*/

#include<stdio.h>
#include<string.h>

int main(){
    char english[50];       // initialize the character array for english input
    char cat[50];           // initialize the character array for cat language
    int i, j = 0;

    printf("Enter a string in English: ");
    fgets(english, 50, stdin);  // take input using fgets()

    for (i = 0; i < strlen(english); i++){  // loop through each character of the input string
        if (english[i] == ' '){             // if the character is a space
            strcat(cat, "meow ");           // add "meow " to the end of the cat language string
        }
        else{                               // if the character is not a space
            cat[j] = english[i];            // add the character to the cat language string
            j++;                            // move the index of the cat language string forward
        }
    }

    printf("The string in Cat Language is: %s\n", cat);  // print the cat language string

    return 0;
}