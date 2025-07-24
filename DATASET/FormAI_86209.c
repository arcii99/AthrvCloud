//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: grateful
#include <stdio.h>
#include <string.h>

void printMorseCode(char* message) {
    // Initialize an array of Morse Code values for each uppercase letter
    const char* morseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", 
                                "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    printf("Here is your message in Morse Code: \n");

    for (int i = 0; i < strlen(message); i++) {
        char letter = message[i];
        // Convert the uppercase ASCII value of the letter to its corresponding Morse Code index
        int morseCodeIndex = letter - 'A';
        // Print the Morse Code value for the letter
        if (morseCodeIndex >= 0 && morseCodeIndex < 26) {
            printf("%s ", morseCodes[morseCodeIndex]);
        }
        // If the character is not an uppercase letter, print an error message
        else {
            printf("Error: Only uppercase letters are accepted. \n");
            return;
        }
    }
    printf("\n");
}

int main() {
    printf("Welcome to the Morse Code converter! \n");
    printf("Please enter your message in uppercase letters: ");

    char message[100];
    fgets(message, 100, stdin);

    // Remove the newline character at the end of the input string
    message[strcspn(message, "\n")] = 0;

    printMorseCode(message);

    printf("Thank you for using the Morse Code converter! \n");

    return 0;
}