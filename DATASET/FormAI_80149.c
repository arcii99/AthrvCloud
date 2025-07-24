//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int count = 0;
    char userInput;
    time_t startTime, endTime;
    double elapsedTime;

    printf("Welcome to the Typing Speed Test!\n\n");
    printf("Press enter to start the test.\n");
    getchar();
    printf("Type the following sentence:\n\n");
    printf("The quick brown fox jumps over the lazy dog.\n\n");
    fflush(stdout);

    startTime = time(NULL);
    
    while (count < 3) {
        scanf("%c", &userInput);
        if (userInput == 'T' || userInput == 't' || userInput == 'h' || userInput == 'e' || userInput == ' ' || userInput == 'q' || userInput == 'u' || userInput == 'i' || userInput == 'c' || userInput == 'k' || userInput == 'b' || userInput == 'r' || userInput == 'o' || userInput == 'w' || userInput == 'n' || userInput == 'f' || userInput == 'x' || userInput == 'j' || userInput == 'm' || userInput == 'p' || userInput == 's' || userInput == 'v' || userInput == 'e' || userInput == 'l' || userInput == 'a' || userInput == 'z' || userInput == 'y' || userInput == 'd' || userInput == '.' || userInput == '\n') {
            if (userInput == '\n') {
                count++;
            }
            continue;
        }
        else {
            printf("\nWrong input. Try again.\n");
            fflush(stdout);
        }
    }

    endTime = time(NULL);
    elapsedTime = (double)(endTime - startTime);

    printf("\nTest complete!\n");
    printf("Time elapsed: %.2f seconds\n", elapsedTime);
    printf("Your typing speed is: %.2f characters per second.\n", 43 / elapsedTime);
    printf("Thank you for using the Typing Speed Test!\n");

    return 0;
}