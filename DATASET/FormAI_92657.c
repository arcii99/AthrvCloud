//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: multivariable
#include <stdio.h>
#include <string.h>

int main() {

    // Define variables
    char alien_language[100], english_translation[100];
    int i, j;

    // Prompt user to enter alien language
    printf("Enter the alien language to translate: ");
    scanf("%s", alien_language);

    // Translate the alien language
    for(i=0; i<strlen(alien_language); i++) {
        switch(alien_language[i]) {
            case 'A':
                english_translation[i] = 'Z';
                break;
            case 'B':
                english_translation[i] = 'Y';
                break;
            case 'C':
                english_translation[i] = 'X';
                break;
            case 'D':
                english_translation[i] = 'W';
                break;
            case 'E':
                english_translation[i] = 'V';
                break;
            case 'F':
                english_translation[i] = 'U';
                break;
            case 'G':
                english_translation[i] = 'T';
                break;
            case 'H':
                english_translation[i] = 'S';
                break;
            case 'I':
                english_translation[i] = 'R';
                break;
            case 'J':
                english_translation[i] = 'Q';
                break;
            case 'K':
                english_translation[i] = 'P';
                break;
            case 'L':
                english_translation[i] = 'O';
                break;
            case 'M':
                english_translation[i] = 'N';
                break;
            case 'N':
                english_translation[i] = 'M';
                break; 
            case 'O':
                english_translation[i] = 'L';
                break;
            case 'P':
                english_translation[i] = 'K';
                break;
            case 'Q':
                english_translation[i] = 'J';
                break;
            case 'R':
                english_translation[i] = 'I';
                break;
            case 'S':
                english_translation[i] = 'H';
                break;
            case 'T':
                english_translation[i] = 'G';
                break;
            case 'U':
                english_translation[i] = 'F';
                break;
            case 'V':
                english_translation[i] = 'E';
                break;
            case 'W':
                english_translation[i] = 'D';
                break;
            case 'X':
                english_translation[i] = 'C';
                break;
            case 'Y':
                english_translation[i] = 'B';
                break;
            case 'Z':
                english_translation[i] = 'A';
                break;
            default:
                printf("Invalid character entered!");
                break;
        }   
    }

    // Print the translated alien language
    printf("The translated alien language is: %s\n", english_translation);

    return 0;
}