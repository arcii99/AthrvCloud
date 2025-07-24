//FormAI DATASET v1.0 Category: Memory Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void print_board(int board[][COLS]);
void initialize_board(int board[][COLS]);
void shuffle(int cards[], int n);
void clear_screen();

int main()
{
    int board[ROWS][COLS] = {{0}};
    int cards[ROWS * COLS / 2];
    
    srand(time(NULL));
    
    // Fill the cards array with values 1 to 8
    for(int i = 0; i < ROWS * COLS / 2; i++){
        cards[i * 2] = cards[i * 2 + 1] = i + 1;
    }
    
    // Shuffle the cards
    shuffle(cards, ROWS * COLS / 2);
    
    // Fill the board with the shuffled cards
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            board[i][j] = cards[i * COLS + j];
        }
    }
    
    // Print the initial board
    clear_screen();
    print_board(board);
    
    // Wait for the player to press enter to start the game
    printf("\n\nPress Enter to start the game...");
    getchar();
    
    // Clear the screen and hide the board
    clear_screen();
    printf("Memory Game\n\n");
    
    // Keep track of the cards that have been uncovered
    int uncovered[ROWS][COLS] = {{0}};
    int num_uncovered = 0;
    int row1, col1, row2, col2;
    
    // Loop until the player has uncovered all the cards
    while(num_uncovered < ROWS * COLS){
        // Print the board with only the uncovered cards visible
        print_board_with_uncovered_cards(board, uncovered);
        
        // Get the first card
        printf("Enter the row and column of the first card: ");
        scanf("%d %d", &row1, &col1);
        while(uncovered[row1][col1]){ // Make sure the card is not already uncovered
            printf("This card is already uncovered. Please enter the row and column of another card: ");
            scanf("%d %d", &row1, &col1);
        }
        uncovered[row1][col1] = 1;
        num_uncovered++;
        
        // Print the board with the first card uncovered
        clear_screen();
        printf("Memory Game\n\n");
        print_board_with_uncovered_cards(board, uncovered);
        
        // Get the second card
        printf("Enter the row and column of the second card: ");
        scanf("%d %d", &row2, &col2);
        while(uncovered[row2][col2]){ // Make sure the card is not already uncovered
            printf("This card is already uncovered. Please enter the row and column of another card: ");
            scanf("%d %d", &row2, &col2);
        }
        uncovered[row2][col2] = 1;
        num_uncovered++;
        
        // Print the board with the second card uncovered
        clear_screen();
        printf("Memory Game\n\n");
        print_board_with_uncovered_cards(board, uncovered);
        
        // Check if the two cards are a match
        if(board[row1][col1] == board[row2][col2]){
            printf("Match!\n");
        } else {
            printf("No match.\n");
            // Cover the cards again
            uncovered[row1][col1] = 0;
            uncovered[row2][col2] = 0;
            num_uncovered -= 2;
        }
        
        // Wait for the player to press enter to continue
        printf("Press Enter to continue...");
        getchar();
        getchar();
        
        // Clear the screen
        clear_screen();
    }
    
    // Print the final board
    printf("You won!\n");
    print_board(board);
    
    return 0;
}

// Prints the entire board, with all cards visible
void print_board(int board[][COLS])
{
    printf("  ");
    for(int j = 0; j < COLS; j++){
        printf("%d ", j);
    }
    printf("\n");
    for(int i = 0; i < ROWS; i++){
        printf("%d ", i);
        for(int j = 0; j < COLS; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Initializes the board with all cards face down
void initialize_board(int board[][COLS])
{
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            board[i][j] = -1;
        }
    }
}

// Shuffles an array of integers using the Fisher-Yates algorithm
void shuffle(int cards[], int n)
{
    for(int i = n - 1; i > 0; i--){
        int j = rand() % (i + 1);
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

// Clears the console screen
void clear_screen()
{
    system("clear || cls");
}

// Prints the board with only the uncovered cards visible
void print_board_with_uncovered_cards(int board[][COLS], int uncovered[][COLS])
{
    printf("  ");
    for(int j = 0; j < COLS; j++){
        printf("%d ", j);
    }
    printf("\n");
    for(int i = 0; i < ROWS; i++){
        printf("%d ", i);
        for(int j = 0; j < COLS; j++){
            if(uncovered[i][j]){
                printf("%d ", board[i][j]);
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }
}