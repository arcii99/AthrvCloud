//FormAI DATASET v1.0 Category: Database simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 100
#define MAX_PLAYERS 5

struct player {
    char name[MAX_CHARACTERS];
    int score;
};

struct database {
    struct player players[MAX_PLAYERS];
    int num_players;
};

void add_player(struct database *db, char *player_name) {
    if (db->num_players >= MAX_PLAYERS) {
        printf("The database is full. Could not add player.\n");
        return;
    }

    struct player new_player;
    strncpy(new_player.name, player_name, MAX_CHARACTERS);
    new_player.score = 0;

    db->players[db->num_players] = new_player;
    db->num_players++;

    printf("Player \"%s\" added to the database.\n", player_name);
}

void increase_score(struct database *db, char *player_name, int amount) {
    for (int i = 0; i < db->num_players; i++) {
        if (strcmp(db->players[i].name, player_name) == 0) {
            db->players[i].score += amount;
            printf("Increased score of player \"%s\" by %d points. New score: %d.\n", player_name, amount, db->players[i].score);
            return;
        }
    }

    printf("Could not find player \"%s\" in the database. Score not increased.\n", player_name);
}

void print_players(struct database *db) {
    printf("Players in the database:\n");
    for (int i = 0; i < db->num_players; i++) {
        printf("- %s (Score: %d)\n", db->players[i].name, db->players[i].score);
    }
}

int main() {
    struct database db;
    db.num_players = 0;

    add_player(&db, "Sir Lancelot");
    add_player(&db, "Sir Galahad");
    add_player(&db, "Sir Robin");
    add_player(&db, "Sir Bedevere");
    add_player(&db, "The Black Knight");

    increase_score(&db, "Sir Lancelot", 10);
    increase_score(&db, "Sir Robin", 5);
    increase_score(&db, "The Black Knight", 7);

    print_players(&db);

    return 0;
}