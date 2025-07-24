//FormAI DATASET v1.0 Category: Funny ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Energizing C Program!\n");
    printf("This program will generate a random dance move for you to try out!\n");

    srand(time(NULL)); // initialize random seed

    // generate random dance move
    int move = rand() % 4;

    // perform dance move
    printf("Alright, here's your move!\n");

    switch(move) {
        case 0:
            printf("Jump up and down while waving your arms like a crazy person!\n");
            break;
        case 1:
            printf("Spin around like a figure skater and strike a pose!\n");
            break;
        case 2:
            printf("Do the robot dance and make robotic noises!\n");
            break;
        case 3:
            printf("Bust out some breakdance moves and show off your skills!\n");
            break;
        default:
            printf("Uh oh, something went wrong...try again later!\n");
    }

    printf("Thanks for trying out this program!\n");
    printf("Be sure to show off your sick dance moves to all your friends!\n");

    return 0;
}