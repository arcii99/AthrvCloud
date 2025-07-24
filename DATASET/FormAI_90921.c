//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: configurable
#include <stdio.h>
#include <string.h>

#define DOT "."
#define DASH "-"
#define SPACE " "
#define DOT_DASH_SPACE " / "
#define MAX_INPUT_LENGTH 500

char *morseCode[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", 
                        "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
                        "-.--", "--..", "/", ".----", "..---", "...--", "....-", ".....", "-....", "--...", 
                        "---..", "----.", "-----" 
                    };

char morseCodeChars[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 
                            'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ',
                            '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'
                        };

// function to convert a character to its Morse code equivalent
char* charToMorseCode(char c){
    int index = -1;
    // finding the index of the character in morseCodeChars array
    for(int i = 0; i < 38; i++){
        if(morseCodeChars[i] == c){
            index = i;
            break;
        }
    }
    // if index is found, return the corresponding morse code
    if(index > -1){
        return morseCode[index];
    }
    // if character is not a letter or a digit, return null
    return NULL;
}

// function to convert a string to Morse code
void textToMorseCode(char *inputString){
    // finding the length of the input string
    int inputLength = strlen(inputString);
    
    // iterating through each character of the input string
    for(int i = 0; i < inputLength; i++){
        // converting the current character to its Morse code equivalent
        char *morseCodeEquivalent = charToMorseCode(toupper(inputString[i]));
        
        // if the character is not a letter or a digit, print an error message
        if(morseCodeEquivalent == NULL){
            printf("Invalid character: %c\n", inputString[i]);
            return;
        }
        
        // printing the Morse code of the current character
        printf("%s", morseCodeEquivalent);
        // adding a space between Morse codes of different characters
        if(i != inputLength - 1){
            printf("%s", DOT_DASH_SPACE);
        }
    }
}

// main function
int main(){
    // getting input from user
    char inputString[MAX_INPUT_LENGTH];
    printf("Enter a string to convert to Morse code: ");
    fgets(inputString, MAX_INPUT_LENGTH, stdin);
    inputString[strcspn(inputString, "\n")] = 0; // removing the newline character from the input
    
    // converting the input string to Morse code and printing the result
    textToMorseCode(inputString);

    return 0;
}