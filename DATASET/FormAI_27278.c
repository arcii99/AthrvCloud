//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SENTENCE_LENGTH 50

char sentences[10][SENTENCE_LENGTH] = {
    "The quick brown fox jumps over the lazy dog",
    "Jackdaws love my big sphinx of quartz",
    "Pack my box with five dozen liquor jugs",
    "How vexingly quick daft zebras jump",
    "Quick zephyrs blow, vexing daft Jim",
    "Sphinx of black quartz, judge my vow",
    "The five boxing wizards jump quickly",
    "Public junk dwarves quiz mighty fox",
    "Crazy Frederick bought many very exquisite opal jewels",
    "We promptly judged antique ivory buckles for the next prize"
};

int main() {
    srand(time(NULL));

    int random_choice = rand() % 10;
    char sentence[SENTENCE_LENGTH];
    strcpy(sentence, sentences[random_choice]);

    printf("Type this sentence as fast as you can:\n%s\n", sentence);
    fflush(stdout);

    char user_input[SENTENCE_LENGTH];
    fgets(user_input, SENTENCE_LENGTH, stdin);

    int i = 0, correct = 0;
    while (user_input[i] != '\n' && sentence[i] != '\0') {
        if (user_input[i] == sentence[i])
            correct++;
        i++;
    }

    int length = strlen(sentence) - 1;
    double accuracy = (double) correct / length * 100;
    double speed = (double) length / 5 / ((double) (clock() / CLOCKS_PER_SEC / 60.0));

    printf("You typed with %.2f accuracy and %.2f wpm (%d/%d).\n", accuracy, speed, correct, length);

    return 0;
}