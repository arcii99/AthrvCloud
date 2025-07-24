//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 21
#define COLUMNS 22
#define GHOSTS 4

int main(){

    int i, j, x, y, n=0;
    char ch;

    // Initialize the random seed
    srand(time(NULL));

    // Pac-Man grid initialization
    char pacManGrid[ROWS][COLUMNS] = {
        "+++++++++++++++++++++",
        "+                   +",
        "+ ++++++++++ +++++ +",
        "+ +         + +    +",
        "+ + +++++++ + ++++ +",
        "+     +    +       +",
        "+++++ +++++++ ++++ +",
        "    +     +   +    +",
        "+++++ + + + ++++++++",
        "+        +          +",
        "+ +++++++++ +++++++ +",
        "+ +   +            +",
        "+ + + ++++ ++++++ + +",
        "+       +   +      +",
        "+ + +++++++ +++++ ++",
        "+ +          +     +",
        "+ +++++++ ++++++++++",
        "+                   +",
        "+++++++++++++++++++++"
    };

    // Ghosts initialization
    char ghosts[GHOSTS] = {'$','8','%','+'};

    // Place Pac-Man at a random location
    do {
        x = rand() % ROWS;
        y = rand() % COLUMNS;
    } while (pacManGrid[x][y] != ' ');

    pacManGrid[x][y] = '<';

    // Place ghosts at random locations
    for(i=0; i<GHOSTS; i++){
        do {
            x = rand() % ROWS;
            y = rand() % COLUMNS;
        } while (pacManGrid[x][y] != ' ');

        pacManGrid[x][y] = ghosts[i];
    }

    // Display the Pac-Man grid
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMNS; j++){
            printf("%c", pacManGrid[i][j]);
        }
        printf("\n");
    }

    // Main game loop
    while(n<20){

        // Check for keyboard input
        ch = getchar();

        // Move Pac-Man
        switch(ch){
            case 'w':
                if(pacManGrid[x-1][y] != '+'){
                    pacManGrid[x][y] = ' ';
                    pacManGrid[--x][y] = '^';
                }
                break;
            case 'a':
                if(pacManGrid[x][y-1] != '+'){
                    pacManGrid[x][y] = ' ';
                    pacManGrid[x][--y] = '<';
                }
                break;
            case 's':
                if(pacManGrid[x+1][y] != '+'){
                    pacManGrid[x][y] = ' ';
                    pacManGrid[++x][y] = 'v';
                }
                break;
            case 'd':
                if(pacManGrid[x][y+1] != '+'){
                    pacManGrid[x][y] = ' ';
                    pacManGrid[x][++y] = '>';
                }
                break;
            default:
                break;
        }

        // Move ghosts randomly
        for(i=0; i<GHOSTS; i++){
            switch(rand()%4){
                case 0:
                    if(pacManGrid[x-1][y] != '+'){
                        pacManGrid[x][y] = ' ';
                        pacManGrid[--x][y] = ghosts[i];
                    }
                    break;
                case 1:
                    if(pacManGrid[x][y-1] != '+'){
                        pacManGrid[x][y] = ' ';
                        pacManGrid[x][--y] = ghosts[i];
                    }
                    break;
                case 2:
                    if(pacManGrid[x+1][y] != '+'){
                        pacManGrid[x][y] = ' ';
                        pacManGrid[++x][y] = ghosts[i];
                    }
                    break;
                case 3:
                    if(pacManGrid[x][y+1] != '+'){
                        pacManGrid[x][y] = ' ';
                        pacManGrid[x][++y] = ghosts[i];
                    }
                    break;
                default:
                    break;
            }
        }

        // Display the Pac-Man grid
        system("clear"); // Only works in Linux/Unix/MacOS
        for(i=0; i<ROWS; i++){
            for(j=0; j<COLUMNS; j++){
                printf("%c", pacManGrid[i][j]);
            }
            printf("\n");
        }

        n++;
    }

    return 0;
}