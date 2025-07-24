//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int i = 0, total_words = 0, correct_words = 0, incorrect_words = 0;
    time_t start_time, end_time;
    double elapsed_time;

    // Populate the words array from a text file
    FILE *word_file = fopen("words.txt", "r");
    if (!word_file) {
        printf("Error: failed to open words file\n");
        return -1;
    }
    char word[MAX_WORD_LENGTH];
    while ((fgets(word, MAX_WORD_LENGTH, word_file) != NULL) && (i < MAX_WORDS)) {
        int len = strlen(word);
        if (len > 0 && word[len-1] == '\n') {
            word[--len] = '\0';
        }
        strcpy(words[i], word);
        i++;
    }
    total_words = i;
    fclose(word_file);

    printf("Type the following words:\n");

    // Shuffle the words array to make typing test more challenging
    srand(time(NULL));
    for (int i = 0; i < total_words; i++) {
        int j = rand() % total_words;
        char temp[MAX_WORD_LENGTH];
        strcpy(temp, words[i]);
        strcpy(words[i], words[j]);
        strcpy(words[j], temp);
    }

    // Display each word and calculate typing speed
    start_time = time(NULL);
    for (int i = 0; i < total_words; i++) {
        printf("%s ", words[i]);
        char input[MAX_WORD_LENGTH];
        scanf("%s", input);
        if (strcmp(input, words[i]) == 0) {
            correct_words++;
        } else {
            incorrect_words++;
        }
    }
    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    // Print typing test results
    printf("\n\nTyping Test Results:\n");
    printf("Total words: %d\n", total_words);
    printf("Correct words: %d\n", correct_words);
    printf("Incorrect words: %d\n", incorrect_words);
    printf("Elapsed time: %.2lf seconds\n", elapsed_time);
    double typing_speed = ((double)correct_words / elapsed_time) * 60;
    printf("Typing speed: %.2lf wpm\n", typing_speed);

    return 0;
}