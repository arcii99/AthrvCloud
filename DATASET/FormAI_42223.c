//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: cheerful
#include <stdio.h>
#include <string.h>

void convertToMorse(char* input) {
    char* morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", 
                        ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    char* letters = "abcdefghijklmnopqrstuvwxyz";
    int length = strlen(input);

    for(int i=0; i<length; i++) {
        if(input[i] == ' ') {
            printf("  "); // Adds an extra space between words in Morse
        }
        else {
            char c = tolower(input[i]);
            int index = (int) c - 97;
            if(index < 0 || index > 25) {
                printf("%c ", c); // Prints out any characters not in the alphabet
            }
            else {
                printf("%s ", morse[index]); // Converts input to Morse and prints it out
            }
        }
    }
    printf("\n");
}

int main() {
    char input[100];

    printf("Welcome to the cheerful Text to Morse code converter!\n");
    printf("Please enter the text you would like to convert:\n");

    fgets(input, 100, stdin);
    printf("The Morse code for your input is:\n");

    convertToMorse(input);

    printf("Thank you for using this program! Have a great day!\n");
    return 0;
}