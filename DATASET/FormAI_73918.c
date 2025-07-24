//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int typing_speed = 0, correct_words = 0, total_words = 0;
    char input[100], c;
    printf("Welcome to the Typing Speed Test Program!\nPress Enter to start.\n");

    while(1) {
        c = getchar(); // Waits for enter key
        if(c == '\n') {
            break;
        }
    }

    printf("\n3\n2\n1\nSTART!\n");

    // Randomly generated words
    char *words[] = {"apple", "banana", "cherry", "diamond", "elephant", "falcon", "giraffe", "helicopter", "ice cream", "juice", "king", "leopard", "mountain", "notebook", "orangutan", "penguin", "queen", "rabbit", "strawberry", "telephone", "umbrella", "violin", "window", "xylophone", "yellow", "zoo"};

    printf("\nType the following words:\n");

    srand(time(0)); // Initializing random seed

    for(int i = 0; i < 10; i++) { // Total of 10 words to type
        printf("%s\n", words[rand() % 26]);
        total_words++;
        scanf("%s", input);
        if(strcmp(input, words[i]) == 0) { // If typed word is correct
            correct_words++;
        }
    }

    typing_speed = (correct_words * 60) / 5; // 5 seconds for each word

    printf("\nYou typed %d out of %d words correctly.\n", correct_words, total_words);
    printf("Your typing speed is: %d words per minute\n", typing_speed);

    return 0;
}