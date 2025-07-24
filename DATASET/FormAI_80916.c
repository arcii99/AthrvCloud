//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: configurable
#include <stdio.h>
#include <string.h>

// Define configurable variables
#define MAX_LENGTH 1000
#define DICT_SIZE 10

// Define dictionary
char dictionary[DICT_SIZE][2][MAX_LENGTH] = {
    {"hello", "meow"},
    {"world", "purr"},
    {"goodbye", "hiss"},
    {"cat", "feline"},
    {"dog", "canine"},
    {"eat", "devour"},
    {"sleep", "nap"},
    {"scratch", "claw"},
    {"play", "toy with"},
    {"hunt", "stalk"}
};

int main(void) {

    // Initialize variables
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    char *token;
    int i, j, found_match;

    // Prompt user for input
    printf("Enter a phrase in English: ");
    fgets(input, MAX_LENGTH, stdin);

    // Convert input phrase to C Cat language
    token = strtok(input, " ");
    while(token != NULL) {
        found_match = 0;
        for(i=0; i<DICT_SIZE; i++) {
            if(strcmp(token,dictionary[i][0]) == 0) {
                strcat(output, dictionary[i][1]);
                strcat(output, " ");
                found_match = 1;
            }
        }
        if(found_match == 0) {
            strcat(output, token);
            strcat(output, " ");
        }
        token = strtok(NULL, " ");
    }

    // Output translated phrase
    printf("C Cat translation: %s\n", output);

    return 0;
}