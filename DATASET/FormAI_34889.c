//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void travel();
void encounter();
void displayStats();
void gameover();

int fuel = 100;
int hull = 100;
int credits = 0;
int distance = 0;

int main() {
    srand(time(NULL));
    printf("Welcome to Procedural Space Adventure!\n");
    while (fuel > 0 && hull > 0 && distance < 50) {
        travel();
        encounter();
        displayStats();
    }
    gameover();
    return 0;
}

void travel() {
    int randomNum = rand() % 10 + 1;
    fuel -= randomNum;
    hull -= randomNum / 2;
    distance += randomNum;
    printf("Travelled %d light years\n", randomNum);
}

void encounter() {
    int randomNum = rand() % 3 + 1;
    int reward = rand() % 20 + 1;
    switch(randomNum) {
        case 1:
            printf("You encountered a friendly trader!\n");
            printf("They gave you %d credits for some fuel\n", reward);
            credits += reward;
            fuel += 20;
            break;
        case 2:
            printf("You encountered a hostile pirate!\n");
            printf("You lost %d credits and %d hull points\n", reward, reward*2);
            credits -= reward;
            hull -= reward*2;
            break;
        case 3:
            printf("You encountered a mysterious entity!\n");
            printf("It gave you %d fuel and %d hull points\n", reward, reward);
            fuel += reward;
            hull += reward;
            break;
        default:
            printf("Invalid encounter\n");
    }
}

void displayStats() {
    printf("\nFuel: %d\n", fuel);
    printf("Hull: %d\n", hull);
    printf("Credits: %d\n", credits);
    printf("Distance travelled: %d light years\n\n", distance);
}

void gameover() {
    if (fuel <= 0) {
        printf("You have run out of fuel and are now adrift in space\n");
    } else if (hull <= 0) {
        printf("Your ship has been destroyed\n");
    } else if (distance >= 50) {
        printf("Congratulations, you have successfully completed your mission!\n");
    } else {
        printf("Game over\n");
    }
}