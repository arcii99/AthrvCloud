//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL)); //seeding the random number generator with the current time
    int card[5][5] = {0}; //initializing the player's card with all zeros
    int i, j, value, row, col, count=0;

    //generating random values for the player's card
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(j==2 && i==2){
                card[i][j]=0; //center value is always marked as zero
                continue;
            }
            value=rand()%15+1+(15*j); //values can range from 1 to 15, 16 to 30, 31 to 45, etc
            while(count<5 && card[count][j]!=0){ //checking if the value is repeated in the same column
                if(card[count][j]==value){
                    value=rand()%15+1+(15*j);
                    count=-1;
                }
                count++;
            }
            card[i][j]=value; //assigning the generated value to the card
            count=0;
        }
    }

    printf("Your card:\n");
    for(i=0;i<5;i++){ //displaying the player's card
        for(j=0;j<5;j++){
            printf("%d\t",card[i][j]);
        }
        printf("\n");
    }

    int caller[75] = {0}; //initializing the caller's numbers with all zeros
    count = 0;
    int found = 0;
    int number;
    int result[5] = {0}; //an array to hold the result of the game
    int full_house = 0;

    printf("Starting game!\n");

    while(1){ //continue the game until the player gets a full house
        number=rand()%75+1; //generate a random number from 1 to 75
        found = 0;
        for(i=0;i<75;i++){ //check if the number has already been called
            if(caller[i]==number){
                found = 1;
                break;
            }
        }
        if(found==0){ //if the number has not been called, add it to the called numbers array
            caller[count] = number;
            count++;
            printf("The caller says: %d\n", number);
            for(i=0;i<5;i++){
                for(j=0;j<5;j++){
                    if(card[i][j]==number){ //if the number is found on the player's card, mark it
                        card[i][j] = 0;
                    }
                }
            }
            for(i=0;i<5;i++){ //check if the player has won the game
                if(card[i][0]==0 && card[i][1]==0 && card[i][2]==0 && card[i][3]==0 && card[i][4]==0){
                    result[i] = 1;
                }
                if(card[0][i]==0 && card[1][i]==0 && card[2][i]==0 && card[3][i]==0 && card[4][i]==0){
                    result[i] = 1;
                }
            }
            if(card[0][0]==0 && card[1][1]==0 && card[2][2]==0 && card[3][3]==0 && card[4][4]==0){
                result[i] = 1;
            }
            if(card[0][4]==0 && card[1][3]==0 && card[2][2]==0 && card[3][1]==0 && card[4][0]==0){
                result[i] = 1;
            }
            full_house = 1; //check if the player has got a full house
            for(i=0;i<5;i++){
                if(result[i]==0){
                    full_house = 0;
                    break;
                }
            }
            if(full_house==1){ //if the player has got a full house, end the game
                printf("You got a full house! You win!\n");
                break;
            }
        }
    }

    printf("Game over!\n");

    return 0;
}