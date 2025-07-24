//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PLAYERS 4
#define MAX_MSG_LENGTH 100

struct player {
    int id;
    char name[20];
    bool is_infected;
    bool has_virus_protection;
};

struct message {
    int source_id;
    int dest_id;
    char content[MAX_MSG_LENGTH];
};

struct player players[MAX_PLAYERS];
struct message message_queue[MAX_PLAYERS * MAX_PLAYERS];
int num_messages = 0;

void infect_player(int player_id) {
    players[player_id].is_infected = true;
    printf("Player %d has been infected with a virus!\n", player_id);
}

void protect_player(int player_id) {
    players[player_id].has_virus_protection = true;
    printf("Player %d has installed a virus protection program!\n", player_id);
}

void print_player_info(int player_id) {
    struct player p = players[player_id];
    printf("Player %d: %s\n", p.id, p.name);
    if (p.is_infected) {
        printf("  - Infected with a virus!\n");
    } else {
        printf("  - Not infected\n");
    }
    if (p.has_virus_protection) {
        printf("  - Virus protection installed\n");
    } else {
        printf("  - No virus protection\n");
    }
}

void print_all_players_info() {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        print_player_info(i);
    }
}

void queue_message(int source_id, int dest_id, char* content) {
    struct message msg = {source_id, dest_id, ""};
    strncpy(msg.content, content, MAX_MSG_LENGTH);
    message_queue[num_messages++] = msg;
}

void process_messages() {
    for (int i = 0; i < num_messages; i++) {
        struct message msg = message_queue[i];
        if (players[msg.dest_id].has_virus_protection) {
            printf("Message from Player %d to Player %d blocked\n", msg.source_id, msg.dest_id);
        } else {
            printf("Message from Player %d to Player %d: %s\n", msg.source_id, msg.dest_id, msg.content);
            if (strstr(msg.content, "virus")) {
                infect_player(msg.dest_id);
            }
        }
    }
    num_messages = 0;
}

int main() {
    // initialize players
    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].id = i;
        sprintf(players[i].name, "Player %d", i+1);
        players[i].is_infected = false;
        players[i].has_virus_protection = false;
    }

    // simulate messages between players
    queue_message(0, 1, "Hi there");
    queue_message(1, 2, "What's up?");
    queue_message(2, 3, "Just hanging out");
    queue_message(3, 0, "Did you hear about the virus going around?");

    // simulate some players installing virus protection
    protect_player(1);
    protect_player(2);

    // process messages and check for viruses
    process_messages();
    print_all_players_info();
    return 0;
}