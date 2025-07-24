//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>

char getChar() { //Function to get keyboard inputs without waiting for Enter key press
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int main() {
    srand(time(NULL));
    int score = 0; //Initialize score to 0
    bool gameOver = false;
    int speed = 500000; //Initialize initial speed of game
    int x = 10, y = 10; //Initialize position of player
    int fruitX, fruitY; //Declare variables to store position of fruit
    int width = 20, height = 20; //Width and Height of Game Board
    int tailX[100], tailY[100]; //Arrays to store positions of the tail
    int nTail = 0; //Variable to store length of tail
    char inputChar = ' '; //Variable to store keyboard input
    int dir = 0; //Variable to store direction of movement of player
    //0 - Stop, 1 - Up, 2 - Down, 3 - Left, 4 - Right
    system("clear"); //Clear the screen
    
    //Game Loop
    while (!gameOver) {
        //Generate Position of Fruit
        fruitX = rand() % (width-2) + 1;
        fruitY = rand() % (height-2) + 1;
        //Generate Fruit
        printf("\033[%d;%dH", fruitY, fruitX); //Move to Position of Fruit
        printf("@"); //Print Fruit
        
        //Read Keyboard Input
        usleep(speed); //Introduce Delay
        dir = (inputChar == 'w' || inputChar == 'W')? 1 : ((inputChar == 's' || inputChar == 'S')? 2 : ((inputChar == 'a' || inputChar == 'A')? 3 : ((inputChar == 'd' || inputChar == 'D')? 4 : dir)));
        //Check Direction of Movement
        switch(dir) {
            case 0: //Stop
                break;
            case 1: //Up
                y--;
                break;
            case 2: //Down
                y++;
                break;
            case 3: //Left
                x--;
                break;
            case 4: //Right
                x++;
                break;
        }
        
        if (x > width - 2 || x < 1 || y > height - 2 || y < 1) { //Check for Boundary Collision
            gameOver = true;
        }
        for (int i = 0; i < nTail; i++) { //Check for Tail Collision
            if (tailX[i] == x && tailY[i] == y) {
                gameOver = true;
            }
        }
        if (x == fruitX && y == fruitY) { //If Player eats Fruit
            score += 10;
            nTail++; //Increase Tail Length
            speed -= 10000; //Increase Speed of Game
        }
        
        //Update Tail Positions
        int prevX = tailX[0], prevY = tailY[0], tempX, tempY;
        tailX[0] = x;
        tailY[0] = y;
        for (int i = 1; i < nTail; i++) {
            tempX = tailX[i];
            tempY = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = tempX;
            prevY = tempY;
        }
        
        //Print Game Board
        printf("\033[0;0H");//Move to Top Left Corner of Screen
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == 0 || i == height - 1) { //Print Top and Bottom Boundary
                    printf("#");
                }
                else if (j == 0 || j == width - 1) { //Print Left and Right Boundary
                    printf("#");
                }
                else if (i == y && j == x) { //Print Player
                    printf("O");
                }
                else if (i == fruitY && j == fruitX) { //Print Fruit
                    printf("@");
                }
                else { //Print Tail
                    bool printTail = false;
                    for (int k = 0; k < nTail; k++) {
                        if (tailX[k] == j && tailY[k] == i) {
                            printf("o");
                            printTail = true;
                        }
                    }
                    if (!printTail) {
                        printf(" ");
                    }
                }
            }
            printf("\n");
        }
        
        //Print Score
        printf("Score: %d", score);
        
        //Get Keyboard Input
        inputChar = getChar();
    }
    printf("\nGame Over!\nFinal Score: %d", score);
    return 0;
}