//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main()
{
    printf("Welcome to the Typing Speed Test!\n\n");

    printf("You will be given a random sentence to type. Once you have typed the entire sentence, your typing speed will be calculated and displayed.\n\n");

    printf("Please press enter to begin the test.\n");
    getchar();

    // Array of random sentences
    char sentences[10][100] = {"The quick brown fox jumps over the lazy dog",
                               "Sphinx of black quartz, judge my vow",
                               "How vexingly quick daft zebras jump",
                               "Jaded zombies acted quaintly but kept driving their oxen forward",
                               "Pack my box with five dozen liquor jugs",
                               "The five boxing wizards jump quickly",
                               "The quick onyx goblin jumps over the lazy dwarf",
                               "Waltz, bad nymph, for quick jigs vex",
                               "Quick zephyrs blow, vexing daft Jim",
                               "The quick brown fox jumps over a lazy dog"};

    // Set random seed
    srand(time(NULL));

    // Select random sentence
    int random_index = rand() % 10;
    char random_sentence[100];
    strcpy(random_sentence, sentences[random_index]);

    printf("\n%s\n", random_sentence);

    // Start timer
    clock_t start = clock();

    // Take user input
    char user_input[100];
    fgets(user_input, 100, stdin);

    // Remove newline character from user_input
    user_input[strcspn(user_input, "\n")] = 0;

    // Convert all characters to uppercase for comparison
    for (int i = 0; i < strlen(user_input); i++)
    {
        user_input[i] = toupper(user_input[i]);
    }

    // Calculate time taken
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Calculate typing speed
    int words_typed = 1;
    for (int i = 0; i < strlen(user_input); i++)
    {
        if (user_input[i] == ' ')
        {
            words_typed++;
        }
    }

    double typing_speed = ((double)words_typed) / time_taken;
    printf("\nCongratulations! You typed %d words in %.2f seconds. Your typing speed is %.2f words per second.\n", words_typed, time_taken, typing_speed);

    return 0;
}