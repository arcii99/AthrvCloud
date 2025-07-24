//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: intelligent
#include<stdio.h>

int main(){
    int floors, elevators, curr_floor = 0, next_floor;
    printf("Enter number of floors in building: ");
    scanf("%d", &floors);
    printf("Enter number of elevators: ");
    scanf("%d", &elevators);

    int elevator[elevators];

    for(int i=0; i<elevators; i++){
        elevator[i] = curr_floor;
    }

    printf("\nElevator Simulation Program\n");

    while(1){
        printf("\nEnter floor number to go to (0 to exit): ");
        scanf("%d", &next_floor);

        if(next_floor == 0){
            printf("Exiting...\n");
            break;
        }

        int min_distance = floors;
        int min_elevator;

        for(int i=0; i<elevators; i++){
            int distance = next_floor - elevator[i];
            if(distance < 0){
                distance = -distance;
            }
            if(distance < min_distance){
                min_distance = distance;
                min_elevator = i;
            }
        }

        printf("Elevator %d moving to floor %d\n", min_elevator+1, next_floor);
        elevator[min_elevator] = next_floor;
    }
    return 0;
}