//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//Function prototypes
void clearScreen();
void delay(int milliseconds);
void intro();
void game();

int main(){
    //Call intro sequence
    intro();
    
    //Call game sequence
    game();
    
    return 0;
}

//Function to clear terminal screen
void clearScreen(){
    system("clear||cls");
}

//Function to add delay
void delay(int milliseconds){
    int c, d;
    
    for(c = 1; c <= milliseconds; c++)
        for(d = 1; d <= 3276; d++);
}

//Function for intro sequence
void intro(){
    printf("\n\n\n");
    printf("\t\tWelcome to the Mystical Forest!\n");
    printf("\n\n\n");
    delay(3000);
    clearScreen();
    
    printf("\t\tYou have been bestowed upon with a mission.\n\n");
    printf("\t\tThe mission is to find the mythical dragon's egg and return it to the village.\n\n");
    delay(5000);
    clearScreen();
}

//Function for game sequence
void game(){
    int steps = 0, choice, random, egg;
    char name[20];
    
    printf("\t\tEnter your name: ");
    scanf("%s", name);
    printf("\n\n\t\t%s, you embark on a journey to find the dragon's egg.\n\n", name);
    delay(5000);
    clearScreen();
    
    while(steps <= 10){ //Game loop
        printf("\n\n");
        printf("\t\tYou are wandering in the mystical forest.\n\n");
        printf("\t\tYou have taken %d steps.\n\n", steps);
        printf("\t\tWhat would you like to do?\n\n");
        printf("\t\t1 - Move forward\n");
        printf("\t\t2 - Move backward\n");
        printf("\t\t3 - Turn left\n");
        printf("\t\t4 - Turn right\n");
        printf("\t\t5 - Quit game\n\n");
        
        printf("\t\tEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1: //Move forward
                steps++;
                random = rand() % 10; //Generate random number between 0 and 9
                if(random == 9){
                    printf("\n\n\t\tOh no! You got lost in the forest!\n\n");
                    delay(3000);
                    printf("\t\tCalming your nerves, you start walking again.\n\n");
                    delay(3000);
                }
                else{
                    printf("\n\n\t\tYou move forward one step.\n\n");
                    delay(2000);
                }
                break;
            
            case 2: //Move backward
                if(steps == 0){
                    printf("\n\n\t\tYou can't move backward any further.\n\n");
                    delay(2000);
                }
                else{
                    printf("\n\n\t\tYou move backward one step.\n\n");
                    steps--;
                    delay(2000);
                }
                break;
            
            case 3: //Turn left
                printf("\n\n\t\tYou turn left.\n\n");
                delay(2000);
                break;
            
            case 4: //Turn right
                printf("\n\n\t\tYou turn right.\n\n");
                delay(2000);
                break;
                
            case 5: //Quit game
                printf("\n\n\t\tQuitting game. Goodbye, %s.\n\n", name);
                delay(3000);
                exit(0);
                
            default:
                printf("\n\n\t\tInvalid choice. Please try again.\n\n");
                delay(2000);
                break;
        }
        
        if(steps > 10){ //End of game
            egg = rand() % 2; //Generate random number between 0 and 1
            
            if(egg == 0){
                printf("\n\n\t\tCongratulations, %s! You found the dragon's egg!\n\n", name);
                delay(3000);
                printf("\t\tYou return to the village as a hero, with the egg.\n\n");
                delay(5000);
                printf("\t\tThank you for playing!\n\n");
                delay(3000);
                exit(0);
            }
            else{
                printf("\n\n\t\tOh no! The egg is not here. You have failed your mission.\n\n");
                delay(5000);
                printf("\t\tYou return to the village, empty-handed.\n\n");
                delay(5000);
                printf("\t\tThank you for playing.\n\n");
                delay(3000);
                exit(0);
            }
        }
    }
}