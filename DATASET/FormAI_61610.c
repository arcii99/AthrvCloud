//FormAI DATASET v1.0 Category: Game of Life ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 20
#define COLUMNS 40
#define GENERATIONS 100

int main(){
    int i, j, k, m;
    int generations = 0;
    int current_gen[ROWS][COLUMNS];
    int next_gen[ROWS][COLUMNS];
    
    // Initializing the current generation with random values
    srand(time(NULL));
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMNS; j++){
            current_gen[i][j] = rand() % 2;
        }
    }
    
    // Generating next generations
    while(generations < GENERATIONS){
        system("clear");  // Clearing console screen for every new generation
        
        // Printing the current generation
        printf("Current Generation:\n");
        for(i=0; i<ROWS; i++){
            for(j=0; j<COLUMNS; j++){
                if(current_gen[i][j] == 1){
                    printf("#");
                }else{
                    printf(" ");
                }
            }
            printf("\n");
        }
        
        // Generating next generation
        for(i=0; i<ROWS; i++){
            for(j=0; j<COLUMNS; j++){
                int live_neighbours = 0;
                
                // Counting the live neighbours
                for(k=-1; k<=1; k++){
                    for(m=-1; m<=1; m++){
                        if(i+k >= 0 && j+m >= 0 && i+k < ROWS && j+m < COLUMNS){
                            if(k != 0 || m != 0){
                                live_neighbours += current_gen[i+k][j+m];
                            }
                        }
                    }
                }
                
                // Applying the rules to generate next generation
                if(current_gen[i][j] == 1){
                    if(live_neighbours < 2 || live_neighbours > 3){
                        next_gen[i][j] = 0;
                    }else{
                        next_gen[i][j] = 1;
                    }
                }else{
                    if(live_neighbours == 3){
                        next_gen[i][j] = 1;
                    }else{
                        next_gen[i][j] = 0;
                    }
                }
            }
        }
        
        // Updating the current generation with the next generation
        for(i=0; i<ROWS; i++){
            for(j=0; j<COLUMNS; j++){
                current_gen[i][j] = next_gen[i][j];
            }
        }
        
        printf("\nGeneration: %d", generations+1);  // Printing the current generation number
        generations++;
        
        // Sleeping for 500ms before printing the next generation
        struct timespec ts;
        ts.tv_sec = 0;
        ts.tv_nsec = 500000000;
        nanosleep(&ts, NULL);
    }
    
    return 0;
}