//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: complex
#include <stdio.h>
#include <string.h>

int main() {
    char alien_language[100];
    printf("Enter the sentence in Alien Language: ");
    scanf("%[^\n]", alien_language); // Use %[^\n] instead of %s to read the entire sentence including spaces

    // Translate the alien language to English
    for(int i=0; i<strlen(alien_language); i++) {
        if(alien_language[i] == 'k') {
            printf("a");
        }
        else if(alien_language[i] == 'm') {
            printf("b");
        }
        else if(alien_language[i] == 'g') {
            printf("c");
        }
        else if(alien_language[i] == 'r') {
            printf("d");
        }
        else if(alien_language[i] == 't') {
            printf("e");
        }
        else if(alien_language[i] == 'u') {
            printf("f");
        }
        else if(alien_language[i] == 'h') {
            printf("g");
        }
        else if(alien_language[i] == 'j') {
            printf("h");
        }
        else if(alien_language[i] == 'n') {
            printf("i");
        }
        else if(alien_language[i] == 's') {
            printf("j");
        }
        else if(alien_language[i] == 'o') {
            printf("k");
        }
        else if(alien_language[i] == 'q') {
            printf("l");
        }
        else if(alien_language[i] == 'v') {
            printf("m");
        }
        else if(alien_language[i] == 'x') {
            printf("n");
        }
        else if(alien_language[i] == 'z') {
            printf("o");
        }
        else if(alien_language[i] == 'p') {
            printf("p");
        }
        else if(alien_language[i] == 'f') {
            printf("q");
        }
        else if(alien_language[i] == 'w') {
            printf("r");
        }
        else if(alien_language[i] == 'y') {
            printf("s");
        }
        else if(alien_language[i] == 'b') {
            printf("t");
        }
        else if(alien_language[i] == 'd') {
            printf("u");
        }
        else if(alien_language[i] == 'l') {
            printf("v");
        }
        else if(alien_language[i] == 'c') {
            printf("w");
        }
        else if(alien_language[i] == 'e') {
            printf("x");
        }
        else if(alien_language[i] == 'a') {
            printf("y");
        }
        else if(alien_language[i] == 'i') {
            printf("z");
        }
        else {
            printf("%c", alien_language[i]);
        }
    }

    return 0;
}