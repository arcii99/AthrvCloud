//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));

    // Generate random map
    int map[10][10];
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            map[i][j] = rand()%2;
        }
    }

    // Initialize player position
    int player_pos[2] = {0,0};

    // Game Loop
    while(1){

        // Print map
        printf("Map:\n");
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                if(i==player_pos[0] && j==player_pos[1]){
                    printf("@");
                }
                else if(map[i][j]==1){
                    printf("#");
                }
                else{
                    printf(".");
                }
            }
            printf("\n");
        }

        // Get user input
        char input;
        printf("Enter Move (WASD): ");
        scanf(" %c", &input);

        // Update player position based on input
        if(input == 'w' && player_pos[0]>0 && map[player_pos[0]-1][player_pos[1]]==0){
            player_pos[0]--;
        }
        else if(input == 'a' && player_pos[1]>0 && map[player_pos[0]][player_pos[1]-1]==0){
            player_pos[1]--;
        }
        else if(input == 's' && player_pos[0]<9 && map[player_pos[0]+1][player_pos[1]]==0){
            player_pos[0]++;
        }
        else if(input == 'd' && player_pos[1]<9 && map[player_pos[0]][player_pos[1]+1]==0){
            player_pos[1]++;
        }

        // Check for win condition
        if(player_pos[0]==9 && player_pos[1]==9){
            printf("You Win!");
            break;
        }
    }

    return 0;
}