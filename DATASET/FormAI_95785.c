//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char *words[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grapefruit", "honeydew", "kiwi", "lemon", "mango", "nectarine", "orange", "pear", "quince", "raspberry", "strawberry", "tangerine", "watermelon"};
    int num_words = 19;
    int word_length;
    char typed_word[50];
    int correct_count = 0;
    int incorrect_count = 0;
    int i;
    srand(time(0));

    printf("Welcome to the Typing Speed Test!\n\n");
    printf("You will be given a series of words to type.\n");
    printf("Type each word as quickly and accurately as possible.\n\n");
    printf("Press enter to begin!\n");
    getchar();

    for (i = 0; i < 10; i++) {
        int rand_index = rand() % num_words;
        printf("Word %d: ", i+1);
        printf("%s\n", words[rand_index]);
        word_length = strlen(words[rand_index]);
        fgets(typed_word, 50, stdin);
        typed_word[strcspn(typed_word, "\n")] = 0; // remove newline character
        if (strcmp(typed_word, words[rand_index]) == 0) {
            correct_count++;
        } else {
            incorrect_count++;
        }
        printf("\n");
    }

    printf("Finished!\n");
    printf("You got %d words correct and %d words incorrect.\n", correct_count, incorrect_count);
    return 0;
}