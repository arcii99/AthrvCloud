//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: introspective
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char user_input[100];
    int words_count = 0, typing_speed = 0, correctly_typed = 0;
    char random_words[10][20] = {"apple", "banana", "cherry", "grape", "kiwi", "lemon", "mango", "orange", "pear", "pineapple"};

    printf("Welcome to the Typing Speed Test Program!\n");
    printf("You will be given a set of random words to type. Once you finish typing, the program will display your typing speed and accuracy.\n");
    printf("Ready? Press Enter to start.\n");
    getchar();

    srand(time(0));
    int index = rand() % 10;
    printf("Type the word: %s\n", random_words[index]);

    time_t start_time = time(NULL);

    while (fgets(user_input, 100, stdin)) {
        user_input[strcspn(user_input, "\n")] = 0;
        if (strcmp(user_input, random_words[index]) == 0) {
            printf("Correct! Next word.\n");
            correctly_typed++;
            words_count++;

            if (words_count == 10) {
                break;
            }

            index = rand() % 10;
            printf("Type the word: %s\n", random_words[index]);
        } else {
            printf("Incorrect. Try again.\n");
        }
    }

    time_t end_time = time(NULL);

    double total_time = difftime(end_time, start_time);
    int total_chars = strlen(random_words[index]) * 10;
    typing_speed = (total_chars / total_time) * 60;

    printf("Your typing speed is: %d words per minute\n", typing_speed);
    printf("Your accuracy rate is: %.2f%%\n", (correctly_typed * 100.0) / words_count);

    return 0;
}