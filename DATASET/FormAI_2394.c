//FormAI DATASET v1.0 Category: Chess engine ; Style: thoughtful
#include <stdio.h>

//Board representation
int board[8][8] = 
{
    {-4,-2,-3,-5,-6,-3,-2,-4},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    { 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0},
    { 1, 1, 1, 1, 1, 1, 1, 1},
    { 4, 2, 3, 5, 6, 3, 2, 4}
};

//Display the current state of the board
void display_board()
{
    int i, j;

    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            switch(board[i][j])
            {
                case -6: printf("B "); break;
                case -5: printf("Q "); break;
                case -4: printf("R "); break;
                case -3: printf("N "); break;
                case -2: printf("B "); break;
                case -1: printf("P "); break;
                case 0: printf(". "); break;
                case 1: printf("P "); break;
                case 2: printf("N "); break;
                case 3: printf("B "); break;
                case 4: printf("R "); break;
                case 5: printf("Q "); break;
                case 6: printf("K "); break;
            }
        }

        printf("\n");
    }

    printf("\n");
}

//Check if the move is valid
int is_valid_move(int start_x, int start_y, int target_x, int target_y)
{
    //Make sure the target square isn't occupied by our own piece
    if(board[target_x][target_y] != 0 && board[start_x][start_y] > 0 && board[target_x][target_y] > 0)
        return 0;

    if(board[target_x][target_y] != 0 && board[start_x][start_y] < 0 && board[target_x][target_y] < 0)
        return 0;

    //Make sure the piece can move like that
    switch(board[start_x][start_y])
    {
        case 1: //Pawn
            if(target_y != start_y) //Moving diagonally (attacking)
            {
                if(board[target_x][target_y] == 0) //Make sure there's a piece to take
                    return 0;

                if(target_x == start_x - 1 || target_x == start_x + 1) //Make sure we're only moving one square diagonally
                    return 1;
            }
            else //Moving forward
            {
                if(board[target_x][target_y] != 0) //Make sure the target square is empty
                    return 0;

                if(target_x == start_x - 1 && board[start_x][start_y] > 0) //Black pieces move down the board (increasing row number)
                    return 1;

                if(target_x == start_x + 1 && board[start_x][start_y] < 0) //White pieces move up the board (decreasing row number)
                    return 1;
            }
            break;
        case 2: //Knight
            if((target_x == start_x - 2 && (target_y == start_y - 1 || target_y == start_y + 1)) ||
               (target_x == start_x - 1 && (target_y == start_y - 2 || target_y == start_y + 2)) ||
               (target_x == start_x + 1 && (target_y == start_y - 2 || target_y == start_y + 2)) ||
               (target_x == start_x + 2 && (target_y == start_y - 1 || target_y == start_y + 1)))
                return 1;
            else
                return 0;
            break;
        case 3: //Bishop
            if(target_x - start_x == target_y - start_y)
            {
                if(target_x > start_x) //Moving down the board
                {
                    int i;
                    for(i = 1; i < target_x - start_x; i++)
                    {
                        if(board[start_x + i][start_y + i] != 0)
                            return 0;
                    }

                    return 1;
                }
                else //Moving up the board
                {
                    int i;
                    for(i = 1; i < start_x - target_x; i++)
                    {
                        if(board[start_x - i][start_y - i] != 0)
                            return 0;
                    }

                    return 1;
                }
            }

            if(target_x - start_x == start_y - target_y)
            {
                if(target_x > start_x) //Moving down the board
                {
                    int i;
                    for(i = 1; i < target_x - start_x; i++)
                    {
                        if(board[start_x + i][start_y - i] != 0)
                            return 0;
                    }

                    return 1;
                }
                else //Moving up the board
                {
                    int i;
                    for(i = 1; i < start_x - target_x; i++)
                    {
                        if(board[start_x - i][start_y + i] != 0)
                            return 0;
                    }

                    return 1;
                }
            }

            return 0;
            break;
        case 4: //Rook
            if(target_x == start_x) //Moving horizontally
            {
                if(target_y > start_y) //Moving right
                {
                    int i;
                    for(i = start_y + 1; i < target_y; i++)
                    {
                        if(board[start_x][i] != 0)
                            return 0;
                    }

                    return 1;
                }
                else //Moving left
                {
                    int i;
                    for(i = start_y - 1; i > target_y; i--)
                    {
                        if(board[start_x][i] != 0)
                            return 0;
                    }

                    return 1;
                }
            }

            if(target_y == start_y) //Moving vertically
            {
                if(target_x > start_x) //Moving down
                {
                    int i;
                    for(i = start_x + 1; i < target_x; i++)
                    {
                        if(board[i][start_y] != 0)
                            return 0;
                    }

                    return 1;
                }
                else //Moving up
                {
                    int i;
                    for(i = start_x - 1; i > target_x; i--)
                    {
                        if(board[i][start_y] != 0)
                            return 0;
                    }

                    return 1;
                }
            }

            return 0;
            break;
        case 5: //Queen
            if(is_valid_move(start_x, start_y, target_x, target_y))
                return 1;

            if(target_x == start_x || target_y == start_y)
            {
                if(is_valid_move(start_x, start_y, target_x, start_y))
                    return 1;

                if(is_valid_move(start_x, start_y, start_x, target_y))
                    return 1;
            }

            return 0;
            break;
        case 6: //King
            if(target_x == start_x && target_y == start_y + 2) //Castling kingside
            {
                if(board[start_x][start_y + 1] != 0 || board[start_x][start_y + 2] != 0)
                    return 0;

                return 1;
            }

            if(target_x == start_x && target_y == start_y - 2) //Castling queenside
            {
                if(board[start_x][start_y - 1] != 0 || board[start_x][start_y - 2] != 0 || board[start_x][start_y - 3] != 0)
                    return 0;

                return 1;
            }

            if(abs(start_x - target_x) <= 1 && abs(start_y - target_y) <= 1) //Moving one square in any direction
                return 1;

            return 0;
            break;
        default:
            return 0;
            break;
    }
}

