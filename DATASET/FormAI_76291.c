//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: safe
#include <stdio.h>
#include <string.h>

int main() {
    char alien_message[100], translated_message[100];
    printf("Enter the alien message: ");
    scanf("%s", alien_message);

    for(int i = 0; i < strlen(alien_message); i++) {
        switch(alien_message[i]) {
            case 'A':
                translated_message[i] = 'Z';
                break;
            case 'B':
                translated_message[i] = 'Y';
                break;
            case 'C':
                translated_message[i] = 'X';
                break;
            case 'D':
                translated_message[i] = 'W';
                break;
            case 'E':
                translated_message[i] = 'V';
                break;
            case 'F':
                translated_message[i] = 'U';
                break;
            case 'G':
                translated_message[i] = 'T';
                break;
            case 'H':
                translated_message[i] = 'S';
                break;
            case 'I':
                translated_message[i] = 'R';
                break;
            case 'J':
                translated_message[i] = 'Q';
                break;
            case 'K':
                translated_message[i] = 'P';
                break;
            case 'L':
                translated_message[i] = 'O';
                break;
            case 'M':
                translated_message[i] = 'N';
                break;
            case 'N':
                translated_message[i] = 'M';
                break;
            case 'O':
                translated_message[i] = 'L';
                break;
            case 'P':
                translated_message[i] = 'K';
                break;
            case 'Q':
                translated_message[i] = 'J';
                break;
            case 'R':
                translated_message[i] = 'I';
                break;
            case 'S':
                translated_message[i] = 'H';
                break;
            case 'T':
                translated_message[i] = 'G';
                break;
            case 'U':
                translated_message[i] = 'F';
                break;
            case 'V':
                translated_message[i] = 'E';
                break;
            case 'W':
                translated_message[i] = 'D';
                break;
            case 'X':
                translated_message[i] = 'C';
                break;
            case 'Y':
                translated_message[i] = 'B';
                break;
            case 'Z':
                translated_message[i] = 'A';
                break;
            default:
                translated_message[i] = alien_message[i]; // leave the character unchanged if it's not a letter
        }
    }

    printf("The translated message is: %s\n", translated_message);
    return 0;
}