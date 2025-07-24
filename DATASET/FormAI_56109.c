//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: inquisitive
#include <stdio.h>
#include <string.h>

void convertToMorse(char message[], char morse[][6]){
    int len = strlen(message); 
    // Maximum length of a Morse code letter is 5
    // We added 1 to the array to allow for a null terminator ('\0')
    for(int i=0; i<len+1; i++){
        for(int j=0; j<6; j++){
            morse[i][j] = '\0'; // Initialize each element to null terminator
        }
    }
    // Morse code representation of each character in message
    char *morseLetters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", 
                            "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
                            "-.--", "--..", "/", ".----", "..---", "...--", "....-", ".....", "-....", "--...", 
                            "---..", "----.", "-----", ".-.-.-", "--..--", "..--.."};
    for(int i=0; i<len; i++){
        int ascii = (int)message[i]; // ASCII code for current character
        if(ascii>=65 && ascii<=90){ // Uppercase letters
            // Find index of corresponding Morse code letter
            int index = ascii-65;
            strcpy(morse[i], morseLetters[index]);
        }
        else if(ascii>=97 && ascii<=122){ // Lowercase letters
            // Find index of corresponding Morse code letter
            int index = ascii-97;
            strcpy(morse[i], morseLetters[index]);
        }
        else if(ascii>=48 && ascii<=57){ // Digits
            // Find index of corresponding Morse code digit
            int index = ascii-22;
            strcpy(morse[i], morseLetters[index]);
        }
        else{ // Special characters
            if(ascii==32){ // Space character
                strcpy(morse[i], "/"); // Morse code for space is "/"
            }
            else{
                // Find index of corresponding Morse code symbol
                if(ascii==46) // Period
                    strcpy(morse[i], morseLetters[36]);
                else if(ascii==44) // Comma
                    strcpy(morse[i], morseLetters[37]);
                else if(ascii==63) // Question mark
                    strcpy(morse[i], morseLetters[38]);
            }
        }
    }
}

int main(){
    char message[101]; // Maximum length of input message is 100
    char morse[101][6]; // Maximum length of a Morse code letter is 5; 100 letters in message + 1 null terminator
    printf("Enter a message to convert to Morse code:\n");
    fgets(message, sizeof(message), stdin); // Read input message from user
    message[strcspn(message, "\n")] = '\0'; // Remove newline character from input
    
    convertToMorse(message, morse); // Convert input message to Morse code
    
    printf("Morse code representation of the input message:\n");
    int len = strlen(message); 
    for(int i=0; i<len; i++){
        printf("%s ", morse[i]); // Print Morse code representation of each letter in message
    }
    printf("\n");

    return 0;
}