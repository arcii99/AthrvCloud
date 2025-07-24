//FormAI DATASET v1.0 Category: Funny ; Style: relaxed
#include <stdio.h>

int main() {
    int num, sum = 0, i;
    printf("Enter a number: ");
    scanf("%d", &num);
    for (i = 0; i <= num; i++) {
        if (i % 2 == 0) {
            sum += i;
        } else {
            continue;
        }
    }
    printf("The sum of all even numbers from 0 to %d is: %d\n", num, sum);

    printf("Now let's play a game of rock-paper-scissors!\n");
    printf("Enter your choice: (1 for rock, 2 for paper, 3 for scissors) \n");
    int player_choice, computer_choice = rand()%3 + 1;
    scanf("%d", &player_choice);

    if (player_choice == computer_choice) {
        printf("It's a tie!\n");
    } else if (player_choice == 1 && computer_choice == 3) {
        printf("You win! You chose rock and the computer chose scissors.\n");
    } else if (player_choice == 2 && computer_choice == 1) {
        printf("You win! You chose paper and the computer chose rock.\n");
    } else if (player_choice == 3 && computer_choice == 2) {
        printf("You win! You chose scissors and the computer chose paper.\n");
    } else {
        printf("You lost :( The computer chose %d\n", computer_choice);
    }

    printf("Now let's print out the lyrics to '99 Bottles of Beer'!\n");
    int bottles = 99;
    while (bottles >= 1) {
        printf("%d bottles of beer on the wall, %d bottles of beer.\n", bottles, bottles);
        printf("Take one down, pass it around, %d bottles of beer on the wall.\n\n", bottles-1);
        bottles--;
    }
    printf("No more bottles of beer on the wall, no more bottles of beer.\n");
    printf("Go to the store and buy some more, 99 bottles of beer on the wall.\n");

    return 0;
}