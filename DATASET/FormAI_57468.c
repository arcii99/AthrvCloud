//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Welcome to the greedy algorithm joke!\n");
    
    int num_levels;
    printf("How many levels do you want to play? ");
    scanf("%d", &num_levels);

    int level_coin_values[num_levels];
    for (int i=0; i<num_levels; i++){
        printf("Enter the coin values for level %d: ", i+1);
        scanf("%d", &level_coin_values[i]);
    }

    printf("\nLet's start playing!\n");

    int total_coins_collected = 0;
    int current_level = 1;
    while (current_level <= num_levels) {
        printf("\nPlaying level %d...\n", current_level);
        int max_coin_value = -1;
        int max_coin_value_index = -1;
        for (int i=0; i<num_levels; i++){
            if (i == current_level-1){ // skip the current level's coin values
                continue;
            }
            if (level_coin_values[i] > max_coin_value){
                max_coin_value = level_coin_values[i];
                max_coin_value_index = i;
            }
        }
        if (max_coin_value == -1){
            // all other coin values are -1 (not possible in real game)
            printf("Oops! No more levels to play. End game.\n");
            break;
        }
        total_coins_collected += max_coin_value;
        printf("Collected %d coins from level %d.\n", max_coin_value, max_coin_value_index+1);
        current_level = max_coin_value_index+1;
    }

    printf("\nTotal coins collected: %d\n", total_coins_collected);
    
    return 0;
}