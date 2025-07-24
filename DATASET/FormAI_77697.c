//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SENTENCE_LENGTH 60
#define MAX_TIME 60 // maximum time for typing test in seconds

// function to generate random sentence 
void generateSentence(char sentence[]) {
    char words[][10] = {"the", "quick", "brown", "fox", "jumps", "over", "lazy", "dog", "with", "a", "jump", "and", "a", "skip", "in", "the", "park"};

    for(int i=0; i<SENTENCE_LENGTH; i++) {
        int randomIndex = rand() % 17;
        for(int j=0; words[randomIndex][j]!='\0'; j++) {
            sentence[i+j] = words[randomIndex][j];
        }
        sentence[i+strlen(words[randomIndex])] = ' ';
        i += strlen(words[randomIndex]);
    }
    sentence[SENTENCE_LENGTH] = '\0';
}

int main() {
    srand(time(NULL));
    char sentence[SENTENCE_LENGTH+1];
    int mistakes = 0, count = 0;
    time_t startTime, endTime;

    generateSentence(sentence);
    printf("Type the following sentence within %d seconds:\n%s\n\n", MAX_TIME, sentence);

    // start timer
    startTime = time(NULL);

    // take input from user
    char input[SENTENCE_LENGTH+1];
    fgets(input, sizeof(input), stdin);

    // end timer
    endTime = time(NULL);

    // calculate time taken
    int timeTaken = (int)difftime(endTime, startTime);

    // remove trailing newline from input
    input[strcspn(input, "\n")] = 0;

    // check for typing mistakes
    for(int i=0; i<strlen(sentence); i++) {
        if(sentence[i] != input[i]) {
            mistakes++;
        }
        count++;
    }

    // display typing results
    printf("\nTime taken: %d seconds\n", timeTaken);
    printf("Number of characters typed: %d\n", count);
    printf("Number of mistakes made: %d\n", mistakes);
    printf("Typing speed: %d characters per minute\n", (int)(count/((double)timeTaken/60)));

    return 0;
}