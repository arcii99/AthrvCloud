//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PLAYERS 4 // Max number of players in game
#define MAX_NAME_LEN 20 // Max length of player's name
#define REFRESH_RATE 1 // Screen refresh rate in seconds

struct player {
    char name[MAX_NAME_LEN];
    int cpu_usage;
    int score;
};

int get_cpu_usage() {
    FILE* fp;
    char path[1035]; // Buffer for reading /proc/stat
    long curr_cpu_ticks, curr_idle_ticks, prev_cpu_ticks, prev_idle_ticks;
    int cpu_usage;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error opening /proc/stat file\n");
        return -1;
    }

    fgets(path, sizeof(path), fp);
    sscanf(path+5, "%ld %*ld %*ld %ld", &prev_cpu_ticks, &prev_idle_ticks);

    fclose(fp);

    sleep(1);

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error opening /proc/stat file\n");
        return -1;
    }

    fgets(path, sizeof(path), fp);
    sscanf(path+5, "%ld %*ld %*ld %ld", &curr_cpu_ticks, &curr_idle_ticks);

    fclose(fp);

    cpu_usage = (int)(((curr_cpu_ticks + curr_idle_ticks) - (prev_cpu_ticks + prev_idle_ticks)) * 100.0 / (curr_cpu_ticks + curr_idle_ticks - prev_cpu_ticks - prev_idle_ticks));
    return cpu_usage;
}

void print_players(struct player* players, int num_players) {
    system("clear"); // Clear the screen

    printf("%20s%10s%10s\n", "Player Name", "CPU Usage", "Score");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < num_players; i++) {
        printf("%20s%10d%10d\n", players[i].name, players[i].cpu_usage, players[i].score);
    }
}

int main() {
    struct player players[MAX_PLAYERS];
    int num_players = 0;
    char input;
    int cpu_usage;

    while (num_players < MAX_PLAYERS) {
        printf("Enter name of player %d: ", num_players+1);
        scanf("%s", players[num_players].name);
        players[num_players].cpu_usage = 0;
        players[num_players].score = 0;
        num_players++;

        printf("Add another player? (y/n): ");
        scanf(" %c", &input);
        if (input == 'n') break;
    }

    while (1) {
        for (int i = 0; i < num_players; i++) {
            cpu_usage = get_cpu_usage();
            if (cpu_usage == -1) {
                players[i].cpu_usage = 0;
                continue;
            }
            players[i].cpu_usage = cpu_usage;
            players[i].score += cpu_usage;
        }

        print_players(players, num_players);

        sleep(REFRESH_RATE);
    }

    return 0;
}