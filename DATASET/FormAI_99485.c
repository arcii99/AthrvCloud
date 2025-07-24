//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: optimized
#include <stdio.h>
#include <string.h>

int main() {
    char english[100], alien[100];
    int i, length, option;

    printf("Welcome to the C Alien Language Translator!\n");
    printf("Choose an option:\n");
    printf("1. English to Alien\n");
    printf("2. Alien to English\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("Enter a sentence in English: ");
            getchar(); // Clears the input buffer
            fgets(english, 100, stdin);
            length = strlen(english);

            for(i = 0; i < length - 1; i++) {
                if(english[i] == 'a') {
                    alien[i] = '^';
                } else if(english[i] == 'b') {
                    alien[i] = '*';
                } else if(english[i] == 'c') {
                    alien[i] = '&';
                } else if(english[i] == 'd') {
                    alien[i] = '$';
                } else if(english[i] == 'e') {
                    alien[i] = '#';
                } else if(english[i] == 'f') {
                    alien[i] = '@';
                } else if(english[i] == 'g') {
                    alien[i] = '!';
                } else if(english[i] == 'h') {
                    alien[i] = ')';
                } else if(english[i] == 'i') {
                    alien[i] = '(';
                } else if(english[i] == 'j') {
                    alien[i] = '-';
                } else if(english[i] == 'k') {
                    alien[i] = '+';
                } else if(english[i] == 'l') {
                    alien[i] = '/';
                } else if(english[i] == 'm') {
                    alien[i] = '|';
                } else if(english[i] == 'n') {
                    alien[i] = '=';
                } else if(english[i] == 'o') {
                    alien[i] = '~';
                } else if(english[i] == 'p') {
                    alien[i] = '`';
                } else if(english[i] == 'q') {
                    alien[i] = ':';
                } else if(english[i] == 'r') {
                    alien[i] = ';';
                } else if(english[i] == 's') {
                    alien[i] = ']';
                } else if(english[i] == 't') {
                    alien[i] = '[';
                } else if(english[i] == 'u') {
                    alien[i] = '}';
                } else if(english[i] == 'v') {
                    alien[i] = '{';
                } else if(english[i] == 'w') {
                    alien[i] = '"';
                } else if(english[i] == 'x') {
                    alien[i] = '\'';
                } else if(english[i] == 'y') {
                    alien[i] = '>';
                } else if(english[i] == 'z') {
                    alien[i] = '<';
                } else {
                    alien[i] = english[i];
                }
            }

            printf("\nAlien translation: %s\n", alien);
            break;

        case 2:
            printf("Enter a sentence in Alien: ");
            getchar(); // Clears the input buffer
            fgets(alien, 100, stdin);
            length = strlen(alien);

            for(i = 0; i < length - 1; i++) {
                if(alien[i] == '^') {
                    english[i] = 'a';
                } else if(alien[i] == '*') {
                    english[i] = 'b';
                } else if(alien[i] == '&') {
                    english[i] = 'c';
                } else if(alien[i] == '$') {
                    english[i] = 'd';
                } else if(alien[i] == '#') {
                    english[i] = 'e';
                } else if(alien[i] == '@') {
                    english[i] = 'f';
                } else if(alien[i] == '!') {
                    english[i] = 'g';
                } else if(alien[i] == ')') {
                    english[i] = 'h';
                } else if(alien[i] == '(') {
                    english[i] = 'i';
                } else if(alien[i] == '-') {
                    english[i] = 'j';
                } else if(alien[i] == '+') {
                    english[i] = 'k';
                } else if(alien[i] == '/') {
                    english[i] = 'l';
                } else if(alien[i] == '|') {
                    english[i] = 'm';
                } else if(alien[i] == '=') {
                    english[i] = 'n';
                } else if(alien[i] == '~') {
                    english[i] = 'o';
                } else if(alien[i] == '`') {
                    english[i] = 'p';
                } else if(alien[i] == ':') {
                    english[i] = 'q';
                } else if(alien[i] == ';') {
                    english[i] = 'r';
                } else if(alien[i] == ']') {
                    english[i] = 's';
                } else if(alien[i] == '[') {
                    english[i] = 't';
                } else if(alien[i] == '}') {
                    english[i] = 'u';
                } else if(alien[i] == '{') {
                    english[i] = 'v';
                } else if(alien[i] == '"') {
                    english[i] = 'w';
                } else if(alien[i] == '\'') {
                    english[i] = 'x';
                } else if(alien[i] == '>') {
                    english[i] = 'y';
                } else if(alien[i] == '<') {
                    english[i] = 'z';
                } else {
                    english[i] = alien[i];
                }
            }

            printf("\nEnglish translation: %s\n", english);
            break;

        default:
            printf("Invalid choice, please try again!\n");
    }

    return 0;
}