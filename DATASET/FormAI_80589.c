//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 50
#define MAX_WORD_LENGTH 15
#define MAX_TIME 60

char words[MAX_WORDS][MAX_WORD_LENGTH] = {
    "computer", "science", "programming", "language", "algorithm",
    "data", "structure", "array", "pointer", "function",
    "loop", "conditional", "operator", "variable", "constant",
    "class", "object", "inheritance", "polymorphism", "encapsulation",
    "interface", "abstraction", "template", "namespace", "memory",
    "heap", "stack", "integer", "float", "double",
    "char", "string", "boolean", "unsigned", "signed",
    "struct", "union", "file", "input", "output",
    "stream", "type", "casting", "bitwise", "shift",
    "operator", "macro", "preprocessor", "library", "header"
};

int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generate_words() {
    for (int i = 0; i < MAX_WORDS; i++) {
        int len = get_random_number(3, MAX_WORD_LENGTH);
        for (int j = 0; j < len; j++) {
            int c = get_random_number('a', 'z');
            words[i][j] = (char) c;
        }
        words[i][len] = '\0';
    }
}

int main() {
    srand(time(NULL));
    generate_words();
    printf("Welcome to the Typing Speed Test!\n");
    printf("You have %d seconds to type as many words as you can.\n\n", MAX_TIME);
    printf("Press ENTER to start...\n");
    getchar();

    int i = 0;
    int score = 0;
    time_t start_time = time(NULL);
    while ((time(NULL) - start_time) < MAX_TIME) {
        int word_index = get_random_number(0, MAX_WORDS - 1);
        printf("%s ", words[word_index]);
        char input[MAX_WORD_LENGTH];
        scanf("%s", input);
        if (strcmp(input, words[word_index]) == 0) {
            score++;
        }
        i++;
    }

    printf("\n\nTime's up!\n");
    printf("You typed %d words in %d seconds.\n", score, MAX_TIME);
    printf("Your typing speed is %.2f WPM (Words Per Minute).\n", (float) score * 60 / MAX_TIME);

    return 0;
}