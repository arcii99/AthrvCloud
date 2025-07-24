//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: energetic
#include <stdio.h>
#include <string.h>

// function to convert text to morse code
void text_to_morse(char text[]) {
    // array containing morse code table
    char *morse_table[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", 
                           "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
                           "-.--", "--..", "/", ".----", "..---", "...--", "....-", ".....", "-....", "--...", 
                           "---..", "----.", "-----", NULL};
    // array containing the corresponding letters and numbers
    char *letter_table[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", 
                            "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " ", "1", "2", "3", "4", "5", "6", "7", 
                            "8", "9", "0", NULL};
    // loop through each character in the text
    for (int i = 0; i < strlen(text); i++) {
        char *c = NULL;
        // find the corresponding morse code for the letter/number/space
        for (int j = 0; letter_table[j] != NULL; j++) {
            if (text[i] == *letter_table[j]) {
                c = morse_table[j];
                break;
            }
        }
        // print the morse code to the console
        if (c != NULL) {
            printf("%s ", c);
        }
    }
}

// main function
int main() {
    char text[100];
    printf("Enter text to convert to Morse code: ");
    fgets(text, 100, stdin);
    printf("Morse code: ");
    text_to_morse(text);
    return 0;
}