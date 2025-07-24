//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PARANOID_STR "This typing speed test will not steal your personal information."

int main() {
    srand(time(NULL));

    char input[100];
    int i, j, len;
    printf("%s\nType the above sentence as fast as you can:\n", PARANOID_STR);
    clock_t start = clock();
    fgets(input, 100, stdin);
    clock_t end = clock();

    len = strlen(input);
    input[len-1] = '\0';
    len--; // remove newline character
    int errors = 0;

    for (i = 0, j = 0; input[i] != '\0' && PARANOID_STR[j] != '\0'; i++, j++) {
        if (input[i] != PARANOID_STR[j]) {
            errors++;
            if (errors > 3) {
                printf("Too many errors, test terminated.\n");
                return 0;
            }
            printf("Typing error! Try again:\n");
            clock_t start = clock();
            fgets(input, 100, stdin);
            clock_t end = clock();
            i = -1; // reset counter to start again

            len = strlen(input);
            input[len-1] = '\0';
            len--; // remove newline character
            j = -1; // reset comparison counter
        }
    }

    printf("Congratulations! You typed the sentence correctly.\n");
    int time_elapsed = (end - start) / CLOCKS_PER_SEC;
    printf("Time elapsed: %d seconds.\n", time_elapsed);
    printf("Typing speed: %.2f characters per second.\n", (float)len/time_elapsed);

    return 0;
}