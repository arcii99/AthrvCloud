//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20
#define MAX_TIME 60 // in seconds

typedef struct Word {
    char value[MAX_WORD_LENGTH];
} Word;

Word wordList[MAX_WORDS] = {
    {"the"}, {"quick"}, {"brown"}, {"fox"},
    {"jumps"}, {"over"}, {"the"}, {"lazy"},
    {"dog"}, {"apple"}, {"banana"}, {"cherry"},
    {"desk"}, {"chair"}, {"lamp"}, {"book"},
    {"paper"}, {"pencil"}, {"computer"}, {"keyboard"},
    {"mouse"}, {"monitor"}, {"printer"}, {"scanner"},
    {"car"}, {"train"}, {"bus"}, {"bicycle"},
    {"shoe"}, {"sock"}, {"shirt"}, {"pants"},
    {"hat"}, {"glove"}, {"scarf"}, {"jacket"},
    {"phone"}, {"camera"}, {"watch"}, {"pen"},
    {"pencil"}, {"marker"}, {"crayon"}, {"paint"},
    {"brush"}, {"canvas"}, {"easel"}, {"palette"},
    {"knife"}, {"fork"}, {"spoon"}, {"plate"},
};

int main() {
    printf("Welcome to the Typing Speed Test Game!\n");
    printf("You will have %d seconds to type as many words as you can from the following list:\n\n", MAX_TIME);
    for(int i=0; i<MAX_WORDS; i++) {
        printf("%s ", wordList[i].value);
    }
    printf("\n\nPress ENTER to start the game...\n");
    getchar();

    srand(time(NULL)); // initialize random seed
    char userWord[MAX_WORD_LENGTH];
    int numCorrect = 0, numIncorrect = 0;
    time_t startTime = time(NULL); // get current time
    time_t currentTime = startTime;

    while((currentTime - startTime) < MAX_TIME) {
        int randomIndex = rand()%MAX_WORDS;
        printf("%s > ", wordList[randomIndex].value);
        scanf("%s", userWord);

        if(strcmp(userWord, wordList[randomIndex].value) == 0) {
            printf("Correct!\n");
            numCorrect++;
        } else {
            printf("Incorrect!\n");
            numIncorrect++;
        }

        currentTime = time(NULL);
    }

    printf("\n\nTime's up!\n\n");
    printf("You typed %d words correctly and %d words incorrectly.\n", numCorrect, numIncorrect);
    printf("Your accuracy rate is %.2f%%.\n", ((float)numCorrect/MAX_WORDS)*100);
    printf("Your typing speed is %d words per minute.\n", ((int)((float)numCorrect/MAX_TIME)*60));
    printf("\n\nThanks for playing the Typing Speed Test Game!\n");

    return 0;
}