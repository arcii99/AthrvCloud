//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: automated
#include <stdio.h>
#include <string.h>

int main() {
    char alienWord[50];
    printf("Enter an alien word: ");
    scanf("%s", alienWord);

    int len = strlen(alienWord);
    char englishWord[len];

    for (int i = 0; i < len; i++) {
        switch (alienWord[i]) {
            case 'X':
                englishWord[i] = 'A';
                break;
            case 'Y':
                englishWord[i] = 'B';
                break;
            case 'Z':
                englishWord[i] = 'C';
                break;
            case 'L':
                englishWord[i] = 'D';
                break;
            case 'M':
                englishWord[i] = 'E';
                break;
            case 'N':
                englishWord[i] = 'F';
                break;
            case 'O':
                englishWord[i] = 'G';
                break;
            case 'P':
                englishWord[i] = 'H';
                break;
            case 'Q':
                englishWord[i] = 'I';
                break;
            case 'R':
                englishWord[i] = 'J';
                break;
            case 'S':
                englishWord[i] = 'K';
                break;
            case 'T':
                englishWord[i] = 'L';
                break;
            case 'U':
                englishWord[i] = 'M';
                break;
            case 'V':
                englishWord[i] = 'N';
                break;
            case 'W':
                englishWord[i] = 'O';
                break;
            case 'A':
                englishWord[i] = 'P';
                break;
            case 'B':
                englishWord[i] = 'Q';
                break;
            case 'C':
                englishWord[i] = 'R';
                break;
            case 'D':
                englishWord[i] = 'S';
                break;
            case 'E':
                englishWord[i] = 'T';
                break;
            case 'F':
                englishWord[i] = 'U';
                break;
            case 'G':
                englishWord[i] = 'V';
                break;
            case 'H':
                englishWord[i] = 'W';
                break;
            case 'I':
                englishWord[i] = 'X';
                break;
            case 'J':
                englishWord[i] = 'Y';
                break;
            case 'K':
                englishWord[i] = 'Z';
                break;
            default:
                englishWord[i] = ' ';
                break;
        }
    }

    printf("The alien word %s translates to %s in English.", alienWord, englishWord);

    return 0;
}