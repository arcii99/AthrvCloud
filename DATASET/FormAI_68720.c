//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 100
#define TOTAL_WORDS 10

char *words[] = {"apple", "banana", "cherry", "grape", "kiwi", "lemon", "mango", "orange", "peach", "pineapple"};

int main()
{
    char input[MAX_STRING_LENGTH];
    int correctCount = 0;
    srand(time(NULL));
    
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will have to type in %d randomly selected words as fast as you can.\n", TOTAL_WORDS);
    printf("Press ENTER to start the test.");
    getchar();  // Wait for user input
    
    for (int i=0; i<TOTAL_WORDS; i++) {
        int index = rand() % TOTAL_WORDS;
        printf("Word %d: %s\n", i+1, words[index]);
        scanf("%s", input);
        if (strcmp(input, words[index]) == 0) {
            printf("Correct!\n");
            correctCount++;
        } else {
            printf("Incorrect.\n");
        }
    }
    
    printf("Test finished!\n");
    printf("You typed in %d out of %d words correctly.\n", correctCount, TOTAL_WORDS);
    printf("Your typing speed is %.2f words per minute.\n", (float)TOTAL_WORDS / ((clock() / CLOCKS_PER_SEC) / 60.0));

    return 0;
}