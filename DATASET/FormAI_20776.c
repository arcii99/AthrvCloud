//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: realistic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 10
#define MAX_LEN 20

int main() {
    printf("Welcome to the Typing Speed Test!\n\n");
    printf("Type the following words as fast as you can:\n\n");

    char words[MAX_WORDS][MAX_LEN] = {"programming", "keyboard", "computer", "algorithm", "syntax", 
                                    "operator", "variable", "compile", "debug", "function"};

    // Shuffle the words array
    srand(time(NULL));
    for (int i = 0; i < MAX_WORDS; i++) {
        int j = rand() % MAX_WORDS;
        char temp[MAX_LEN];
        strcpy(temp, words[i]);
        strcpy(words[i], words[j]);
        strcpy(words[j], temp);
    }

    int correct = 0;
    int total_time = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        printf("%s ", words[i]);
        time_t start = time(NULL); // Start timing
        char input[MAX_LEN];
        scanf("%s", input);
        time_t end = time(NULL); // End timing
        total_time += (int)(end - start);

        // Convert input to lowercase for comparison
        for (int j = 0; j < strlen(input); j++) {
            input[j] = tolower(input[j]);
        }

        if (strcmp(input, words[i]) == 0) {
            printf("Correct!\n");
            correct++;
        } else {
            printf("Incorrect.\n");
        }
    }

    printf("\nYou typed %d out of %d words correctly.\n", correct, MAX_WORDS);
    printf("Your average typing speed was %.1f words per minute.\n", (float)correct/(float)total_time*60);

    return 0;
}