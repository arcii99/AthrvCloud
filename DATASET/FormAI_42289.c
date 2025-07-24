//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS_PER_PLANE 300 //maximum number of bags that can be accommodated in a single plane
#define MAX_TERMINALS 3 //maximum number of terminals in the airport
#define MAX_CONVEYOR_BELTS 5 //maximum number of conveyor belts installed in each terminal
#define MAX_BAGS_ON_BELT 20 //maximum number of bags that can be placed on a single conveyor belt

//define a Baggage struct to hold necessary properties of each bag
typedef struct {
    int id; //unique id for each bag
    int weight; //weight of each bag in kgs
    int terminal; //terminal to which the bag belongs [0, MAX_TERMINALS-1]
    int conveyor_belt; //conveyor belt on which the bag is currently placed [0, MAX_CONVEYOR_BELTS-1]; -1 if not on any belt
} Baggage;

//define a ConveyorBelt struct to hold necessary properties of each conveyor belt
typedef struct {
    int id; //unique id for each belt
    int terminal; //terminal to which the belt belongs [0, MAX_TERMINALS-1]
    int num_bags; //current number of bags placed on the belt
    Baggage bags[MAX_BAGS_ON_BELT]; //array to hold bags placed on the belt
} ConveyorBelt;

//define a Terminal struct to hold necessary properties of each terminal
typedef struct {
    int id; //unique id for each terminal
    int num_bags_processed; //total number of bags processed by the terminal
    ConveyorBelt conveyor_belts[MAX_CONVEYOR_BELTS]; //array of conveyor belts installed in the terminal
} Terminal;

//function to randomly generate a baggage object with random properties
Baggage generate_baggage(int id) {
    Baggage bag;
    bag.id = id;
    bag.weight = rand() % 30 + 1; //random weight between 1-30 kgs
    bag.terminal = rand() % MAX_TERMINALS; //random terminal between 0-MAX_TERMINALS-1
    bag.conveyor_belt = -1; //-1 indicating that the bag is not on any belt initially
    return bag;
}

int main() {
    srand(time(NULL)); //seed the random number generator
    
    Terminal terminals[MAX_TERMINALS]; //array of terminals in the airport
    
    //initialise each terminal in the airport
    for (int i = 0; i < MAX_TERMINALS; i++) {
        Terminal terminal = {i, 0};
        //initialise conveyor belts for this terminal
        for (int j = 0; j < MAX_CONVEYOR_BELTS; j++) {
            ConveyorBelt belt = {j, i, 0};
            terminal.conveyor_belts[j] = belt;
        }
        terminals[i] = terminal;
    }
    
    //generate a list of random baggages to be processed
    Baggage baggages[MAX_BAGS_PER_PLANE];
    for (int i = 0; i < MAX_BAGS_PER_PLANE; i++) {
        Baggage bag = generate_baggage(i);
        baggages[i] = bag;
    }
    
    //simulate the processing of each bag in the airport
    for (int i = 0; i < MAX_BAGS_PER_PLANE; i++) {
        Baggage bag = baggages[i];
        printf("Processing Bag %d weighing %d kgs destined for Terminal %d\n", bag.id, bag.weight, bag.terminal);
        
        //check if there is any available conveyor belt in the bag's terminal
        int conveyor_belt_id = -1;
        for (int j = 0; j < MAX_CONVEYOR_BELTS; j++) {
            if (terminals[bag.terminal].conveyor_belts[j].num_bags < MAX_BAGS_ON_BELT) {
                conveyor_belt_id = j;
                break;
            }
        }
        
        if (conveyor_belt_id != -1) { //if an available conveyor belt is found
            ConveyorBelt *belt = &terminals[bag.terminal].conveyor_belts[conveyor_belt_id];
            bag.conveyor_belt = conveyor_belt_id; //set the belt id on which the bag is being placed
            belt->bags[belt->num_bags] = bag; //add the bag to the selected conveyor belt
            belt->num_bags++; //increment the number of bags on the selected conveyor belt
            terminals[bag.terminal].num_bags_processed++; //increment the bags processed counter for the bag's terminal
            printf("Bag %d placed on ConveyorBelt %d in Terminal %d\n", bag.id, conveyor_belt_id, bag.terminal);
        } else { //if no available conveyor belt is found
            printf("No available conveyor belt in Terminal %d for Bag %d\n", bag.terminal, bag.id);
        }
    }
    
    //print the statistics for each terminal after processing all bags
    for (int i = 0; i < MAX_TERMINALS; i++) {
        printf("Terminal %d processed %d bags:\n", i, terminals[i].num_bags_processed);
        for (int j = 0; j < MAX_CONVEYOR_BELTS; j++) {
            printf("\tConveyorBelt %d: %d bags\n", j, terminals[i].conveyor_belts[j].num_bags);
        }
    }

    return 0;
}