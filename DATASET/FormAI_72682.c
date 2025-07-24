//FormAI DATASET v1.0 Category: Weather simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 4

//Function that generates a random temperature between -10 and 40
int generateTemperature() {
    int temp = rand() % 51 - 10;
    return temp;
}

//Struct of player information
typedef struct player {
    char name[20];
    int temperature;
} player;

//Function that updates the temperature of the players
void updateTemperatures(player* players) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i].temperature += generateTemperature();
        printf("%s's temperature is now %d\n", players[i].name, players[i].temperature);
    }
}

//Function that gets the player with the highest temperature
player getHottestPlayer(player* players) {
    player hottestPlayer = players[0];
    for (int i = 1; i < NUM_PLAYERS; i++) {
        if (players[i].temperature > hottestPlayer.temperature) {
            hottestPlayer = players[i];
        }
    }
    return hottestPlayer;
}

int main() {
    srand(time(0)); //Seed the random number generator
    
    //Initialize the players
    player players[NUM_PLAYERS];
    strcpy(players[0].name, "Alice");
    strcpy(players[1].name, "Bob");
    strcpy(players[2].name, "Charlie");
    strcpy(players[3].name, "Dave");
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i].temperature = 20; //Initial temperature is 20 degrees Celsius
    }
    
    //Start the game loop
    int day = 1;
    while (1) {
        printf("\nDay %d:\n", day);
        updateTemperatures(players);
        player hottestPlayer = getHottestPlayer(players);
        printf("%s is the hottest player with a temperature of %d\n", hottestPlayer.name, hottestPlayer.temperature);
        
        //Check if the hottest player has reached a temperature of 40 or higher
        if (hottestPlayer.temperature >= 40) {
            printf("%s has died of heat stroke. Game over!\n", hottestPlayer.name);
            break;
        }
        
        day++;
    }
    
    return 0;
}