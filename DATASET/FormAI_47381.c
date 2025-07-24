//FormAI DATASET v1.0 Category: Firewall ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TOTAL_PLAYERS 4

// Structure to represent a Player
struct Player{
    int id;
    int health;
    int attackPower;
    int defensePower;
    int firewallStrength;
};

// Function to print the current status of all players
void printPlayerStatus(struct Player players[]){
    printf("\nPlayer ID\tHealth\tAttack\tDefense\tFirewall Strength\n");
    for(int i=0;i<TOTAL_PLAYERS;i++){
        printf("%d\t\t%d\t%d\t%d\t%d\n", players[i].id, players[i].health, players[i].attackPower, players[i].defensePower, players[i].firewallStrength);
    }
    printf("\n");
}

// Function to simulate the attack
void attack(int attacker, int defender, struct Player players[]){
    // Calculate the net damage after considering the defense power of the defender
    int damage = players[attacker].attackPower - players[defender].defensePower;
    // Check if the attack has been blocked by the defender's firewall strength
    if(players[defender].firewallStrength >= rand()%100){
        printf("Attack of Player %d was blocked by firewall of Player %d!\n",players[attacker].id, players[defender].id);
        return;
    }
    // Apply the damage to the defender
    players[defender].health -= damage;
    printf("Player %d attacked Player %d and dealt %d damage!\n", players[attacker].id, players[defender].id, damage);
}

// Function to check if the given player is still in the game
int isPlayerAlive(int id, struct Player players[]){
    return players[id-1].health > 0;
}

// Function to simulate a round of the game
void playRound(struct Player players[]){
    // Randomly select two players to attack each other
    int attacker = rand()%TOTAL_PLAYERS + 1;
    int defender = rand()%TOTAL_PLAYERS + 1;
    // Ensure that the attacker and defender are not the same player
    while(defender == attacker){
        defender = rand()%TOTAL_PLAYERS + 1;
    }
    // Make the selected players attack each other
    attack(attacker-1, defender-1, players);
}

// Main function to run the game
int main(){
    struct Player players[TOTAL_PLAYERS];
    // Initialize the players
    for(int i=0;i<TOTAL_PLAYERS;i++){
        players[i].id = i+1;
        players[i].health = 100;
        players[i].attackPower = rand()%10 + 1;
        players[i].defensePower = rand()%10 + 1;
        players[i].firewallStrength = rand()%50 + 50;
    }
    // Print out the initial status of all players
    printPlayerStatus(players);
    // Seed the random number generator with current time
    srand(time(NULL));
    int round = 1;
    // Keep playing rounds until only one player is alive
    while(1){
        printf("Round %d:\n", round++);
        playRound(players);
        int alivePlayers = 0, winner = 0;
        // Check how many players are still alive
        for(int i=0;i<TOTAL_PLAYERS;i++){
            if(isPlayerAlive(players[i].id, players)){
                alivePlayers++;
                winner = i+1;
            }
        }
        // If only one player is alive, declare them as the winner and end the game
        if(alivePlayers == 1){
            printf("Player %d is the winner!\n", winner);
            break;
        }
    }
    return 0;
}