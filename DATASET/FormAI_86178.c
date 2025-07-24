//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following paragraph as fast as you can:\n\n");

    const char *paragraph = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean sit amet est vel purus porttitor bibendum. Nullam varius gravida nisi vitae pretium. Sed sagittis leo eu rhoncus vestibulum. Sed id felis ullamcorper, dignissim velit nec, auctor sapien. Maecenas nec ipsum mi. Vestibulum ullamcorper tincidunt dui, vitae ultrices augue commodo ac. Nam euismod libero euismod aliquet lutut pharetra justo elementum. Curabitur at justo nec leo pharetra efficitur. Aenean auctor, ex non luctus aliquam, dui lectus fringilla elit, a posuere nulla ex vel tortor. Morbi consectetur ullamcorper libero eget ullamcorper.";

    const int paragraph_length = strlen(paragraph);
    const int time_limit_seconds = 60;

    clock_t start_time = clock();
    int characters_typed = 0;
    char current_character;

    while((clock() - start_time) / CLOCKS_PER_SEC < time_limit_seconds && characters_typed < paragraph_length) {
        current_character = getchar();
        if(current_character == paragraph[characters_typed]) {
            characters_typed++;
        }
    }

    if(characters_typed == paragraph_length) {
        printf("\nCongratulations, you typed the paragraph correctly in %d seconds!\n", time_limit_seconds);
    } else {
        printf("\nTime's up! You typed %d characters out of %d.\n", characters_typed, paragraph_length);
    }

    return 0;
}