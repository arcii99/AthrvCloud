//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    char str[1024];
    int i, count = 0, correct = 0;
    clock_t start, end;
    double time_taken;

    printf("Welcome to the Typing Speed Test program!\n");
    printf("Please type the following text as fast and accurately as you can:\n\n");

    // Text to type
    char text[] = "The quick brown fox jumps over the lazy dog.";

    // Display the text to be typed
    printf("%s\n", text);

    // Get the current time
    start = clock();

    // Get user input
    fgets(str, 1024, stdin);

    // Calculate the time elapsed
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Count number of characters typed
    for(i = 0; str[i] != '\0'; i++) {
        if(isalpha(str[i]))
            count++;
    }

    // Compare the user input with the original text
    for(i = 0; i < count; i++) {
        if(str[i] == text[i])
            correct++;
    }

    // Display the results
    printf("\nYou typed: \n%s", str);
    printf("You typed %d characters in %.2f seconds.\n", count, time_taken);
    printf("Accuracy: %.2f%% \n", (double)correct/count * 100);

    return 0;
}