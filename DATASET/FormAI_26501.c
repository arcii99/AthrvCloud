//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: curious
#include<stdio.h>
#include<string.h>

char* morseCode(char c){
    // Morse code lookup table
    char *morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
                    "--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-",
                    "-.--","--.."};

    if(c >= 'a' && c <= 'z'){   // if character is lowercase
        return morse[c - 'a'];
    }
    else if(c >= 'A' && c <= 'Z'){  // if character is uppercase
        return morse[c - 'A'];
    }
    else{   // if character is not a letter
        return "";
    }
}

int main(){
    char text[1000], morse[5000];
    int i, j;

    printf("Enter the text to convert to Morse code: ");
    fgets(text, 1000, stdin);   // get text input from user

    text[strcspn(text, "\n")] = 0;   // remove newline character

    for(i=0, j=0; i<strlen(text); i++){   // loop through each character in text
        if(text[i] == ' '){   // if character is a space
            morse[j++] = '/';
        }
        else{   // if character is not a space
            char* code = morseCode(text[i]);
            strcat(morse, code);   // concatenate Morse code for character to morse string
            morse[j++] = ' ';   // add space after Morse code for character
        }
    }

    printf("Morse code: %s\n", morse);

    return 0;
}