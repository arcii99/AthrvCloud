//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main(){
    char alienLang[26] = "qzuotxzwvygfklmnepdcijrsbah"; // this is the alien language mapping
    char input[1000]; // input string from user
    printf("Welcome to the C Alien Language Translator!\n");
    printf("Enter a sentence in the Alien Language to translate: ");
    fgets(input, sizeof(input), stdin); // getting the entire input
    input[strcspn(input, "\n")] = 0; // removing the newline character from the input

    int len = strlen(input); // getting the length of the string

    for(int i = 0; i <len; i++){
        if(input[i] >= 'a' && input[i] <= 'z'){ // checking if the current character is a lowercase alphabet
            int index = input[i] - 'a'; // getting the index of the alphabet in the alienLang array
            printf("%c", alienLang[index]); // printing the translated character
        }else if(input[i] >= 'A' && input[i] <= 'Z'){ // checking if the current character is an uppercase alphabet
            int index = input[i] -'A'; // getting the index of the alphabet in the alienLang array
            printf("%c", toupper(alienLang[index])); // printing the translated character in uppercase
        }else{
            printf("%c", input[i]); // the character is not an alphabet, so we directly print it
        }
    }
    printf("\n\nThank you for using the C Alien Language Translator!\n");

    return 0;
}