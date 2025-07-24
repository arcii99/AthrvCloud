//FormAI DATASET v1.0 Category: Memory Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define CARD_NUM 8

int flip_card(int card_index, int board[ROWS][COLS], int cards[CARD_NUM]);
void display_board(int board[ROWS][COLS]);
void shuffle_cards(int cards[CARD_NUM]);
void initialize_board(int board[ROWS][COLS], int cards[CARD_NUM]);

int main()
{
    int board[ROWS][COLS], cards[CARD_NUM];
    int flipped_cards[2] = {-1, -1};
    int correct_guesses = 0, attempts = 0, card_index;

    // seed random number generator
    srand(time(0));

    printf("Welcome to the Memory Game!!\n\n");
    printf("You will be shown a board with cards, and you need to match the cards by selecting two cards at a time.\n\n");

    // initialize game board and cards
    initialize_board(board, cards);

    // shuffle cards
    shuffle_cards(cards);

    // display initial board
    printf("Here are the cards on the board:\n\n");
    display_board(board);

    printf("Instructions: Enter the grid number of the card you want to flip (e.g. 1 2): ");

    // game loop
    while(correct_guesses < CARD_NUM)
    {
        // get user input and flip the card
        scanf("%d %d", &flipped_cards[0], &flipped_cards[1]);
        flipped_cards[0]--;
        flipped_cards[1]--;
        card_index = board[flipped_cards[0] / 2][flipped_cards[0] % 2];

        // check if card is valid
        if(flipped_cards[0] < 0 || flipped_cards[0] >= ROWS*COLS || flipped_cards[1] < 0 || flipped_cards[1] >= ROWS*COLS)
        {
            printf("Invalid selection. Try again. Enter the grid number of the card you want to flip (e.g. 1 2): ");
            continue;
        }

        // check if card has already been guessed correctly
        if(card_index == -1 || board[flipped_cards[1] / 2][flipped_cards[1] % 2] == -1)
        {
            printf("You already guessed that card correctly. Try again. Enter the grid number of the card you want to flip (e.g. 1 2): ");
            continue;
        }

        // flip card and update board display
        if(flip_card(card_index, board, cards))
        {
            correct_guesses++;
        }
        attempts++;
        display_board(board);
        printf("Correct guesses: %d\nAttempts: %d\n\n", correct_guesses, attempts);

        if(correct_guesses == CARD_NUM)
        {
            printf("Congratulations, you have won! It took you %d attempts to complete the game.\n", attempts);
            break;
        }

        printf("Enter the grid number of the card you want to flip (e.g. 1 2): ");
    }

    return 0;
}

// flip a card and return whether it was a correct guess
int flip_card(int card_index, int board[ROWS][COLS], int cards[CARD_NUM])
{
    static int flipped = 0;
    static int first_card = -1;
    int i, j;

    // flip card
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            if(board[i][j] == card_index)
            {
                board[i][j] = cards[card_index];
                printf("Flipping card %d: (%d,%d) -> %d\n", flipped+1, i+1, j+1, cards[card_index]);
                flipped++;
                break;
            }
        }
        if(flipped == 2)
        {
            break;
        }
    }

    // check if guess was correct
    if(first_card == -1)
    {
        first_card = card_index;
        return 0;
    }

    if(cards[first_card] == cards[card_index])
    {
        printf("You guessed correctly!\n");
        board[i][j] = -1;
        board[(first_card/2)*2 + (i/2)][(first_card%2)*2 + (j/2)] = -1;
        first_card = -1;
        return 1;
    }
    else
    {
        printf("Sorry, that was not a match.\n");
        board[i][j] = card_index;
        board[(first_card/2)*2 + (i/2)][(first_card%2)*2 + (j/2)] = first_card;
        first_card = -1;
        return 0;
    }
}

// display the board
void display_board(int board[ROWS][COLS])
{
    int i, j;

    printf("\n");

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            if(board[i][j] == -1)
            {
                printf("   ");
            }
            else
            {
                printf("%2d ", board[i][j]);
            }
        }
        printf("\n");
    }

    printf("\n");
}

// shuffle the cards
// adapted from https://stackoverflow.com/a/6127601/4365290
void shuffle_cards(int cards[CARD_NUM])
{
    int i, j, temp;
    for(i = CARD_NUM - 1; i > 0; i--)
    {
        j = rand() % (i + 1);
        temp = cards[j];
        cards[j] = cards[i];
        cards[i] = temp;
    }
}

// initialize the board and cards
void initialize_board(int board[ROWS][COLS], int cards[CARD_NUM])
{
    int i, j, k = 0;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            board[i][j] = k / 2;
            k++;
        }
    }

    for(i = 0; i < CARD_NUM; i++)
    {
        cards[i] = i;
    }
}