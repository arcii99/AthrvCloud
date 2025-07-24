//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sentenceCount = 5;
    int wordCount = 10;
    char sentences[5][50] = {
        "The quick brown fox jumps over the lazy dog",
        "Jackdaws love my big sphinx of quartz",
        "How vexingly quick daft zebras jump",
        "Bright vixens jump; dozy fowl quack",
        "Pack my box with five dozen liquor jugs"
    };

    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following sentences as fast as you can:\n\n");

    int totalWords = sentenceCount * wordCount;
    int correctWords = 0;
    int milliseconds = 0;
    time_t startTime, endTime;

    srand(time(0));
    for(int i = 0; i < sentenceCount; i++) {
        printf("Sentence %d: %s\n", i+1, sentences[i]);

        for(int j = 0; j < wordCount; j++) {
            char input[50];
            printf("[%d/%d] ", i*wordCount+j+1, totalWords);
            scanf("%s", input);

            if(strcmp(sentences[i]+(j*5), input) == 0) {
                printf("Correct!\n");
                correctWords++;
            } else {
                printf("Incorrect.\n");
            }
        }
    }
    endTime = time(0);

    milliseconds = (int)(endTime - startTime) * 1000;

    printf("\nYou typed %d words correctly in %d milliseconds.\n", correctWords, milliseconds);
    printf("Your average typing speed is %0.2f words per minute.\n", ((float)correctWords / (float)totalWords) * 60000.0);

    return 0;
}