//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20

typedef struct player {
    char name[MAX_NAME_LENGTH];
    pid_t pid;
    float cpu_usage;
} player;

int main() {
    player players[MAX_PLAYERS];
    int num_players = 0;

    // Get list of process IDs
    FILE* fp = popen("ps -A -o uid,pid,%cpu | sort -nrk 3,3 | head -n 10", "r");
    if (fp == NULL) {
        printf("Failed to open pipe for ps command\n");
        exit(1);
    }

    // Parse output of ps command and store data in 'players' array
    char buffer[128];
    char* token;
    while (fgets(buffer, 128, fp) != NULL) {
        token = strtok(buffer, " ");
        token = strtok(NULL, " ");  // ignore UID
        players[num_players].pid = atoi(token);
        token = strtok(NULL, " ");
        players[num_players].cpu_usage = atof(token);
        sprintf(players[num_players].name, "Player %d", num_players+1);
        num_players++;
    }
    pclose(fp);

    // Print out list of players and their CPU usage
    printf("Top %d players by CPU usage:\n", num_players);
    for (int i = 0; i < num_players; i++) {
        printf("%s: %f%%\n", players[i].name, players[i].cpu_usage);
    }

    return 0;
}