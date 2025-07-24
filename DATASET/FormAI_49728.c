//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int bag_count = 0, conveyor_capacity = 20, num_conveyors = 10, total_bags_handled = 0, total_bags_lost = 0;
    srand(time(NULL));

    printf("Welcome to the Airport Baggage Handling Simulation!\n");
    printf("============================================\n");
    printf("Starting Simulation...\n");

    for(int i = 0; i < num_conveyors; i++){
        printf("Conveyor %d started...\n", i);
        while(bag_count < conveyor_capacity){
            int random_num = rand() % 100;
            if(random_num < 80){
                printf("Bag %d received on conveyor %d\n", total_bags_handled, i);
                total_bags_handled++;
                bag_count++;
            } else {
                printf("Bag %d lost on conveyor %d\n", total_bags_handled, i);
                total_bags_lost++;
            }
        }
        printf("Conveyor %d full. Bags sent to next conveyor...\n", i);
        bag_count = 0;
    }

    printf("Simulation complete!\n");
    printf("============================================\n");
    printf("Total bags handled: %d\n", total_bags_handled);
    printf("Total bags lost: %d\n", total_bags_lost);

    return 0;
}