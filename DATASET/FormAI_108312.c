//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: inquisitive
#include <stdio.h>
#include <string.h>

/* A function to convert text to morse code */
void textToMorse(char* str) {
    /* Defining morse code for all the characters, including spaces */
    char *morse[36] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", 
        ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", 
        ".--", "-..-", "-.--", "--..", " ", ".----", "..---", "...--", "....-", 
        ".....", "-....", "--...", "---..", "----.", "-----"
    };

    /* Looping through each character of the text */
    for (int i = 0; i < strlen(str); i++) {
        /* If the character is a lowercase letter, converting it to uppercase */
        if (str[i] >= 97 && str[i] <= 122) {
            str[i] = str[i] - 32;
        }
        /* If the character is a digit or uppercase letter, print the corresponding morse code */
        if (str[i] >= 48 && str[i] <= 90) {
            printf("%s ", morse[str[i] - 48 - 7]);
        }
        /* If the character is a space, print a slash */
        if (str[i] == 32) {
            printf("/ ");
        }
    }
    printf("\n");
}

int main() {
    /* Prompting the user to enter a string */
    printf("Enter a text to convert to morse code:\n");
    char str[100];
    fgets(str, 100, stdin);

    /* Removing the newline character from the end of the string */
    str[strcspn(str, "\n")] = 0;

    /* Calling the function to convert the text to morse code */
    textToMorse(str);

    /* Exiting the program */
    return 0;
}