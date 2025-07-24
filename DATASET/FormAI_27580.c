//FormAI DATASET v1.0 Category: Table Game ; Style: minimalist
/*
A minimalist C table game with randomized questions and answers.
Author: [Your Name]
Date: [Date]

How to play:
1. Enter the number of players.
2. Enter each player's name.
3. Answer the randomized questions correctly to score points.
4. The player with the highest score wins.

The program uses arrays, loops, and functions to create a simple game interface.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void generateQuestions(char questions[][50], char answers[][50]);
void shuffleArray(int array[], int size);
void displayPlayers(int numPlayers, char players[][50]);
void askQuestion(char question[], char answer[]);
void updateScores(int currentPlayer, int scores[]);
void displayScores(int numPlayers, char players[][50], int scores[]);
int highestScore(int numPlayers, int scores[]);

int main()
{
    int numPlayers, currentPlayer = 0;
    char players[10][50];
    int scores[10] = {0};
    char questions[10][50];
    char answers[10][50];
    int questionOrder[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    generateQuestions(questions, answers);
    shuffleArray(questionOrder, 10);

    // get number of players
    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);

    // get player names
    for (int i = 0; i < numPlayers; i++)
    {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i]);
    }

    // game loop
    for (int i = 0; i < 10; i++)
    {
        // display players and current scores
        displayPlayers(numPlayers, players);
        displayScores(numPlayers, players, scores);

        // ask randomized question and get answer
        int j = questionOrder[i];
        char question[50], answer[50];
        strcpy(question, questions[j]);
        strcpy(answer, answers[j]);
        askQuestion(question, answer);

        // update current player's score
        updateScores(currentPlayer, scores);

        // move to next player
        currentPlayer = (currentPlayer + 1) % numPlayers;
    }

    // display winner
    int winnerIndex = highestScore(numPlayers, scores);
    printf("%s wins with %d points!\n", players[winnerIndex], scores[winnerIndex]);

    return 0;
}

// generate questions and answers
void generateQuestions(char questions[][50], char answers[][50])
{
    // seed random number generator
    srand(time(NULL));

    // generate questions and answers
    strcpy(questions[0], "What is the capital of France?");
    strcpy(answers[0], "Paris");
    strcpy(questions[1], "What is the largest mammal on earth?");
    strcpy(answers[1], "Whale");
    strcpy(questions[2], "What is the smallest country in the world?");
    strcpy(answers[2], "Vatican");
    strcpy(questions[3], "What is the closest planet to the sun?");
    strcpy(answers[3], "Mercury");
    strcpy(questions[4], "What is the largest country in the world?");
    strcpy(answers[4], "Russia");
    strcpy(questions[5], "What is the tallest mountain in the world?");
    strcpy(answers[5], "Everest");
    strcpy(questions[6], "What is the national animal of Australia?");
    strcpy(answers[6], "Kangaroo");
    strcpy(questions[7], "What is the second largest continent?");
    strcpy(answers[7], "Africa");
    strcpy(questions[8], "What is the densest planet in the solar system?");
    strcpy(answers[8], "Earth");
    strcpy(questions[9], "What is the longest river in the world?");
    strcpy(answers[9], "Nile");
}

// shuffle array
void shuffleArray(int array[], int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        int j = rand() % size;
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
}

// display players
void displayPlayers(int numPlayers, char players[][50])
{
    printf("\n--- %d players ---\n", numPlayers);
    for (int i = 0; i < numPlayers; i++)
    {
        printf("%d. %s\n", i+1, players[i]);
    }
}

// ask question and validate answer
void askQuestion(char question[], char answer[])
{
    char userAnswer[50];
    printf("\nQuestion: %s\n", question);
    printf("Answer: ");
    scanf("%s", userAnswer);
    while (strcmp(userAnswer, answer) != 0)
    {
        printf("Incorrect. Try again.\n");
        printf("Answer: ");
        scanf("%s", userAnswer);
    }
    printf("Correct!\n");
}

// update current player's score
void updateScores(int currentPlayer, int scores[])
{
    scores[currentPlayer]++;
}

// display scores
void displayScores(int numPlayers, char players[][50], int scores[])
{
    printf("\n--- Scores ---\n");
    for (int i = 0; i < numPlayers; i++)
    {
        printf("%s: %d\n", players[i], scores[i]);
    }
}

// get index of player with highest score
int highestScore(int numPlayers, int scores[])
{
    int max = 0, index = 0;
    for (int i = 0; i < numPlayers; i++)
    {
        if (scores[i] > max)
        {
            max = scores[i];
            index = i;
        }
    }
    return index;
}