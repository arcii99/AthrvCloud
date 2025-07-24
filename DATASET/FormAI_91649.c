//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

// Define the C Cat Language dictionary
const char* cat_dict[] = {"meow", "purr", "hiss", "yowl", "yawn", "scratch", "lick", "nap", "claw"};

// Define function to translate C Cat Language to English
void translate_to_english(char* input) {
    char* token = strtok(input, " ");
    while(token != NULL) {
        int i;
        for (i = 0; i < sizeof(cat_dict)/sizeof(char*); i++) {
            if (strcmp(token, cat_dict[i]) == 0) {
                printf("%s ", cat_dict[i]);
                break;
            }
        }
        if (i == sizeof(cat_dict)/sizeof(char*)) {
            printf("Unknown cat word: %s ", token);
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
}

// Define function to translate English to C Cat Language
void translate_to_cat(char* input) {
    char* token = strtok(input, " ");
    while(token != NULL) {
        if (strlen(token) <= 2) {
            printf("%s ", token);
        } else {
            int i;
            for (i = 0; i < sizeof(cat_dict)/sizeof(char*); i++) {
                if (strncmp(token, cat_dict[i], 3) == 0) {
                    printf("%s ", cat_dict[i]);
                    break;
                }
            }
            if (i == sizeof(cat_dict)/sizeof(char*)) {
                printf("Unknown English word: %s ", token);
            }
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
}

int main() {
    char input[100];
    printf("Welcome to C Cat Language Translator. Enter the command (type \"quit\" to exit)\n");
    while(1) {
        scanf("%[^\n]%*c", input);
        if (strcmp(input, "quit") == 0) {
            break;
        } else if (strcmp(input, "help") == 0) {
            printf("This is a C Cat Language Translator. Type a sentence in either C Cat Language or English to get it translated. The program will automatically detect the language and translate it for you.\n");
        } else {
            if (strstr(input, "meow") != NULL || strstr(input, "purr") != NULL || strstr(input, "hiss") != NULL || strstr(input, "yowl") != NULL || strstr(input, "yawn") != NULL || strstr(input, "scratch") != NULL || strstr(input, "lick") != NULL || strstr(input, "nap") != NULL || strstr(input, "claw") != NULL) {
                translate_to_english(input);
            } else {
                translate_to_cat(input);
            }
        }
        memset(input, 0, sizeof(input));
    }
    return 0;
}