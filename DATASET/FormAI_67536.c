//FormAI DATASET v1.0 Category: Dice Roller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DICE_SIDES 6
#define NUM_PLAYERS 2

void print_dice(int value) {
    switch(value) {
        case 1:
            printf(" _______ \n|       |\n|   *   |\n|       |\n|_______|\n");
            break;
        case 2:
            printf(" _______ \n| *     |\n|       |\n|     * |\n|_______|\n");
            break;
        case 3:
            printf(" _______ \n| *     |\n|   *   |\n|     * |\n|_______|\n");
            break;
        case 4:
            printf(" _______ \n| *   * |\n|       |\n| *   * |\n|_______|\n");
            break;
        case 5:
            printf(" _______ \n| *   * |\n|   *   |\n| *   * |\n|_______|\n");
            break;
        case 6:
            printf(" _______ \n| *   * |\n| *   * |\n| *   * |\n|_______|\n");
            break;
        default:
            printf("Error: invalid dice value.\n");
            break;
    }
}

int roll_dice() {
    return (rand() % DICE_SIDES) + 1;
}

int main() {
    int player_scores[NUM_PLAYERS] = {0};
    int player_turn = 0;
    int round_num = 1;
    srand(time(0));
    
    printf("Welcome to C Dice Roller!\n");
    
    while(1) {
        printf("\n=== Round %d ===\n", round_num);
        printf("Player %d's turn:\n", player_turn + 1);
        
        printf("Rolling the dice...");
        int roll = roll_dice();
        print_dice(roll);
        printf("Result: %d\n", roll);
        
        player_scores[player_turn] += roll;
        printf("Player %d's score: %d\n", player_turn + 1, player_scores[player_turn]);
        
        if(player_scores[player_turn] >= 20) {
            printf("Player %d wins!\n", player_turn + 1);
            break;
        }
        
        player_turn = (player_turn + 1) % NUM_PLAYERS;
        round_num++;
    }
    
    return 0;
}