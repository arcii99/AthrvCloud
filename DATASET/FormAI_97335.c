//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#define MAX_FLOOR 10

//structure for passenger
struct passenger {
    int source_floor;
    int destination_floor;
};

void display_elevator_status(int elevator_floor, int direction, int num_passengers) {
    //function to display current elevator status
    printf("Elevator is at floor %d, moving in direction %d, with %d passengers\n", elevator_floor, direction, num_passengers);
}

int main() {
    struct passenger p[MAX_FLOOR]; //maximum number of passengers on a floor
    int num_passengers = 0, elevator_floor = 0, direction = 0;

    //initialize elevator direction to 1 (upwards)
    //elevator will always start moving from ground floor to top floor and back to ground floor
    direction = 1;

    while(1) {
        display_elevator_status(elevator_floor, direction, num_passengers); //display current elevator status

        //if elevator direction is upwards and it has reached top floor or downwards and it has reached ground floor
        if((direction == 1 && elevator_floor == MAX_FLOOR) || (direction == -1 && elevator_floor == 0)) {
            direction *= -1; //change direction
        }

        //unload passengers
        int i;
        for(i=0; i<num_passengers; i++) {
            if(p[i].destination_floor == elevator_floor) {
                printf("Passenger getting off at floor %d\n", elevator_floor);
                //shift remaining passengers in the array
                for(int j=i; j<num_passengers; j++) {
                    p[j] = p[j+1];
                }
                num_passengers--;
            }
        }

        //load passengers
        if(num_passengers < MAX_FLOOR) {
            int source_floor = rand() % (MAX_FLOOR+1); //generate a random source floor for the passenger
            int destination_floor;
            do {
                destination_floor = rand() % (MAX_FLOOR+1); //generate a random destination floor until it is not equal to the source floor
            } while(destination_floor == source_floor);
            printf("Passenger on floor %d going to floor %d\n", source_floor, destination_floor);
            struct passenger new_passenger = {source_floor, destination_floor};

            //add passenger to the array
            p[num_passengers++] = new_passenger;
        }

        //move elevator to next floor in the direction it is moving
        elevator_floor += direction;

        //wait for some time before moving to the next floor
        sleep(1);
    }

    return 0;
}