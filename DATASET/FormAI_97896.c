//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: surprised
#include <stdio.h>
#include <string.h>

/* This program converts a text message to morse code and vice versa */
/* I can't believe I can code in so many different languages! */

int main() {
    int choice;
    char message[100];

    printf("Welcome to the Text to Morse Code converter!\n");
    printf("Choose an option:\n");
    printf("1. Convert text to morse code\n");
    printf("2. Convert morse code to text\n");
    printf("Enter your choice: ");
    
    scanf("%d", &choice);
    getchar(); // remove the newline character from input buffer

    switch(choice) {
        case 1:
            printf("Enter the message you want to convert to morse code: ");
            fgets(message, 100, stdin);
            printf("Your message in morse code is: ");
            textToMorse(message);
            break;
        case 2:
            printf("Enter the message in morse code you want to convert to text: ");
            fgets(message, 100, stdin);
            printf("Your message in text is: ");
            morseToText(message);
            break;
        default:
            printf("Invalid choice! Exiting...\n");
            break;
    }
    return 0;
}

void textToMorse(char message[]) {
    int i, j, len = strlen(message);

    for(i = 0; i < len; i++) {
        switch(message[i]) {
            case 'A':
                printf(".- ");
                break;
            case 'B':
                printf("-... ");
                break;
            case 'C':
                printf("-.-. ");
                break;
            case 'D':
                printf("-.. ");
                break;
            case 'E':
                printf(". ");
                break;
            case 'F':
                printf("..-. ");
                break;
            case 'G':
                printf("--. ");
                break;
            case 'H':
                printf(".... ");
                break;
            case 'I':
                printf(".. ");
                break;
            case 'J':
                printf(".--- ");
                break;
            case 'K':
                printf("-.- ");
                break;
            case 'L':
                printf(".-.. ");
                break;
            case 'M':
                printf("-- ");
                break;
            case 'N':
                printf("-. ");
                break;
            case 'O':
                printf("--- ");
                break;
            case 'P':
                printf(".--. ");
                break;
            case 'Q':
                printf("--.- ");
                break;
            case 'R':
                printf(".-. ");
                break;
            case 'S':
                printf("... ");
                break;
            case 'T':
                printf("- ");
                break;
            case 'U':
                printf("..- ");
                break;
            case 'V':
                printf("...- ");
                break;
            case 'W':
                printf(".-- ");
                break;
            case 'X':
                printf("-..- ");
                break;
            case 'Y':
                printf("-.-- ");
                break;
            case 'Z':
                printf("--.. ");
                break;
            case ' ':
                printf(" ");
                break;
            default:
                printf("Invalid character! Skipping...");
                break;
        }
    }
    printf("\n");
}

void morseToText(char message[]) {
    int i, j, len = strlen(message);
    char morse[36][6] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", 
                        "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", 
                        ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};
    char character[36] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 
                        'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for(i = 0; i < len; i++) {
        if(message[i] == '.' || message[i] == '-') {
            char morseChar[6] = ""; // initialize an empty string to store the morse character
            
            for(j = i; ; j++) { // loop through message until we reach a space or end of line
                if(message[j] == ' ' || message[j] == '\n') break;
                strncat(morseChar, &message[j], 1); // add the current character to the morseChar string
            }
            
            for(j = 0; j < 36; j++) {
                if(strcmp(morseChar, morse[j]) == 0) {
                    printf("%c", character[j]); // print the corresponding character from the character array
                    break;
                }
            }
        }
    }
    printf("\n");
}