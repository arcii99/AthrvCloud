//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: puzzling
#include <stdio.h>

#define ROWS 10
#define COLS 10

int main() {

    int i, j;

    char puzzle[ROWS][COLS] = {
        {'C','O','D','I','N','G','I','S','F','U'},
        {'N','E','V','E','R','G','I','V','E','U'},
        {'P','E','N','S','A','N','D','P','A','P'},
        {'C','O','D','E','I','S','A','R','T','S'},
        {'E','A','S','Y','A','S','E','A','T','I'},
        {'H','A','C','K','I','N','G','I','S','F'},
        {'L','E','A','R','N','I','N','G','I','S'},
        {'I','M','P','O','R','T','A','N','T','B'},
        {'P','Y','T','H','O','N','I','S','F','U'},
        {'W','R','I','T','I','N','G','C','O','D'}
    };
  
    // display original puzzle
    printf("PUZZLE:\n");
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            printf("%c ", puzzle[i][j]);
        }
        printf("\n");
    }

    // ASCII art generator code
    printf("\n");
    printf("ASCII ART:\n");
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            if (puzzle[i][j] == 'C') {
                printf("* ");
            } else if (puzzle[i][j] == 'O') {
                printf("# ");
            } else if (puzzle[i][j] == 'D') {
                printf("@ ");
            } else if (puzzle[i][j] == 'I') {
                printf("%c ", 92);
            } else if (puzzle[i][j] == 'N') {
                printf("| ");
            } else if (puzzle[i][j] == 'G') {
                printf("+ ");
            } else if (puzzle[i][j] == 'F') {
                printf("- ");
            } else if (puzzle[i][j] == 'E') {
                printf("0 ");
            } else if (puzzle[i][j] == 'V') {
                printf("^ ");
            } else if (puzzle[i][j] == 'U') {
                printf("v ");
            } else if (puzzle[i][j] == 'P') {
                printf("& ");
            } else if (puzzle[i][j] == 'S') {
                printf("$ ");
            } else if (puzzle[i][j] == 'A') {
                printf("@ ");
            } else if (puzzle[i][j] == 'T') {
                printf("+ ");
            } else if (puzzle[i][j] == 'R') {
                printf("%c ", 92);
            } else if (puzzle[i][j] == 'H') {
                printf("# ");
            } else if (puzzle[i][j] == 'K') {
                printf("%c ", 92);
            } else if (puzzle[i][j] == 'L') {
                printf("' ");
            } else if (puzzle[i][j] == 'M') {
                printf("%c ", 92);
            } else if (puzzle[i][j] == 'Q') {
                printf("& ");
            } else if (puzzle[i][j] == 'Y') {
                printf("Y ");
            } else if (puzzle[i][j] == 'W') {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    
    return 0;
}