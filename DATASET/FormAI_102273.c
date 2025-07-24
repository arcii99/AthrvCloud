//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: artistic
#include<stdio.h>
#include<stdlib.h>

int main(){

    // Create a random network topology
    int topology[5][5] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };

    // Create a map to keep track of connections
    int map[5][5] = {{0}};

    // Map out the connections in the network
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            
            // Check if there's a connection between nodes
            if(topology[i][j] == 1){
                
                // Mark the connection on the map
                map[i][j] = 1;
                
                // Check if there's a connection back to the original node
                if(topology[j][i] == 1){
                    map[j][i] = 1;
                }
            }
        }
    }

    // Print out the network topology map
    printf("\n Network Topology Map:\n");
    printf("    1   2   3   4   5\n");
    printf("  +---+---+---+---+---+\n");
    for(int i=0; i<5; i++){
        printf("%d ", i+1);
        for(int j=0; j<5; j++){
            if(map[i][j] == 1){
                printf("| X ");
            }else{
                printf("|   ");
            }
        }
        printf("|\n  +---+---+---+---+---+\n");
    }

    return 0;
}