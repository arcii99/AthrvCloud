//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4

typedef struct
{
    char* elementName;
    char* symbol;
    int atomicNumber;
    int correctOption;
    char* options[MAX_OPTIONS];
} Question;

Question questions[MAX_QUESTIONS] = {
    {"Hydrogen", "H", 1, 1, {"1", "2", "3", "4"}},
    {"Helium", "He", 2, 2, {"2", "4", "6", "8"}},
    {"Carbon", "C", 6, 3, {"4", "6", "8", "10"}},
    {"Nitrogen", "N", 7, 2, {"5", "7", "9", "11"}},
    {"Oxygen", "O", 8, 1, {"6", "8", "10", "12"}},
    {"Fluorine", "F", 9, 3, {"7", "9", "11", "13"}},
    {"Neon", "Ne", 10, 0, {"10", "12", "14", "16"}},
    {"Sodium", "Na", 11, 1, {"9", "11", "13", "15"}},
    {"Magnesium", "Mg", 12, 0, {"8", "10", "12", "14"}},
    {"Aluminum", "Al", 13, 3, {"12", "14", "16", "18"}}
};

void shuffleOptions(char* options[], int correctOption)
{
    // Swap correct option with a random other option
    int randomOption = rand() % MAX_OPTIONS;
    char* temp = options[correctOption];
    options[correctOption] = options[randomOption];
    options[randomOption] = temp;

    // Shuffle the remaining options randomly
    for (int i = 0; i < MAX_OPTIONS; i++)
    {
        int j = rand() % MAX_OPTIONS;
        char* temp = options[i];
        options[i] = options[j];
        options[j] = temp;
    }
}

int main()
{
    // Seed random number generator
    srand(time(NULL));

    int score = 0;

    printf("Welcome to the C Periodic Table Quiz!\n\n");

    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        shuffleOptions(questions[i].options, questions[i].correctOption);
        Question q = questions[i];

        printf("Question %d: What is the atomic number of %s (%s)?\n", i+1, q.elementName, q.symbol);
        printf("Options:\n");
        for (int j = 0; j < MAX_OPTIONS; j++)
        {
            printf("%d. %s\n", j+1, q.options[j]);
        }

        int userOption = 0;
        printf("Your answer: ");
        scanf("%d", &userOption);

        if (userOption == q.correctOption + 1)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect. The correct answer is %d.\n", q.correctOption+1);
        }

        printf("Your current score is %d out of %d.\n\n", score, i+1);
    }

    printf("Final score: %d out of %d.\n", score, MAX_QUESTIONS);

    return 0;
}