//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: high level of detail
#include<stdio.h>
#include<string.h>

// function to translate Alien language to English
void translate(char str[]){
    char english[27] = "abcdefghijklmnopqrstuvwxyz"; // array of English alphabets
    char alien[27] = "yhesocvxduiglbkrqtnwmpfjz"; // array of Alien language alphabets
    int i, j;

    // loop through the input string
    for(i = 0; i < strlen(str); i++){
        // if the current character is a letter and not a space or punctuation
        if(str[i] >= 'a' && str[i] <= 'z'){
            // loop through the Alien language array to find the corresponding English alphabet
            for(j = 0; j < 26; j++){
                if(str[i] == alien[j]){
                    // print the English alphabet for the current Alien language alphabet
                    printf("%c", english[j]);
                    break;
                }
            }
        }
        else{
            // if the current character is not a letter, print it as is
            printf("%c", str[i]);
        }
    }
}

int main(){
    char str[100];

    printf("Enter a string in Alien language: ");
    fgets(str, sizeof(str), stdin); // read input from user

    printf("In English: ");
    translate(str); // call the translate function

    return 0;
}