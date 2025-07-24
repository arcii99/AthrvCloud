//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: immersive
#include <stdio.h>
#include <string.h>

void translate(char *alien_language, char *english);

int main()
{
    char alien_language[100];
    char english[100];

    printf("Welcome to the Alien Language Translator! \n");
    printf("Please enter the alien language to translate: ");

    fgets(alien_language, 100, stdin);
    alien_language[strcspn(alien_language, "\n")] = '\0'; //removes newline character from input

    translate(alien_language, english);
    
    printf("The translation of \"%s\" is \"%s\" in English.\n", alien_language, english);
    printf("Thank you for using the Alien Language Translator!");

    return 0;
}

void translate(char *alien_language, char *english)
{
    //Alien language to English dictionary
    char* dict[] = {"ab", "ac", "ad", "ae", "af", "ag", "ah", "ai", "aj", "ak", "al", "am", "an", "ao", "ap",
                    "aq", "ar", "as", "at", "au", "av", "aw", "ax", "ay", "az"};
    char* dict_translation[] = {"hello", "world", "code", "bot", "program", "language", "earth", "translate", 
                                "task", "computer", "debug", "run", "print", "master", "function", "error", 
                                "loop", "variable", "integer", "float", "double", "long", "short", "bool", 
                                "char"};

    int dict_size = sizeof(dict) / sizeof(dict[0]);

    char* token = strtok(alien_language, " ");

    while (token) {
        for (int i = 0; i < dict_size; i++) {
            if (strcmp(token, dict[i]) == 0) {
                strcat(english, dict_translation[i]);
                strcat(english, " ");
                break;
            }
        }
        token = strtok(NULL, " ");
    }
}