//FormAI DATASET v1.0 Category: QR code reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main() {
    char qrCodes[MAX][MAX], player1[MAX], player2[MAX];
    // Initialize all QR codes to empty
    for (int i = 0; i < MAX; i++) {
        strcpy(qrCodes[i], "");
    }
    int playerTurn = 1, player1Score = 0, player2Score = 0, codeCount = 0, qrCodeLength = 0;
    printf("***** QR Code Reader Game *****\n\n");
    printf("Player 1, enter your name: ");
    fgets(player1, MAX, stdin);
    printf("Player 2, enter your name: ");
    fgets(player2, MAX, stdin);
    // Remove newline characters
    player1[strcspn(player1, "\n")] = 0;
    player2[strcspn(player2, "\n")] = 0;
    while (codeCount < 10) {
        printf("\n");
        if (playerTurn == 1) {
            printf("%s's turn\n", player1);
        } else {
            printf("%s's turn\n", player2);
        }
        printf("Enter QR code: ");
        fgets(qrCodes[codeCount], MAX, stdin);
        qrCodeLength = strlen(qrCodes[codeCount]) - 1; // Remove newline character
        qrCodes[codeCount][qrCodeLength] = '\0'; // Replace with null terminator
        // Check for duplicate QR codes
        for (int i = 0; i < codeCount; i++) {
            if (strcmp(qrCodes[codeCount], qrCodes[i]) == 0) {
                printf("Duplicate QR code, enter a different one.\n");
                qrCodes[codeCount][0] = '\0';
                break;
            }
        }
        // Check if QR code contains "player1" or "player2"
        if ((strstr(qrCodes[codeCount], player1) != NULL || strstr(qrCodes[codeCount], player2) != NULL) && qrCodes[codeCount][0] != '\0') {
            if (playerTurn == 1) {
                player1Score++;
                printf("Valid QR code! %s's score is now %d\n", player1, player1Score);
            } else {
                player2Score++;
                printf("Valid QR code! %s's score is now %d\n", player2, player2Score);
            }
        } else {
            printf("Invalid QR code. Score remains the same.\n");
        }
        if (playerTurn == 1) {
            playerTurn = 2;
        } else {
            playerTurn = 1;
        }
        codeCount++;
    }
    printf("\n***** Game Over *****\n");
    if (player1Score > player2Score) {
        printf("%s wins with a score of %d - %d\n", player1, player1Score, player2Score);
    } else if (player2Score > player1Score) {
        printf("%s wins with a score of %d - %d\n", player2, player2Score, player1Score);
    } else {
        printf("It's a tie! Final score: %d - %d\n", player1Score, player2Score);
    }
    return 0;
}