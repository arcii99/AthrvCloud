//FormAI DATASET v1.0 Category: Smart home light control ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_ROOMS 3
#define NUM_LIGHTS 4
#define MAX_PLAYERS 4

typedef struct {
    bool state;
    int brightness;
} Light;

typedef struct {
    char name[20];
    int room_num;
} Player;

Light lights[NUM_ROOMS][NUM_LIGHTS];
Player players[MAX_PLAYERS];

void initializeLights() {
    for (int r = 0; r < NUM_ROOMS; r++) {
        for (int l = 0; l < NUM_LIGHTS; l++) {
            lights[r][l].state = false;
            lights[r][l].brightness = 0;
        }
    }
}

void initializePlayers() {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        strcpy(players[i].name, "");
        players[i].room_num = -1;
    }
}

void printLightState() {
    printf("Current light state:\n");
    for (int r = 0; r < NUM_ROOMS; r++) {
        printf("  Room %d:\n", r);
        for (int l = 0; l < NUM_LIGHTS; l++) {
            printf("    Light %d: %s, %d%% brightness\n", l, 
                lights[r][l].state ? "on" : "off", lights[r][l].brightness);
        }
    }
}

void printPlayerList() {
    printf("Current players in game:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (strcmp(players[i].name, "") == 0) {
            break;
        }
        printf("  %s: in room %d\n", players[i].name, players[i].room_num);
    }
}

void printGameInstructions() {
    printf("Welcome to Multiplayer Smart Home Light Control!\n");
    printf("You are one of up to %d players, each controlling a part of the house.\n", MAX_PLAYERS);
    printf("Enter 'help' at any time to see a list of commands.\n");
}

void listCommands() {
    printf("Available Commands:\n");
    printf("  list: get the current light state\n");
    printf("  join <room number>: join the specified room\n");
    printf("  leave: leave the current room\n");
    printf("  turn <light number> [on/off]: turn the specified light on or off\n");
    printf("  brightness <light number> <percentage>: set the specified light's brightness\n");
    printf("  players: list current players in game\n");
    printf("  help: display list of commands\n");
}

bool isRoomValid(int room_num) {
    return room_num >= 0 && room_num < NUM_ROOMS;
}

bool isLightValid(int light_num) {
    return light_num >= 0 && light_num < NUM_LIGHTS;
}

bool isPlayerValid(int player_num) {
    return player_num >= 0 && player_num < MAX_PLAYERS;
}

void joinRoom(int player_num, int room_num) {
    if (isRoomValid(room_num)) {
        players[player_num].room_num = room_num;
    } else {
        printf("Invalid room number.\n");
    }
}

void leaveRoom(int player_num) {
    players[player_num].room_num = -1;
}

void turnLight(int room_num, int light_num, bool state) {
    if (isRoomValid(room_num) && isLightValid(light_num)) {
        lights[room_num][light_num].state = state;
    } else {
        printf("Invalid room or light number.\n");
    }
}

void setBrightness(int room_num, int light_num, int brightness) {
    if (isRoomValid(room_num) && isLightValid(light_num) && brightness >= 0 && brightness <= 100) {
        lights[room_num][light_num].brightness = brightness;
    } else {
        printf("Invalid room, light, or brightness value.\n");
    }
}

int getPlayerNum(char *player_name) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (strcmp(players[i].name, player_name) == 0) {
            return i;
        }
    }
    return -1;
}

int getNextPlayerNum() {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (strcmp(players[i].name, "") == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    initializeLights();
    initializePlayers();
    printGameInstructions();

    char input[50];
    while (true) {
        printf("\nEnter your command: ");
        fgets(input, 50, stdin);
        input[strlen(input)-1] = '\0'; // remove newline character from end of input

        char *command = strtok(input, " ");
        char *arg1 = strtok(NULL, " ");
        char *arg2 = strtok(NULL, " ");

        if (strcmp(command, "list") == 0) {
            printLightState();
        } else if (strcmp(command, "join") == 0) {
            int room_num = atoi(arg1);
            if (isRoomValid(room_num)) {
                int next_player_num = getNextPlayerNum();
                if (next_player_num != -1) {
                    printf("Enter your name: ");
                    char name_input[20];
                    fgets(name_input, 20, stdin);
                    name_input[strlen(name_input)-1] = '\0'; // remove newline character from end of name input
                    
                    int player_num = getPlayerNum(name_input);
                    if (player_num != -1) {
                        printf("Player with that name already exists.\n");
                    } else {
                        strcpy(players[next_player_num].name, name_input);
                        players[next_player_num].room_num = room_num;
                        printf("Player %s joined room %d.\n", name_input, room_num);
                    }
                } else {
                    printf("Maximum number of players reached.\n");
                }
            } else {
                printf("Invalid room number.\n");
            }
        } else if (strcmp(command, "leave") == 0) {
            int player_num = getPlayerNum(arg1);
            if (isPlayerValid(player_num)) {
                leaveRoom(player_num);
                strcpy(players[player_num].name, "");
                printf("Player %s left the game.\n", arg1);
            } else {
                printf("The player with that name is not in the game.\n");
            }
        } else if (strcmp(command, "turn") == 0) {
            int light_num = atoi(arg1);
            bool state = strcmp(arg2, "on") == 0 ? true : false;
            int player_num = getPlayerNum(arg1);
            if (isLightValid(light_num) && isPlayerValid(player_num)) {
                int room_num = players[player_num].room_num;
                turnLight(room_num, light_num, state);
            } else {
                printf("Invalid light or player name.\n");
            }
        } else if (strcmp(command, "brightness") == 0) {
            int light_num = atoi(arg1);
            int brightness = atoi(arg2);
            int player_num = getPlayerNum(arg1);
            if (isLightValid(light_num) && isPlayerValid(player_num)) {
                int room_num = players[player_num].room_num;
                setBrightness(room_num, light_num, brightness);
            } else {
                printf("Invalid light or player name.\n");
            }
        } else if (strcmp(command, "players") == 0) {
            printPlayerList();
        } else if (strcmp(command, "help") == 0) {
            listCommands();
        } else {
            printf("Invalid command. Enter 'help' to see a list of commands.\n");
        }
    }
    return 0;
}