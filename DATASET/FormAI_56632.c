//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: ultraprecise
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

char *get_random_word(const char *words[], int count);
void start_typing_test(const char *words[], int count);

int main()
{
    const char *words[MAX_WORDS] = {"programming", "algorithm", "variable", "function", "pointer", "structure", "computation", "loop", "condition", "recursion", "debugging", "syntax", "compiler", "interpreter", "object", "array", "string", "character", "integer", "float", "double", "boolean", "void", "class", "interface", "inheritance", "polymorphism", "encapsulation", "abstraction", "stack", "queue", "linkedlist", "tree", "graph", "hash", "set", "map", "vector", "deque", "iterator", "algorithm", "sort", "search", "divide", "conquer", "dynamic", "programming", "greedy", "backtracking", "heuristic", "genetic", "neural", "network", "machine", "learning"};
    int count = sizeof(words) / sizeof(words[0]);
    start_typing_test(words, count);
    return 0;
}

char *get_random_word(const char *words[], const int count)
{
    srand(time(NULL));
    int index = rand() % count;
    return (char *) words[index];
}

void start_typing_test(const char *words[], const int count)
{
    char input[MAX_WORD_LENGTH];
    char *word;
    int word_count = 0, success_count = 0, failure_count = 0, i, len;
    time_t elapsed_time;
    time_t start_time = time(NULL);
    printf("Welcome to the Typing Speed Test\n\n");
    printf("Type the following words as fast as possible:\n\n");

    while (word_count < 10) {
        word = get_random_word(words, count);
        printf("%s ", word);
        fflush(stdout);
        fgets(input, MAX_WORD_LENGTH, stdin);
        len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[--len] = '\0';
        }
        for (i = 0; i < len; i++) {
            input[i] = tolower(input[i]);
        }
        if (strcmp(word, input) == 0) {
            printf("Correct!\n");
            success_count++;
        } else {
            printf("Incorrect, the word was %s\n", word);
            failure_count++;
        }
        word_count++;
    }

    elapsed_time = time(NULL) - start_time;
    printf("\n\nTyping Speed Test Result Summary\n\n");
    printf("Total words typed: %d\n", word_count);
    printf("Correct: %d, Incorrect: %d\n", success_count, failure_count);
    printf("Total time taken: %ld seconds\n", elapsed_time);
    printf("Typing speed: %.2f words per minute\n", ((double) word_count / elapsed_time) * 60);
}