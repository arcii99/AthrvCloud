//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 15

void shuffle(char arr[MAX_WORDS][MAX_WORD_LENGTH], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp[MAX_WORD_LENGTH];
        strcpy(temp, arr[i]);
        strcpy(arr[i], arr[j]);
        strcpy(arr[j], temp);
    }
}

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH] = {"hello", "world", "typing", "speed", "is", "important", "for", "coders", "like", "you"};
    shuffle(words, MAX_WORDS);
    printf("Type the following words and press Enter (not case sensitive):\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
    clock_t start_time = clock();
    char input[MAX_WORDS][MAX_WORD_LENGTH];
    for (int i = 0; i < MAX_WORDS; i++) {
        scanf("%s", input[i]);
        for (int j = 0; j < strlen(input[i]); j++) {
            input[i][j] = tolower(input[i][j]);
        }
    }
    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    int wpm = (int)(MAX_WORDS / (time_taken / 60));
    printf("Your typing speed is %d WPM (words per minute).\n", wpm);
    return 0;
}