//FormAI DATASET v1.0 Category: Table Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 10
#define MAX_CHIPS 100

void displayTable(int table[]) {
    printf("Table: ");
    for(int i=0; i<TABLE_SIZE; i++) {
        printf("%d ", table[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); //initialize random seed

    int table[TABLE_SIZE] = {0}; //initialize table with all zeros
    int player1_chips = MAX_CHIPS, player2_chips = MAX_CHIPS;

    printf("Starting the game!\n");

    while(1) {
        //display table and player chips
        displayTable(table);
        printf("Player 1 chips: %d\n", player1_chips);
        printf("Player 2 chips: %d\n", player2_chips);

        //ask player 1 for input
        printf("Player 1, how many chips do you want to put on the table? ");
        int player1_input;
        scanf("%d", &player1_input);

        //check if player 1 input is valid
        if(player1_input<1 || player1_input>3) {
            printf("Invalid input! You can only put 1-3 chips on the table.\n");
            continue;
        }
        if(player1_input > player1_chips) {
            printf("You only have %d chips. Enter a valid input.\n", player1_chips);
            continue;
        }

        //subtract chips from player 1
        player1_chips -= player1_input;

        //add chips to the table
        for(int i=0; i<player1_input; i++) {
            //find a random index on the table that is not already occupied
            int index;
            do {
                index = rand() % TABLE_SIZE;
            } while(table[index] != 0);
            table[index] = 1;
        }

        //display updated table and player chips
        displayTable(table);
        printf("Player 1 chips: %d\n", player1_chips);
        printf("Player 2 chips: %d\n", player2_chips);

        //check if player 1 won
        int count = 0;
        for(int i=0; i<TABLE_SIZE; i++) {
            if(table[i] == 1) {
                count++;
            } else {
                count = 0;
            }
            if(count == 4) {
                printf("Player 1 Wins!\n");
                return 0;
            }
        }

        //ask player 2 for input
        printf("Player 2, how many chips do you want to put on the table? ");
        int player2_input;
        scanf("%d", &player2_input);

        //check if player 2 input is valid
        if(player2_input<1 || player2_input>3) {
            printf("Invalid input! You can only put 1-3 chips on the table.\n");
            continue;
        }
        if(player2_input > player2_chips) {
            printf("You only have %d chips. Enter a valid input.\n", player2_chips);
            continue;
        }

        //subtract chips from player 2
        player2_chips -= player2_input;

        //add chips to the table
        for(int i=0; i<player2_input; i++) {
            //find a random index on the table that is not already occupied
            int index;
            do {
                index = rand() % TABLE_SIZE;
            } while(table[index] != 0);
            table[index] = 2;
        }

        //display updated table and player chips
        displayTable(table);
        printf("Player 1 chips: %d\n", player1_chips);
        printf("Player 2 chips: %d\n", player2_chips);

        //check if player 2 won
        count = 0;
        for(int i=0; i<TABLE_SIZE; i++) {
            if(table[i] == 2) {
                count++;
            } else {
                count = 0;
            }
            if(count == 4) {
                printf("Player 2 Wins!\n");
                return 0;
            }
        }
    }

    return 0;
}