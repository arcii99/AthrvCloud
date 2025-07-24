//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

char table[3][3]; // table for tic-tac-toe
char player, computer; // players
int max_scores [9] ={0,1,2,4,8,16,32,64,128}; // array for maximum scores
int depth; // depth counter

// function for printing the table
void print_table() {
    printf("\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%c ",table[i][j]);
        }
        printf("\n");
    }
}

// function for calculating score
int calculate_score() {
    int score = 0;
    for(int i=0;i<3;i++){
        if(table[i][0]==table[i][1]&&table[i][1]==table[i][2]){
            if(table[i][0]==computer) score+=100; // computer wins
            else if(table[i][0]==player) score-=100; // player wins
        }
        if(table[0][i]==table[1][i]&&table[1][i]==table[2][i]){
            if(table[0][i]==computer) score+=100; // computer wins
            else if(table[0][i]==player) score-=100; // player wins
        }
    }
    if(table[0][0]==table[1][1]&&table[1][1]==table[2][2]){
        if(table[0][0]==computer) score+=100; // computer wins
        else if(table[0][0]==player) score-=100; // player wins
    }
    if(table[0][2]==table[1][1]&&table[1][1]==table[2][0]){
        if(table[0][2]==computer) score+=100; // computer wins
        else if(table[0][2]==player) score-=100; // player wins
    }
    return score;
}

// function for checking game over
int check_game_over() {
    for(int i=0;i<3;i++){
        if(table[i][0]==table[i][1]&&table[i][1]==table[i][2]){
            if(table[i][0]==computer) return 1; // computer wins
            else if(table[i][0]==player) return -1; // player wins
        }
        if(table[0][i]==table[1][i]&&table[1][i]==table[2][i]){
            if(table[0][i]==computer) return 1; // computer wins
            else if(table[0][i]==player) return -1; // player wins
        }
    }
    if(table[0][0]==table[1][1]&&table[1][1]==table[2][2]){
        if(table[0][0]==computer) return 1; // computer wins
        else if(table[0][0]==player) return -1; // player wins
    }
    if(table[0][2]==table[1][1]&&table[1][1]==table[2][0]){
        if(table[0][2]==computer) return 1; // computer wins
        else if(table[0][2]==player) return -1; // player wins
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(table[i][j]!=' ') continue;
            else return 0; // game still in progress
        }
    }
    return 2; // game is a tie
}

// function for minimax algorithm
int minimax(int isMax) {
    int score = calculate_score();
    if(score==100) return score-depth; // computer wins
    if(score==-100) return score+depth; // player wins
    int game_state = check_game_over();
    if(game_state==2) return 0; // game is a tie
    
    if(isMax) {
        int current_score = -1000;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(table[i][j]!=' ') continue;
                table[i][j] = computer;
                depth++;
                int next_score = minimax(!isMax);
                table[i][j] = ' ';
                depth--;
                current_score = (current_score>next_score)?current_score:next_score; // take maximum score
            }
        }
        return current_score;
    }
    else {
        int current_score = 1000;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(table[i][j]!=' ') continue;
                table[i][j] = player;
                depth++;
                int next_score = minimax(!isMax);
                table[i][j] = ' ';
                depth--;
                current_score = (current_score<next_score)?current_score:next_score; // take minimum score
            }
        }
        return current_score;
    }
}

// function for computer's turn
void computer_turn() {
    int best_score = -1000, row = 0, col = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(table[i][j]!=' ') continue;
            table[i][j] = computer;
            depth = 0;
            int score = minimax(0); // calculate minimax score
            table[i][j] = ' ';
            if(best_score<score) {
                best_score = score;
                row = i;
                col = j;
            }
        }
    }
    printf("Computer chose row %d, col %d\n",row,col);
    table[row][col] = computer;
    print_table();
}

int main() {

    printf("Welcome to Tic-Tac-Toe!\n");
    
    // initialize table, empty space represented by ' '
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            table[i][j] = ' ';
        }
    }

    // choose player's symbol
    printf("Choose your symbol (X or O): ");
    scanf("%c",&player);
    computer = (player=='X')?'O':'X'; // computer's symbol
    printf("You chose %c, computer chose %c\n",player,computer);

    // main game loop
    while(1){
        printf("Your turn: ");
        int row,col;
        scanf("%d %d",&row,&col);
        if(table[row][col]!=' '){
            printf("That space is already taken\n");
            continue;
        }
        table[row][col] = player;
        print_table();
        int game_state = check_game_over();
        if(game_state==1) {
            printf("You lose!\n");
            break;
        }
        if(game_state==2) {
            printf("It's a tie!\n");
            break;
        }
        printf("Computer's turn...\n");
        computer_turn();
        game_state = check_game_over();
        if(game_state==-1) {
            printf("You win!\n");
            break;
        }
        if(game_state==2) {
            printf("It's a tie!\n");
            break;
        }
    }
    return 0;
}