//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// Cat Language dictionary
typedef struct {
    char* cat_word;
    char* human_translation;
} Dictionary;

Dictionary cat_dictionary[] = {
    {"meow", "hello"},
    {"purr", "thank you"},
    {"hiss", "no"},
    {"scratch", "stop"},
    {"crinkle", "food"},
    {"nap", "sleep"},
    {"play", "fun"},
    {"hunt", "chase"},
    {"lick", "clean"},
    {"stretch", "exercise"}
};

// Function to translate the Cat Language
void cat_translate(char* input) {
    // Split input into individual words
    char* word = strtok(input, " ");
    while(word != NULL) {
        // Loop through dictionary to find matching cat word
        int i;
        for(i = 0; i < 10; i++) {
            if(strcmp(cat_dictionary[i].cat_word, word) == 0) {
                printf("%s ", cat_dictionary[i].human_translation);
                break;
            }
        }
        // If no match found, print the original word
        if(i == 10) {
            printf("%s ", word);
        }
        word = strtok(NULL, " ");
    }
}

// Function to generate random cat language
void cat_speak() {
    // Used to seed random number generator
    srand(time(NULL));
    // Generate a random number of meows between 1 and 10
    int num_meows = rand() % 10 + 1;
    int i;
    for(i = 0; i < num_meows; i++) {
        printf("meow ");
        // Sleep for a random amount of time between 0.1 and 1 second
        usleep((rand() % 1000 + 100) * 1000);
    }
    printf("\n");
}

int main() {
    // Example usage
    printf("Cat says:\n");
    cat_speak();
    printf("\nEnter a sentence in Cat Language:\n");
    char input[200];
    fgets(input, 200, stdin);
    printf("You say:\n%s\n", input);
    printf("Translation:\n");
    cat_translate(input);
    printf("\n");
    return 0;
}