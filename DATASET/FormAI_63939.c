//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: brave
#include<stdio.h>
#include<ctype.h> // to use toupper() function
#include<string.h>

#define MAX_LENGTH 50
// Define Morse code array with Alphabets, Numbers and Special Characters
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", 
    ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
    ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----",
    "--..--", ".-.-.-", "..--..", "-.-.--"
};

// Define English Alphabets, Numbers and Special Characters array
char *english[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", 
    "J", "K", "L", "M", "N", "O", "P", "Q", 
    "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
    ",", ".", "?", "!"
};

// Function to convert English text to Morse code
void english_to_morse(char *text){
    int i, j;

    // Loop through each character of the text to convert to Morse code
    for(i = 0; i < strlen(text); i++){
        // Check if character is a space
        if(text[i] == ' '){
            printf("  "); // Double space for space character
        } else {
            // Check if character is Alphabets, Numbers or Special characters
            for(j = 0; j < 43; j++){
                // Convert uppercase character to lowercase
                char character = toupper(text[i]);
                // Compare the character with the appropriate Morse code
                if(character == english[j][0]){
                    printf("%s ", morse_code[j]); // Print Morse code with space after each character
                }
            }
        }
    }
}

int main(){
    char text[MAX_LENGTH];
    printf("Enter the text to convert to Morse code:\n");
    fgets(text, sizeof(text), stdin); // Get text input from user

    printf("\nMorse code for given text:\n");
    english_to_morse(text); // Call function to convert text to Morse code

    return 0;
}