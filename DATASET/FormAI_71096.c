//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char typed_text[100], original_text[] = "The quick brown fox jumps over the lazy dog";
    int mistakes = 0, i = 0, speed;
    time_t start_time, end_time, total_time = 0;

    printf("Type the following text as fast and accurately as possible:\n%s\n\n", original_text);

    while (original_text[i] != '\0') {
        start_time = time(NULL);
        scanf("%c", &typed_text[i]);
        end_time = time(NULL);

        if (typed_text[i] != original_text[i]) {
            mistakes++;
        }

        total_time += end_time - start_time;
        i++;
    }

    speed = (int) (((double) i / total_time) * 60);

    printf("\n\nYou typed: %s\n", typed_text);
    printf("Your typing speed is %d words per minute\n", speed);
    printf("You made %d mistakes\n", mistakes);

    return 0;
}