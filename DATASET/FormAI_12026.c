//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    srand(time(0)); // seed the random number generator with the current time
    char correctText[] = "The quick brown fox jumps over the lazy dog";
    int correctLen = strlen(correctText);
    char inputText[100];
    int inputLen;
    int errors = 0;
    int totalTime = 0;
    printf("Welcome to the Typing Speed Test!\n\nYou will be given a sentence to type. Ready?\n\n");
    printf("%s\n", correctText);
    printf("\nType the sentence and hit enter:\n");
    time_t start = time(NULL);
    fgets(inputText, 100, stdin);
    time_t end = time(NULL);
    inputLen = strlen(inputText);
    if (inputText[inputLen-1] == '\n') {
        inputText[inputLen-1] = '\0'; // remove the newline character at the end of the input
        inputLen--;
    }
    for (int i = 0; i < inputLen; i++) {
        if (inputText[i] != correctText[i]) {
            errors++;
        }
    }
    if (errors > 0) {
        printf("\n%d errors. Better luck next time!\n", errors);
    } else {
        int timeTaken = (int)(end - start);
        int typingSpeed = (int)(((float)correctLen/(float)timeTaken) * 60.0);
        printf("\nCongratulations! You typed the sentence perfectly in %d seconds.", timeTaken);
        printf("\nYour typing speed is %d words per minute.\n", typingSpeed);
    }
    return 0;
}