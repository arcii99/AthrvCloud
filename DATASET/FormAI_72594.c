//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: active
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Welcome to the C Cat Language Translator!\n");
    printf("Enter a sentence in C Cat language:\n");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;
    for(int i=0; i<strlen(input); i++) {
        if(input[i] == '=') {
            printf("Meow ");
        } else if(input[i] == '+') {
            printf("Purr ");
        } else if(input[i] == '-') {
            printf("Hiss ");
        } else if(input[i] == '*') {
            printf("Meow meow ");
        } else if(input[i] == '/') {
            printf("Mrrrooowww ");
        } else if(input[i] == '%') {
            printf("Meow meow meow ");
        } else if(input[i] == '>') {
            printf("Meow meow meow meow ");
        } else if(input[i] == '<') {
            printf("Mrraaawww ");
        } else if(input[i] == '&') {
            printf("Purr purr ");
        } else if(input[i] == '|') {
            printf("Hiss hiss ");
        } else if(input[i] == '!') {
            printf("Mrraaooowww! ");
        } else if(input[i] == '.') {
            printf("Meow meow meow meow meow ");
        } else if(input[i] == ',') {
            printf("Meow meow meow meow meow meow ");
        } else if(input[i] >= '0' && input[i] <= '9') {
            for(int j=0; j<input[i]-'0'; j++) {
                printf("Meow ");
            }
        } else if(input[i] >= 'a' && input[i] <= 'z') {
            for(int j=0; j<('z'-input[i]); j++) {
                printf("Purr ");
            }
            printf("Meow ");
        } else if(input[i] >= 'A' && input[i] <= 'Z') {
            for(int j=0; j<('Z'-input[i]); j++) {
                printf("Hiss ");
            }
            printf("Meow ");
        } else {
            printf("%c", input[i]);
        }
    }
    printf("\nThank you for using the C Cat Language Translator!");
    return 0;
}