//FormAI DATASET v1.0 Category: Robot movement control ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to generate random movements for the robot
char generate_random_movement(){
    int n = rand() % 4;
    if (n==0){
        return 'U'; //up
    }
    else if (n==1){
        return 'D'; //down
    }
    else if (n==2){
        return 'L'; //left
    }
    else{
        return 'R'; //right
    }
}

int main(){
    srand((unsigned) time(NULL)); //seeding the random number generator with the current time
    int x=0, y=0; //starting coordinates of the robot
    printf("Starting position: (%d, %d)\n", x, y);
    int n = rand() % 100 + 1; //number of movements the robot will make
    printf("Number of movements: %d\n", n);
    char movements[n];
    for(int i=0; i<n; i++){
        movements[i] = generate_random_movement(); //generating a random movement and storing it in the movements array
    }
    printf("Movements: ");
    for(int i=0; i<n; i++){
        printf("%c ",movements[i]);
    }
    printf("\n");

    for(int i=0; i<n; i++){
        char movement = movements[i];
        switch(movement){
            case 'U':
                y++;
                printf("Movement %d: Up -> (%d, %d)\n", i+1, x, y);
                break;
            case 'D':
                y--;
                printf("Movement %d: Down -> (%d, %d)\n", i+1, x, y);
                break;
            case 'L':
                x--;
                printf("Movement %d: Left -> (%d, %d)\n", i+1, x, y);
                break;
            case 'R':
                x++;
                printf("Movement %d: Right -> (%d, %d)\n", i+1, x, y);
                break;
            default:
                printf("Invalid movement\n");
                break;
        }
    }

    printf("Final position: (%d, %d)\n", x, y);
    
    return 0;
}