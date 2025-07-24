//FormAI DATASET v1.0 Category: Dice Roller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    srand(time(NULL)); //Initialize the random seed with current time
    
    int sides, rolls;
    printf("Welcome to the Immersive Dice Roller program\n");
    printf("============================================\n");
    
    while(1) {  //Infinite loop to keep the program running
        
        printf("Enter the number of sides on the dice (or 0 to quit): ");
        scanf("%d", &sides);
        
        if(sides == 0) {
            printf("Exiting program....\n");
            break;
        }
        
        printf("Enter the number of rolls: ");
        scanf("%d", &rolls);
        
        printf("Rolling the dice.....\n");
        printf("======================\n");
        
        for(int i=0; i<rolls; i++) {
            int result = rand() % sides + 1;
            printf("Roll %d: %d\n", i+1, result);
        }
        
        printf("======================\n");
        printf("Rolls completed\n\n");
    }
    
    return 0;
}