//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL)); //Seed for random number generation
    int fuel = 1000; // Starting fuel
    int oxygen = 1000; // Starting oxygen
    int distance = 0; // Starting distance
    int choice; // Choice variable to get user input
    
    printf("Welcome to Procedural Space Adventure\n");
    printf("Your goal is to reach the end of the galaxy\n");
    printf("You have a spaceship with 1000 units of fuel and 1000 units of oxygen\n");
    printf("You can use up fuel and oxygen to travel and survive in space\n");
    printf("Make wise choices to reach the end safely!\n\n");
    
    while(distance < 100){ // Loop until distance reached is 100
        printf("Distance travelled: %d\n", distance);
        printf("Units of fuel left: %d\n", fuel);
        printf("Units of oxygen left: %d\n", oxygen);
        printf("Choose your action:\n");
        printf("1. Travel to the next planet\n");
        printf("2. Refuel the spaceship\n");
        printf("3. Rest in the spaceship\n");
        printf("4. Check status\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                if(fuel < 100){ // check if minimum fuel requirement is met
                    printf("Not enough fuel to travel!\n");
                    break;
                }
                
                int travel_distance = rand() % 10 + 1; // random distance to travel
                int fuel_used = rand() % 200 + 100; // random fuel usage
                
                distance += travel_distance; // increment distance
                fuel -= fuel_used; // decrement fuel
                oxygen -= travel_distance * 10; // decrement oxygen
                
                if(oxygen <= 0 || fuel <= 0){ // Check if oxygen or fuel is depleted
                    printf("You have run out of oxygen or fuel, game over!\n");
                    return 0;
                }
                
                printf("You travelled %d units of distance and used %d units of fuel and %d units of oxygen!\n", travel_distance, fuel_used, travel_distance * 10);
                
                break;
                
            case 2:
                int refuel_amount = rand() % 200 + 100; // random refuel amount
                
                if(refuel_amount > (1000 - fuel)){ // check if max fuel is exceeded
                    printf("Maximum fuel reached!\n");
                    fuel = 1000; // refuel to max
                }
                else{
                    fuel += refuel_amount; // refuel with random amount
                }
                
                printf("You refueled the spaceship with %d units of fuel!\n", refuel_amount);
                
                break;
                
            case 3:
                int rest_amount = rand() % 100 + 50; // random rest amount
                
                if(rest_amount > (1000 - oxygen)){ // check if max oxygen is exceeded
                    printf("Maximum oxygen reached!\n");
                    oxygen = 1000; // rest to max
                }
                else{
                    oxygen += rest_amount; // rest with random amount
                }
                
                printf("You rested in the spaceship and gained %d units of oxygen!\n", rest_amount);
                
                break;
                
            case 4:
                printf("Current status:\n");
                printf("Distance travelled: %d\n", distance);
                printf("Units of fuel left: %d\n", fuel);
                printf("Units of oxygen left: %d\n", oxygen);
                
                break;
                
            default:
                printf("Invalid choice!\n");
                break;
        }
        
        printf("\n");
        
        if(distance >= 100){ // check if distance reached 100
            printf("Congratulations! You have reached the end of the galaxy!\n");
        }
    }
    
    return 0; // Exit program
}