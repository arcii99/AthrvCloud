//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int energy = 100;
    int money = 500;
    int ship_health = 100;
    int distance_to_earth = 100;
    
    srand(time(0)); // Seeding the Random Number Generator with current time
    
    printf("\n\nWelcome to the Space Adventure!\n\n");
    printf("Current Stats:\n");
    printf("Energy: %d\n", energy);
    printf("Money: %d\n", money);
    printf("Ship Health: %d\n", ship_health);
    printf("Distance to Earth: %d\n", distance_to_earth);
    
    while(distance_to_earth > 0){
        int event = rand() % 5 + 1; // Generating random number between 1 and 5
        
        switch(event){
            case 1:
                printf("\n\nYou encountered an asteroid belt!\n");
                printf("Ship Health decreased by 10\n");
                ship_health -= 10;
                break;
            
            case 2:
                printf("\n\nYou discovered a new planet!\n");
                int planet_type = rand() % 3 + 1; // Generating random number between 1 and 3
                
                switch(planet_type){
                    case 1:
                        printf("It's a barren planet, nothing here.\n");
                        break;
                    
                    case 2:
                        printf("It's a planet rich in minerals!\n");
                        int minerals = rand() % 1000 + 1; // Generating random number between 1 and 1000
                        printf("%d minerals found!\n", minerals);
                        money += minerals;
                        break;
                    
                    case 3:
                        printf("It's inhabited by aliens!\n");
                        int alien_type = rand() % 3 + 1; // Generating random number between 1 and 3
                        
                        switch(alien_type){
                            case 1:
                                printf("They are friendly and offer you a gift!\n");
                                printf("Energy increased by 20\n");
                                energy += 20;
                                break;
                            
                            case 2:
                                printf("They are hostile and attack your ship!\n");
                                printf("Ship Health decreased by 20\n");
                                ship_health -= 20;
                                break;
                            
                            case 3:
                                printf("They are interested in trading with you!\n");
                                printf("Energy decreased by 10\n");
                                energy -= 10;
                                printf("Money increased by 200\n");
                                money += 200;
                                break;
                        }
                        break;
                }
                break;
            case 3:
                printf("\n\nYou stumbled upon a wormhole!\n");
                printf("Energy decreased by 10\n");
                energy -= 10;
                printf("Distance to Earth decreased by 50\n");
                distance_to_earth -= 50;
                break;
            
            case 4:
                printf("\n\nYou encountered a space station!\n");
                printf("Energy increased by 10\n");
                energy += 10;
                printf("Money decreased by 50\n");
                money -= 50;
                printf("Ship Health increased by 10\n");
                ship_health += 10;
                break;
            
            case 5:
                printf("\n\nYou found a space debris!\n");
                printf("Energy increased by 5\n");
                energy += 5;
                printf("Money increased by 20\n");
                money += 20;
                break;
        }
        
        printf("\n\nCurrent Stats:\n");
        printf("Energy: %d\n", energy);
        printf("Money: %d\n", money);
        printf("Ship Health: %d\n", ship_health);
        printf("Distance to Earth: %d\n", distance_to_earth);
        
        if(ship_health <= 0){
            printf("\n\nYour ship has been destroyed!\n");
            printf("GAME OVER\n\n");
            break;
        }
        
        if(energy <= 0){
            printf("\n\nYou ran out of energy!\n");
            printf("GAME OVER\n\n");
            break;
        }
        
        if(distance_to_earth <= 0){
            printf("\n\nYou have reached Earth safely!\n");
            printf("Congratulations, You have completed your Space Adventure!\n\n");
        }
        
    }
    
    return 0;
}