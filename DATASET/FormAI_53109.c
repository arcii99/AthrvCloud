//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    char text[] = "It is a capital mistake to theorize before one has data. Insensibly one begins to twist facts to suit theories, instead of theories to suit facts.";
    char input[100];
    int i, len, errors = 0;
    float time_taken;
    clock_t start, end;

    printf("Welcome to the Typing Speed Test!\n\n");
    printf("Type the following quote as fast and accurately as possible:\n\n");
    printf("\"%s\"\n\n", text);

    start = clock();

    printf("Type here:\n");
    fgets(input, 100, stdin);

    end = clock();
    time_taken = ((float) (end - start)) / CLOCKS_PER_SEC;

    len = strlen(text);

    for (i = 0; i < len; i++) {
        if (text[i] != input[i]) {
            errors++;
        }
    }

    printf("\n\n");
    printf("Results:\n");
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Typing speed: %.2f WPM\n", (len / 5.0) / (time_taken / 60.0));
    printf("Number of errors: %d\n", errors);

    printf("\n\n");
    printf("Congratulations, you have completed the Typing Speed Test!\n\n");

    return 0;
}