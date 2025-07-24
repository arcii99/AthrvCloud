//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // seed RNG with current time
    
    int player_x = 10;
    int player_y = 10;

    int enemy_x[20];
    int enemy_y[20];
    int num_enemies = 10;

    for(int i = 0; i < num_enemies; i++) {
        enemy_x[i] = rand() % 50;
        enemy_y[i] = (rand() % 10) + 20;
    }

    int score = 0;

    while(1) {

        // Print game board
        system("clear"); // Clear console
        printf("Score: %d\n", score);

        for(int i = 0; i < 30; i++) {
            for(int j = 0; j < 50; j++) {
                if(i == player_y && j == player_x) {
                    printf("P");
                } else {
                    int enemy_found = 0;
                    for(int k = 0; k < num_enemies; k++) {
                        if(enemy_x[k] == j && enemy_y[k] == i) {
                            printf("E");
                            enemy_found = 1;
                            break;
                        }
                    }
                    if(!enemy_found) {
                        printf("-");
                    }
                }
            }
            printf("\n");
        }

        // Handle user input
        char input = getchar();
        getchar(); // Consume extra newline character

        if(input == 'a' && player_x > 0) {
            player_x--;
        } else if(input == 'd' && player_x < 49) {
            player_x++;
        } else if(input == ' ') {
            // Player fired!
            for(int i = 0; i < num_enemies; i++) {
                if(enemy_y[i] == player_y + 1 && abs(enemy_x[i] - player_x) < 3) {
                    // Hit an enemy!
                    score += 10;
                    enemy_y[i] = -1;
                }
            }
        }

        // Move enemies down
        for(int i = 0; i < num_enemies; i++) {
            if(enemy_y[i] == -1) {
                continue;
            }
            enemy_y[i]++;
            if(enemy_y[i] == 29) {
                // Enemy reached player!
                printf("Game over! Final score: %d\n", score);
                return 0;
            }
        }

        // Spawn new enemies
        if(rand() % 10 == 0) {
            int empty_space = 0;
            for(int i = 0; i < num_enemies; i++) {
                if(enemy_y[i] == -1) {
                    empty_space = 1;
                    enemy_x[i] = rand() % 50;
                    enemy_y[i] = 0;
                    break;
                }
            }
            if(!empty_space) {
                // All enemy slots are full!
                printf("Game over! Final score: %d\n", score);
                return 0;
            }
        }

    }

    return 0;
}