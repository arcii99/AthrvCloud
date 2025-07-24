//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Cryptic
#include<stdio.h> //include the standard input/output library

#define BOARD_SIZE 3 //define the size of the board

char board[BOARD_SIZE][BOARD_SIZE]; //declare a 2-dimensional array to represent the board
int depth = 0; //initialize the depth of the game tree to 0

int is_game_won(char player); //declare the function to check if the game has been won
int evaluate(char player); //declare the function to evaluate the board
int minimax(int alpha, int beta, char player); //declare the minimax function

int main()
{
    int i, j, best_score, best_move; //declare the necessary variables
    char human_player = 'X', computer_player = 'O'; //set the player characters
    
    //initialize the board with blank spaces
    for(i = 0; i < BOARD_SIZE; i++)
    {
        for(j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }
    
    //main game loop
    while(!is_game_won(human_player) && !is_game_won(computer_player) && depth < BOARD_SIZE * BOARD_SIZE)
    {
        //display the board
        printf("\n  1 2 3\n");
        printf(" -------\n");
        for(i = 0; i < BOARD_SIZE; i++)
        {
            printf("%d|", i + 1);
            for(j = 0; j < BOARD_SIZE; j++)
            {
                printf("%c|", board[i][j]);
            }
            printf("\n -------\n");
        }
        
        //get human player move
        printf("Enter your move (row then column): ");
        scanf("%d %d", &i, &j);
        if(board[i-1][j-1] != ' ')
        {
            printf("Invalid move.\n");
            continue;
        }
        board[i-1][j-1] = human_player;
        depth++;
        
        //get computer player move
        best_score = -10000;
        best_move = 0;
        for(i = 0; i < BOARD_SIZE; i++)
        {
            for(j = 0; j < BOARD_SIZE; j++)
            {
                if(board[i][j] == ' ')
                {
                    board[i][j] = computer_player;
                    int score = minimax(-10000, 10000, human_player);
                    board[i][j] = ' ';
                    if(score > best_score)
                    {
                        best_score = score;
                        best_move = i * BOARD_SIZE + j;
                    }
                }
            }
        }
        i = best_move / BOARD_SIZE;
        j = best_move % BOARD_SIZE;
        board[i][j] = computer_player;
        depth++;
    }
    
    //display the final board and result
    if(is_game_won(human_player))
    {
        printf("\n  1 2 3\n");
        printf(" -------\n");
        for(i = 0; i < BOARD_SIZE; i++)
        {
            printf("%d|", i + 1);
            for(j = 0; j < BOARD_SIZE; j++)
            {
                printf("%c|", board[i][j]);
            }
            printf("\n -------\n");
        }
        printf("You win!\n");
    }
    else if(is_game_won(computer_player))
    {
        printf("\n  1 2 3\n");
        printf(" -------\n");
        for(i = 0; i < BOARD_SIZE; i++)
        {
            printf("%d|", i + 1);
            for(j = 0; j < BOARD_SIZE; j++)
            {
                printf("%c|", board[i][j]);
            }
            printf("\n -------\n");
        }
        printf("I win!\n");
    }
    else
    {
        printf("\n  1 2 3\n");
        printf(" -------\n");
        for(i = 0; i < BOARD_SIZE; i++)
        {
            printf("%d|", i + 1);
            for(j = 0; j < BOARD_SIZE; j++)
            {
                printf("%c|", board[i][j]);
            }
            printf("\n -------\n");
        }
        printf("It's a tie!\n");
    }
    
    return 0; //exit the program
}

//function to check if the game has been won
int is_game_won(char player)
{
    int i, j;
    
    //check rows
    for(i = 0; i < BOARD_SIZE; i++)
    {
        int row_count = 0;
        for(j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j] == player)
            {
                row_count++;
            }
        }
        if(row_count == BOARD_SIZE)
        {
            return 1;
        }
    }
    
    //check columns
    for(i = 0; i < BOARD_SIZE; i++)
    {
        int col_count = 0;
        for(j = 0; j < BOARD_SIZE; j++)
        {
            if(board[j][i] == player)
            {
                col_count++;
            }
        }
        if(col_count == BOARD_SIZE)
        {
            return 1;
        }
    }
    
    //check diagonals
    int diag_count = 0;
    for(i = 0; i < BOARD_SIZE; i++)
    {
        if(board[i][i] == player)
        {
            diag_count++;
        }
    }
    if(diag_count == BOARD_SIZE)
    {
        return 1;
    }
    
    diag_count = 0;
    for(i = 0; i < BOARD_SIZE; i++)
    {
        if(board[i][BOARD_SIZE-i-1] == player)
        {
            diag_count++;
        }
    }
    if(diag_count == BOARD_SIZE)
    {
        return 1;
    }
    
    return 0;
}

