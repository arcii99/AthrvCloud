//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define ELEVATOR_CAPACITY 10
#define FLOORS 10
#define SLEEP_TIME 500000

int elevator[ELEVATOR_CAPACITY];
int floor_targets[FLOORS];
int current_floor = 0;
char direction = 'u'; // Up is default direction

void print_elevator(){
    printf("\n  ___  \n");
    printf(" | %c | \n",direction);
    printf(" |###|\n");
    for(int i = ELEVATOR_CAPACITY - 1; i >= 0; i--){
        if(elevator[i] == 0)
            printf(" |   |\n");
        else
            printf(" | %d |\n",elevator[i]);
    }
    printf(" |___|\n");
}

void print_floor(){
    printf("Floor: %d\n",current_floor);
    printf("Floor Targets: ");
    for(int i = 0; i < FLOORS; i++){
        if(floor_targets[i])
            printf("%d ",i+1);
    }
    printf("\n\n");
}

void delay(int sleep_time){
    for(long int i = 0; i < sleep_time; i++){
        // Intentional delay
    }
}

int main(){
    printf("\nWelcome to the Elevator Simulation\n\n");

    while(1){
        print_elevator();
        print_floor();

        if(!floor_targets[current_floor])
            printf("No one needs to get off on this floor\n\n");
        else{
            printf("Stopping at this floor to let passengers off...\n");
            delay(SLEEP_TIME);
            for(int i = 0; i < ELEVATOR_CAPACITY; i++){
                if(elevator[i] == current_floor + 1){
                    printf("Passenger %d has got off the elevator\n",i+1);
                    elevator[i] = 0;
                }
            }
            floor_targets[current_floor] = 0;
        }

        for(int i = 0; i < ELEVATOR_CAPACITY; i++){
            if(elevator[i] == 0){
                for(int j = current_floor + 1; j <= FLOORS; j++){
                    if(floor_targets[j-1]){
                        printf("Calling elevator to floor %d...\n",j);
                        delay(SLEEP_TIME);
                        current_floor = j-1;
                        elevator[i] = j;
                        floor_targets[j-1] = 0;
                        break;
                    }
                }
                break;
            }
        }

        if(current_floor == FLOORS - 1)
            direction = 'd';
        else if(current_floor == 0)
            direction = 'u';

        printf("\nElevator is moving %c\n",direction);
        delay(SLEEP_TIME);
        if(direction == 'u')
            current_floor++;
        else if(direction == 'd')
            current_floor--;
    }

    return 0;
}