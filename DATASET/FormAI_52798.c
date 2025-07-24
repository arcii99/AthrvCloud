//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: shocked
#include <stdio.h>
#include <string.h>

// Function to convert a string to Alien language
void toAlienLanguage(char str[]) {
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        // Replace each character with its alien language equivalent
        switch(str[i]) {
            case 'a':
                str[i] = 'Z';
                break;
            case 'b':
                str[i] = 'Y';
                break;
            case 'c':
                str[i] = 'X';
                break;
            case 'd':
                str[i] = 'W';
                break;
            case 'e':
                str[i] = 'V';
                break;
            case 'f':
                str[i] = 'U';
                break;
            case 'g':
                str[i] = 'T';
                break;
            case 'h':
                str[i] = 'S';
                break;
            case 'i':
                str[i] = 'R';
                break;
            case 'j':
                str[i] = 'Q';
                break;
            case 'k':
                str[i] = 'P';
                break;
            case 'l':
                str[i] = 'O';
                break;
            case 'm':
                str[i] = 'N';
                break;
            case 'n':
                str[i] = 'M';
                break;
            case 'o':
                str[i] = 'L';
                break;
            case 'p':
                str[i] = 'K';
                break;
            case 'q':
                str[i] = 'J';
                break;
            case 'r':
                str[i] = 'I';
                break;
            case 's':
                str[i] = 'H';
                break;
            case 't':
                str[i] = 'G';
                break;
            case 'u':
                str[i] = 'F';
                break;
            case 'v':
                str[i] = 'E';
                break;
            case 'w':
                str[i] = 'D';
                break;
            case 'x':
                str[i] = 'C';
                break;
            case 'y':
                str[i] = 'B';
                break;
            case 'z':
                str[i] = 'A';
                break;
            default:
                str[i] = ' ';
        }
    }
    printf("The alien language equivalent of the given string is:\n%s\n", str);
}

int main() {
    char str[100];
    printf("Enter the string to be converted to Alien Language: ");
    fgets(str, sizeof(str), stdin);
    toAlienLanguage(str);
    return 0;
}