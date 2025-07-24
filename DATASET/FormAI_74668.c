//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    int i, count = 0, correct = 0;
    char sentence[100] = "The quick brown fox jumps over the lazy dog";
    char input[100];
    time_t start, end;
    double seconds;

    printf("Type the following sentence as fast as you can:\n%s\n", sentence);

    // Get user input
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input
    for(i = 0; input[i] != '\0'; i++) {
        if(input[i] == '\n') {
            input[i] = '\0';
        }
    }

    // Calculate typing speed
    time(&start);

    for(i = 0; i < sizeof(sentence)-1; i++) {
        if(input[i] == sentence[i]) {
            correct++;
        }
        count++;
    }

    time(&end);
    seconds = difftime(end, start);

    printf("You typed: %s\n", input);
    printf("Time taken: %.2lf seconds\n", seconds);
    printf("Words per minute: %.2lf\n", count/5.0/(seconds/60.0));
    printf("Accuracy: %.2lf%%\n", (correct*100.0)/count);

    return 0;
}