//FormAI DATASET v1.0 Category: Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the bizarre universe of this C game!");
    printf("\n");
    printf("In this game, you are a pixelated bird with the power of telekinesis!");
    printf("\n");
    printf("Use your powers to move the obstacles and reach the end goal!");
    printf("\n");
    printf("Press spacebar to unleash a wave of energy to move the obstacles!");
    printf("\n");
    
    int score = 0;
    int level = 1;
    
    while(level <= 5) {
        printf("\n");
        printf("Level %d:", level);
        printf("\n");
        
        // Generating random obstacles
        int num_obstacles = rand() % 5 + 1;
        int obstacle_positions[num_obstacles];
        
        for(int i = 0; i < num_obstacles; i++) {
            obstacle_positions[i] = rand() % 15 + 1;
        }
        
        // Displaying the obstacles
        int player_position = 0;
        for(int i = 0; i < 16; i++) {
            if(i == player_position) {
                printf("B");
            } else {
                int obstacle_flag = 0;
                for(int j = 0; j < num_obstacles; j++) {
                    if(obstacle_positions[j] == i) {
                        printf("X");
                        obstacle_flag = 1;
                        break;
                    }
                }
                if(obstacle_flag == 0) {
                    printf("-");
                }
            }
        }
        
        // Checking if player completed the level
        if(player_position == 15) {
            score += 100 * level;
            printf("\n");
            printf("Congratulations! You cleared level %d", level);
            printf("\n");
            printf("Score: %d", score);
            printf("\n");
            level++;
        } else {
            printf("\n");
            printf("Enter '1' to move left or '2' to move right: ");
            int move_direction;
            scanf("%d", &move_direction);
            
            if(move_direction == 1) {
                player_position--;
            } else if(move_direction == 2) {
                player_position++;
            } else {
                printf("Invalid input");
                printf("\n");
            }
            
            // Moving the obstacles using telekinesis power
            if(move_direction == 3) {
                for(int i = 0; i < num_obstacles; i++) {
                    obstacle_positions[i]++;
                }
            } else if(move_direction == 4) {
                for(int i = 0; i < num_obstacles; i++) {
                    obstacle_positions[i]--;
                }
            }
        }
    }
    
    // Displaying final score
    printf("\n");
    printf("Game over");
    printf("\n");
    printf("Final score: %d", score);
    printf("\n");
    
    return 0;
}