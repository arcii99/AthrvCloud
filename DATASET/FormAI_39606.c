//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000

int main()
{
    printf("Welcome to the Typing Speed Test!\n\n");
    printf("You will be given a random phrase to type and your typing speed will be calculated.\n\n");
    printf("Press any key to start the test...\n\n");
    getchar();

    char phrases[][MAX_STRING_LENGTH] = {
        "The quick brown fox jumps over the lazy dog.",
        "The five boxing wizards jump quickly.",
        "Sphinx of black quartz, judge my vow.",
        "Pack my box with five dozen liquor jugs.",
        "Jackdaws love my big sphinx of quartz.",
        "How vexingly quick daft zebras jump!",
        "My ex pub quiz crowd gave joyful thanks.",
        "Two driven jocks help fax my big quiz.",
        "The jay, pig, fox, zebra and my wolves quack!",
        "Waltz, bad nymph, for quick jigs vex.",
    };
    int num_phrases = sizeof(phrases) / sizeof(phrases[0]);

    srand(time(0));
    int index = rand() % num_phrases;
    char phrase[MAX_STRING_LENGTH];
    strcpy(phrase, phrases[index]);

    printf("Type the following phrase:\n\n");
    printf("%s\n\n", phrase);

    clock_t start_time = clock();

    char input[MAX_STRING_LENGTH];
    fgets(input, MAX_STRING_LENGTH, stdin);

    clock_t end_time = clock();

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    int num_characters = strlen(input) - 1;
    int num_correct = 0;

    for (int i = 0; i < num_characters; i++)
    {
        if (input[i] == phrase[i])
        {
            num_correct++;
        }
    }

    int typing_speed = (int)(((double)num_correct / (double)num_characters) / time_taken) * 60;

    printf("\n");
    printf("Your typing speed is %d WPM!\n", typing_speed);

    return 0;
}