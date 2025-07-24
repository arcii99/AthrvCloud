//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Function to generate a random word from a given list of words
char* generate_random_word(char* words[], int num_words) {
    srand(time(NULL));
    int random_index = rand() % num_words;
    char* word = words[random_index];
    return word;
}

// Function to measure the typing speed of the user
int measure_typing_speed(char* word) {
    clock_t start = clock();
    char typed_word[100];
    fgets(typed_word, 100, stdin);
    typed_word[strcspn(typed_word, "\n")] = 0;
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    int errors = 0;
    for(int i = 0; i < strlen(word); i++) {
        if(word[i] != typed_word[i])
            errors++;
    }
    int speed = (int)(strlen(word) / time_taken) * 60;
    printf("\nYou typed: %s\n", typed_word);
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Typing speed: %d WPM\n", speed);
    printf("Errors: %d\n", errors);
    return speed;
}

int main() {
    printf("Welcome to the Typing Speed Test inspired by Sherlock Holmes!\n");
    printf("Type 'start' to begin the test or 'quit' to exit: ");
    char start[10];
    fgets(start, 10, stdin);
    start[strcspn(start, "\n")] = 0;
    if(strcmp(start, "quit") == 0) {
        printf("\nGoodbye!\n");
        return 0;
    } else if(strcmp(start, "start") == 0) {
        printf("\nGet ready to type! Your first word is:\n\n");
        // List of words for the user to type
        char* words[] = {"elementary", "my", "dear", "watson", "the", "game", "is", "afoot", "baker", "street", "221b", "holmes", "moriarty", "detective", "inspector", "lestrade", "hound", "of", "baskervilles", "rache", "treasure", "amber", "reichenbach", "fall", "scandal", "in", "bohemia", "red", "headed", "league", "identity", "final", "problem", "valley", "fear", "adventure", "abbey", "grange", "sign", "four", "study", "scarlet", "league", "violet", "pony", "carbuncle"};
        int num_words = sizeof(words) / sizeof(words[0]);
        char* current_word = generate_random_word(words, num_words);

        // Typing speed test loop
        while(1) {
            printf("%s\n", current_word);
            int speed = measure_typing_speed(current_word);
            if(speed < 20) {
                printf("\nYour typing speed is too slow. Keep practicing!\n");
            } else if(speed < 40) {
                printf("\nYour typing speed is average. You can do better!\n");
            } else if(speed < 60) {
                printf("\nYour typing speed is good. Keep practicing!\n");
            } else {
                printf("\nCongratulations! You have a great typing speed!\n");
            }
            printf("\nType 'next' for the next word or 'quit' to exit: ");
            char next[10];
            fgets(next, 10, stdin);
            next[strcspn(next, "\n")] = 0;
            if(strcmp(next, "quit") == 0) {
                printf("\nGoodbye!\n");
                return 0;
            }
            current_word = generate_random_word(words, num_words);
        }
    } else {
        printf("\nInvalid input. Please try again.\n");
        main();
    }
    return 0;
}