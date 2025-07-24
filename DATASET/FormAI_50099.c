//FormAI DATASET v1.0 Category: Error handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int randomNumber = rand() % 10;
    char possibleErrorMessage[5][20] = {"Bus Error", "Segmentation Fault", "Illegal Instruction", "Stack Overflow", "Floating Point Exception"};
    int errorIndex = rand() % 5;
    char* errorMessage = possibleErrorMessage[errorIndex];

    if(randomNumber < 5) {
        printf("The program is running smoothly with no errors.\n");
    }
    else if(randomNumber < 8) {
        printf("The program encountered a minor error.\n");
        printf("Error message: %s\n", errorMessage);
    }
    else {
        printf("The program encountered a critical error and cannot continue running.\n");
        printf("Error message: %s\n", errorMessage);
        printf("Exiting program...\n");
        exit(1);
    }
    return 0;
}