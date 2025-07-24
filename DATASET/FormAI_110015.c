//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void generateRandomString(char *str, int maxLength) {
    int i, length = rand() % maxLength;
    for (i = 0; i < length; i++) {
        str[i] = (char)(rand() % 57 + 65);
        if (str[i] >= 91 && str[i] <= 96) {
            str[i] += 7;
        }
    }
    str[i] = '\0';
}

int main() {
    char input[100], randomString[100];
    int counter = -1, correctCounter = 0, incorrectCounter = 0, i;
    double accuracyPercentage, elapsedTime;
    srand(time(NULL));
    printf("\n\nWelcome to the Statistical Typing Speed Test!\n\n");
    printf("You will be given a random string of characters and you will be required to type them as quickly and accurately as possible.\n\nWhen you are ready, hit ENTER to begin the test!\n");
    getchar();
    while (counter < 9) {
        system("CLS");
        generateRandomString(randomString, 45);
        printf("String %d/10\n\n%s\n\n", counter + 2, randomString);
        double startTime = (double)clock() / CLOCKS_PER_SEC;
        fgets(input, 100, stdin);
        double endTime = (double)clock() / CLOCKS_PER_SEC;
        elapsedTime = endTime - startTime;
        for (i = 0; i < strlen(randomString); i++) {
            if (input[i] == randomString[i]) {
                correctCounter++;
            }
            else {
                incorrectCounter++;
            }
        }
        counter++;
    }
    system("CLS");
    accuracyPercentage = ((double)correctCounter / (double)(correctCounter + incorrectCounter)) * 100;
    printf("\n\nCongratulations on completing the test!\n\n");
    printf("Statistics:\n\nTime elapsed: %.2f seconds\n\nNumber of correct keystrokes: %d\n\nNumber of incorrect keystrokes: %d\n\nAccuracy percentage: %.2f%%\n\n", elapsedTime, correctCounter, incorrectCounter, accuracyPercentage);
    return 0;
}