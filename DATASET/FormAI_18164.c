//FormAI DATASET v1.0 Category: Error handling ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char userInput[10];
    int num;

    printf("Please enter a number between 1 and 10: ");
    fgets(userInput, 10, stdin);
    num = atoi(userInput);

    if(num < 1 || num > 10) {
        printf("Error: Invalid input. Please enter a number between 1 and 10\n");
        exit(1);
    }

    printf("Congrats! You entered %d\n", num);

    return 0;
}