//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

// Function prototype
void translate(char word[], char alien[]);

int main() {
    // Declare variables
    char word[100];
    char alien[100];

    printf("Enter word to be translated: ");
    scanf("%s", word);

    translate(word, alien);
    printf("In Alien language, it is \"%s\"\n", alien);

    return 0;
}

// Function to translate to Alien language
void translate(char word[], char alien[]) {
    int i, j;
    int len = strlen(word);

    // Loop through each character and convert to Alien language
    for(i = 0, j = 0; i < len; i++, j++) {
        switch(word[i]) {
            case 'a':
                alien[j] = 'z';
                break;
            case 'b':
                alien[j] = 'y';
                break;
            case 'c':
                alien[j] = 'x';
                break;
            case 'd':
                alien[j] = 'w';
                break;
            case 'e':
                alien[j] = 'v';
                break;
            case 'f':
                alien[j] = 'u';
                break;
            case 'g':
                alien[j] = 't';
                break;
            case 'h':
                alien[j] = 's';
                break;
            case 'i':
                alien[j] = 'r';
                break;
            case 'j':
                alien[j] = 'q';
                break;
            case 'k':
                alien[j] = 'p';
                break;
            case 'l':
                alien[j] = 'o';
                break;
            case 'm':
                alien[j] = 'n';
                break;
            case 'n':
                alien[j] = 'm';
                break;
            case 'o':
                alien[j] = 'l';
                break;
            case 'p':
                alien[j] = 'k';
                break;
            case 'q':
                alien[j] = 'j';
                break;
            case 'r':
                alien[j] = 'i';
                break;
            case 's':
                alien[j] = 'h';
                break;
            case 't':
                alien[j] = 'g';
                break;
            case 'u':
                alien[j] = 'f';
                break;
            case 'v':
                alien[j] = 'e';
                break;
            case 'w':
                alien[j] = 'd';
                break;
            case 'x':
                alien[j] = 'c';
                break;
            case 'y':
                alien[j] = 'b';
                break;
            case 'z':
                alien[j] = 'a';
                break;
            default:
                alien[j] = word[i];
                break;
        }
    }

    alien[len] = '\0'; // Terminate string with null character
}