//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: detailed
#include <stdio.h>

#define ROW 30
#define COL 40

void clearScreen();
void displayMaze(char maze[][COL], int, int, int, int);
void movePacman(int *, int *, char[][COL], int, int *, int *, int *, int *);
void moveGhost(int *, int *, char[][COL], int, int *, int *, int *, int *);

int main()
{
    int score = 0;
    int lives = 3;
    int row = 23, col = 18;
    int ghostRow = 14, ghostCol = 16;
    int pacmanMoves = 0, ghostMoves = 0;
    int prevRow, prevCol, prevGhostRow, prevGhostCol;
    char maze[ROW][COL] = {"#######################################",
                           "#          #              #           #",
                           "# ### ##### # ### ###### # ### ##### #",
                           "# #      #  # # # #     # # # #   # #",
                           "# ###### ## # # ### ##### # # # # # #",
                           "# #    #    #   # #   #   # #   # # #",
                           "# # ## ##### ### # # # # # # ##### #",
                           "#     #     #   #   # # #   #       #",
                           "##### # ###### ### # # # ### ##### #",
                           "#       #     #     #   #     #     #",
                           "# ###### # # ###### # # # ####### ##",
                           "# #      # # #      # # # #       # #",
                           "# # ###### # # ###### # # # # # # #",
                           "# #    #   #   #      #   # # # # #",
                           "# # ## # ################# # # # #",
                           "# #    #        #          # # # # #",
                           "# ###### ########          # # # #",
                           "#          #                # # # #",
                           "# ###### # ##### ###### ### # # # #",
                           "# #      #   #   #    # #   # # # #",
                           "# # # ####### # # #### # ##### # #",
                           "# # # #      #   #    # #     #   #",
                           "# # ### ###### # ##### # ####### #",
                           "#   #  #   #   #   #   # #       #",
                           "### # ## ##### # # # #### # ##### #",
                           "#   #          #   #      #       #",
                           "#######################################"};

    displayMaze(maze, row, col, ghostRow, ghostCol);

    while (lives > 0)
    {
        prevRow = row;
        prevCol = col;
        prevGhostRow = ghostRow;
        prevGhostCol = ghostCol;

        movePacman(&row, &col, maze, score, &pacmanMoves, &ghostRow, &ghostCol, &lives);
        moveGhost(&ghostRow, &ghostCol, maze, score, &ghostMoves, &row, &col, &lives);

        if (prevRow != row || prevCol != col || prevGhostRow != ghostRow || prevGhostCol || ghostCol)
        {
            // Clear previous location of pacman and ghosts
            printf("\033[%d;%dH%c", prevRow, prevCol, maze[prevRow][prevCol]);
            printf("\033[%d;%dH%c", prevGhostRow, prevGhostCol, maze[prevGhostRow][prevGhostCol]);

            // Display pacman and ghosts in the new location
            printf("\033[%d;%dH%c", row, col, 'P');
            printf("\033[%d;%dH%c", ghostRow, ghostCol, 'G');
        }
    }

    return 0;
}

void clearScreen()
{
    printf("\033[2J");
}

void displayMaze(char maze[][COL], int row, int col, int ghostRow, int ghostCol)
{
    clearScreen();

    printf("\033[0;0H");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (i == row && j == col)
                printf("P");
            else if (i == ghostRow && j == ghostCol)
                printf("G");
            else
                printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void movePacman(int *row, int *col, char maze[][COL], int score, int *moves, int *ghostRow, int *ghostCol, int *lives)
{
    char direction;
    printf("Enter direction (WASD): ");
    scanf("%c", &direction);

    // Clear input buffer
    while (getchar() != '\n')
        ;

    int newRow = *row, newCol = *col;

    switch (direction)
    {
    case 'w':
    case 'W':
        newRow--;
        break;
    case 'a':
    case 'A':
        newCol--;
        break;
    case 's':
    case 'S':
        newRow++;
        break;
    case 'd':
    case 'D':
        newCol++;
        break;
    }

    if (maze[newRow][newCol] == ' ')
    {
        (*moves)++;
        *row = newRow;
        *col = newCol;
    }
    else if (maze[newRow][newCol] == '.')
    {
        (*moves)++;
        *row = newRow;
        *col = newCol;
        score++;
    }
    else if (maze[newRow][newCol] == 'G')
    {
        (*lives)--;
        displayMaze(maze, *row, *col, *ghostRow, *ghostCol);
    }
}

void moveGhost(int *ghostRow, int *ghostCol, char maze[][COL], int score, int *moves, int *row, int *col, int *lives)
{
    int newRow = *ghostRow, newCol = *ghostCol;
    int distanceFromPacman = abs(newRow - *row) + abs(newCol - *col);

    if (distanceFromPacman > 6)
    {
        switch (rand() % 4)
        {
        case 0:
            newRow--;
            break;
        case 1:
            newCol--;
            break;
        case 2:
            newRow++;
            break;
        case 3:
            newCol++;
            break;
        }
    }
    else
    {
        if (*row > *ghostRow)
            newRow++;
        else if (*row < *ghostRow)
            newRow--;

        if (*col > *ghostCol)
            newCol++;
        else if (*col < *ghostCol)
            newCol--;
    }

    if (maze[newRow][newCol] == ' ')
    {
        (*moves)++;
        *ghostRow = newRow;
        *ghostCol = newCol;
    }
    else if (maze[newRow][newCol] == '.')
    {
        (*moves)++;
        *ghostRow = newRow;
        *ghostCol = newCol;
        score++;
    }
    else if (maze[newRow][newCol] == 'P')
    {
        (*lives)--;
        displayMaze(maze, *row, *col, *ghostRow, *ghostCol);
    }
}