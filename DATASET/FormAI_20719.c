//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: realistic
#include <stdio.h> 
#include <string.h>

int main() {
    char c[] = "Hello, I am a C Cat!";
    printf("Original sentence: %s\n", c);
    
    for(int i = 0; i < strlen(c); i++) {
        switch(c[i]) {
            case 'c':
            case 'C':
                printf("Meow ");
                break;
            case 'a':
            case 'A':
                printf("Purr ");
                break;
            case 't':
            case 'T':
                printf("Hiss ");
                break;
            case ' ':
                printf(" ");
                break;
            default:
                printf("%c ", c[i]);
        }
    }

    printf("\n");
    return 0;
}