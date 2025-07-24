//FormAI DATASET v1.0 Category: Memory Game ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 4
#define COLS 4
#define MAX_VALUE 8

void initialize_board(int board[][COLS], int rows, int cols);
void print_board(int board[][COLS], int rows, int cols);
void shuffle(int *array, size_t n);
void swap(int *a, int *b);
int validate_input(int *x, int *y);
void process_guess(int game_board[][COLS], int solution_board[][COLS], int *x, int *y);
int check_win(int board[][COLS], int rows, int cols);

int main()
{
    int solution_board[ROWS][COLS];
    int game_board[ROWS][COLS];
    int selected[2];
    int data[MAX_VALUE * 2];
    int count = 0;
    
    //initialize random seed
    srand(time(NULL));
    
    //initialize the solution board
    initialize_board(solution_board, ROWS, COLS);
    
    //copy the solution board into the game board
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            game_board[i][j] = solution_board[i][j];
        }
    }
    
    //create an array of values that will be used for the game board
    for(int i = 1; i <= MAX_VALUE; i++)
    {
        data[count++] = i;
        data[count++] = i;
    }
    
    //shuffle the array to avoid predictable game boards
    shuffle(data, MAX_VALUE * 2);
    
    //populate the game board with the shuffled values
    count = 0;
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            game_board[i][j] = data[count++];
        }
    }
    
    //print the initial board
    print_board(game_board, ROWS, COLS);
    
    //start the game loop
    while(!check_win(game_board, ROWS, COLS))
    {
        printf("Enter the row and column of the card you want to flip: ");
        scanf("%d %d", &selected[0], &selected[1]);
        
        //validate the user's input
        if(validate_input(&selected[0], &selected[1]) == 0)
        {
            printf("Invalid input. Please try again.\n");
        }
        else
        {
            //process the user's guess
            process_guess(game_board, solution_board, &selected[0], &selected[1]);
            print_board(game_board, ROWS, COLS);
        }
    }
    
    printf("Congratulations! You win!\n");
    
    return 0;
}

//initialize the board with zeros
void initialize_board(int board[][COLS], int rows, int cols)
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            board[i][j] = 0;
        }
    }
}

//print the current state of the board
void print_board(int board[][COLS], int rows, int cols)
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(board[i][j] == 0)
            {
                printf("[] ");
            }
            else
            {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

//shuffle an array of integers
void shuffle(int *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          swap(&array[j], &array[i]);
        }
    }
}

//swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//validate user input
int validate_input(int *x, int *y)
{
    if(*x < 1 || *y < 1 ||
       *x > ROWS || *y > COLS)
    {
        return 0;
    }
    return 1;
}

//process a guess from the user
void process_guess(int game_board[][COLS], int solution_board[][COLS], int *x, int *y)
{
    int row = *x - 1;
    int col = *y - 1;
    
    //check if the user has already flipped this card
    if(game_board[row][col] != 0)
    {
        printf("You have already flipped that card. Try again.\n");
    }
    else
    {
        game_board[row][col] = solution_board[row][col];
        
        //check if the second card matches
        if(game_board[row][col] == game_board[row-1][col] ||
           game_board[row][col] == game_board[row+1][col] ||
           game_board[row][col] == game_board[row][col-1] ||
           game_board[row][col] == game_board[row][col+1])
        {
            printf("Nice match!\n");
        }
        else
        {
            printf("Sorry, that card does not match. Try again.\n");
            game_board[row][col] = 0;
        }
    }
}

//check if the game is won
int check_win(int board[][COLS], int rows, int cols)
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(board[i][j] == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}