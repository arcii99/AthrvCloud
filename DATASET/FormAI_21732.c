//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Donald Knuth
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 15

char words[MAX_WORDS][MAX_WORD_LENGTH] = {
    "programming",
    "algorithm",
    "variable",
    "function",
    "pointer",
    "syntax",
    "compiler",
    "debugger",
    "recursion",
    "iteration"
};

void shuffle(char array[][MAX_WORD_LENGTH], int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp[MAX_WORD_LENGTH];
        strcpy(temp, array[i]);
        strcpy(array[i], array[j]);
        strcpy(array[j], temp);
    }
}

double measure_typing_speed() {
    char input[MAX_WORD_LENGTH];
    int errors = 0, correct = 0;
    clock_t start = clock();
    for (int i = 0; i < MAX_WORDS; i++) {
        printf("%s ", words[i]);
        scanf("%s", input);
        if (strcmp(input, words[i]) == 0) {
            correct++;
        } else {
            errors++;
        }
    }
    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    double typing_speed = correct / elapsed_time * 60;
    printf("\n\nTotal Time: %.2f seconds\n", elapsed_time);
    printf("Correct Words Typed: %d\n", correct);
    printf("Incorrect Words Typed: %d\n", errors);
    printf("Typing Speed: %.2f wpm\n", typing_speed);
    return typing_speed;
}

int main() {
    printf("----------------------------------------\n");
    printf(" Welcome to the Typing Speed Test\n");
    printf("----------------------------------------\n\n");
    
    shuffle(words, MAX_WORDS);
    
    printf("Instructions:\n");
    printf("Type each word that appears on the screen and press ENTER.\n");
    printf("You have to type %d words.\n", MAX_WORDS);
    printf("Press ENTER to start the test\n");
    getchar();
    
    double typing_speed = measure_typing_speed();
    
    printf("\n\nThank you for taking the Typing Speed Test\n");
    if (typing_speed < 30) {
        printf("You need to improve your typing speed.\n");
    } else if (typing_speed < 60) {
        printf("Your typing speed is good.\n");
    } else {
        printf("Your typing speed is excellent!\n");
    }
    
    return 0;
}