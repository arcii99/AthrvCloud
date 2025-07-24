//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Morse code dictionary
const char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
                            "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
                            "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                            "-.--", "--.."};

/**
 * Function to convert string to morse code
 * @param message: the message string to be converted
 */ 
void convertToMorseCode(const char *message){
    printf("The morse code translation for \"%s\" is below:\n", message);
    int length = strlen(message);
    for(int i = 0; i < length; i++){
        char c = toupper(message[i]);
        if(isalpha(c)){ 
            printf("%s ",morse_code[c - 'A']);
        } else if (c == ' '){
            printf("  "); // two spaces represent a space in morse code
        }
    }
}

int main(){
    printf("Welcome to the Morse Code Converter by Sherlock Holmes.\n");
    printf("Please enter the message to convert to morse code: ");
    char message[100];
    fgets(message, sizeof(message), stdin);
    // remove trailing newline character from message input
    message[strcspn(message,"\n")] = 0; 
    convertToMorseCode(message);
    return 0;
}