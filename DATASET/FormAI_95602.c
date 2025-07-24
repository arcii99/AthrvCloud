//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(NULL)); //initialize random seed
    
    int num_of_bags, time_interval;
    printf("Enter the number of bags: "); //user input for number of bags
    scanf("%d", &num_of_bags);
    printf("Enter the time interval for bags to be loaded (in seconds): "); //user input for time interval
    scanf("%d", &time_interval);
    
    printf("******************************************************\n");
    printf("      Welcome to the Airport Baggage Handling System \n");
    printf("******************************************************\n");
    printf("Loading %d bags onto the conveyor...\n",num_of_bags);
    printf("Time interval between bags: %d seconds\n",time_interval);
    
    int conveyor_speed = 10; //meters per second
    int total_time = num_of_bags / conveyor_speed;
    printf("Total time for loading: %d seconds\n",total_time);
    
    //simulate conveyor movement and bag loading
    int i;
    for(i=0; i<num_of_bags; i++) {
        printf("\nBag %d is loaded onto the conveyor...\n", i+1);
        int delay = rand() % time_interval + 1; //random delay for bag loading
        sleep(delay);
    }
    
    printf("\nAll bags have been loaded onto the conveyor. Conveyor moving...\n");
    printf("Estimated time for conveyor to reach the plane: %d seconds\n",total_time);
    printf("Thank you for using the Airport Baggage Handling System!\n");
    
    return 0;
}