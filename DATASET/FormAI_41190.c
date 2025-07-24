//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

void generateRandomString(char *str, int len) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

    srand(time(NULL));

    for(int i = 0; i < len; i++) {
        int index = rand() % (int) (sizeof(charset) - 1);
        str[i] = charset[index];
    }

    str[len] = '\0';
}

int main() {
    int inputIndex = 0, correctCount = 0, incorrectCount = 0, elapsedTime;
    char randomStr[MAX_INPUT_SIZE];
    clock_t start, end;
    
    generateRandomString(randomStr, MAX_INPUT_SIZE);

    printf("Type this string as fast as you can:\n%s\n", randomStr);

    start = clock();

    char inputStr[MAX_INPUT_SIZE];
    fgets(inputStr, MAX_INPUT_SIZE, stdin);

    end = clock();

    elapsedTime = (int) (end - start) / CLOCKS_PER_SEC;

    while(inputIndex < MAX_INPUT_SIZE && inputStr[inputIndex] != '\n' && randomStr[inputIndex] != '\0') {
        if(inputStr[inputIndex] == randomStr[inputIndex]) {
            correctCount++;
        } else {
            incorrectCount++;
        }

        inputIndex++;
    }

    printf("\n");
    printf("You typed %d correct characters and %d incorrect characters.\n", correctCount, incorrectCount);
    printf("It took you %d seconds to complete the typing test.\n", elapsedTime);

    return 0;
}