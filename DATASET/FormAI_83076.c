//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int milli_seconds)
{
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int main()
{
    int word_count = 0, correct_words = 0;
    char word[50], typed_word[50];

    srand(time(NULL));

    printf("Type the following words:\n");

    while (word_count < 10) {
        char *words[] = {"linux", "kernel", "programming", "command", "system", "software", "computer", "terminal", "language", "ubuntu"};
        int word_idx = rand() % 10;
        printf("%s\n", words[word_idx]);
        scanf("%s", word);

        if (strcmp(word, words[word_idx]) == 0) {
            correct_words++;
            printf("Correct!\n");
        } else {
            printf("Wrong! The correct word is %s.\n", words[word_idx]);
        }

        word_count++;
        delay(1000);
    }

    printf("Typing speed: %d words per minute.\n", correct_words);

    return 0;
}