//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: relaxed
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char playerName[20];

void introduction(){
    printf("\n\nWelcome to the Haunted House Simulator!");
    printf("\n\nWhat's your name? ");
    scanf("%s", playerName);
    printf("\nAlright, %s! Let's get started.\n", playerName);
}

void roomOne(){
    printf("\n%s, you find yourself standing in front of a large mansion. ", playerName);
    printf("The gates creak open and you decide to take a step inside.");
    printf("\nYou are in the main hallway, staring at two doors. ");
    printf("One to your left and one to your right. ");
    printf("Which one will you choose, %s?\n", playerName);

    char choice[10];
    scanf("%s", choice);

    if(strcmp(choice, "left") == 0){
        printf("\nYou enter the left room. ");
        printf("The room is completely black. ");
        printf("You cannot see anything. ");
        printf("Suddenly, you hear a strange noise but it's too dark to see anything. ");
        printf("You get scared and run out of the room. ");
        roomOne();
    }
    else if(strcmp(choice, "right") == 0){
        printf("\nYou enter the right room. ");
        printf("You see a small table with a quill and a parchment on it. ");
        printf("You read the parchment and it says: 'Enter the next room but beware'. ");
        printf("You decide to take the quill and parchment with you. ");
        printf("You enter the door and reach the next room.");
        roomTwo();
    }
    else{
        printf("\nInvalid choice. Please choose again: ");
        roomOne();
    }
}

void roomTwo(){
    printf("\n%s, you find yourself in a room with two doors again. ", playerName);
    printf("One to your left and one to your right. ");
    printf("Which one will you choose?\n");

    char choice[10];
    scanf("%s", choice);

    if(strcmp(choice, "left") == 0){
        printf("\nYou enter the left room. ");
        printf("You see a large crystal ball in the middle of the room. ");
        printf("Suddenly, the crystal ball starts glowing. ");
        printf("You see a vision of a ghostly figure. ");
        printf("You feel a chill run down your spine and decide to leave the room. ");
        roomTwo();
    }
    else if(strcmp(choice, "right") == 0){
        printf("\nYou enter the right room. ");
        printf("You see a small bookshelf in the corner of the room. ");
        printf("You decide to take a closer look. ");
        printf("You notice a book with a strange symbol on its cover. ");
        printf("You open the book and read the following: 'The key to exit the house is in one of the rooms. Find it before it's too late'.");
        printf("You close the book and take it with you, still looking for a way out of this house.");
        roomThree();
    }
    else{
        printf("Invalid choice. Please choose again: ");
        roomTwo();
    }
}

void roomThree(){
    printf("\n%s, you find yourself in yet another room with two doors. ", playerName);
    printf("You've got to be getting closer to the exit now! ");
    printf("Where to next?\n");

    char choice[10];
    scanf("%s", choice);

    if(strcmp(choice, "left") == 0){
        printf("\nYou enter the left room. ");
        printf("The room is completely empty. ");
        printf("You check the room, looking for something to help you exit the house. ");
        printf("You continue searching and eventually come across a key!");
        printf("You take the key and feel relieved. ");
        printf("You head to the other door in the room.");
        roomFour();
    }
    else if(strcmp(choice, "right") == 0){
        printf("\nYou enter the right room. ");
        printf("You are facing a large painting on the wall. ");
        printf("The painting shows a ghostly figure. ");
        printf("It feels like the figure is staring directly at you. ");
        printf("This is too much for you. You quickly exit the room and try the other door.");
        roomFour();
    }
    else{
        printf("\nInvalid choice. Please choose again: ");
        roomThree();
    }
}

void roomFour(){
    int random = rand() % 2;
    if(random == 0){
        printf("%s, you find yourself in a room with two doors. ", playerName);
        printf("You see a note on the floor. ");
        printf("The note reads: 'Go back to the entrance'.");
        printf("You decide to follow the instructions and make your way back to the entrance.");
        roomOne();
    }
    else{
        printf("\n%s, you finally reach the last room! ", playerName);
        printf("The door is locked. ");
        printf("You remember the key you found in the third room and use it to unlock the door. ");
        printf("You open the door and find yourself outside the haunted house. ");
        printf("You have successfully escaped! ");
        printf("Congratulations!");
        exit(0); // End the program
    }
}

int main(){
    srand(time(0)); // Seed for random number generation
    introduction();
    roomOne();
    return 0;
}