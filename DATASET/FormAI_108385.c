//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char words[][10] = {"apple", "orange", "banana", "grape", "lemon", "kiwi", "peach", 
                        "apricot", "cherry", "plum", "papaya", "pear", "mango", "berry", 
                        "melon", "avocado", "pineapple", "strawberry", "coconut", "fig"};
    int num_words = sizeof(words) / sizeof(words[0]);
    srand(time(NULL));
    clock_t start_time, end_time;
    double total_time;
    int correct = 0;

    printf("Welcome to the C Typing Speed Test!\n");
    printf("This program will display a sequence of random words for you to type.\n");
    printf("Once you complete the sequence, your typing speed will be calculated.\n\n");
    printf("Press ENTER to begin...");
    getchar();

    for (int i = 0; i < 5; i++) {
        int index = rand() % num_words;
        printf("Word %d: %s\n", i+1, words[index]);
        char input[10];
        scanf("%s", input);
        if (strcmp(input, words[index]) == 0) {
            correct++;
        }
    }

    end_time = clock();
    total_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    double typing_speed = (double) (correct * 60) / total_time;

    printf("You typed %d words correctly out of 5.\n", correct);
    printf("Your typing speed is %.2f words per minute.\n", typing_speed);

    return 0;
}