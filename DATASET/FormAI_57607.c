//FormAI DATASET v1.0 Category: Memory Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GRID_SIZE 10
#define MAX_NUMBERS 50

void printIntro();
void generateRandomNumbers(int array[], int size);
void shuffleArray(int array[], int size);
void printNumbers(int array[], int size);
int getGuess(int* guesses, int size);
void updateGameState(int* guesses, int guessCount, int* gameState, int* array, int size);
int isGameOver(int* gameState, int size);
void printEndGame(int* gameState, int size);

int main() {
    int gridSize = 4;
    int maxGuessCount = MAX_NUMBERS / 2;
    int guessCount = 0;
    int gameState[MAX_GRID_SIZE * MAX_GRID_SIZE] = { 0 };
    int randomNumbers[MAX_NUMBERS];
    int guesses[MAX_GRID_SIZE * MAX_GRID_SIZE] = { 0 };
    
    srand(time(NULL));
    
    printIntro();
    generateRandomNumbers(randomNumbers, gridSize * gridSize);
    shuffleArray(randomNumbers, gridSize * gridSize);
    printNumbers(randomNumbers, gridSize * gridSize);
    
    while (guessCount < maxGuessCount) {
        int guess = getGuess(guesses, gridSize * gridSize);
        updateGameState(guesses, guessCount, gameState, randomNumbers, gridSize * gridSize);
        guessCount++;
        if (isGameOver(gameState, gridSize * gridSize)) {
            printEndGame(gameState, gridSize * gridSize);
            return 0;
        }
    }
    
    return 0;  
}

void printIntro() {
    printf("Welcome to the Memory Game!\n");
    printf("You will be presented with a grid of numbers. You have to memorize the numbers and then guess them.\n");
}

void generateRandomNumbers(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = i / 2 + 1;
    }
}

void shuffleArray(int array[], int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void printNumbers(int array[], int size) {
    printf("Press ENTER to reveal the numbers!\n");
    getchar();
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
    printf("Press ENTER to start guessing!\n");
    getchar();
}

int getGuess(int* guesses, int size) {
    int guess = -1;
    do {
        printf("Enter a guess (0 to quit): ");
        scanf("%d", &guess);
        if (guess == 0) {
            printf("Thanks for playing!\n");
            exit(0);
        }
        if (guess > size || guess < 1) {
            printf("Invalid guess! Please try again.\n");
            continue;
        }
        if (guesses[guess - 1] != 0) {
            printf("You already guessed that number! Please try again.\n");
            continue;
        }
        break;
    } while (1);
    return guess;
}

void updateGameState(int* guesses, int guessCount, int* gameState, int* array, int size) {
    int guessIndex1 = guesses[(guessCount * 2) % (size * 2)] - 1;
    int guessIndex2 = guesses[(guessCount * 2 + 1) % (size * 2)] - 1;
    if (array[guessIndex1] == array[guessIndex2]) {
        gameState[guessIndex1] = 1;
        gameState[guessIndex2] = 1;
        printf("Correct guess!\n");
    } else {
        printf("Incorrect guess!\n");
    }
}

int isGameOver(int* gameState, int size) {
    for (int i = 0; i < size; i++) {
        if (gameState[i] == 0) {
            return 0;
        }
    }
    return 1;
}

void printEndGame(int* gameState, int size) {
    printf("Congratulations! You won!\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", gameState[i]);
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
}