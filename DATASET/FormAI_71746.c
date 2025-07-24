//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char sentence[] = "The quick brown fox jumps over the lazy dog";
    char input[100];
    int i = 0;
    int j = 0;
    int time_taken = 0;

    printf("Welcome to the Surrealist Typing Speed Test!\n");
    printf("You will be given a strange sentence to type out.\n");
    printf("When you are ready, press ENTER to begin.\n");
    scanf("%c", &input[0]);

    time_t t1 = time(NULL);

    while (sentence[i] != '\0') {
        printf("%c", sentence[i]);
        scanf("%c", &input[j]);

        if (input[j] == sentence[i]) {
            j++;
        }
        i++;
    }

    time_t t2 = time(NULL);
    time_taken = difftime(t2, t1);

    if (strcmp(input, sentence) == 0) {
        printf("\nCongratulations! You have completed the typewriter's dream.\n");
        printf("It took you %d seconds to type out the sentence perfectly.\n", time_taken);
    }
    else {
        printf("\nYou have failed the test. The typewriter is disappointed in you.\n");
        printf("The correct sentence is: '%s'\n", sentence);
    }

    return 0;
}