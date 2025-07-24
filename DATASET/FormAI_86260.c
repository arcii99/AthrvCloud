//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_RAM_SIZE 100
#define MIN_RAM_USAGE 20

//function to generate random RAM usage value
int generateRandomRAMUsage(){
    int ramUsage = rand() % MAX_RAM_SIZE + 1;
    return ramUsage;
}

//function to determine if RAM usage is below minimum threshold
bool isRAMUsageBelowMinimumThreshold(int ramUsage){
    return ramUsage < MIN_RAM_USAGE;
}

//main function
int main(){
    //initialize variables
    int ramUsage;
    bool isBelowThreshold = false;
    
    printf("Welcome to the C RAM Usage Monitor Program!\n");
    
    //continue generating random RAM usage values until below threshold
    while(!isBelowThreshold){
        ramUsage = generateRandomRAMUsage();
        
        //if RAM usage is below minimum threshold, print message and exit loop
        if(isRAMUsageBelowMinimumThreshold(ramUsage)){
            printf("Hooray! RAM usage is below the minimum threshold of %d.\n", MIN_RAM_USAGE);
            isBelowThreshold = true;
        }
        else{
            printf("Current RAM usage is %d. Checking again...\n", ramUsage);
        }
    }
    
    printf("Thank you for using the C RAM Usage Monitor Program!\n");
    
    return 0;
}