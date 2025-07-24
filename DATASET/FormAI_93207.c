//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int length, num_players;
    char password[50];
    printf("Enter the number of players: ");
    scanf("%d", &num_players);
    printf("Enter the length of the password: ");
    scanf("%d", &length);
    srand(time(0));
    printf("The password is: ");
    for(int i = 0; i < length; i++) {
        password[i] = rand() % 94 + 33;
        printf("%c", password[i]);
    }
    printf("\n\n");
    for(int i = 1; i <= num_players; i++) {
        char guess[50];
        printf("Player %d, enter your guess: ", i);
        scanf("%s", guess);
        if(strcmp(guess, password) == 0) {
            printf("Player %d wins!\n", i);
            break;
        }
        else {
            printf("Incorrect guess, try again!\n");
        }
    }
    return 0;
}