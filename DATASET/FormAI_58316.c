//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    const int LENGTH = 50;
    char text[LENGTH + 1];
    int correct = 0;
    int mistakes = 0;
    int total_time = 0;
    int time_taken = 0;
    int current_char_index = 0;
    int i;

    for (i = 0; i < LENGTH; i++) {
        text[i] = rand() % 26 + 'a';
    }
    text[LENGTH] = '\0';

    printf("Your typing speed test is about to start...\n\n");
    printf("Type the following text as fast and as accurately as possible:\n\n");
    printf("%s\n\n", text);

    time_t start_time = time(NULL);

    while (current_char_index < LENGTH) {
        char input_char = getchar();
        if (input_char == text[current_char_index]) {
            correct++;
        } else {
            mistakes++;
        }
        current_char_index++;
    }

    time_taken = (int) (time(NULL) - start_time);
    total_time += time_taken;

    printf("\n\nTest complete!\n");
    printf("You typed %d characters correctly and made %d mistakes.\n", correct, mistakes);
    printf("It took you %d seconds to complete this test.\n", time_taken);
    printf("Your typing speed was %.2f characters per minute.\n", (float) (correct * 60) / total_time);

    return 0;
}