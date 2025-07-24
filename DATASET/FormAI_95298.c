//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to delay execution of program
void delay(int seconds) {
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int main() {
    int player_pos = 5;
    int enemy_pos = 15;
    int score = 0;
    srand(time(NULL));

    printf("\nWelcome to Post-Apocalyptic Maze Runner!\n");
    printf("Instructions:\n");
    printf("\t- You are the player, represented by '*'\n");
    printf("\t- The enemy, represented by 'X', is trying to catch you\n");
    printf("\t- Move left or right with 'a' and 'd' respectively\n");
    printf("\t- Your objective is to gather as many points as possible\n");
    printf("\t- Each point scored will increase your speed\n");
    printf("\t- The game will end if the enemy catches up with you\n\n");

    printf("\t|-----------------------|\n");

    while(1) {
        // Print player and enemy positions
        printf("\t|");
        for(int i = 0; i < 20; i++) {
            if(i == player_pos) printf("*");
            else if(i == enemy_pos) printf("X");
            else printf(" ");
        }
        printf("|\n");

        // Randomly move enemy left or right
        int rand_num = rand() % 3;
        if(rand_num == 0) enemy_pos--;
        else if(rand_num == 1) enemy_pos++;
        delay(1000 / (score+1)); // Decrease delay time as score increases

        // Check for collision
        if(player_pos == enemy_pos) {
            printf("You were caught by the enemy! Game over.\n");
            printf("Final score: %d\n", score);
            break;
        }

        // Ask for input
        printf("Press 'a' to move left or 'd' to move right: ");
        char input;
        scanf("%c", &input);

        // Move player left or right
        if(input == 'a' && player_pos > 0) player_pos--;
        else if(input == 'd' && player_pos < 19) player_pos++;

        // Increase score and print message if point scored
        if(player_pos == enemy_pos - 1 || player_pos == enemy_pos + 1) {
            score++;
            printf("Point scored! Current score: %d\n", score);
        }

        // Clear input buffer
        while((getchar()) != '\n');
        
        // Clear screen for next iteration
        printf("\033[2J");
        printf("\033[%d;%dH", 0, 0);
    }

    return 0;
}