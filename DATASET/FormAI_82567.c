//FormAI DATASET v1.0 Category: Recursive ; Style: multiplayer
#include <stdio.h>

void count_down(int n) {
    if (n == 0) {
        printf("Blastoff!\n");
    } else {
        printf("%d\n", n);
        count_down(n-1);
    }
}

void handle_message(char* message, int player) {
    printf("Player %d says: %s\n", player, message);
    printf("Player %d starts the countdown:\n", player);
    count_down(player * 5);
}

int main() {
    int players = 2;
    printf("Welcome to the game!\n");
    printf("There are %d players.\n", players);
    printf("Starting game...\n");
    printf("Player 1, enter a message: ");
    char message[100];
    scanf("%s", message);
    handle_message(message, 1);
    printf("Player 2, enter a message: ");
    scanf("%s", message);
    handle_message(message, 2);
    printf("Game over!\n");
    return 0;
}