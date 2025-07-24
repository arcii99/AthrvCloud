//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to clear the screen
void clrscr() {
    system("@cls||clear");
}

int main() {
    // set up random seed
    srand(time(NULL));
    
    // initialize game variables
    int score = 0;
    int lives = 3;
    int level = 1;
    
    // print initial game screen
    clrscr();
    printf("You're playing Surprised!\n");
    printf("Instructions:\n");
    printf("Use arrow keys to catch the falling objects\n");
    printf("You have 3 lives and must reach 5 levels to win\n");
    printf("Press any key to start\n");
    getchar();
    clrscr();
    
    // main game loop
    while (1) {
        // print game stats
        printf("Score: %d | Lives: %d | Level: %d\n", score, lives, level);
        
        // generate random object
        int object = rand() % 3;
        char symbol;
        switch (object) {
            case 0:
                symbol = '*';
                break;
            case 1:
                symbol = '&';
                break;
            case 2:
                symbol = '$';
                break;
        }
        
        // print object
        printf("%c\n", symbol);
        
        // get user input
        char input = getchar();
        
        // check if caught object
        if (input == symbol) {
            score++;
        } else {
            lives--;
        }
        
        // check game over conditions
        if (lives == 0) {
            printf("Game over!\n");
            printf("Press any key to exit\n");
            getchar();
            exit(0);
        }
        
        if (score == 10) {
            level++;
            score = 0;
            printf("Congratulations, you beat level %d!\n", level-1);
        }
        
        if (level == 6) {
            printf("You won the game!\n");
            printf("Press any key to exit\n");
            getchar();
            exit(0);
        }
        
        // clear screen and repeat loop
        clrscr();
    }
    
    return 0;
}