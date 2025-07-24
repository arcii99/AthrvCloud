//FormAI DATASET v1.0 Category: Table Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
int rollDice();

int main(){
    int ch, sum = 0;
    char name[30];
    printf("Welcome to the C Table Game!\n");
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Hi %s! Let's get started.\n", name);

    while(sum <= 50) {
        printf("Press 'r' to roll the dice: ");
        scanf(" %c", &ch);
        if(ch == 'r') {
            int num = rollDice();
            printf("You rolled a %d.\n", num);
            sum += num; 
            printf("Your current score is %d.\n", sum);
        } else {
            printf("Invalid input. Try again.\n");
        }
    }

    printf("Congratulations %s! You won with a score of %d.\n", name, sum);
    return 0;
}

int rollDice() {
    // seed random number generator
    srand(time(NULL));

    // generate random number between 1 and 6
    int num = (rand() % 6) + 1;

    return num;
}