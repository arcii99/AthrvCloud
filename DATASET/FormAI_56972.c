//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LENGTH 100

void sanitizeInput(char *string){
    char *temp = string;
    while (*temp){
        if (!isalnum(*temp))
            *temp = '_';
        temp++;
    }
}

int main() {
    char player1[LENGTH];
    char player2[LENGTH];
    printf("Enter a name for player 1: ");
    // Get input for player 1
    fgets(player1, LENGTH, stdin);
    sanitizeInput(player1);
    printf("Player 1's sanitized name is %s\n", player1);
    printf("Enter a name for player 2: ");
    // Get input for player 2
    fgets(player2, LENGTH, stdin);
    sanitizeInput(player2);
    printf("Player 2's sanitized name is %s\n", player2);
    return 0;
}