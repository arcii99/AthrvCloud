//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define CORRECT_ANSWER 1

// Function to generate random words
void generate_words(char *words[], int num_words) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";    
    srand(time(NULL));    
    for (int i = 0; i < num_words; i++) {
        for (int j = 0; j < 5; j++) {
            words[i][j] = alphabet[rand() % 26];
        }
        words[i][5] = '\0';
    }
}

// Function to display the words to be typed
void display_words(char *words[], int num_words) {
    printf("Type the following words:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

// Function to calculate typing speed
double calculate_typing_speed(struct timespec start, struct timespec end, int num_words) {
    double time_diff = (end.tv_sec - start.tv_sec) + 
                        (end.tv_nsec - start.tv_nsec) / 1000000000.0;
    double wpm = (num_words / time_diff) * 60.0 / 5.0;
    return wpm;
}

// Function to get user input and compare with the correct answer
bool check_answer(char *answer, char *correct) {
    return (strcmp(answer, correct) == 0) ? true : false;
}

int main() {
    int num_words = 25;
    char *words[num_words];
    for (int i = 0; i < num_words; i++) {
        words[i] = malloc(6 * sizeof(char));
    }
    generate_words(words, num_words);    
    display_words(words, num_words);    
    char input[6];
    int num_correct = 0;

    // Start timer
    struct timespec start_time, end_time;    
    clock_gettime(CLOCK_REALTIME, &start_time);

    // User input loop
    for (int i = 0; i < num_words; i++) {
        scanf("%s", input);
        if (check_answer(input, words[i])) {
            num_correct++;
        }
    }

    // End timer
    clock_gettime(CLOCK_REALTIME, &end_time);

    double typing_speed = calculate_typing_speed(start_time, end_time, num_words);    
    printf("\nYou typed %d words correctly in %.2f seconds.\n", num_correct, (double)(end_time.tv_sec - start_time.tv_sec));
    printf("Your typing speed is %.2f words per minute.\n", typing_speed);

    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    
    return 0;
}