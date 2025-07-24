//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: surrealist
#include <stdio.h>
#include <string.h>

// Translator function
void translate(char input[]) {
    int length = strlen(input);
    int i;
    printf("Translation: ");
    for (i=0; i<length; i++) {
        char c = input[i];
        switch(c) {
            case 'a': printf("Ǝ"); break;
            case 'b': printf("¡"); break;
            case 'c': printf("Ҝ"); break;
            case 'd': printf("Ø"); break;
            case 'e': printf("Є"); break;
            case 'f': printf("Є"); break;
            case 'g': printf("Ɣ"); break;
            case 'h': printf("Ħ"); break;
            case 'i': printf("Θ"); break;
            case 'j': printf("Ĵ"); break;
            case 'k': printf("Ќ"); break;
            case 'l': printf("Ľ"); break;
            case 'm': printf("Ӎ"); break;
            case 'n': printf("Ň"); break;
            case 'o': printf("Ø"); break;
            case 'p': printf("Ƥ"); break;
            case 'q': printf("Ǫ"); break;
            case 'r': printf("Ř"); break;
            case 's': printf("Š"); break;
            case 't': printf("Ť"); break;
            case 'u': printf("Ü"); break;
            case 'v': printf("√"); break;
            case 'w': printf("Ш"); break;
            case 'x': printf("Ж"); break;
            case 'y': printf("¥"); break;
            case 'z': printf("Ƶ"); break;
            default: printf("%c",c); break; // prints character as is if not found in translation table
        }
    }
    printf("\n");
}

// Main function
int main() {
    printf("Welcome to the C Alien Language translator. Please enter a sentence: ");
    char input[1000];
    fgets(input, 1000, stdin);
    translate(input);
    return 0;
}