//FormAI DATASET v1.0 Category: Spell checking ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/*
    This program is a unique C spell checking example program that checks the spelling
    of a word entered by the user. If the word is spelled correctly, it prints a message
    stating that the word is spelled correctly. If the word is spelled incorrectly, it prints
    a message providing suggestions for correctly spelled words based on the Levenshtein distance
    algorithm.

    The program uses a dictionary stored in a file named "dictionary.txt", which contains a list
    of correctly spelled words. The dictionary is loaded into memory upon program startup and is
    stored in a hash table for efficient searching.

    The program also includes functions for calculating the Levenshtein distance between two words
    and for generating a list of suggestions for correcting a misspelled word.
*/

#define HASH_SIZE 10000
#define MAX_WORD_LENGTH 50
#define MAX_SUGGESTIONS 10

typedef struct node {
    char* word;
    struct node* next;
} node_t;

node_t* hashtable[HASH_SIZE];
int dictionary_size = 0;

int hash_word(const char* word) {
    int hash = 0;
    for(int i = 0; i < strlen(word); i++) {
        hash = (31 * hash + tolower(word[i])) % HASH_SIZE;
    }
    return hash;
}

void add_word_to_hashtable(const char* word) {
    int hash = hash_word(word);
    node_t* head = hashtable[hash];

    while(head != NULL) {
        if(strcmp(head->word, word) == 0) {
            // word already exists in hashtable
            return;
        }
        head = head->next;
    }

    node_t* new_node = malloc(sizeof(node_t));
    new_node->word = malloc(strlen(word) + 1);
    strcpy(new_node->word, word);
    new_node->next = hashtable[hash];
    hashtable[hash] = new_node;
    dictionary_size++;
}

void load_dictionary_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    char word_buffer[MAX_WORD_LENGTH];

    while(fscanf(file, "%s", word_buffer) == 1) {
        add_word_to_hashtable(word_buffer);
    }

    fclose(file);
}

int levenshtein_distance(const char* a, const char* b) {
    int distance[strlen(a) + 1][strlen(b) + 1];

    for(int i = 0; i <= strlen(a); i++) {
        distance[i][0] = i;
    }

    for(int j = 0; j <= strlen(b); j++) {
        distance[0][j] = j;
    }

    for(int j = 1; j <= strlen(b); j++) {
        for(int i = 1; i <= strlen(a); i++) {
            if(a[i - 1] == b[j - 1]) {
                distance[i][j] = distance[i - 1][j - 1];
            }
            else {
                int delete_distance = distance[i - 1][j] + 1;
                int insert_distance = distance[i][j - 1] + 1;
                int substitute_distance = distance[i - 1][j - 1] + 1;
                distance[i][j] = delete_distance < insert_distance ?
                    (delete_distance < substitute_distance ? delete_distance : substitute_distance) :
                    (insert_distance < substitute_distance ? insert_distance : substitute_distance);
            }
        }
    }

    return distance[strlen(a)][strlen(b)];
}

node_t** find_suggestions(const char* word, int* num_suggestions_out) {
    node_t* suggestions[MAX_SUGGESTIONS];
    int distances[MAX_SUGGESTIONS];
    int num_suggestions = 0;
    int max_distance = strlen(word) / 2 + 1;

    for(int i = 0; i < HASH_SIZE && num_suggestions < MAX_SUGGESTIONS; i++) {
        node_t* head = hashtable[i];
        while(head != NULL) {
            int distance = levenshtein_distance(word, head->word);
            if(distance <= max_distance) {
                suggestions[num_suggestions] = head;
                distances[num_suggestions] = distance;
                num_suggestions++;
            }
            head = head->next;
        }
    }

    // sort suggestions by distance
    for(int i = 1; i < num_suggestions; i++) {
        for(int j = i; j > 0 && distances[j - 1] > distances[j]; j--) {
            node_t* temp_node = suggestions[j];
            int temp_distance = distances[j];
            suggestions[j] = suggestions[j - 1];
            distances[j] = distances[j - 1];
            suggestions[j - 1] = temp_node;
            distances[j - 1] = temp_distance;
        }
    }

    // trim suggestions to max size
    if(num_suggestions > MAX_SUGGESTIONS) {
        num_suggestions = MAX_SUGGESTIONS;
    }

    node_t** suggestions_out = malloc(sizeof(node_t*) * num_suggestions);
    for(int i = 0; i < num_suggestions; i++) {
        suggestions_out[i] = suggestions[i];
    }

    *num_suggestions_out = num_suggestions;
    return suggestions_out;
}

int main() {
    load_dictionary_file("dictionary.txt");

    char word_buffer[MAX_WORD_LENGTH];
    printf("Enter a word to spell check: ");
    scanf("%s", word_buffer);

    int hash = hash_word(word_buffer);
    node_t* head = hashtable[hash];

    while(head != NULL) {
        if(strcmp(head->word, word_buffer) == 0) {
            printf("'%s' is spelled correctly.\n", word_buffer);
            return 0;
        }
        head = head->next;
    }

    int num_suggestions;
    node_t** suggestions = find_suggestions(word_buffer, &num_suggestions);

    printf("'%s' is spelled incorrectly. Suggestions:\n", word_buffer);
    for(int i = 0; i < num_suggestions; i++) {
        printf("  %s\n", suggestions[i]->word);
    }

    return 0;
}