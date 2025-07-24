//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Defining constants
#define ROWS 5
#define COLS 5
#define SHIPS 3

// Defining global variables
int totalShips = SHIPS;
int userBoard[ROWS][COLS];
int compBoard[ROWS][COLS];
int userShips[SHIPS];
int compShips[SHIPS];

// Function prototypes
void intro();
void initializeBoard(int board[][COLS], int rows);
void displayBoard(int board[][COLS], int rows);
void placeShips(int board[][COLS], int rows, int ships, int player);
void getUserInput(int *row, int *col);
int checkShot(int board[][COLS], int row, int col);
void userTurn();
void compTurn();
void game();

// Main function
int main()
{
    srand(time(NULL)); // Initializing random seed
    intro(); // Displaying game introduction
    initializeBoard(userBoard, ROWS); // Initializing user board
    initializeBoard(compBoard, ROWS); // Initializing computer board
    placeShips(userBoard, ROWS, SHIPS, 1); // Placing user ships
    placeShips(compBoard, ROWS, SHIPS, 0); // Placing computer ships
    game(); // Starting game
    return 0;
}

// Function to display game introduction
void intro()
{
    printf("*** BATTLESHIP GAME ***\n\n");
    printf("You have %d ships to place on a %d by %d board.\n", SHIPS, ROWS, COLS);
    printf("The computer will also place %d ships on the board.\n", SHIPS);
    printf("The first player to sink all the opponent's ships wins the game.\n\n");
}

// Function to initialize board
void initializeBoard(int board[][COLS], int rows)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            board[i][j] = 0; // Marking all positions with 0 to indicate empty
        }
    }
}

// Function to display board
void displayBoard(int board[][COLS], int rows)
{
    printf("  ");
    for(int i=1; i<=COLS; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for(int i=0; i<rows; i++)
    {
        printf("%c ", 'A' + i);
        for(int j=0; j<COLS; j++)
        {
            if(board[i][j] == 0)
            {
                printf(". ");
            }
            else if(board[i][j] == 1)
            {
                printf("S ");
            }
            else if(board[i][j] == 2)
            {
                printf("O ");
            }
        }
        printf("\n");
    }
}

// Function to place ships on board
void placeShips(int board[][COLS], int rows, int ships, int player)
{
    int i, j, k, placed, length;
    for(k=0; k<ships; k++)
    {
        length = rand() % 3 + 2; // Generating ship length randomly between 2 and 4
        placed = 0;
        if(player == 1) // User's turn
        {
            while(!placed)
            {
                printf("Enter the starting position for a ship of length %d: ", length);
                scanf("%d %d", &i, &j);
                if(i<0 || i>=rows || j<0 || j>=COLS) // Checking if input is within board limits
                {
                    printf("Invalid position. Please try again.\n");
                }
                else if((j+length-1)>=COLS) // Checking if ship will fit within board limits
                {
                    printf("Ship will go out of board. Please try again.\n");
                }
                else // Placing the ship
                {
                    for(int l=0; l<length; l++)
                    {
                        if(board[i][j+l] != 0) // Checking if position is already occupied
                        {
                            printf("Position already occupied. Please try again.\n");
                            break;
                        }
                        else if(l == length-1) // Placing the ship if all positions are empty
                        {
                            for(int m=0; m<length; m++)
                            {
                                board[i][j+m] = 1;
                            }
                            placed = 1;
                            userShips[k] = length; // Storing user ship lengths
                        }
                    }
                }
            }
        }
        else // Computer's turn
        {
            while(!placed)
            {
                i = rand() % rows;
                j = rand() % COLS;
                if((j+length-1)<COLS) // Checking if ship will fit within board limits
                {
                    for(int l=0; l<length; l++)
                    {
                        if(board[i][j+l] != 0) // Checking if position is already occupied
                        {
                            break;
                        }
                        else if(l == length-1) // Placing the ship if all positions are empty
                        {
                            for(int m=0; m<length; m++)
                            {
                                board[i][j+m] = 1;
                            }
                            placed = 1;
                            compShips[k] = length; // Storing computer ship lengths
                        }
                    }
                }
            }
        }
    }
    printf("\n");
    if(player == 1) // Displaying user board after placing ships
    {
        printf("Your board:\n");
        displayBoard(userBoard, ROWS);
        printf("\n");
    }
}

// Function to get user input for shooting
void getUserInput(int *row, int *col)
{
    printf("Enter the position to shoot: ");
    scanf("%d %d", row, col);
}

// Function to check shot and return result
int checkShot(int board[][COLS], int row, int col)
{
    if(board[row][col] == 0) // Miss
    {
        board[row][col] = 2;
        printf("You missed!\n");
        return 0;
    }
    else if(board[row][col] == 1) // Hit
    {
        board[row][col] = 2;
        printf("You hit a ship!\n");
        return 1;
    }
    else // Already guessed
    {
        printf("You already guessed this position. Please try again.\n");
        return -1;
    }
}

// Function to execute user's turn
void userTurn()
{
    int row, col, result;
    do
    {
        getUserInput(&row, &col);
        result = checkShot(compBoard, row, col);
    }
    while(result == -1); // Loop until valid shot is made
    if(result == 1) // Decreasing computer's ship count
    {
        totalShips--;
        for(int i=0; i<SHIPS; i++)
        {
            if(compShips[i] > 0)
            {
                compShips[i]--;
                if(compShips[i] == 0)
                {
                    printf("You destroyed a ship!\n");
                }
            }
        }
    }
}

// Function to execute computer's turn
void compTurn()
{
    int row, col, result;
    do
    {
        row = rand() % ROWS;
        col = rand() % COLS;
        result = checkShot(userBoard, row, col);
    }
    while(result == -1); // Loop until valid shot is made
    if(result == 1) // Decreasing user's ship count
    {
        for(int i=0; i<SHIPS; i++)
        {
            if(userShips[i] > 0)
            {
                userShips[i]--;
                if(userShips[i] == 0)
                {
                    printf("You lost a ship!\n");
                }
            }
        }
    }
}

// Function to execute game
void game()
{
    int turn = 1;
    while(totalShips > 0) // Loop until all ships of one player are sunk
    {
        if(turn == 1) // User's turn
        {
            printf("Your turn:\n");
            displayBoard(compBoard, ROWS); // Displaying computer board to user
            userTurn();
            printf("\n");
        }
        else // Computer's turn
        {
            printf("Computer's turn:\n");
            compTurn();
            printf("\n");
        }
        turn = !turn; // Changing turn
    }
    if(turn == 1) // Computer wins
    {
        printf("You have lost the game. Better luck next time!\n");
    }
    else // User wins
    {
        printf("Congratulations! You have won the game!\n");
    }
}