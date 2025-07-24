//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    //Initialization of variables
    int signal_strength;
    int player_choice;
    int attempts = 3;
    
    //Introduction
    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n\n");
    printf("In this post-apocalyptic world, Wi-Fi signals are scarce and unpredictable.\n");
    printf("Your goal is to guess the strength of the signal (between 0 and 10) in order to connect to it.\n");
    printf("You will have three attempts to guess correctly.\n");
    
    //Random signal strength generation
    srand(time(NULL));
    signal_strength = rand() % 11;
    
    //Game loop
    do{
        printf("\nEnter your guess (0-10): ");
        scanf("%d", &player_choice);
        
        if(player_choice == signal_strength){
            printf("\nCongratulations, you have connected to the Wi-Fi signal with a strength of %d!\n", signal_strength);
            break;
        }
        else{
            printf("Incorrect guess!");
            attempts--;
            if(attempts > 0){
                printf(" You have %d attempts left.\n", attempts);
            }
            else{
                printf(" You have no more attempts left.\n");
            }
        }
    } while(attempts > 0);
    
    return 0;
}