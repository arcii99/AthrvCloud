//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[] = "The quick brown fox jumps over the lazy dog";
    int len = strlen(text);

    printf("Welcome to the Typing Speed Test!\n\n");
    printf("Type the following text as fast as you can:\n\n%s\n\n", text);

    char userInput[len];
    time_t start, end;
    double totalTime;

    printf("Press enter when you are ready to start.\n");

    while (getchar() != '\n') {}

    start = time(NULL);

    fgets(userInput, len, stdin);

    end = time(NULL);

    totalTime = difftime(end, start);
    int accuracy = 0;

    for (int i = 0; i < len; i++) {
        if (tolower(text[i]) == tolower(userInput[i])) accuracy++;
    }

    printf("Your typing speed is: %.2f seconds per character.\n", totalTime / len);
    printf("You typed %d out of %d characters correctly.\n", accuracy, len);

    return 0;
}