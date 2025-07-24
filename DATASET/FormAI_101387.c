//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: introspective
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

//function to display the welcome message
void displayWelcomeMessage(){
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Press any key to enter the house...\n");
    getchar();  //wait for user input
    system("cls");  //clear screen
}

//function to randomly generate a room number (1-10)
int generateRoomNumber(){
    srand(time(NULL));  //initialize random seed
    return (rand() % 10) + 1;  //generate random number between 1-10
}

//function to simulate a haunted room
void simulateRoom(int roomNumber){
    printf("You enter room %d...\n", roomNumber);
    sleep(2); //wait for 2 seconds to build suspense
    int ghostProb = (rand() % 100) + 1;  //generate random number between 1-100
    if(ghostProb > 50){
        printf("You encounter a ghost in this room!\n");
    }
    else{
        printf("This room seems safe...for now.\n");
    }
    printf("Press any key to continue...\n");
    getchar();  //wait for user input
    system("cls");  //clear screen
}

//function to play the game
void playGame(){
    bool gameOver = false;
    int roomNumber = 1;
    while(!gameOver){
        simulateRoom(roomNumber);
        if(roomNumber == 10){
            printf("Congratulations! You have escaped the haunted house!\n");
            gameOver = true;
        }
        else{
            roomNumber++;
        }
    }
}

int main(){
    displayWelcomeMessage();
    playGame();
    return 0;
}