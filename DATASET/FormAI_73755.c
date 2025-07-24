//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Cat Language Vocabulary
const char* cat_vocab[] = {"meow", "purr", "hiss", "scratch", "nap", "play", "eat", "drink", "hunt", "loaf"};

// Define the corresponding English translations
const char* english_translations[] = {"hello", "happy", "angry", "annoyed", "sleep", "fun", "food", "water", "kill", "relax"};

// Define the maximum number of words in an input sentence
#define MAX_WORDS 100

// Function to tokenize the input sentence
int tokenize_sentence(char sentence[], char* tokens[])
{
    char* word;
    word = strtok(sentence, " ");
    int num_words = 0;
    while (word != NULL)
    {
        tokens[num_words] = word;
        num_words++;
        word = strtok(NULL, " ");
    }
    return num_words;
}

// Function to translate a single word
char* translate_word(char* word)
{
    for (int i = 0; i < sizeof(cat_vocab)/sizeof(cat_vocab[0]); i++)
    {
        if (strcmp(word, cat_vocab[i]) == 0)
        {
            return english_translations[i];
        }
    }
    return word;
}

// Function to translate a sentence
void translate_sentence(char sentence[], char translated_sentence[])
{
    char* tokens[MAX_WORDS];
    int num_words = tokenize_sentence(sentence, tokens);
    for (int i = 0; i < num_words; i++)
    {
        strcat(translated_sentence, translate_word(tokens[i]));
        strcat(translated_sentence, " ");
    }
}

// Main function for the translator program
int main()
{
    char sentence[1000];
    printf("Enter a sentence in Cat Language:\n");
    fgets(sentence, 1000, stdin);
    strtok(sentence, "\n");  // Remove the new line character from input
    char translated_sentence[1000] = "";
    translate_sentence(sentence, translated_sentence);
    printf("The sentence translated to English is:\n%s\n", translated_sentence);
    return 0;
}