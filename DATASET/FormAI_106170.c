//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: multiplayer
#include <stdio.h>
#include <time.h>

#define NUM_PLAYERS 2
#define NUM_WORDS 10
#define MAX_WORD_LENGTH 10

void generate_words(char words[NUM_WORDS][MAX_WORD_LENGTH]) {
    const char* pool = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < NUM_WORDS; ++i) {
        for (int j = 0; j < MAX_WORD_LENGTH-1; ++j) {
            words[i][j] = pool[rand() % 26];
        }
        words[i][MAX_WORD_LENGTH-1] = '\0';
    }
}

void print_words(char words[NUM_WORDS][MAX_WORD_LENGTH]) {
    for (int i = 0; i < NUM_WORDS; ++i) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

double play_typing_game(char words[NUM_WORDS][MAX_WORD_LENGTH]) {
    time_t start, end;
    printf("Type the following words as fast as you can:\n");
    print_words(words);
    printf("Ready?\n");
    getchar();  // wait for user to press enter
    time(&start);
    for (int i = 0; i < NUM_WORDS; ++i) {
        char buffer[MAX_WORD_LENGTH];
        printf("%d. ", i+1);
        scanf("%s", buffer);
        if (strcmp(buffer, words[i]) != 0) {
            printf("Incorrect! You typed: %s\n", buffer);
            return -1;
        }
    }
    time(&end);
    double duration = difftime(end, start);
    printf("Congratulations! You completed the typing game in %g seconds.\n", duration);
    return duration;
}

int main() {
    char words[NUM_WORDS][MAX_WORD_LENGTH];
    generate_words(words);
    double times[NUM_PLAYERS];
    for (int i = 0; i < NUM_PLAYERS; ++i) {
        printf("Player %d:\n", i+1);
        times[i] = play_typing_game(words);
    }
    printf("Results:\n");
    if (times[0] < times[1]) {
        printf("Player 1 wins with a time of %g seconds!\n", times[0]);
    } else if (times[0] > times[1]) {
        printf("Player 2 wins with a time of %g seconds!\n", times[1]);
    } else {
        printf("It's a tie!\n");
    }
    return 0;
}