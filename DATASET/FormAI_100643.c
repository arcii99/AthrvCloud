//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 50
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 10
#define MAX_ATTEMPTS 3
#define TIME_LIMIT 60

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH+1] = {"apple", "banana", "cherry", "dragon", "elephant", "forest", "guitar", "harbor", "island", "jungle", "koala", "leopard", "mountain", "nebula", "octopus", "penguin", "quartz", "rainbow", "sapphire", "tulip", "umbrella", "violin", "waterfall", "xylophone", "yellow", "zebra"};
    char input[MAX_WORD_LENGTH+1];
    int score = 0, attempts = 0;

    srand(time(NULL));

    printf("Welcome to the Typing Speed Test!\n");
    printf("Type as many words as you can in %d seconds.\n", TIME_LIMIT);

    time_t start_time = time(NULL);
    while((time(NULL) - start_time) < TIME_LIMIT) {
        int random_index = rand() % MAX_WORDS;
        printf("Word: %s\n", words[random_index]);
        scanf("%s", input);
        if(strcmp(input, words[random_index]) == 0) {
            score += strlen(words[random_index]);
            printf("Correct! Your score is %d.\n", score);
            continue;
        }
        else {
            attempts++;
            printf("Incorrect! You have %d attempts remaining.\n", MAX_ATTEMPTS - attempts);
            if(attempts == MAX_ATTEMPTS) {
                printf("Game Over! Your final score is %d.\n", score);
                return 0;
            }
        }

    }
    printf("Time Up! Your final score is %d.\n", score);
    return 0;
}