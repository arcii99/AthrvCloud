//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: single-threaded
#include<stdio.h>
#include<string.h>
#include<ctype.h>

// Define the maximum length of a word
#define MAX_WORD_LEN 50

// Define the maximum number of translations
#define MAX_TRANSLATIONS 10

// Define the maximum number of words in a sentence
#define MAX_SENTENCE_LENGTH 100

// Define the number of translated sentences to output
#define NUM_TRANSLATED_SENTENCES 3

// Function prototypes
int getWord(char* sentence, char* word, int start_pos);
void translateWord(char* input_word, char* output_word, int max_translations);

int main(){

    char sentence[MAX_SENTENCE_LENGTH];    // User input sentence
    char translated_sentence[MAX_SENTENCE_LENGTH];    // Output translated sentence
    char input_word[MAX_WORD_LEN];      // Current input word to translate
    char output_word[MAX_WORD_LEN];     // Translated word
    int num_words_translated = 0;          // Counter for number of words translated
    int sentence_end = 0;           // Position of last character in sentence
    int word_start = 0;             // Position of first character in current word
    int word_end = 0;               // Position of last character in current word
    int i, j;                       // Index variables
    int num_translations = 0;       // Number of translations for current word

    // Prompt user for sentence to translate
    printf("Enter a sentence to translate:\n");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Remove trailing newline character from sentence
    sentence[strcspn(sentence, "\n")] = 0;

    // Convert sentence to lowercase
    for(i = 0; i < strlen(sentence); i++){
        sentence[i] = tolower(sentence[i]);
    }

    // Determine position of last character in sentence
    sentence_end = strlen(sentence) - 1;

    // Translate each word in sentence
    for(i = 0; i < strlen(sentence);){

        // Get next word from sentence
        word_start = i;
        i = getWord(sentence, input_word, i);
        word_end = i - 1;

        // Translate current word
        translateWord(input_word, output_word, MAX_TRANSLATIONS);

        // Append translated word to output sentence
        for(j = 0; j < strlen(output_word); j++){
            translated_sentence[num_words_translated + j] = output_word[j];
        }
        num_words_translated += strlen(output_word);

        // If not at end of sentence, append space character
        if(i <= sentence_end){
            translated_sentence[num_words_translated] = ' ';
            num_words_translated++;
        }

        // Keep track of number of translations for current word
        num_translations++;

        // If there are more translations available and sentence is not complete, prompt user for choice
        if(num_translations < MAX_TRANSLATIONS && i <= sentence_end){

            printf("'%s' has multiple translations. Choose your preferred translation (1-%d): ", input_word, num_translations);
            int choice;
            scanf("%d", &choice);

            if(choice <= num_translations && choice > 0){
                // User chose a valid translation
                translateWord(input_word, output_word, choice);
            }
            else{
                // Invalid choice, just use first translation
                translateWord(input_word, output_word, 1);
            }

            // Append translated word to output sentence
            for(j = 0; j < strlen(output_word); j++){
                translated_sentence[num_words_translated + j] = output_word[j];
            }
            num_words_translated += strlen(output_word);

            // If not at end of sentence, append space character
            if(i <= sentence_end){
                translated_sentence[num_words_translated] = ' ';
                num_words_translated++;
            }

        }

    }

    // Print out translated sentence
    printf("\nTranslated sentence:\n%s\n", translated_sentence);

    return 0;
}

/*
* Function: getWord
* ------------------
* Given a sentence, extracts the next word starting from start_pos.
* The word is returned in the word parameter and the function
* returns the position of the first character of the word immediately
* following the extracted word.
*/
int getWord(char* sentence, char* word, int start_pos){

    int i, j;
    int sentence_length = strlen(sentence);
    int word_length = 0;

    // Skip over leading whitespace
    for(i = start_pos; i < sentence_length && isspace(sentence[i]); i++);

    // Extract the word
    for(j = i; j < sentence_length && !isspace(sentence[j]) && word_length < MAX_WORD_LEN - 1; j++){
        word[word_length] = sentence[j];
        word_length++;
    }
    word[word_length] = '\0';

    return j;
}

/*
* Function: translateWord
* -----------------------
* Given a word, attempts to translate it into C Cat Language.
* The translated word is returned in the output_word parameter.
* If there are multiple possible translations, one is chosen at random.
*/
void translateWord(char* input_word, char* output_word, int max_translations){

    // Define arrays of possible translations
    char *adjectives[] = {"fluffy", "cuddly", "fuzzy", "adorable", "cute", "soft", "snuggly", "whiskery", "playful", "wild", "curious"};
    char *nouns[] = {"paws", "tail", "fur", "whiskers", "toy", "kibble", "blanket", "mouse", "scratch post", "claw", "treat"};
    char *verbs[] = {"purrs", "meows", "hisses", "claws", "pounces", "naps", "play with", "chases", "licks", "sniffs", "paws at"};

    // Count number of translations available for each part of speech
    int num_adjectives = sizeof(adjectives) / sizeof(char*);
    int num_nouns = sizeof(nouns) / sizeof(char*);
    int num_verbs = sizeof(verbs) / sizeof(char*);

    // Generate random indices for each part of speech
    int adj_index = rand() % num_adjectives;
    int noun_index = rand() % num_nouns;
    int verb_index = rand() % num_verbs;

    // Copy the input word to the output word buffer
    strcpy(output_word, input_word);

    // Replace the first letter of the output word with uppercase
    output_word[0] = toupper(output_word[0]);

    // Replace the last letter of the output word with the randomly selected adjective
    if(num_adjectives > 0){
        int adj_choice = rand() % num_adjectives;
        strncat(output_word, adjectives[adj_choice], MAX_WORD_LEN - strlen(input_word) - 1);
    }

    // Append the randomly selected noun to the output word
    if(num_nouns > 0){
        int noun_choice = rand() % num_nouns;
        strncat(output_word, " ", 1);
        strncat(output_word, nouns[noun_choice], MAX_WORD_LEN - strlen(output_word) - 1);
    }

    // Append the randomly selected verb to the output word
    if(num_verbs > 0){
        int verb_choice = rand() % num_verbs;
        strncat(output_word, " that ", 6);
        strncat(output_word, verbs[verb_choice], MAX_WORD_LEN - strlen(output_word) - 1);
    }

    // If there are multiple translations available, append the number of translations in parentheses
    if(max_translations > 1){
        char num_translations_string[4];
        snprintf(num_translations_string, 4, "(%d)", max_translations);
        strncat(output_word, num_translations_string, 4);
    }
}