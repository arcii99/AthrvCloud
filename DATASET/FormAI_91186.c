//FormAI DATASET v1.0 Category: Error handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 10

typedef struct player {
    int id;
    char name[20];
    int score;
} Player;

Player players[MAX_PLAYERS];
int num_players = 0;

void handle_error(int error_code) {
    switch(error_code) {
        case 1:
            printf("Error: Player name too long\n");
            break;
        case 2:
            printf("Error: Maximum number of players reached\n");
            break;
        default:
            printf("Unknown error occurred\n");
            break;
    }
}

void add_player(char name[]) {
    if(strlen(name) > 20) {
        handle_error(1);
        return;
    }
    if(num_players == MAX_PLAYERS) {
        handle_error(2);
        return;
    }
    Player new_player;
    new_player.id = num_players + 1;
    strcpy(new_player.name, name);
    new_player.score = 0;
    players[num_players] = new_player;
    num_players++;
    printf("%s added to the game!\n", name);
}

void play_game() {
    if(num_players < 2) {
        printf("Error: Not enough players to start game\n");
        return;
    }
    printf("Game on....\n");
    srand(time(NULL));
    for(int i = 1; i <= 3; i++) {
        printf("Round %d\n", i);
        for(int j = 0; j < num_players; j++) {
            int score = rand() % 10 + 1;
            players[j].score += score;
            printf("%s scored %d points in round %d\n", players[j].name, score, i);
        }
    }
    printf("Game over!\n");
}

int main() {
    add_player("John");
    add_player("Nashitsham");
    add_player("Emily");
    add_player("Mark");
    add_player("Sam");
    add_player("Lena");
    add_player("Jacob");
    add_player("David");
    add_player("Amanda");
    add_player("Adam"); // this player will trigger an error
    play_game();

    return 0;
}