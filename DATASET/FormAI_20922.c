//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    char* words[] = {"apple", "banana", "cherry", "orange", "grape", "kiwi", "mango", "pear", "pineapple", "strawberry"};
    int word_count = sizeof(words) / sizeof(char*);
    int count = 0, correct = 0, incorrect = 0;
    double time_taken = 0;
    char input[20];
    printf("Welcome to the Typing Speed Test!\n");
    printf("Enter as many words as you can in 30 seconds.\n\n");
    printf("Press ENTER to begin.\n");
    getchar();
    clock_t start = clock();
    while ((double)(clock() - start) / CLOCKS_PER_SEC < 30.0) {
        int random_word_index = rand() % word_count;
        printf("%s\t", words[random_word_index]);
        scanf("%s", input);
        if (strcmp(words[random_word_index], input) == 0) {
            printf("Correct!\n");
            correct++;
        } else {
            printf("Incorrect! The correct word is %s.\n", words[random_word_index]);
            incorrect++;
        }
        count++;
    }
    clock_t end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken: %.2lf seconds\n", time_taken);
    printf("Total words entered: %d\n", count);
    printf("Correct words: %d\n", correct);
    printf("Incorrect words: %d\n", incorrect);
    printf("Typing speed: %.2lf words per minute\n", (double)count / time_taken * 60.0);
    return 0;
}