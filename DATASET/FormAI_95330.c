//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define SENTENCES_SIZE 10
#define SENTENCE_LENGTH 80

void generate_sentences(char sentences[SENTENCES_SIZE][SENTENCE_LENGTH]);
void print_sentences(char sentences[SENTENCES_SIZE][SENTENCE_LENGTH]);
double calculate_typing_speed(double seconds, int chars);

int main()
{
    char sentences[SENTENCES_SIZE][SENTENCE_LENGTH];
    double start_time, end_time, elapsed_time;
    int characters_typed = 0;

    generate_sentences(sentences);

    printf("Welcome to the Typing Speed Test Program!\n");
    printf("You will be presented with 10 sentences to type as quickly and accurately as possible.\n");
    printf("Press ENTER to start the test.\n");

    getchar(); // Wait for user to press ENTER

    print_sentences(sentences); // Display the sentences to be typed

    start_time = (double)clock() / CLOCKS_PER_SEC; // Get starting time

    for (int i = 0; i < SENTENCES_SIZE; i++)
    {
        char input[SENTENCE_LENGTH];
        fgets(input, SENTENCE_LENGTH, stdin); // Get user's input

        for (int j = 0; j < SENTENCE_LENGTH && input[j] != '\0'; j++)
        {
            if (input[j] != sentences[i][j])
            {
                printf("Incorrect!\n");
            }
            else
            {
                characters_typed++;
            }
        }
    }

    end_time = (double)clock() / CLOCKS_PER_SEC; // Get ending time
    elapsed_time = end_time - start_time; // Calculate elapsed time

    double typing_speed = calculate_typing_speed(elapsed_time, characters_typed);

    printf("\nCongratulations! You have completed the Typing Speed Test!\n");
    printf("You typed %d characters with an accuracy of %.2f%% in %.2f seconds.\n", characters_typed, (double)characters_typed / (SENTENCES_SIZE * SENTENCE_LENGTH) * 100, elapsed_time);
    printf("Your typing speed is %.2f characters per second.\n", typing_speed);

    return 0;
}

void generate_sentences(char sentences[SENTENCES_SIZE][SENTENCE_LENGTH])
{
    char words[12][10] = {"apple", "banana", "cherry", "kiwi", "lemon", "orange", "pear", "pineapple", "strawberry", "watermelon", "grape", "blueberry"};

    srand((unsigned int)time(NULL)); // Initialize random seed

    for (int i = 0; i < SENTENCES_SIZE; i++)
    {
        for (int j = 0; j < SENTENCE_LENGTH; j++)
        {
            if (j == 0 || sentences[i][j-1] == ' ')
            {
                int index = rand() % 12;
                sentences[i][j] = toupper(words[index][0]); // Capitalize first letter of each word
                for (int k = 1; k < 10 && words[index][k] != '\0'; k++)
                {
                    sentences[i][j+k] = words[index][k];
                }
                j += 10;
            }
            else if (j == SENTENCE_LENGTH-1)
            {
                sentences[i][j] = '.';
            }
            else
            {
                sentences[i][j] = 'a' + rand() % 26;
            }
        }
    }
}

void print_sentences(char sentences[SENTENCES_SIZE][SENTENCE_LENGTH])
{
    for (int i = 0; i < SENTENCES_SIZE; i++)
    {
        printf("%d.\t%s\n", i+1, sentences[i]);
    }
}

double calculate_typing_speed(double seconds, int chars)
{
    return (double)chars / seconds;
}