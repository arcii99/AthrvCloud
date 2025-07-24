//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set up random number generator
    srand(time(NULL));
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Press Enter to start...\n");
    
    // Wait for user to press Enter
    while(getchar() != '\n') {}
    
    // Begin the game
    printf("You find yourself standing in front of an old, dilapidated house.\n");
    printf("It's late at night and there's a full moon out.\n");
    printf("Do you enter the house? (y/n): ");
    
    // Get user input
    char input = getchar();
    
    if(input == 'y') {
        printf("You cautiously open the front door and step inside.\n");
        printf("It's dark and quiet, but you can hear strange noises coming from the depths of the house.\n");
        printf("Do you turn on your flashlight? (y/n): ");
        input = getchar();
        
        if(input == 'y') {
            printf("You fumble in your pocket and find your trusty flashlight.\n");
            printf("As you turn it on, you catch a glimpse of something moving in the shadows.\n");
            printf("Do you investigate the noise? (y/n): ");
            
            input = getchar();
            
            if(input == 'y') {
                printf("You cautiously make your way towards the source of the noise.\n");
                printf("Suddenly, something jumps out at you from the darkness!\n");
                printf("You scream and start running, trying to find your way out of the house.\n");
                printf("Do you go left or right? (l/r): ");
                
                input = getchar();
                
                if(input == 'l') {
                    printf("You turn left and run through a maze of dark corridors.\n");
                    printf("You can hear the thing chasing you, getting closer and closer...\n");
                    printf("You come to a dead end. There's nowhere to run.\n");
                    printf("The thing catches up to you and...\n");
                    printf("GAME OVER\n");
                }
                else if(input == 'r') {
                    printf("You turn right and run through a long hallway.\n");
                    printf("You can hear the thing behind you, but it seems to be getting farther away.\n");
                    printf("You come to a staircase. Do you go up or down? (u/d): ");
                    
                    input = getchar();
                    
                    if(input == 'u') {
                        printf("You climb the stairs and find yourself in an old attic.\n");
                        printf("It's creepy up here, but at least you're away from the thing chasing you.\n");
                        printf("Do you try to find a way out of the attic? (y/n): ");
                        
                        input = getchar();
                        
                        if(input == 'y') {
                            printf("You start searching the attic for a way out.\n");
                            printf("As you're looking through an old chest, you come across a strange book.\n");
                            printf("You start flipping through the pages and suddenly a ghostly figure appears!\n");
                            printf("The ghostly figure speaks to you, telling you about a secret passage in the house.\n");
                            printf("You thank the ghostly figure and start searching for the secret passage.\n");
                            printf("After a few minutes, you find it and escape the house!\n");
                            printf("Congratulations, you made it out alive!\n");
                        }
                        else if(input == 'n') {
                            printf("You decide to stay in the attic and wait for daylight.\n");
                            printf("As you're sitting there, you hear the thing chasing you making its way up the stairs.\n");
                            printf("You huddle in the corner, hoping it won't find you...\n");
                            printf("But it does.\n");
                            printf("GAME OVER\n");
                        }
                    }
                    else if(input == 'd') {
                        printf("You descend the stairs and find yourself in a basement.\n");
                        printf("It's musty and creepy down here, but at least you're away from the thing chasing you.\n");
                        printf("Do you try to find a way out of the basement? (y/n): ");
                        
                        input = getchar();
                        
                        if(input == 'y') {
                            printf("You start searching the basement for a way out.\n");
                            printf("As you're looking through an old pile of junk, you come across a hidden door!\n");
                            printf("You pry it open and escape the house!\n");
                            printf("Congratulations, you made it out alive!\n");
                        }
                        else if(input == 'n') {
                            printf("You decide to stay in the basement and wait for daylight.\n");
                            printf("As you're sitting there, you hear the thing chasing you making its way down the stairs.\n");
                            printf("You huddle in the corner, hoping it won't find you...\n");
                            printf("But it does.\n");
                            printf("GAME OVER\n");
                        }
                    }
                }
            }
            else if(input == 'n') {
                printf("You decide to leave the noise alone and try to find a way out of the house.\n");
                printf("As you're walking, you step on a loose floorboard and fall through the floor!\n");
                printf("You keep falling and falling, until...\n");
                printf("GAME OVER\n");
            }
        }
        else if(input == 'n') {
            printf("You decide to make your way through the house without a flashlight.\n");
            printf("As you're walking, you trip over something and fall!\n");
            printf("You hit your head and everything goes black...\n");
            printf("GAME OVER\n");
        }
    }
    else if(input == 'n') {
        printf("You decide not to enter the house and start walking back to town.\n");
        printf("As you're walking, you hear strange noises coming from the house...\n");
        printf("You look back and see something moving in the shadows!\n");
        printf("You start running, but it's already too late.\n");
        printf("GAME OVER\n");
    }
    
    return 0;
}