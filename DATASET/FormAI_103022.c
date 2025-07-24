//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: light-weight
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

/* Function to translate a string from Alien language to English language */
void translate(char* alien_string) {
    int i, j;
    int length = strlen(alien_string);
    
    /* Check for repeated characters and remove them */
    for(i = 0; i < length; i++) {
        for(j = i + 1; alien_string[j] != '\0'; j++) {
            if(alien_string[i] == alien_string[j]) {
                int k;
                for(k = j; k < length; k++) {
                    alien_string[k] = alien_string[k+1];
                }
                length--;
                j--;
            }
        }
    }

    /* Translate the string from Alien language to English language */
    for(i = 0; i < length; i++) {
        switch(alien_string[i]) {
            case 'a': printf("b");
                      break;
            case 'b': printf("c");
                      break;
            case 'c': printf("d");
                      break;
            case 'd': printf("e");
                      break;
            case 'e': printf("f");
                      break;
            case 'f': printf("g");
                      break;
            case 'g': printf("h");
                      break;
            case 'h': printf("i");
                      break;
            case 'i': printf("j");
                      break;
            case 'j': printf("k");
                      break;
            case 'k': printf("l");
                      break;
            case 'l': printf("m");
                      break;
            case 'm': printf("n");
                      break;
            case 'n': printf("o");
                      break;
            case 'o': printf("p");
                      break;
            case 'p': printf("q");
                      break;
            case 'q': printf("r");
                      break;
            case 'r': printf("s");
                      break;
            case 's': printf("t");
                      break;
            case 't': printf("u");
                      break;
            case 'u': printf("v");
                      break;
            case 'v': printf("w");
                      break;
            case 'w': printf("x");
                      break;
            case 'x': printf("y");
                      break;
            case 'y': printf("z");
                      break;
            case 'z': printf("a");
                      break;
            default: printf("%c", alien_string[i]);
                     break;
        }
    }

    printf("\n");
}

int main() {
    char input[MAX_LENGTH];
    
    /* Get input from user and translate it */
    printf("Enter a string in Alien language: ");
    fgets(input, MAX_LENGTH, stdin);
    translate(input);

    return 0;
}