//function to evaluate the board
int evaluate(char player)
{
    int i, j;
    int score = 0;
    
    //check rows
    for(i = 0; i < BOARD_SIZE; i++)
    {
        int human_count = 0, computer_count = 0;
        for(j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j] == player)
            {
                computer_count++;
            }
            else if(board[i][j] != ' ')
            {
                human_count++;
            }
        }
        if(human_count == 0)
        {
            if(computer_count == 3)
            {
                score += 100;
            }
            else if(computer_count == 2)
            {
                score += 10;
            }
            else if(computer_count == 1)
            {
                score += 1;
            }
        }
        else if(computer_count == 0)
        {
            if(human_count == 3)
            {
                score -= 100;
            }
            else if(human_count == 2)
            {
                score -= 10;
            }
            else if(human_count == 1)
            {
                score -= 1;
            }
        }
    }
    
    //check columns
    for(i = 0; i < BOARD_SIZE; i++)
    {
        int human_count = 0, computer_count = 0;
        for(j = 0; j < BOARD_SIZE; j++)
        {
            if(board[j][i] == player)
            {
                computer_count++;
            }
            else if(board[j][i] != ' ')
            {
                human_count++;
            }
        }
        if(human_count == 0)
        {
            if(computer_count == 3)
            {
                score += 100;
            }
            else if(computer_count == 2)
            {
                score += 10;
            }
            else if(computer_count == 1)
            {
                score += 1;
            }
        }
        else if(computer_count == 0)
        {
            if(human_count == 3)
            {
                score -= 100;
            }
            else if(human_count == 2)
            {
                score -= 10;
            }
            else if(human_count == 1)
            {
                score -= 1;
            }
        }
    }
    
    //check diagonals
    int human_count = 0, computer_count = 0;
    for(i = 0; i < BOARD_SIZE; i++)
    {
        if(board[i][i] == player)
        {
            computer_count++;
        }
        else if(board[i][i] != ' ')
        {
            human_count++;
        }
    }
    if(human_count == 0)
    {
        if(computer_count == 3)
        {
            score += 100;
        }
        else if(computer_count == 2)
        {
            score += 10;
        }
        else if(computer_count == 1)
        {
            score += 1;
        }
    }
    else if(computer_count == 0)
    {
        if(human_count == 3)
        {
            score -= 100;
        }
        else if(human_count == 2)
        {
            score -= 10;
        }
        else if(human_count == 1)
        {
            score -= 1;
        }
    }
    
    human_count = 0;
    computer_count = 0;
    for(i = 0; i < BOARD_SIZE; i++)
    {
        if(board[i][BOARD_SIZE-i-1] == player)
        {
            computer_count++;
        }
        else if(board[i][BOARD_SIZE-i-1] != ' ')
        {
            human_count++;
        }
    }
    if(human_count == 0)
    {
        if(computer_count == 3)
        {
            score += 100;
        }
        else if(computer_count == 2)
        {
            score += 10;
        }
        else if(computer_count == 1)
        {
            score += 1;
        }
    }
    else if(computer_count == 0)
    {
        if(human_count == 3)
        {
            score -= 100;
        }
        else if(human_count == 2)
        {
            score -= 10;
        }
        else if(human_count == 1)
        {
            score -= 1;
        }
    }
    
    return score;
}

//minimax function
int minimax(int alpha, int beta, char player)
{
    int i, j, score;
    
    //check if game is over or depth limit has been reached
    if(is_game_won('X') || is_game_won('O') || depth >= BOARD_SIZE * BOARD_SIZE)
    {
        return evaluate(player);
    }
    
    //maximizing player (computer)
    if(player == 'O')
    {
        int best_score = -10000;
        for(i = 0; i < BOARD_SIZE; i++)
        {
            for(j = 0; j < BOARD_SIZE; j++)
            {
                if(board[i][j] == ' ')
                {
                    board[i][j] = player;
                    depth++;
                    score = minimax(alpha, beta, 'X');
                    board[i][j] = ' ';
                    depth--;
                    if(score > best_score)
                    {
                        best_score = score;
                    }
                    if(best_score > alpha)
                    {
                        alpha = best_score;
                    }
                    if(alpha >= beta)
                    {
                        return best_score;
                    }
                }
            }
        }
        return best_score;
    }
    //minimizing player (human)
    else
    {
        int best_score = 10000;
        for(i = 0; i < BOARD_SIZE; i++)
        {
            for(j = 0; j < BOARD_SIZE; j++)
            {
                if(board[i][j] == ' ')
                {
                    board[i][j] = player;
                    depth++;
                    score = minimax(alpha, beta, 'O');
                    board[i][j] = ' ';
                    depth--;
                    if(score < best_score)
                    {
                        best_score = score;
                    }
                    if(best_score < beta)
                    {
                        beta = best_score;
                    }
                    if(beta <= alpha)
                    {
                        return best_score;
                    }
                }
            }
        }
        return best_score;
    }
}