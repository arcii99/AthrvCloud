//FormAI DATASET v1.0 Category: Dice Roller ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random number between 1 and 6
int roll_dice() {
    int num = (rand() % 6) + 1;
    return num;
}

// function to print dice
void print_dice(int num) {
    switch(num) {
        case 1:
            printf("+---------+\n");
            printf("|         |\n");
            printf("|    O    |\n");
            printf("|         |\n");
            printf("+---------+\n");
            break;
        case 2:
            printf("+---------+\n");
            printf("| O       |\n");
            printf("|         |\n");
            printf("|       O |\n");
            printf("+---------+\n");
            break;
        case 3:
            printf("+---------+\n");
            printf("| O       |\n");
            printf("|    O    |\n");
            printf("|       O |\n");
            printf("+---------+\n");
            break;
        case 4:
            printf("+---------+\n");
            printf("| O     O |\n");
            printf("|         |\n");
            printf("| O     O |\n");
            printf("+---------+\n");
            break;
        case 5:
            printf("+---------+\n");
            printf("| O     O |\n");
            printf("|    O    |\n");
            printf("| O     O |\n");
            printf("+---------+\n");
            break;
        case 6:
            printf("+---------+\n");
            printf("| O     O |\n");
            printf("| O     O |\n");
            printf("| O     O |\n");
            printf("+---------+\n");
            break;
    }
}

int main() {
    // seed the random number generator
    srand(time(NULL));
    
    // loop until user wants to quit
    while(1) {
        printf("Press Enter to Roll the Dice (Q to Quit): ");
        char c = getchar();
        
        // if user wants to quit, exit the program
        if(c == 'q' || c == 'Q') {
            printf("Exiting Program...\n");
            break;
        }
        
        // roll the dice and print the result
        int dice_num = roll_dice();
        printf("You got a %d!\n\n", dice_num);
        print_dice(dice_num);
    }
    
    return 0;
}