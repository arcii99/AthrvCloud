//FormAI DATASET v1.0 Category: Game ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int user_input, computer_choice, counter = 0;
    char ch;

    printf("Welcome to the Ro-Sham-Bo World!\n");
    printf("Instructions:\n");
    printf("Choose:\n");
    printf("1 for Rock,\n");
    printf("2 for Scissors, and\n");
    printf("3 for Paper.\n");
    printf("\nThe opponent will choose too.\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &user_input);

        if(user_input < 1 || user_input > 3) {
            printf("Invalid Input! Please Try Again!\n");
            continue;
        }

        srand(time(0));
        computer_choice = rand() % 3 + 1;
        printf("Opponent's Choice: %d\n", computer_choice);

        counter++;

        if(user_input == computer_choice) {
            printf("It's a tie!\n");
        } else if(user_input == 1 && computer_choice == 2 || user_input == 2 && computer_choice == 3 || user_input == 3 && computer_choice == 1) {
            printf("Congratulations! You Won!\n");
        } else {
            printf("Oops! You Lost! Try Again!\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &ch);
    } while(ch == 'y' || ch == 'Y');

    printf("\nThanks for playing!\n");
    printf("You played %d games!\n", counter);

    return 0;
}