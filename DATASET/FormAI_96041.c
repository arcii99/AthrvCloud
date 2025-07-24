//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: happy
#include <stdio.h>
#include <string.h>

int main(){

char playerName[20];
char playAgain[3];
int score = 0;
int pick;

printf("\n------- Welcome to the Happy Adventure Game ---------\n");

printf("\nWhat's your name?\n");
scanf("%s", playerName);

printf("\nWelcome %s! Let's see if you can make it through our happy adventure game.\n", playerName);

do {

printf("\n********** Round 1 **********\n");
printf("You have arrived at a fork in the road. What do you do?\n");

printf("1. Go left\n");
printf("2. Go right\n");

scanf("%d", &pick);

if (pick == 1) {
    printf("\nYou find a pot of gold! Amazing job %s! Your score increased by 200 points.\n", playerName);
    score += 200;
}
else {
    printf("\nYou encounter a friendly unicorn who gives you a ride to the end of the game! Congratulations %s! Your score increased by 500 points.\n", playerName);
    score += 500;
}

printf("\nYour current score is %d.\n", score);

printf("\nWould you like to play again? (yes or no)\n");
scanf("%s", playAgain);

}while (strcmp(playAgain, "yes") == 0); 

printf("\nThank you for playing the Happy Adventure Game. Your final score is %d. Have a great day!\n", score);

return 0;
}