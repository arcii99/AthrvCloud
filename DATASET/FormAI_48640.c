//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: recursive
#include <stdio.h>

int checkWin(char board[3][3]) {
  int i,j,statusCode=0;
  char symbol;

  for(i=0;i<3;i++) {
    /* Horizontal Check */
    if(board[i][0]==board[i][1] && board[i][1]==board[i][2]) {
      symbol=board[i][0];
      statusCode=1;
    }

    /* Vertical Check */
    if(board[0][i]==board[1][i] && board[1][i]==board[2][i]) {
      symbol=board[0][i];
      statusCode=1;
    }
  }

  /* Diagonal Check */
  if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) {
    symbol=board[0][0];
    statusCode=1;
  }
  if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) {
    symbol=board[0][2];
    statusCode=1;
  }

  if(statusCode==1) {
    if(symbol=='X')
      return 10;
    else
      return -10;
  }
  else
    return 0;
}

int isMovesLeft(char board[3][3])
{
    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            if (board[i][j]=='_')
                return 1;
    return 0;
}

int miniMax(char board[3][3], int depth, int isMax)
{
    int score = checkWin(board);

    if (score == 10)
        return score;

    if (score == -10)
        return score;

    if (isMovesLeft(board)==0)
        return 0;

    if (isMax)
    {
        int best = -1000;
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                if (board[i][j]=='_')
                {
                    board[i][j] = 'X';

                    best = fmax(best, miniMax(board, depth+1, !isMax));

                    board[i][j] = '_';
                }
            }
        }
        return best;
    }
    else
    {
        int best = 1000;
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                if (board[i][j]=='_')
                {
                    board[i][j] = 'O';

                    best = fmin(best, miniMax(board, depth+1, !isMax));

                    board[i][j] = '_';
                }
            }
        }
        return best;
    }
}

void findBestMove(char board[3][3])
{
    int bestVal = -1000;
    int row = -1;
    int col = -1;

    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            if (board[i][j]=='_')
            {
                board[i][j] = 'X';

                int moveVal = miniMax(board, 0, 0);

                board[i][j] = '_';

                if (moveVal > bestVal)
                {
                    row = i;
                    col = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    printf("The Best Move is: %d, %d with a score of %d\n", row, col, bestVal);
}

int main()
{
    char board[3][3] = {{'_', '_', '_'},
                        {'_', '_', '_'},
                        {'_', '_', '_'}} ;

    findBestMove(board);

    return 0;
}