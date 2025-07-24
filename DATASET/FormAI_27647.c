//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALIEN_DICT_SIZE 10
#define ALIEN_WORD_SIZE 50

// Alien language dictionary
char alien_dict[ALIEN_DICT_SIZE][2][ALIEN_WORD_SIZE] = {
    {"hello", "akna"},
    {"world", "dunku"},
    {"how", "qozen"},
    {"are", "ogru"},
    {"you", "izal"},
    {"I", "nanu"},
    {"love", "tamun"},
    {"programming", "jazu"},
    {"challenges", "boqim"},
    {"together", "mypozu"}
};

// Function to translate a sentence from English to Alien language
void translate_to_alien(char *english_sentence) {
    char alien_sentence[ALIEN_WORD_SIZE * strlen(english_sentence)];
    char *english_word, *alien_word;
    
    // Split the sentence into individual words
    english_word = strtok(english_sentence, " ");
    
    // Translate each word and concatenate them into a sentence
    while (english_word != NULL) {
        alien_word = NULL;
        for (int i = 0; i < ALIEN_DICT_SIZE; i++) {
            if (strcmp(english_word, alien_dict[i][0]) == 0) {
                alien_word = alien_dict[i][1];
                break;
            }
        }
        if (alien_word != NULL)
            strcat(alien_sentence, alien_word);
        else
            strcat(alien_sentence, english_word);
        strcat(alien_sentence, " ");
        english_word = strtok(NULL, " ");
    }
    printf("Translation: %s\n", alien_sentence);
}

// Function to translate a sentence from Alien language to English
void translate_to_english(char *alien_sentence) {
    char english_sentence[ALIEN_WORD_SIZE * strlen(alien_sentence)];
    char *alien_word, *english_word;
    
    // Split the sentence into individual words
    alien_word = strtok(alien_sentence, " ");
    
    // Translate each word and concatenate them into a sentence
    while (alien_word != NULL) {
        english_word = NULL;
        for (int i = 0; i < ALIEN_DICT_SIZE; i++) {
            if (strcmp(alien_word, alien_dict[i][1]) == 0) {
                english_word = alien_dict[i][0];
                break;
            }
        }
        if (english_word != NULL)
            strcat(english_sentence, english_word);
        else
            strcat(english_sentence, alien_word);
        strcat(english_sentence, " ");
        alien_word = strtok(NULL, " ");
    }
    printf("Translation: %s\n", english_sentence);
}

int main() {
    int translation_choice;
    char sentence[ALIEN_WORD_SIZE * 10];
    
    printf("Enter a sentence: ");
    fgets(sentence, ALIEN_WORD_SIZE * 10, stdin);
    
    printf("Select translation direction:\n");
    printf("1. English to Alien\n");
    printf("2. Alien to English\n");
    printf("Choice: ");
    scanf("%d", &translation_choice);
    
    // Clear input buffer
    while (getchar() != '\n');
    
    if (translation_choice == 1)
        translate_to_alien(sentence);
    else if (translation_choice == 2)
        translate_to_english(sentence);
    else
        printf("Invalid choice.\n");
    
    return 0;
}