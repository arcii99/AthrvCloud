//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

// Define the maximum length of a string
#define MAX_LEN 100

// Define the C Alien Language dictionary
const char* ALIEN_DICT[] = {
    "blorg", "hello",
    "fleem", "goodbye",
    "plax", "yes",
    "krell", "no",
    "zog", "thank you",
    "snik", "please"
};

// Define the number of entries in the dictionary
const int NUM_ENTRIES = 6;

// Function to translate a given word to its equivalent in C Alien Language
void translate_word(char* word) {
    int i;
    for(i = 0; i < NUM_ENTRIES*2; i += 2) {
        if(strcmp(word, ALIEN_DICT[i]) == 0) {
            printf("%s ", ALIEN_DICT[i+1]);
            return;
        }
    }
    printf("%s ", word);
}

int main() {
    char message[MAX_LEN];
    printf("Enter a message: ");
    fgets(message, MAX_LEN, stdin);
    char* word = strtok(message, " ");
    
    while(word != NULL) {
        translate_word(word);
        word = strtok(NULL, " ");
    }
    
    return 0;
}