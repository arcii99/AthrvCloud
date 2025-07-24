//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define HUMAN_PLAYER 1
#define COMPUTER_PLAYER 2
#define BOARD_SIZE 3
#define WIN_CONDITIONS 8
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int board[BOARD_SIZE][BOARD_SIZE];

typedef struct ComponentSystem {
    int num_components;
    int indexes[BOARD_SIZE * BOARD_SIZE];
} ComponentSystem;

typedef struct WinCondition {
    ComponentSystem row;
    ComponentSystem column;
    ComponentSystem diagonal1;
    ComponentSystem diagonal2;
} WinCondition;

WinCondition win_conditions[WIN_CONDITIONS];

ComponentSystem create_component() {
    return (ComponentSystem){0, {0}};
}

void add_to_component(ComponentSystem *component, int index) {
    component->indexes[component->num_components++] = index;
}

void clear_board() {
    for (int i = 0; i < BOARD_SIZE; ++i)
        for (int j = 0; j < BOARD_SIZE; ++j)
            board[i][j] = 0;
}

void init_win_conditions() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        win_conditions[i].row = create_component();
        win_conditions[i].column = create_component();
        for (int j = 0; j < BOARD_SIZE; ++j) {
            add_to_component(&win_conditions[i].row, i * BOARD_SIZE + j);
            add_to_component(&win_conditions[i].column, j * BOARD_SIZE + i);
        }
    }
    win_conditions[6].diagonal1 = create_component();
    win_conditions[7].diagonal2 = create_component();
    for (int i = 0; i < BOARD_SIZE; ++i) {
        add_to_component(&win_conditions[6].diagonal1, i * BOARD_SIZE + i);
        add_to_component(&win_conditions[7].diagonal2, (BOARD_SIZE - 1 - i) * BOARD_SIZE + i);
    }
}

int check_component_win(ComponentSystem component, int player) {
    for (int i = 0; i < component.num_components; ++i) {
        int index = component.indexes[i];
        int row = index / BOARD_SIZE;
        int col = index % BOARD_SIZE;
        if (board[row][col] != player)
            return 0;
    }
    return 1;
}

int check_win(int player) {
    for (int i = 0; i < WIN_CONDITIONS; ++i) {
        if (check_component_win(win_conditions[i].row, player) ||
            check_component_win(win_conditions[i].column, player) ||
            check_component_win(win_conditions[i].diagonal1, player) ||
            check_component_win(win_conditions[i].diagonal2, player))
            return 1;
    }
    return 0;
}

int is_board_full() {
    for (int i = 0; i < BOARD_SIZE; ++i)
        for (int j = 0; j < BOARD_SIZE; ++j)
            if (board[i][j] == 0)
                return 0;
    return 1;
}

int get_opponent(int player) {
    return player == HUMAN_PLAYER ? COMPUTER_PLAYER : HUMAN_PLAYER;
}

int score_for_player(int player) {
    if (check_win(player))
        return 10;
    else if (check_win(get_opponent(player)))
        return -10;
    else
        return 0;
}

int alpha_beta(int player, int alpha, int beta, int *best_row, int *best_col) {
    if (check_win(HUMAN_PLAYER))
        return -10;
    if (check_win(COMPUTER_PLAYER))
        return 10;
    if (is_board_full())
        return 0;
    int max_score = -1000;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == 0) {
                board[i][j] = player;
                int score = alpha_beta(get_opponent(player), alpha, beta, NULL, NULL);
                board[i][j] = 0;
                if (player == COMPUTER_PLAYER && score > alpha) {
                    alpha = score;
                    *best_row = i;
                    *best_col = j;
                } else if (player == HUMAN_PLAYER && score < beta) {
                    beta = score;
                }
                max_score = player == COMPUTER_PLAYER ? MAX(max_score, score) : MIN(max_score, score);
                if (alpha >= beta)
                    return max_score;
            }
        }
    }
    return max_score;
}

void print_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == HUMAN_PLAYER)
                printf("X");
            else if (board[i][j] == COMPUTER_PLAYER)
                printf("O");
            else
                printf("-");
        }
        printf("\n");
    }
}

void make_human_move() {
    int row, col;
    printf("Enter row and column (0 - 2): ");
    scanf("%d %d", &row, &col);
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == 0)
        board[row][col] = HUMAN_PLAYER;
    else {
        printf("Invalid move\n");
        make_human_move();
    }
}

void make_computer_move() {
    int row, col;
    alpha_beta(COMPUTER_PLAYER, -1000, 1000, &row, &col);
    board[row][col] = COMPUTER_PLAYER;
    printf("Computer chooses row %d column %d\n", row, col);
}

void play_game() {
    int current_player = HUMAN_PLAYER;
    clear_board();
    while (!is_board_full() && !check_win(HUMAN_PLAYER) && !check_win(COMPUTER_PLAYER)) {
        print_board();
        if (current_player == HUMAN_PLAYER)
            make_human_move();
        else {
            printf("Computer thinking...\n");
            make_computer_move();
        }
        current_player = get_opponent(current_player);
    }
    print_board();
    if (check_win(HUMAN_PLAYER))
        printf("You win!\n");
    else if (check_win(COMPUTER_PLAYER))
        printf("Computer wins!\n");
    else
        printf("Tie game!\n");
}

int main() {
    init_win_conditions();
    printf("Welcome to Tic Tac Toe!\n");
    while (1) {
        play_game();
        printf("Play again? (y/n)\n ");
        char answer;
        while (1) {
            scanf(" %c", &answer);
            if (answer == 'y' || answer == 'n')
                break;
            else
                printf("Invalid input\n");
        }
        if (answer == 'n')
            break;
    }
    return 0;
}