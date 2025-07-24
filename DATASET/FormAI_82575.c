//FormAI DATASET v1.0 Category: Memory Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int attempts = 0;

void initializeBoard(int board[][COLS], int size);
void shuffle(int board[][COLS], int size);
void printBoard(int board[][COLS], int size);
int selectCard(int board[][COLS], int size, char* player);
void flipCard(int board[][COLS], int size, int row, int col);
int checkCards(int board[][COLS], int size);
void congratulations(char* player);

int main()
{
    int board[ROWS][COLS];
    initializeBoard(board, ROWS*COLS);
    shuffle(board, ROWS*COLS);
    printBoard(board, ROWS*COLS);
    char *player1 = "Player1";
    char *player2 = "Player2";

    while(1)
    {
        int row1 = selectCard(board, ROWS*COLS, player1);
        int col1 = selectCard(board, ROWS*COLS, player1);
        flipCard(board, ROWS*COLS, row1, col1);
        printBoard(board, ROWS*COLS);

        int row2 = selectCard(board, ROWS*COLS, player2);
        int col2 = selectCard(board, ROWS*COLS, player2);
        flipCard(board, ROWS*COLS, row2, col2);
        printBoard(board, ROWS*COLS);

        if(checkCards(board, ROWS*COLS))
        {
            congratulations(player1);
            break;
        }
        else if(attempts == ROWS*COLS*2)
        {
            printf("Tie!");
            break;
        }

        int row3 = selectCard(board, ROWS*COLS, player1);
        int col3 = selectCard(board, ROWS*COLS, player1);
        flipCard(board, ROWS*COLS, row3, col3);
        printBoard(board, ROWS*COLS);

        int row4 = selectCard(board, ROWS*COLS, player2);
        int col4 = selectCard(board, ROWS*COLS, player2);
        flipCard(board, ROWS*COLS, row4, col4);
        printBoard(board, ROWS*COLS);

        if(checkCards(board, ROWS*COLS))
        {
            congratulations(player2);
            break;
        }
        else if(attempts == ROWS*COLS*2)
        {
            printf("Tie!");
            break;
        }
    }

    return 0;
}

void initializeBoard(int board[][COLS], int size)
{
    int n = 1;
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            board[i][j] = n++;
        }
    }
}

void shuffle(int board[][COLS], int size)
{
    srand(time(0));
    for(int i=0; i<size; i++)
    {
        int x1 = rand() % ROWS;
        int y1 = rand() % COLS;

        int x2 = rand() % ROWS;
        int y2 = rand() % COLS;

        int temp = board[x1][y1];
        board[x1][y1] = board[x2][y2];
        board[x2][y2] = temp;
    }
}

void printBoard(int board[][COLS], int size)
{
    system("clear");
    printf("MEMORY GAME\n\n");

    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            if(board[i][j] == -1)
            {
                printf("-\t");
            }
            else
            {
                printf("%d\t", board[i][j]);
            }
        }
        printf("\n");
    }
}

int selectCard(int board[][COLS], int size, char* player)
{
    int row, col;
    do
    {
        attempts++;
        printf("%s - Enter the row and column (e.g. 1 2): ", player);
        scanf("%d %d", &row, &col);

        if(row > ROWS || col > COLS)
        {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        if(board[row-1][col-1] == -1)
        {
            printf("That card is already flipped. Please try again.\n");
            continue;
        }
        
        return row-1;
    }while(1);
}

void flipCard(int board[][COLS], int size, int row, int col)
{
    board[row][col] = -1;
}

int checkCards(int board[][COLS], int size)
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            if(board[i][j] != -1)
            {
                return 0;
            }
        }
    }

    return 1;
}

void congratulations(char* player)
{
    printf("Congratulations %s! You won in %d attempts.\n", player, attempts);
}