//Make the move
void make_move(int start_x, int start_y, int target_x, int target_y)
{
    //Castling kingside
    if(target_y == start_y + 2)
    {
        board[start_x][start_y + 1] = board[start_x][start_y + 3];
        board[start_x][start_y + 3] = 0;
    }

    //Castling queenside
    if(target_y == start_y - 2)
    {
        board[start_x][start_y - 1] = board[start_x][start_y - 4];
        board[start_x][start_y - 4] = 0;
    }

    //En passant
    if(board[start_x][start_y] == 1 && start_y != target_y && board[target_x][target_y] == 0)
        board[target_x + 1][target_y] = 0;

    if(board[start_x][start_y] == -1 && start_y != target_y && board[target_x][target_y] == 0)
        board[target_x - 1][target_y] = 0;

    //Make the move
    board[target_x][target_y] = board[start_x][start_y];
    board[start_x][start_y] = 0;
}

int main()
{
    //Start game loop
    int game_over = 0;
    int turn = 1; //1 = white, -1 = black
    while(!game_over)
    {
        printf("Current board:\n");
        display_board();

        printf("It is ");

        if(turn == 1)
            printf("white's turn.\n");
        else
            printf("black's turn.\n");

        //Get move from user
        char move[5];
        printf("Enter your move (in algebraic notation, e.g. e2-e4): ");
        scanf("%s", &move);

        //Translate move into coordinates
        int start_x = move[1] - '1';
        int start_y = move[0] - 'a';
        int target_x = move[4] - '1';
        int target_y = move[3] - 'a';

        //Make sure the move is valid
        if(is_valid_move(start_x, start_y, target_x, target_y))
        {
            make_move(start_x, start_y, target_x, target_y);
        }
        else
        {
            printf("Invalid move.\n");
            continue;
        }

        //Check for game over
        int i, j;
        int white_king = 0, black_king = 0;
        for(i = 0; i < 8; i++)
        {
            for(j = 0; j < 8; j++)
            {
                if(board[i][j] == 6)
                    white_king = 1;

                if(board[i][j] == -6)
                    black_king = 1;
            }
        }

        if(!white_king)
        {
            printf("Black wins!\n");
            game_over = 1;
        }

        if(!black_king)
        {
            printf("White wins!\n");
            game_over = 1;
        }

        //Switch turns
        turn *= -1;
    }

    return 0;
}