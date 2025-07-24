//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 20

typedef struct Bag{
    int id;
    int weight;
} Bag;

void simulate(Bag bags[]){
    int i;
    int time = 0;
    int num_bags = NUM_BAGS;
    int total_weight = 0;

    // The queue of bags waiting to be loaded onto planes
    Bag* queue = malloc(sizeof(Bag) * num_bags);
    int head = 0;
    int tail = 0;

    // The set of planes being loaded
    int* planes = calloc(3, sizeof(int));
    
    printf("Starting baggage handling simulation...\n");

    // Loop until all the bags have been loaded
    while (num_bags > 0){

        // Check if there are any open planes
        for (i=0; i<3; i++){
            if (planes[i] == 0){
                // If there are bags waiting to be loaded, load the next one onto the plane
                if (head != tail){
                    Bag bag = queue[head];
                    head = (head + 1) % num_bags;
                    planes[i] = bag.weight;
                    total_weight += bag.weight;
                    printf("Plane %d loaded bag %d with weight %d\n", i+1, bag.id, bag.weight);
                    num_bags--;
                    time++;
                }
            } else {
                // If a plane is being loaded, decrement the amount of time remaining
                planes[i]--;
                time++;
            }
        }

        // If there are still bags waiting to be loaded, add them to the queue
        for (i=0; i<num_bags; i++){
            if (rand() % 2 == 0){
                queue[tail] = bags[i];
                tail = (tail + 1) % num_bags;
            }
        }
    }

    printf("Simulation complete.\n");
    printf("Total time: %d\n", time);
    printf("Total weight: %d\n", total_weight);

    free(planes);
    free(queue);
}

int main(){
    int i;

    srand(time(NULL));

    Bag bags[NUM_BAGS];
    for (i=0; i<NUM_BAGS; i++){
        bags[i].id = i+1;
        bags[i].weight = rand() % 51;
    }

    simulate(bags);

    return 0;
}