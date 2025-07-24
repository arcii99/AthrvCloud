//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {

    printf("Welcome to the Typing Speed Test!\nPlease type the following sentence as quickly and accurately as possible:\n\n");

    // Randomized sentence selection
    char sentence[6][50] = {"The quick brown fox jumps over the lazy dog.",
                            "The five boxing wizards jump quickly.",
                            "Jackdaws love my big sphinx of quartz.",
                            "How vexingly quick daft zebras jump!",
                            "Sphinx of black quartz, judge my vow.",
                            "Pack my box with five dozen liquor jugs."};
    srand(time(NULL));
    int randomIndex = rand() % 6;
    char targetSentence[50];
    strcpy(targetSentence, sentence[randomIndex]);
    printf("%s\n", targetSentence);

    // User input
    char userInput[50];
    scanf("%[^\n]", userInput);

    // Calculation of result
    int sentenceLength = strlen(targetSentence);
    int mistakes = 0;
    int timeTaken;
    clock_t begin = clock();

    for (int i = 0; i < sentenceLength; i++) {
        if (userInput[i] != targetSentence[i]) {
            mistakes++;
        }
    }

    clock_t end = clock();
    timeTaken = (int)(end - begin) / CLOCKS_PER_SEC;

    // Output
    printf("\n=== Results ===\n");
    printf("Mistakes: %d\n", mistakes);
    printf("Time taken: %d seconds\n", timeTaken);
    int rawWPM = (sentenceLength / 5) / (timeTaken / 60.0);
    double adjustedWPM = rawWPM - 2 * mistakes;
    printf("Raw WPM: %d\n", rawWPM);
    printf("Adjusted WPM: %.2f\n", adjustedWPM);

    return 0;
}