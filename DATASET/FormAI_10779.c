//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define ALIEN_LANGUAGE_SIZE 10

char* translate(char* input) {

    const char* alphabet[ALIEN_LANGUAGE_SIZE] = {
        "gag", "gaga", "googg", "ggoo", "goog", "gggaaa", "gaaag", "ggggg", "ggggo", "ggooog"
    };

    char* output = calloc(strlen(input) + 1, sizeof(char));
    char* token;
    char* rest = input;
    int i;

    while ((token = strtok_r(rest, " ", &rest))) {
        for (i = 0; i < ALIEN_LANGUAGE_SIZE; i++) {
            if (strcmp(alphabet[i], token) == 0) {
                strcat(output, " ");
                strcat(output, i + 'A');
                break;
            }
        }
    }

    return output;

}

int main() {

    char* input = "google gaga goog gagoo ggog gggaaa gaaag goo ggooog goog google";
    char* output = translate(input);

    printf("%s\n", output);

    return 0;

}