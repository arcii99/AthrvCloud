//FormAI DATASET v1.0 Category: Word Count Tool ; Style: visionary
/* Welcome to the C Word Count Tool */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define INIT_SIZE 10
#define INCREMENT 10

// define a structure to hold word and word count pairs
typedef struct {
    char* word;
    int count;
} WordCountPair;

int main() {
    // allocate heap memory for WordCountPair array
    WordCountPair* arr = (WordCountPair*)malloc(sizeof(WordCountPair) * INIT_SIZE);
    if (arr == NULL) {
        printf("Could not allocate memory for WordCountPair array.\n");
        exit(1);
    }

    // initialize count to 0 for all elements in array
    for (int i = 0; i < INIT_SIZE; i++) {
        arr[i].count = 0;
    }

    // initialize array size and word count to 0
    int arr_size = INIT_SIZE;
    int word_count = 0;

    printf("Enter some text to count words:\n");

    char c = getchar();
    while (c != EOF) {
        char* current_word = (char*)malloc(sizeof(char) * INIT_SIZE);
        int current_word_length = 0;

        while (!isspace(c) && c != EOF) {
            if (current_word_length == arr_size) {
                // reallocate memory for WordCountPair array
                arr_size += INCREMENT;
                arr = (WordCountPair*)realloc(arr, sizeof(WordCountPair) * arr_size);
                if (arr == NULL) {
                    printf("Could not reallocate memory for WordCountPair array.\n");
                    exit(1);
                }
            }
            current_word[current_word_length++] = c;
            c = getchar();
        }

        // check if current word exists in array
        int i = 0;
        while (i < word_count && strcmp(current_word, arr[i].word) != 0) {
            i++;
        }

        // add current word to array if it does not exist
        if (i == word_count) {
            if (word_count == arr_size) {
                // reallocate memory for WordCountPair array
                arr_size += INCREMENT;
                arr = (WordCountPair*)realloc(arr, sizeof(WordCountPair) * arr_size);
                if (arr == NULL) {
                    printf("Could not reallocate memory for WordCountPair array.\n");
                    exit(1);
                }
            }
            arr[word_count].word = current_word;
            arr[word_count++].count = 1;
        }
        // increment count for current word if it exists
        else {
            free(current_word);
            arr[i].count++;
        }
        c = getchar();
    }

    // print the word count for each word
    printf("Word Count\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", arr[i].word, arr[i].count);
    }

    // free heap memory allocated for WordCountPair array
    for (int i = 0; i < word_count; i++) {
        free(arr[i].word);
    }
    free(arr);

    return 0;
}