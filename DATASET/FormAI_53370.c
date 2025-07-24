//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate random numbers
int generateRandom(int lower, int upper){
    srand(time(0));
    return (rand() % (upper - lower + 1)) + lower;
}

//Function to check if user wins or loses
int checkWinLose(int playerNumber, int computerNumber){
    if(playerNumber == computerNumber){
        printf("\nIt's a tie! Both of you have landed on the same planet.");
        return 0;
    }else if(abs(playerNumber - computerNumber) == 1){
        printf("\nCongratulations! You have landed on a habitable planet and saved humanity.\n");
        return 1;
    }else{
        printf("\nOh no! You landed on an uninhabitable planet. Try again.");
        return 0;
    }
}

int main(){
    int playerNumber, computerNumber, numPlanets = 8, choice;

    printf("Welcome to the space adventure game!\n");
    printf("You are a space explorer on a mission to find a habitable planet for humanity.\n");

    do{
        printf("\nChoose a numbered planet between 1 to 8 to land on: ");
        scanf("%d", &playerNumber);
    }while(playerNumber < 1 || playerNumber > 8);

    printf("You have landed on planet %d.\n", playerNumber);

    computerNumber = generateRandom(1, numPlanets); //Computer selects random planet
    printf("The computer has landed on planet %d.\n", computerNumber);

    if(checkWinLose(playerNumber, computerNumber)){
        printf("\nYou have saved humanity and completed your mission. Congratulations!");
    }else{
        printf("\nBetter luck next time!");
    }

    return 0;
}