//FormAI DATASET v1.0 Category: Table Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int grid[5][5];
    int i, j;
    int player_pos = 0;
    int cpu_pos = 24;
    int move;
    int player_turn = 1;
    int cpu_turn = 0;
    
    // initialize grid
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            grid[i][j] = i*5 + j + 1;
        }
    }
    
    // set starting positions
    grid[0][0] = 'P';
    grid[4][4] = 'C';
    
    // print grid
    printf("TABLE GAME\n");
    printf("-----------\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%c\t", grid[i][j]);
        }
        printf("\n");
    }
    
    // game loop
    while (1) {
        if (player_turn) {
            printf("\nYour turn.\n");
            printf("Move (1-6): ");
            scanf("%d", &move);
            
            // update player position
            player_pos += move;
            if (player_pos > 24) player_pos = 24;
            printf("You rolled %d, moved to %d.\n", move, player_pos+1);
            
            // check for win
            if (player_pos == 24) {
                printf("\nCongratulations, you won!\n");
                break;
            }
            
            // update grid
            grid[player_pos/5][player_pos%5] = 'P';
            grid[(player_pos-move)/5][(player_pos-move)%5] = player_pos-move+1;
            
            // switch turns
            player_turn = 0;
            cpu_turn = 1;
        }
        
        else if (cpu_turn) {
            printf("\nCPU turn.\n");
            srand(time(NULL));
            move = rand() % 6 + 1;
            
            // update cpu position
            cpu_pos -= move;
            if (cpu_pos < 0) cpu_pos = 0;
            printf("CPU rolled %d, moved to %d.\n", move, cpu_pos+1);
            
            // check for win
            if (cpu_pos == 0) {
                printf("\nCPU wins, better luck next time!\n");
                break;
            }
            
            // update grid
            grid[cpu_pos/5][cpu_pos%5] = 'C';
            grid[(cpu_pos+move)/5][(cpu_pos+move)%5] = cpu_pos+move+1;
            
            // switch turns
            cpu_turn = 0;
            player_turn = 1;
        }
        
        // print grid
        printf("\n");
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                printf("%c\t", grid[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}