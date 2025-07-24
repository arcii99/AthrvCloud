//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Romeo and Juliet
#include <stdio.h>
#include <time.h>
#include <ctype.h>

int main() {
    printf("=============================\n");
    printf("Welcome to the Typing Test!\n");
    printf("=============================\n");

    char pangram[] = "The quick brown fox jumps over the lazy dog";
    int len = sizeof(pangram) / sizeof(*pangram);
    int i = 0;
    int errors = 0;
    int total_time = 0;

    printf("Type the following sentence:\n%s\n", pangram);
    printf("Press ENTER when you're done.\n");

    while(1) {
        clock_t start = clock();

        // Get input character
        char input = getchar();

        if (input == '\n') {
            clock_t end = clock();
            total_time = (int) ((double) (end - start) * 1000 / CLOCKS_PER_SEC);
            break;
        }

        // Increment error count if needed, move to next character
        if (toupper(input) != toupper(pangram[i])) {
            errors++;
        }
        i++;
    }
    
    printf("Your time: %dms\n", total_time);
    printf("Errors: %d\n", errors);
    printf("=============================\n");
    printf("Thank you for taking the Typing Test!\n");
    printf("=============================\n");

    return 0;
}