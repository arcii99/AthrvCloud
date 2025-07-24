//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Typing Speed Test!\n\n");
    printf("Type the following sentence as fast as you can:\n\n");
    printf("The quick brown fox jumps over the lazy dog.\n\n");

    char user_input[100];
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    fgets(user_input, 100, stdin);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nYou typed: %s\n", user_input);
    printf("Time taken to type: %f seconds\n", cpu_time_used);

    int i = 0;
    int errors = 0;
    while (user_input[i] != '\0')
    {
        if (user_input[i] != "The quick brown fox jumps over the lazy dog.\n"[i])
        {
            errors++;
        }
        i++;
    }

    double wpm = ((i / 5.0) - errors) / cpu_time_used * 60.0;

    printf("Your typing speed is %f WPM!\n", wpm);

    return 0;
}