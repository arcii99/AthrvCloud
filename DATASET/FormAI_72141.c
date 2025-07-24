//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: single-threaded
// This is a game where the user tries to catch falling objects by moving a basket left or right using the arrow keys.
// The longer the user goes without missing an object, the faster the objects fall, making it more challenging.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

// define key codes for arrow keys
#define KEY_LEFT 68
#define KEY_RIGHT 67

// function to check if a key is pressed
int kbhit() {
    struct termios oldt, newt;
    int ch, oldf;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

int main() {
    // initialize variables
    int score = 0;
    int basket_pos = 38;
    int object_pos = rand() % 80;
    int object_speed = 1;
    int object_countdown = 10;
    int missed = 0;
    
    // seed random number generator
    srand(time(NULL));
    
    // set up terminal
    system("clear");
    printf("\033[?25l"); // hide cursor
    
    // main game loop
    while (1) {
        // move basket if arrow key is pressed
        if (kbhit()) {
            int key = getchar();
            if (key == KEY_LEFT && basket_pos > 0) {
                basket_pos--;
            } else if (key == KEY_RIGHT && basket_pos < 79) {
                basket_pos++;
            }
        }
        
        // move object down
        if (object_countdown == 0) {
            object_pos += object_speed;
            object_countdown = 10;
        } else {
            object_countdown--;
        }
        
        // check if object has been caught
        if (object_pos >= basket_pos && object_pos <= basket_pos + 9) {
            score++;
            object_speed++;
            object_pos = rand() % 80;
            missed = 0;
        }
        
        // check if object has missed basket
        if (object_pos >= 24 && object_pos <= 54) {
            if (missed == 3) {
                break;
            } else {
                missed++;
                score--;
                object_pos = rand() % 80;
            }
        }
        
        // print game screen
        system("clear");
        printf("Score: %d\n", score);
        for (int i = 0; i < 80; i++) {
            if (i >= basket_pos && i <= basket_pos + 9) {
                printf("=");
            } else if (i == object_pos) {
                printf("O");
            } else {
                printf(" ");
            }
        }
        
        // delay for smoother animation
        usleep(100000);
    }
    
    // print game over message
    system("clear");
    printf("\nGame over! Your score was: %d\n", score);
    printf("\033[?25h"); // show cursor
    
    return 0;
}