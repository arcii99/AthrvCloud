//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    printf("Welcome to the Typing Speed Test program\n");
    printf("---------------------------------------\n");

    char testWords[10][15] = {"receive", "zoo", "gorilla", "flower", "rabbit", "excuse", "yellow", "unhappy", "island", "bottle"};
    int i, j, userWordCount = 0, charCount = 0, correctCharCount = 0;
    double speed;
    clock_t startTime, endTime;

    srand(time(NULL));
    for(i = 1; i <= 3; i++) {
        printf("\nType the following words:\n\n");

        // Displaying the words
        for(j = 0; j < 10; j++) {
            printf("%s ", testWords[rand() % 10]);
        }

        printf("\n\n");

        // Taking input from user
        startTime = clock();
        for(j = 0; j < 10; j++) {
            char inputWord[15];
            scanf("%s", inputWord);
            userWordCount++;

            // Verifying each character
            for(int k = 0; inputWord[k] != '\0'; k++) {
                if(inputWord[k] == testWords[j][k]) {
                    correctCharCount++;
                }
                charCount++;
            }
        }
        endTime = clock();

        // Calculating the speed and accuracy
        speed = (double)(charCount * 60) / (double)(endTime - startTime);
        printf("You typed %d characters in %.2f seconds.\n", charCount, (double)(endTime - startTime)/CLOCKS_PER_SEC);
        printf("Your typing speed is %.2f characters per minute.\n", speed);
        printf("Your accuracy is %.2f percent.\n", (double)correctCharCount/(double)charCount * 100.0);

        // Resetting the variables
        charCount = 0;
        correctCharCount = 0;
    }

    printf("\nThanks for using Typing Speed Test program!\n");
    return 0;
}