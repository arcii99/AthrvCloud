//FormAI DATASET v1.0 Category: QR code generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 10
#define CODE_LENGTH 10

void generateQRCode(char *code);
void printQRCode(char *code);
void playerGuess(char *code, int playerNum);

int main()
{
    char qrCode[CODE_LENGTH+1];
    generateQRCode(qrCode);
    printQRCode(qrCode);

    int numPlayers;
    printf("Enter number of players (2 to %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    while (numPlayers < 2 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Please enter a number between 2 and %d: ", MAX_PLAYERS);
        scanf("%d", &numPlayers);
    }

    for (int i = 1; i <= numPlayers; i++) {
        printf("\nPlayer %d:\n", i);
        playerGuess(qrCode, i);
    }

    return 0;
}

void generateQRCode(char *code)
{
    srand(time(NULL));
    char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int charsetSize = strlen(charset);
    for (int i = 0; i < CODE_LENGTH; i++) {
        code[i] = charset[rand() % charsetSize];
    }
    code[CODE_LENGTH] = '\0';
}

void printQRCode(char *code)
{
    printf("QR Code: %s\n", code);
}

void playerGuess(char *code, int playerNum)
{
    char guess[CODE_LENGTH+1];
    printf("Enter your guess (length %d): ", CODE_LENGTH);
    scanf("%s", guess);

    int correct = 0;
    for (int i = 0; i < CODE_LENGTH; i++) {
        if (guess[i] == code[i]) {
            correct++;
        }
    }
    printf("Correct positions: %d\n", correct);

    int incorrect = 0;
    for (int i = 0; i < CODE_LENGTH; i++) {
        if (guess[i] != code[i]) {
            for (int j = 0; j < CODE_LENGTH; j++) {
                if (guess[i] == code[j]) {
                    incorrect++;
                }
            }
        }
    }
    printf("Incorrect positions: %d\n", incorrect);
    if (correct == CODE_LENGTH) {
        printf("Player %d wins!\n", playerNum);
    } else {
        printf("Better luck next time, Player %d.\n", playerNum);
    }
}