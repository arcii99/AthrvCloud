//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: high level of detail
#include <stdio.h>
#include <string.h>

// Defining the max size of the alien language words
#define MAX_WORD_SIZE 20

// Defining the max number of alien language words in the dictionary
#define MAX_NUM_WORDS 100

// Defining the max size of the English words
#define MAX_ENGLISH_SIZE 30

// Defining the max size of the input string
#define MAX_INPUT_SIZE 1000

// Struct to hold the alien language words and their English translations
struct Dictionary {
    char alienWord[MAX_WORD_SIZE];
    char englishWord[MAX_ENGLISH_SIZE];
};

// Function to translate the given alien word into English
void translateWord(struct Dictionary* dict, int dictSize, char* alienWord, char* englishWord) {

    // Initializing the English word to be blank
    strcpy(englishWord, "");

    // Looping through all the words in the dictionary
    for(int i = 0; i < dictSize; i++) {

        // Checking if the current word in the dictionary is the alien word we are trying to translate
        if(strcmp(dict[i].alienWord, alienWord) == 0) {

            // Copying the English translation of the alien word from the dictionary to our output variable
            strcpy(englishWord, dict[i].englishWord);

            // Exiting the loop since we found the translation
            break;
        }
    }
}

int main() {

    // Initializing the dictionary with some sample alien words and their English translations
    struct Dictionary dict[MAX_NUM_WORDS] = {
        {"krg", "hello"},
        {"zlx", "goodbye"},
        {"chn", "thank you"},
        {"sgv", "yes"},
        {"knt", "no"},
        {"slm", "peace"}
    };

    // Getting the size of the dictionary (total number of alien words)
    int dictSize = sizeof(dict)/sizeof(dict[0]);

    // Initializing the input string variable
    char input[MAX_INPUT_SIZE];

    // Initializing the output string variable
    char output[MAX_INPUT_SIZE];

    // Prompting the user for input
    printf("Enter a string in alien language: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Looping through each word in the input string
    char* p = strtok(input, " ");
    while(p != NULL) {

        // Trimming the word (removing any trailing spaces or newline characters)
        p[strcspn(p, "\n")] = 0;

        // Translating the current word from alien language to English
        char englishWord[MAX_ENGLISH_SIZE];
        translateWord(dict, dictSize, p, englishWord);

        // Appending the translated word to the output string
        strcat(output, englishWord);
        strcat(output, " ");

        // Moving on to the next word in the input string
        p = strtok(NULL, " ");
    }

    // Printing the translated output
    printf("Translated: %s\n", output);

    return 0;
}