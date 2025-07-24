//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A simple JSON parser */

/* This is an example JSON string to parse */
char json_string[] = "{\"players\": [{\"name\": \"John\", \"score\": 50}, {\"name\": \"Jane\", \"score\": 75}], \"game\": \"Chess\"}";

/* A player struct to store player information */
typedef struct {
    char name[20];
    int score;
} Player;

/* A game struct to store game information */
typedef struct {
    char name[20];
    Player players[2];
} Game;

/* Parses the JSON string and returns a Game struct */
Game parse_json(char *json) {
    /* Create the Game struct to return */
    Game game;

    /* Find the starting position of the players array */
    char *players_start = strstr(json, "\"players\": [");
    if (!players_start) {
        printf("Error: Could not find players array.\n");
        exit(1);
    }

    /* Find the ending position of the players array */
    char *players_end = strstr(players_start, "]");
    if (!players_end) {
        printf("Error: Could not find end of players array.\n");
        exit(1);
    }

    /* Copy the player objects into a new string */
    char players_string[1024];
    strncpy(players_string, players_start + 12, players_end - (players_start + 12));
    players_string[players_end - (players_start + 12)] = '\0';

    /* Count the number of player objects */
    int num_players = 0;
    char *player_start = players_string;
    while ((player_start = strstr(player_start, "{")) != NULL) {
        num_players++;
        player_start++;
    }

    /* Parse each player object */
    char *cur_player = players_string;
    for (int i = 0; i < num_players; i++) {
        /* Find the name and score values */
        char *name_start = strstr(cur_player, "\"name\": \"");
        char *name_end = strstr(name_start + 9, "\"");
        strncpy(game.players[i].name, name_start + 9, name_end - (name_start + 9));
        game.players[i].name[name_end - (name_start + 9)] = '\0';

        char *score_start = strstr(cur_player, "\"score\": ");
        game.players[i].score = atoi(score_start + 9);

        /* Move the pointer to the start of the next player object */
        cur_player = strstr(cur_player + 1, "{");
    }

    /* Find the game name */
    char *game_start = strstr(json, "\"game\": \"");
    if (!game_start) {
        printf("Error: Could not find game name.\n");
        exit(1);
    }
    char *game_end = strstr(game_start + 10, "\"");
    strncpy(game.name, game_start + 10, game_end - (game_start + 10));
    game.name[game_end - (game_start + 10)] = '\0';

    return game;
}

int main() {
    /* Parse the JSON string */
    Game game = parse_json(json_string);

    /* Print the game name and player information */
    printf("Game: %s\n", game.name);
    for (int i = 0; i < 2; i++) {
        printf("Player %d:\n\tName: %s\n\tScore: %d\n", i+1, game.players[i].name, game.players[i].score);
    }

    return 0;
}