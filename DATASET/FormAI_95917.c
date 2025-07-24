//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int num = rand()%10;
    int guess;
    int attempts = 0;
    printf("Welcome to the Haunted House Simulator\n");
    printf("You find yourself at the entrance of a creepy, old house.\n");
    printf("As you approach the door it creaks open with a loud groan.\n");
    printf("Do you enter? (1 for yes, 2 for no): ");
    scanf("%d", &guess);
    if(guess == 2){
        printf("You decide the better of it and turn back.\n");
        printf("Thanks for playing.\n");
        return 0;
    }
    printf("You enter the house, despite your apprehension.\n");
    printf("The door slams shut behind you and you hear it lock.\n");
    printf("You are trapped. The only way out is to find the key.\n");
    printf("You notice a note on a nearby table. It reads:\n");
    printf("I have hidden the key somewhere in the house.\n");
    printf("Good luck finding it.\n");

    while(guess != num){
        printf("\nGuess a number between 1 and 10: ");
        scanf("%d", &guess);
        attempts++;
        if(guess < num){
            printf("Too low!\n");
        } else if(guess > num){
            printf("Too high!\n");
        } else {
            printf("\nCongratulations! You found the key in %d attempts!\n", attempts);
            printf("You unlock the door and flee the haunted house\n");
            printf("Thanks for playing.\n");
            return 0;
        }
    }
    return 0;
}