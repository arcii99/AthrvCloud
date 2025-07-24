//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main()
{
    char typed_string[100], test_string[100];
    int time_taken, input_len, correct_chars = 0;
    clock_t start_time;
    double elapsed_time;

    printf("Welcome to Typing Speed Test program!\nPlease enter the following text:\n");

    strcpy(test_string, "The quick brown fox jumps over the lazy dog");

    printf("%s\n", test_string);

    printf("Type the above text:\n");

    start_time = clock(); // start the timer

    fgets(typed_string, sizeof(typed_string), stdin); // read the user input

    elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;

    input_len = strlen(typed_string);

    for (int i = 0; i < input_len; i++)
    {
        if (typed_string[i] == test_string[i])
        {
            correct_chars++;
        }
    }

    time_taken = (int)(elapsed_time * 1000);

    printf("Time taken: %d ms\n", time_taken);
    printf("Characters typed correctly: %d\n", correct_chars);
    printf("Typing speed: %d characters per minute\n", (int)(correct_chars / (elapsed_time / 60)));

    return 0;
}