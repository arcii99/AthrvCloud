//FormAI DATASET v1.0 Category: Spell checking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define DICTIONARY_FILENAME "dictionary.txt"

/* Function prototypes */
int is_spell_correct(char* word_to_check);
int search_dictionary(char* word, char** dictionary, int dict_size);

int main()
{
    char** dictionary;          /* Pointer to array of strings - dictionary words */
    int dict_size = 0;          /* Size of dictionary array */
    char word_to_check[MAX_WORD_LENGTH];

    FILE* fp = fopen(DICTIONARY_FILENAME, "r");   /* Open dictionary file */

    if (fp == NULL) {
        printf("Could not open dictionary file.\n");
        return 0;
    }

    /* Determine number of words in dictionary */
    while (fgets(word_to_check, MAX_WORD_LENGTH, fp)) {
        dict_size++;
    }

    /* Allocate memory for dictionary */

    dictionary = (char**)malloc(sizeof(char*) * dict_size);

    /* Reset file pointer to beginning of file */
    fseek(fp, 0, SEEK_SET);

    /* Read dictionary into memory */
    int i = 0;
    while (fgets(word_to_check, MAX_WORD_LENGTH, fp)) {
        dictionary[i] = (char*)malloc(sizeof(char) * (strlen(word_to_check) + 1));
        strcpy(dictionary[i], word_to_check);
        i++;
    }

    /* Close dictionary file */
    fclose(fp);

    /* Prompt user to enter word to check */
    printf("Enter a word to check its spelling: ");
    scanf("%s", word_to_check);

    /* Check if word is spelled correctly */
    int is_correct = is_spell_correct(word_to_check);

    /* Output result */
    if (is_correct) {
        printf("The word \"%s\" is spelled correctly.\n", word_to_check);
    }
    else {
        printf("The word \"%s\" is spelled incorrectly.\n", word_to_check);
    }

    /* Free up memory allocated for dictionary */
    for (i = 0; i < dict_size; i++) {
        free(dictionary[i]);
    }
    free(dictionary);

    return 0;
}

/* Function to check if word is spelled correctly */
int is_spell_correct(char* word_to_check)
{
    /* Convert word to lowercase */
    int i = 0;
    while (word_to_check[i]) {
        word_to_check[i] = tolower(word_to_check[i]);
        i++;
    }

    /* Search for word in dictionary */
    char** dictionary;
    int dict_size = 0;
    FILE* fp = fopen(DICTIONARY_FILENAME, "r");

    if (fp == NULL) {
        printf("Could not open dictionary file.\n");
        exit(1);
    }

    /* Determine number of words in dictionary */
    char word[MAX_WORD_LENGTH];
    while (fgets(word, MAX_WORD_LENGTH, fp)) {
        dict_size++;
    }

    /* Allocate memory for dictionary */
    dictionary = (char**)malloc(sizeof(char*) * dict_size);

    /* Reset file pointer to beginning of file */
    fseek(fp, 0, SEEK_SET);

    /* Read dictionary into memory */
    i = 0;
    while (fgets(word, MAX_WORD_LENGTH, fp)) {
        dictionary[i] = (char*)malloc(sizeof(char) * (strlen(word) + 1));
        strcpy(dictionary[i], word);
        i++;
    }

    /* Close dictionary file */
    fclose(fp);

    /* Search dictionary for word */
    int is_found = search_dictionary(word_to_check, dictionary, dict_size);

    /* Free up memory allocated for dictionary */
    for (i = 0; i < dict_size; i++) {
        free(dictionary[i]);
    }
    free(dictionary);

    return is_found;
}

/* Function to search dictionary for a word */
int search_dictionary(char* word, char** dictionary, int dict_size)
{
    int i, cmp;

    for (i = 0; i < dict_size; i++) {
        cmp = strcmp(word, dictionary[i]);
        if (cmp == 0) {
            return 1;
        }
    }

    return 0;
}