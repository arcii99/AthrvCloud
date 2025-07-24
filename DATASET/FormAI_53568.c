//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

int main(){
    int x = 0; // variable for horizontal position
    int y = 0; // variable for vertical position
    int max_x = 10; // maximum horizontal distance
    int max_y = 10; // maximum vertical distance

    // welcome message
    printf("Welcome to Remote Control Vehicle Simulation\n");
    printf("Use the arrow keys to move the vehicle\n");
    printf("Press q to quit the simulation\n");

    // infinite loop for simulation
    while(1){
        // clear output screen
        system("clear");
        // print simulation area
        for(int i=0; i<=max_y; i++){
            for(int j=0; j<=max_x; j++){
                if(i==y && j==x){ // if current position is vehicle position
                    printf("*");
                } else{
                    printf("-");
                }
            }
            printf("\n");
        }

        // read user input
        char input = getchar();

        // move vehicle based on user input
        switch(input){
            case 'q': // quit simulation
                printf("Quitting simulation...\n");
                return 0;
                break;
            case 'w': // move upwards
                if(y>0){
                    y--;
                }
                break;
            case 's': // move downwards
                if(y<max_y){
                    y++;
                }
                break;
            case 'a': // move left
                if(x>0){
                    x--;
                }
                break;
            case 'd': // move right
                if(x<max_x){
                    x++;
                }
                break;
        }
    }

    return 0;
}