//FormAI DATASET v1.0 Category: Table Game ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    //Declaring variables.
    int arr[4][4];
    int row,col;
    int moves=0;
    int score=0;
    char c;

    //Initializing the array with random numbers.
    srand(time(0));
    for(row=0;row<4;row++){
        for(col=0;col<4;col++){
            arr[row][col] = rand()%50+1;
        }
    }

    //Printing the initial state of the array.
    printf("\n\t     Welcome to the C Table Game!\n\n");
    printf("\t\t---------------------------\n");
    for(row=0;row<4;row++){
        printf("\t\t|");
        for(col=0;col<4;col++){
            printf(" %2d |",arr[row][col]);
        }
        printf("\n\t\t---------------------------\n");
    }

    //Gameplay.
    printf("\nUse the following keys to move:\nW = Up\nA = Left\nS = Down\nD = Right\nPress Q to Quit the game\n");
    printf("\nScore: %d",score);
    printf("\nMoves: %d",moves);

    while(1){
        scanf("%c",&c); //Taking the input key.
        system("clear"); //Clearing the screen.

        //Handling the key inputs.
        switch(c){
            case 'w':
            case 'W':   
                for(col=0;col<4;col++){
                    for(row=0;row<3;row++){
                        if(arr[row][col]!=0 && arr[row][col]==arr[row+1][col]){ 
                            arr[row][col] += arr[row+1][col];
                            arr[row+1][col] = 0;
                            score += arr[row][col];
                        }
                        else if(arr[row][col]==0 && arr[row+1][col]!=0){
                            arr[row][col] = arr[row+1][col];
                            arr[row+1][col] = 0;
                        }
                    }
                }
                break;

            case 's':
            case 'S':
                for(col=0;col<4;col++){
                    for(row=3;row>0;row--){
                        if(arr[row][col]!=0 && arr[row][col]==arr[row-1][col]){
                            arr[row][col] += arr[row-1][col];
                            arr[row-1][col] = 0;
                            score += arr[row][col];
                        }
                        else if(arr[row][col]==0 && arr[row-1][col]!=0){
                            arr[row][col] = arr[row-1][col];
                            arr[row-1][col] = 0;
                        }
                    }
                }
                break;

            case 'a':
            case 'A':
                for(row=0;row<4;row++){
                    for(col=0;col<3;col++){
                        if(arr[row][col]!=0 && arr[row][col]==arr[row][col+1]){
                            arr[row][col] += arr[row][col+1];
                            arr[row][col+1] = 0;
                            score += arr[row][col];
                        }
                        else if(arr[row][col]==0 && arr[row][col+1]!=0){
                            arr[row][col] = arr[row][col+1];
                            arr[row][col+1] = 0;
                        }
                    }
                }
                break;

            case 'd':
            case 'D':
                for(row=0;row<4;row++){
                    for(col=3;col>0;col--){
                        if(arr[row][col]!=0 && arr[row][col]==arr[row][col-1]){
                            arr[row][col] += arr[row][col-1];
                            arr[row][col-1] = 0;
                            score += arr[row][col];
                        }
                        else if(arr[row][col]==0 && arr[row][col-1]!=0){
                            arr[row][col] = arr[row][col-1];
                            arr[row][col-1] = 0;
                        }
                    }
                }
                break;

            case 'q':
            case 'Q':
                printf("\n\nQuitting the game!\n");
                exit(0);

            default:
                printf("\nInvalid key or command!\n");
        }

        //Printing the current state of the array.
        printf("\n\t\t---------------------------\n");
        for(row=0;row<4;row++){
            printf("\t\t|");
            for(col=0;col<4;col++){
                if(arr[row][col] == 0){
                    printf("    |");
                }else{
                    printf(" %2d |",arr[row][col]);
                }               
            }
            printf("\n\t\t---------------------------\n");
        }

        //Updating the score and the moves.
        moves++;
        printf("\nScore: %d",score);
        printf("\nMoves: %d",moves);
        printf("\nUse the following keys to move:\nW = Up\nA = Left\nS = Down\nD = Right\nPress Q to Quit the game\n");
    }

    return 0;
}