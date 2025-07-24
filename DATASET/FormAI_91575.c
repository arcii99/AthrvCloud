//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the C Typing Speed Test!\n\n");
    printf("You will be given 10 words to type. To start the test, press Enter.\n");
    getchar();

    const char* words[10] = {"computer", "programming", "language", "algorithm", "syntax", "pointer", "function", "variable", "library", "keyboard"};

    int i, correct = 0;
    double time_spent;

    clock_t begin = clock();
    for (i = 0; i < 10; i++) {
        printf("Type the word: %s\n", words[i]);
        char input[20];
        scanf("%s", input);
        if(strcmp(input, words[i]) == 0) {
            printf("Correct!\n");
            correct++;
        }
        else {
            printf("Incorrect.\n");
        }
    }
    clock_t end = clock();

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\n\nTest complete! You got %d out of 10 correct.\n", correct);
    printf("You took %.2f seconds to complete the test.\n", time_spent);
    printf("Your typing speed is %.2f words per minute.\n", (double)(correct * 60 / time_spent));

    return 0;
}