//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

void print_card(char card[ROWS][COLS]){
    printf("B   I   N   G   O\n");
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(card[i][j] == 'F'){
                printf("F  ");
                continue;
            }
            printf("%d  ", (int)card[i][j]);
        }
        printf("\n");
    }
}

void mark_number(char card[ROWS][COLS], int number){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(card[i][j] == 'F' && (int)card[i][j+1] == number){
                card[i][j] = (char)number;
                return;
            }
        }
    }
}

int check_card(char card[ROWS][COLS]){
    // Check rows
    for(int i=0; i<ROWS; i++){
        int mark_count = 0;
        for(int j=0; j<COLS; j++){
            if((int)card[i][j] == 0 || card[i][j] == 'F'){
                break;
            }
            mark_count++;
        }
        if(mark_count == COLS){
            return 1;
        }
    }

    // Check columns
    for(int i=0; i<COLS; i++){
        int mark_count = 0;
        for(int j=0; j<ROWS; j++){
            if((int)card[j][i] == 0 || card[j][i] == 'F'){
                break;
            }
            mark_count++;
        }
        if(mark_count == ROWS){
            return 1;
        }
    }

    // Check diagonals
    int mark_count = 0;
    for(int i=0; i<ROWS; i++){
        if((int)card[i][i] == 0 || card[i][i] == 'F'){
            break;
        }
        mark_count++;
    }
    if(mark_count == ROWS){
        return 1;
    }

    mark_count = 0;
    for(int i=0; i<ROWS; i++){
        if((int)card[i][COLS-i-1] == 0 || card[i][COLS-i-1] == 'F'){
            break;
        }
        mark_count++;
    }
    if(mark_count == ROWS){
        return 1;
    }

    return 0;
}

int main(){
    char player_card[ROWS][COLS];
    char computer_card[ROWS][COLS];
    int numbers_drawn[MAX_NUM];

    // Generate player's card
    srand(time(NULL));
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(j == 2 && i == 2){
                player_card[i][j] = 'F'; // FREE SPACE
            } else {
                int number;
                do {
                    number = rand() % 15 + 15*j + 1; // Pick a number from the current column range
                } while ((int)player_card[i][0] == number || (int)player_card[i][1] == number || (int)player_card[i][2] == number ||
                        (int)player_card[i][3] == number || (int)player_card[i][4] == number);
                player_card[i][j] = (char)number;
            }
        }
    }

    // Generate computer's card
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(j == 2 && i == 2){
                computer_card[i][j] = 'F'; // FREE SPACE
            } else {
                int number;
                do {
                    number = rand() % 15 + 15*j + 1; // Pick a number from the current column range
                } while ((int)computer_card[i][0] == number || (int)computer_card[i][1] == number || (int)computer_card[i][2] == number ||
                        (int)computer_card[i][3] == number || (int)computer_card[i][4] == number);
                computer_card[i][j] = (char)number;
            }
        }
    }

    printf("Welcome to Bingo Simulator!\n");
    printf("Your Bingo card:\n");
    print_card(player_card);
    printf("\n\n");

    int draw_count = 0;
    while(1){
        int number_drawn;
        do {
            number_drawn = rand() % MAX_NUM + 1;
        } while(numbers_drawn[number_drawn-1] == 1);

        numbers_drawn[number_drawn-1] = 1;

        printf("Number drawn: %d\n", number_drawn);

        mark_number(player_card, number_drawn);
        mark_number(computer_card, number_drawn);

        printf("Your card:\n");
        print_card(player_card);
        printf("\n");

        printf("Computer's card:\n");
        print_card(computer_card);
        printf("\n\n");

        if(check_card(player_card)){
            printf("Congratulations, you won!\n");
            break;
        } else if(check_card(computer_card)){
            printf("Computer won, better luck next time!\n");
            break;
        }

        printf("Press any key to draw next number...\n");
        getchar();
    }

    return 0;
}