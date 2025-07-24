//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: modular
#include <stdio.h>
#include <string.h>

char* translateToEnglish(char*);

int main() {
    char alienSentence[100];
    printf("Enter a sentence in Alien Language: ");
    fgets(alienSentence, 100, stdin);
    // Remove trailing newline character
    alienSentence[strcspn(alienSentence, "\n")] = 0;
    char* englishSentence = translateToEnglish(alienSentence);
    printf("Translated sentence: %s\n", englishSentence);
    return 0;
}

char* translateToEnglish(char* alienSentence) {
    char* englishSentence = malloc(strlen(alienSentence) * sizeof(char));
    for (int i = 0; i < strlen(alienSentence); i++) {
        switch (alienSentence[i]) {
            case 'Z':
                englishSentence[i] = 'A';
                break;
            case 'Y':
                englishSentence[i] = 'B';
                break;
            case 'X':
                englishSentence[i] = 'C';
                break;
            case 'W':
                englishSentence[i] = 'D';
                break;
            case 'V':
                englishSentence[i] = 'E';
                break;
            case 'U':
                englishSentence[i] = 'F';
                break;
            case 'T':
                englishSentence[i] = 'G';
                break;
            case 'S':
                englishSentence[i] = 'H';
                break;
            case 'R':
                englishSentence[i] = 'I';
                break;
            case 'Q':
                englishSentence[i] = 'J';
                break;
            case 'P':
                englishSentence[i] = 'K';
                break;
            case 'O':
                englishSentence[i] = 'L';
                break;
            case 'N':
                englishSentence[i] = 'M';
                break;
            case 'M':
                englishSentence[i] = 'N';
                break;
            case 'L':
                englishSentence[i] = 'O';
                break;
            case 'K':
                englishSentence[i] = 'P';
                break;
            case 'J':
                englishSentence[i] = 'Q';
                break;
            case 'I':
                englishSentence[i] = 'R';
                break;
            case 'H':
                englishSentence[i] = 'S';
                break;
            case 'G':
                englishSentence[i] = 'T';
                break;
            case 'F':
                englishSentence[i] = 'U';
                break;
            case 'E':
                englishSentence[i] = 'V';
                break;
            case 'D':
                englishSentence[i] = 'W';
                break;
            case 'C':
                englishSentence[i] = 'X';
                break;
            case 'B':
                englishSentence[i] = 'Y';
                break;
            case 'A':
                englishSentence[i] = 'Z';
                break;
            default:
                englishSentence[i] = alienSentence[i];
                break;
        }
    }
    // Add null character after the string
    englishSentence[strlen(alienSentence)] = '\0';
    return englishSentence;
}