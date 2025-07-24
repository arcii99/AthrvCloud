//FormAI DATASET v1.0 Category: Table Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// define constants
#define BOARD_SIZE 10
#define NUM_PLAYERS 2
#define MAX_SHIP_SIZE 5
#define NUM_SHIPS 5

// define structs
typedef struct Player {
    char name[100];
    int score;
    char board[BOARD_SIZE][BOARD_SIZE];
    bool ships[NUM_SHIPS];
    int num_ships_left;
} Player;

// declare functions
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
bool is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col);
void place_ship(char board[BOARD_SIZE][BOARD_SIZE], int size);
void initialize_player(Player *p);
void print_player_info(Player *p);
void take_turn(Player *current, Player *opponent);
bool is_game_over(Player *p);
void congratulate_winner(Player *p);

int main() {
    srand(time(NULL)); // seed random number generator
    
    // create two players
    Player players[NUM_PLAYERS];
    for (int i = 0; i < NUM_PLAYERS; i++) {
        initialize_player(&players[i]);
        printf("Enter a name for player %d: ", i+1);
        fgets(players[i].name, 100, stdin);
    }
    
    // place ships on boards for each player
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("\n%s, place your ships:\n", players[i].name);
        for (int j = 0; j < NUM_SHIPS; j++) {
            int size = j+1;
            bool valid_placement = false;
            while (!valid_placement) {
                place_ship(players[i].board, size);
                if (rand() % 2 == 0) { // randomly flip ship horizontally or vertically
                    int row = rand() % BOARD_SIZE;
                    int col = rand() % (BOARD_SIZE - size + 1);
                    bool can_place = true;
                    for (int k = col; k < col+size; k++) {
                        if (!is_valid_move(players[i].board, row, k)) {
                            can_place = false;
                            break;
                        }
                    }
                    if (can_place) {
                        for (int k = col; k < col+size; k++) {
                            players[i].board[row][k] = 'O';
                        }
                        valid_placement = true;
                    }
                }
                else {
                    int row = rand() % (BOARD_SIZE - size + 1);
                    int col = rand() % BOARD_SIZE;
                    bool can_place = true;
                    for (int k = row; k < row+size; k++) {
                        if (!is_valid_move(players[i].board, k, col)) {
                            can_place = false;
                            break;
                        }
                    }
                    if (can_place) {
                        for (int k = row; k < row+size; k++) {
                            players[i].board[k][col] = 'O';
                        }
                        valid_placement = true;
                    }
                }
            }
            players[i].ships[size-1] = true; // mark that the player has this ship
            players[i].num_ships_left++;
            printf("Ship of size %d has been placed.\n", size);
        }
    }
    
    // main game loop
    int current_player = 0;
    while (!is_game_over(&players[current_player])) {
        printf("\n%s, it is your turn.\n", players[current_player].name);
        take_turn(&players[current_player], &players[(current_player+1)%NUM_PLAYERS]);
        current_player = (current_player+1) % NUM_PLAYERS;
    }
    
    // game over, congratulate winner
    congratulate_winner(&players[current_player]);
    
    return 0;
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %c ", i + 'A');
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i+1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("[%c]", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != '-') {
        return false;
    }
    return true;
}

void place_ship(char board[BOARD_SIZE][BOARD_SIZE], int size) {
    // randomly determine orientation
    if (rand() % 2 == 0) { // horizontal
        int row = rand() % BOARD_SIZE;
        int col = rand() % (BOARD_SIZE - size + 1);
        for (int i = col; i < col+size; i++) {
            board[row][i] = '-';
        }
    }
    else { // vertical
        int row = rand() % (BOARD_SIZE - size + 1);
        int col = rand() % BOARD_SIZE;
        for (int i = row; i < row+size; i++) {
            board[i][col] = '-';
        }
    }
}

void initialize_player(Player *p) {
    p->score = 0;
    p->num_ships_left = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            p->board[i][j] = '-';
        }
    }
    for (int i = 0; i < NUM_SHIPS; i++) {
        p->ships[i] = false;
    }
}

void print_player_info(Player *p) {
    printf("Name: %s\n", p->name);
    printf("Score: %d\n", p->score);
    printf("Ships remaining:");
    for (int i = 0; i < NUM_SHIPS; i++) {
        if (p->ships[i]) {
            printf(" %d", i+1);
        }
    }
    printf("\n");
}

void take_turn(Player *current, Player *opponent) {
    print_board(opponent->board);
    int row, col;
    bool valid_move = false;
    while (!valid_move) {
        printf("Enter a row and column to attack (e.g. 3 A): ");
        scanf("%d %c", &row, &col);
        getchar(); // clear newline character from input buffer
        row--; // convert to 0-indexed
        col = col - 'A'; // convert to 0-indexed
        if (is_valid_move(opponent->board, row, col)) {
            valid_move = true;
        }
        else {
            printf("Invalid move. Try again.\n");
        }
    }
    if (opponent->board[row][col] == 'O') {
        printf("Hit!\n");
        opponent->board[row][col] = 'X';
        current->score++;
        for (int i = 0; i < NUM_SHIPS; i++) {
            if (opponent->ships[i] && current->score == i+1) {
                opponent->ships[i] = false;
                opponent->num_ships_left--;
                printf("You've sunk a ship of size %d!\n", i+1);
            }
        }
    }
    else {
        printf("Miss.\n");
        opponent->board[row][col] = 'M';
    }
}

bool is_game_over(Player *p) {
    if (p->num_ships_left == 0) {
        return true;
    }
    return false;
}

void congratulate_winner(Player *p) {
    printf("\nCONGRATULATIONS, %s! YOU ARE THE WINNER!\n", p->name);
    printf("Final score: %d\n", p->score);
    printf("Final board:\n");
    print_board(p->board);
}