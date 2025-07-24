//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int get_random_number(int max_num){
    return (rand() % (max_num+1));
}

int main(){
    srand(time(0));
    int num_devices = 10;
    int devices[num_devices];
    int connections[num_devices][num_devices];

    // Initialize random weights for connections
    for(int i=0; i<num_devices; i++){
        for(int j=0; j<num_devices; j++){
            if(i==j){
                connections[i][j] = 0;
            }else{
                connections[i][j] = get_random_number(10);
            }
        }
    }

    // Initialize random device IDs
    for(int i=0; i<num_devices; i++){
        devices[i] = get_random_number(100);
    }

    // Print the network topology
    printf("Network Topology:\n");
    for(int i=0; i<num_devices; i++){
        printf("%d: ", devices[i]);
        for(int j=0; j<num_devices; j++){
            printf("%d ", connections[i][j]);
        }
        printf("\n");
    }

    return 0;
}