//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: curious
#include <stdio.h>
#include <string.h>

// Function to convert Alien Language to English
void alienToEnglish(char *alienLang) {
    int len = strlen(alienLang);
    for(int i=0; i<len; i++) {
        switch(alienLang[i]) {
            case 'a':
                printf("%c", 'b');
                break;
            case 'b':
                printf("%c", 'c');
                break;
            case 'c':
                printf("%c", 'd');
                break;
            case 'd':
                printf("%c", 'e');
                break;
            case 'e':
                printf("%c", 'f');
                break;
            case 'f':
                printf("%c", 'g');
                break;
            case 'g':
                printf("%c", 'h');
                break;
            case 'h':
                printf("%c", 'i');
                break;
            case 'i':
                printf("%c", 'j');
                break;
            case 'j':
                printf("%c", 'k');
                break;
            case 'k':
                printf("%c", 'l');
                break;
            case 'l':
                printf("%c", 'm');
                break;
            case 'm':
                printf("%c", 'n');
                break;
            case 'n':
                printf("%c", 'o');
                break;
            case 'o':
                printf("%c", 'p');
                break;
            case 'p':
                printf("%c", 'q');
                break;
            case 'q':
                printf("%c", 'r');
                break;
            case 'r':
                printf("%c", 's');
                break;
            case 's':
                printf("%c", 't');
                break;
            case 't':
                printf("%c", 'u');
                break;
            case 'u':
                printf("%c", 'v');
                break;
            case 'v':
                printf("%c", 'w');
                break;
            case 'w':
                printf("%c", 'x');
                break;
            case 'x':
                printf("%c", 'y');
                break;
            case 'y':
                printf("%c", 'z');
                break;
            case 'z':
                printf("%c", 'a');
                break;
            default:
                printf("%c", alienLang[i]);
        }
    }
}

int main() {
    char alienLang[100];
    printf("Enter a sentence in Alien Language (lowercase letters only): ");
    fgets(alienLang, 100, stdin);
    printf("Translation to English: ");
    alienToEnglish(alienLang);
    return 0;
}