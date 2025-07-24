//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Airline Luggage Handling Simulation\n");
    srand(time(NULL));

    int num_of_bags = rand() % 100 + 1;
    printf("Number of Bags: %d\n", num_of_bags);

    int conveyor[100];
    for(int i=0; i<num_of_bags; i++){
        conveyor[i] = rand() % 1000 + 1;
    }

    printf("\nBags on Conveyor Belt\n");
    for(int i=0; i<num_of_bags; i++){
        printf("%d, ", conveyor[i]);
    }

    int loaders[10] = {0};
    printf("\n\nLoaders: ");
    for(int i=0; i<10; i++){
        printf("%d, ", i+1);
    }

    int bags_loaded = 0;
    int current_loader = 0;

    printf("\n\nLoading bags onto the planes...\n");
    while(bags_loaded < num_of_bags){
        if(loaders[current_loader] == 0){
            loaders[current_loader] = conveyor[bags_loaded];
            bags_loaded += 1;
            printf("Bag %d loaded onto loader %d\n", bags_loaded, current_loader+1);
        }
        current_loader = (current_loader + 1) % 10;
    }

    printf("\nAll bags have been loaded onto the planes!\n");

    return 0;
}