//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: real-life
/*This program implements a network topology mapper using C language.
It allows the user to input the number of devices and their respective links/connections.
It then creates a graph using adjacency matrix and displays the topology of the network.*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 10  // maximum number of nodes the program can handle

int main()
{
    int num_devices, matrix[MAX_NODES][MAX_NODES];
    int i, j, k;
    
    printf("Enter the number of devices in the network: ");
    scanf("%d", &num_devices);
    
    //initialize the adjacency matrix 
    for(i=0; i<num_devices; i++){
        for(j=0; j<num_devices; j++){
            matrix[i][j] = 0;
        }
    }
    
    //take input for linkages between devices
    for(k=0; k<num_devices; k++){
        printf("Enter the links for device %d: (-1 to end)\n", k+1);
        i=0, j=0;
        do{
            scanf("%d", &j);
            if(j!=-1){
                matrix[k][j-1] = 1;
            }
        } while(j!=-1);
    }
    
    //display the topology of the network
    printf("\nThe network topology is:\n\n");
    for(i=0; i<num_devices;i++){
        for(j=0; j<num_devices; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}