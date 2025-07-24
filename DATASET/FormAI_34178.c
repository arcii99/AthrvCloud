//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to clear the screen
void clrscr(){
    system("@cls||clear");
}

int main(){

    // define variables
    int user_score = 0;
    int comp_score = 0;
    int rounds, i;

    // initialize random seed
    srand(time(NULL));

    // welcome message
    printf("Welcome to Rock-Paper-Scissors game!\n\n");

    // ask user for number of rounds
    printf("Enter the number of rounds you want to play: ");
    scanf("%d", &rounds);

    // check validity of input
    if(rounds <= 0){
        printf("\nInvalid input. Please enter a positive integer.\n");
        return 1;
    }

    // start game
    for(i=1; i<=rounds; i++){

        // clear the screen
        clrscr();

        // display round number
        printf("Round %d\n\n", i);

        // display scores
        printf("Your score: %d\nComputer score: %d\n\n", user_score, comp_score);

        // ask user for choice
        int user_choice;
        printf("Choose your move:\n");
        printf("1: Rock\n2: Paper\n3: Scissors\n\n");
        printf("Enter your choice: ");
        scanf("%d", &user_choice);

        // check validity of input
        if(user_choice < 1 || user_choice > 3){
            printf("\nInvalid input. Please enter a valid choice (1-3).\n");
            return 1;
        }

        // get computer choice
        int comp_choice = rand() % 3 + 1;

        // display choices
        printf("\nYou chose ");

        switch(user_choice){
            case 1: printf("Rock\n"); break;
            case 2: printf("Paper\n"); break;
            case 3: printf("Scissors\n"); break;
        }

        printf("Computer chose ");

        switch(comp_choice){
            case 1: printf("Rock\n"); break;
            case 2: printf("Paper\n"); break;
            case 3: printf("Scissors\n"); break;
        }

        // determine winner and update scores
        if(user_choice == comp_choice){
            printf("\nIt's a tie!\n");
        }
        else if((user_choice == 1 && comp_choice == 3) || (user_choice == 2 && comp_choice == 1) || (user_choice == 3 && comp_choice == 2)){
            printf("\nYou win!\n");
            user_score++;
        }
        else{
            printf("\nComputer wins!\n");
            comp_score++;
        }

        // pause for user to read results
        getchar();
        printf("\nPress enter to continue...");
        getchar();
    }

    // clear the screen
    clrscr();

    // display final scores and winner
    printf("Final Scores:\n\n");
    printf("Your score: %d\nComputer score: %d\n\n", user_score, comp_score);

    if(user_score == comp_score){
        printf("It's a tie!\n");
    }
    else if(user_score > comp_score){
        printf("Congratulations! You win!\n");
    }
    else{
        printf("Sorry, you lose. Better luck next time!\n");
    }

    return 0;

}