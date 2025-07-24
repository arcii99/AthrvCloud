//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define TRUE 1
#define FALSE 0

//Function to initialize the bingo card
void init_bingo_card(int bingo_card[ROWS][COLS]){
    int i, j, num;

    //Set all the elements to 0
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLS; j++){
            bingo_card[i][j] = 0;
        }
    }

    //Generate random numbers and set them on the card
    srand(time(NULL));
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLS; j++){
            if(j != 2){
                do{
                    num = rand()%15 + (j*15) + 1;
                }while(check_num_on_card(num, bingo_card));
                bingo_card[i][j] = num;
            }
        }
    }

    //Set the center element to 0
    bingo_card[2][2] = 0;
}

//Function to print the bingo card
void print_bingo_card(int bingo_card[ROWS][COLS]){
    int i, j;

    printf("\nB   I   N   G   O\n");
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLS; j++){
            if(bingo_card[i][j] == 0){
                printf("  ");
            }else{
                printf("%-3d", bingo_card[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

//Function to check if a number already exists on the card
int check_num_on_card(int num, int bingo_card[ROWS][COLS]){
    int i, j;

    for(i=0; i<ROWS; i++){
        for(j=0; j<COLS; j++){
            if(bingo_card[i][j] == num){
                return TRUE;
            }
        }
    }
    return FALSE;
}

//Function to mark a number on the card
void mark_num_on_card(int num, int bingo_card[ROWS][COLS]){
    int i, j;

    for(i=0; i<ROWS; i++){
        for(j=0; j<COLS; j++){
            if(bingo_card[i][j] == num){
                bingo_card[i][j] = 0;
                return;
            }
        }
    }
}

//Function to check if a bingo pattern has been formed
int check_bingo(int bingo_card[ROWS][COLS]){
    int i, j;

    //Check rows
    for(i=0; i<ROWS; i++){
        if(bingo_card[i][0] == 0 && bingo_card[i][1] == 0 && bingo_card[i][2] == 0 && bingo_card[i][3] == 0 && bingo_card[i][4] == 0){
            return TRUE;
        }
    }

    //Check columns
    for(j=0; j<COLS; j++){
        if(bingo_card[0][j] == 0 && bingo_card[1][j] == 0 && bingo_card[2][j] == 0 && bingo_card[3][j] == 0 && bingo_card[4][j] == 0){
            return TRUE;
        }
    }

    //Check diagonals
    if(bingo_card[0][0] == 0 && bingo_card[1][1] == 0 && bingo_card[2][2] == 0 && bingo_card[3][3] == 0 && bingo_card[4][4] == 0){
        return TRUE;
    }
    if(bingo_card[0][4] == 0 && bingo_card[1][3] == 0 && bingo_card[2][2] == 0 && bingo_card[3][1] == 0 && bingo_card[4][0] == 0){
        return TRUE;
    }

    return FALSE;
}

int main(){
    int choice, i, j, num, bingo;
    int bingo_card[ROWS][COLS];

    //Initialize the bingo card
    init_bingo_card(bingo_card);

    //Game loop
    do{
        //Print the options menu
        printf("------------------------------\n");
        printf("BINGO SIMULATOR\n");
        printf("------------------------------\n");
        printf("1. Print bingo card\n");
        printf("2. Mark a number\n");
        printf("3. Check for bingo\n");
        printf("4. Quit\n");
        printf("------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                print_bingo_card(bingo_card);
                break;
            case 2:
                printf("Enter the number to mark: ");
                scanf("%d", &num);
                mark_num_on_card(num, bingo_card);
                break;
            case 3:
                bingo = check_bingo(bingo_card);
                if(bingo){
                    printf("BINGO! You have won the game!\n");
                }else{
                    printf("No bingo yet.\n");
                }
                break;
            case 4:
                printf("Thanks for playing!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }while(choice != 4);

    return 0;
}