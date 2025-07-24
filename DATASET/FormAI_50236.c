//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

// Function to generate random capital letters
char generateRandomLetter() {
    return 'A' + rand() % 26;
}

// Function to generate random words of varying length
void generateWords(char words[MAX_WORDS][MAX_WORD_LENGTH]) {
    int i, j;
    for (i = 0; i < MAX_WORDS; i++) {
        int length = rand() % (MAX_WORD_LENGTH - 1) + 1;
        for (j = 0; j < length; j++) {
            words[i][j] = generateRandomLetter();
        }
        words[i][length] = '\0';
    }
}

// Function to get user input and calculate typing speed
void testTypingSpeed(char words[MAX_WORDS][MAX_WORD_LENGTH]) {
    printf("Type the following words as fast as you can:\n");
    int i;
    time_t startTime = time(NULL);
    for (i = 0; i < MAX_WORDS; i++) {
        printf("%s ", words[i]);
        char userWord[MAX_WORD_LENGTH];
        scanf("%s", userWord);
    }
    time_t endTime = time(NULL);
    double timeDifference = difftime(endTime, startTime);
    double wordsPerMinute = MAX_WORDS / (timeDifference / 60.0);
    printf("\n\nYour typing speed is: %.2f words per minute", wordsPerMinute);
}

int main() {
    srand(time(NULL));
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    generateWords(words);
    testTypingSpeed(words);
    return 0;
}