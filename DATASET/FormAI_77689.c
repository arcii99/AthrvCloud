//FormAI DATASET v1.0 Category: Log analysis ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_LOGS 50

struct Log {
    char description[100];
};

struct Player {
    char name[20];
    struct Log logs[MAX_LOGS];
    int num_logs;
};

struct Game {
    char title[50];
    struct Player players[MAX_PLAYERS];
    int num_players;
};

void add_log(struct Game *game, char *player_name, char *log_description) {
    int i, j;
    for (i = 0; i < game->num_players; i++) {
        if (strcmp(game->players[i].name, player_name) == 0) {
            struct Player *player = &(game->players[i]);
            strcpy(player->logs[player->num_logs].description, log_description);
            player->num_logs++;
            return;
        }
    }
    printf("Player not found.\n");
}

void print_logs(struct Game game) {
    int i, j;
    for (i = 0; i < game.num_players; i++) {
        struct Player player = game.players[i];
        printf("%s's Logs:\n", player.name);
        for (j = 0; j < player.num_logs; j++) {
            printf("%d) %s\n", j+1, player.logs[j].description);
        }
    }
}

int main() {
    struct Game game;
    strcpy(game.title, "Multiplayer Log Analyzer");

    printf("Welcome to %s!\n", game.title);

    int choice;
    do {
        printf("\nSelect an option:\n");
        printf("1. Add Log\n");
        printf("2. View Logs\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nAdd Log:\n");
                char player_name[20], log_description[100];
                printf("Enter player name: ");
                scanf("%s", player_name);
                printf("Enter log description: ");
                scanf("%s", log_description);
                add_log(&game, player_name, log_description);
                break;
            case 2:
                printf("\nView Logs:\n");
                print_logs(game);
                break;
            case 3:
                printf("\nExiting %s...\n", game.title);
                break;
            default:
                printf("\nInvalid choice.\n");
        }  
    } while (choice != 3);

    return 0;
}