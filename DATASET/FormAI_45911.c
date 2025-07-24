//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: automated
#include <stdio.h>
#include <stdlib.h>

const int WINNING_POSITIONS[8][3] = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6}
};

char board[9];

void print_board() {
    for(int i = 0; i < 9; i++) {
        if(board[i] == '\0')
            printf(" ");
        else
            printf("%c", board[i]);
        
        if(i == 2 || i == 5 || i == 8)
            printf("\n");
        else
            printf("|");
    }
}

int count_empty_slots() {
    int count = 0;
    for(int i = 0; i < 9; i++) {
        if(board[i] == '\0')
            count++;
    }
    return count;
}

int winner(char symbol) {
    for(int i = 0; i < 8; i++) {
        int pos1 = WINNING_POSITIONS[i][0];
        int pos2 = WINNING_POSITIONS[i][1];
        int pos3 = WINNING_POSITIONS[i][2];
        
        if(board[pos1] == symbol && board[pos2] == symbol && board[pos3] == symbol)
            return 1;
    }
    
    return 0;
}

char get_ai_move(char current_player) {
    char ai_symbol = current_player;
    char human_symbol = 'X';
    if(current_player == 'X')
        human_symbol = 'O';
    
    // Check if AI can win
    for(int i = 0; i < 9; i++) {
        if(board[i] == '\0') {
            board[i] = ai_symbol;
            if(winner(ai_symbol)) {
                return i + '0'; // Converting integer to character
            }
            else {
                board[i] = '\0';
            }
        }
    }
    
    // Check if human can win in next move, and block that move
    for(int i = 0; i < 9; i++) {
        if(board[i] == '\0') {
            board[i] = human_symbol;
            if(winner(human_symbol)) {
                return i + '0';
            }
            else {
                board[i] = '\0';
            }
        }
    }
    
    // Choose a move randomly
    while(1) {
        int random_index = rand() % 9;
        if(board[random_index] == '\0')
            return random_index + '0';
    }
}

void play_tic_tac_toe() {
    int game_over = 0;
    int current_player = 1; // 1 for human, 2 for AI
    
    while(!game_over) {
        print_board();
        
        if(current_player == 1) {
            // Human's turn
            char input;
            printf("\nEnter the position you want to play (1-9): ");
            scanf(" %c", &input);
            
            int index = input - '0';
            if(index < 1 || index > 9 || board[index-1] != '\0') {
                printf("Invalid position. Please try again.\n");
            }
            else {
                board[index-1] = 'X';
                if(winner('X')) {
                    printf("\nYou won!\n");
                    game_over = 1;
                }
                else if(count_empty_slots() == 0) {
                    printf("\nThe game is a tie!\n");
                    game_over = 1;
                }
                else {
                    current_player = 2; // AI's turn
                }
            }
        }
        else {
            // AI's turn
            char move = get_ai_move('O');
            board[move - '0'] = 'O';
            printf("\nAI played at position %c\n", move);
            if(winner('O')) {
                printf("\nAI won!\n");
                game_over = 1;
            }
            else if(count_empty_slots() == 0) {
                printf("\nThe game is a tie!\n");
                game_over = 1;
            }
            else {
                current_player = 1; // Human's turn
            }
        }
    }
    
    print_board();
}

int main() {
    for(int i = 0; i < 9; i++) {
        board[i] = '\0';
    }
    
    play_tic_tac_toe();
    
    return 0;
}