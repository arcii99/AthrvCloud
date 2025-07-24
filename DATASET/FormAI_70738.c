//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {

    char sentence[100] = "The quick brown fox jumped over the lazy dog";
    char input[100];
    int speed, time_taken; 

    printf("Welcome to the Typing Speed Test\n");
    printf("You will be given a sentence to type and we will calculate your typing speed\n");
    printf("Please type the following sentence\n%s\n", sentence);

    clock_t tStart = clock(); // start timer

    fgets(input, sizeof(input), stdin);

    time_taken = (double)(clock() - tStart) / CLOCKS_PER_SEC * 1000; // calculate time taken in milliseconds

    int len_sentence = strlen(sentence); // count length of sentence

    float typed_speed = (len_sentence * 60000) / (float)time_taken; // calculate typing speed in words per minute

    printf("You typed \"%s\"\n", input);

    if (strcmp(sentence, input) == 0) {
        printf("Congratulations! You typed the sentence correctly!\n");
        printf("Your typing speed is %.2f words per minute\n", typed_speed);
    } else {
        printf("Oops! You made a mistake. Please try again!\n");
    }

    return 0;
}