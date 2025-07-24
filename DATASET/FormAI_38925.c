//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_WORDS 10
#define WORD_SIZE 10

int compare(const void *a, const void *b) // qsort compare function
{
    const int *ia = *(const int **)a;
    const int *ib = *(const int **)b;
    return *ia - *ib;
}

float calculateTypingSpeed(int total_time, int total_char)
{
    float typing_speed = (float)total_char / ((float)total_time / 60);
    return typing_speed;
}

int main()
{
    char words[MAX_WORDS][WORD_SIZE] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon"};
    int random_word_indices[MAX_WORDS];
    int i, j, k, l, m, user_input, total_count, correct_count, wrong_count, total_time, total_char;
    time_t start_time, end_time;
    float typing_speed;

    // Seed the random number generator
    srand(time(NULL));

    // Generate random word indices
    for(i=0; i<MAX_WORDS; i++)
        random_word_indices[i] = rand() % MAX_WORDS;

    // Sort array of random word indices for display purposes
    qsort(random_word_indices, MAX_WORDS, sizeof(int), compare);

    printf("Type as many words as you can in 1 minute:\n");

    // Display random words to type
    for(i=0; i<MAX_WORDS; i++)
        printf("%d. %s\n", i+1, words[random_word_indices[i]]);

    // Start timer
    time(&start_time);

    // Loop through each word
    for(i=0; i<MAX_WORDS; i++)
    {
        // Get user input
        scanf("%s", &user_input);

        // Check if user input matches word
        if(strcmp(words[random_word_indices[i]], user_input) == 0)
            correct_count++;
        else
            wrong_count++;

        // Count total number of characters typed
        total_char += strlen(user_input);
    }

    // End timer
    time(&end_time);

    // Calculate total time
    total_time = difftime(end_time, start_time);

    // Calculate total count of words typed
    total_count = correct_count + wrong_count;

    // Calculate typing speed
    typing_speed = calculateTypingSpeed(total_time, total_char);

    // Display results
    printf("\n\nResults:\n");
    printf("Total words typed: %d\n", total_count);
    printf("Correct words typed: %d\n", correct_count);
    printf("Wrong words typed: %d\n", wrong_count);
    printf("Total time taken: %d seconds\n", total_time);
    printf("Typing speed: %.2f words per minute\n", typing_speed);

    return 0;
}