//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int distance = 1000000; // distance to travel in miles
    int fuel = 5000; // gallons of fuel
    int health = 100; // health of spaceship crew
    int repair_kit = 5; // number of repair kits available
    int oxygen = 100; // oxygen level
    int event;
    int travel_distance;
    int travel_oxygen;
    int travel_fuel;
    int travel_health;
    int travel_time;

    srand(time(0)); // to generate random events

    while(distance > 0 && fuel > 0 && health > 0 && oxygen > 0){
        travel_distance = rand() % 1000 + 1000; // travel between 1000 and 2000 miles
        travel_oxygen = 10; // consume oxygen during travel
        travel_fuel = travel_distance / 10; // consume fuel during travel
        travel_time = travel_distance / 100; // travel time in hours
        travel_health = rand() % 20 + 5; // random health loss during travel
        
        printf("Travelling %d miles...\n", travel_distance);
        printf("Consuming %d gallons of fuel...\n", travel_fuel);
        printf("Consuming %d units of oxygen...\n", travel_oxygen);
        printf("Losing %d health points...\n", travel_health);
        printf("Travel time: %d hours\n", travel_time);
        
        fuel -= travel_fuel;
        distance -= travel_distance;
        oxygen -= travel_oxygen;
        health -= travel_health;
        
        if(rand() % 5 == 0 && repair_kit > 0){ // a random event occurs
            repair_kit--;
            printf("Ship damaged! Using a repair kit.\n");
            health += 20;
        }else if(rand() % 5 == 1){
            printf("Found a new planet!\n");
            oxygen += 20;
        }else if(rand() % 5 == 2){
            printf("Discovered an abandoned spaceship!\n");
            fuel += 500;
        }else if(rand() % 5 == 3){
            printf("Alien attack!\n");
            health -= 50;
        }else{
            printf("All quiet on the space front.\n");
        }
        
        if(fuel <= 0){
            printf("Out of fuel! Game over.\n");
            break;
        }
        if(distance <= 0){
            printf("Made it to the end of the journey!\n");
            break;
        }
        if(oxygen <= 0){
            printf("Out of oxygen! Game over.\n");
            break;
        }
        if(health <= 0){
            printf("Crew dead! Game over.\n");
            break;
        }
        
        printf("Current status:\nDistance left: %d miles\nFuel left: %d gallons\nHealth left: %d points\nOxygen left: %d units\n\n", distance, fuel, health, oxygen);
    }
    
    return 0;
}