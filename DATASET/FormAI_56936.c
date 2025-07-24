//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SENTENCES 5
#define MAX_TYPING_TIME 60

// Function prototypes
void print_sentence(char* sentence);
float calculate_typing_speed(int num_chars, float typing_time);

int main()
{
    // Array of sentences for typing test
    char sentences[SENTENCES][100] = {"The quick brown fox jumps over the lazy dog.",
                                      "Peter Piper picked a peck of pickled peppers.",
                                      "How much wood would a woodchuck chuck, if a woodchuck could chuck wood?",
                                      "She sells seashells by the seashore.",
                                      "I saw Susie sitting in a shoeshine shop."};

    printf("Welcome to our peaceful typing speed test! Take a deep breath and focus on typing accurately and efficiently.\n\n");
    printf("You will be given five sentences to type, and you have a maximum of 60 seconds to complete the test.\n\n");
    printf("Are you ready to begin? Press enter to start...");
    getchar();
    printf("\n");

    // Randomly select a sentence from the array
    srand(time(NULL));
    int rand_num = rand() % 5;
    char* sentence_to_type = sentences[rand_num];
    print_sentence(sentence_to_type);

    // Start timer for typing time
    time_t start_time = time(NULL);

    // Read in user's input
    char user_input[100];
    fgets(user_input, 100, stdin);

    // End timer for typing time
    time_t end_time = time(NULL);
    float typing_time = difftime(end_time, start_time);

    // Calculate typing speed
    int num_chars = strlen(sentence_to_type) - 1; // Subtract 1 to remove newline character
    float typing_speed = calculate_typing_speed(num_chars, typing_time);

    // Output results
    printf("\n\nCongratulations on completing the typing test!\n");
    printf("You typed %d characters in %.2f seconds.\n", num_chars, typing_time);
    printf("Your typing speed was %.0f WPM (words per minute)! \n\n", typing_speed);

    return 0;
}

// Function to print the sentence for typing test
void print_sentence(char* sentence)
{
    printf("Type the following sentence:\n\n");
    printf("%s\n\n", sentence);
}

// Function to calculate the user's typing speed
float calculate_typing_speed(int num_chars, float typing_time)
{
    float num_words = num_chars / 5.0;
    float num_minutes = typing_time / 60.0;
    float typing_speed = num_words / num_minutes;

    return typing_speed;
}