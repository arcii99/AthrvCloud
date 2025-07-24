//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int i, j, num, rows, cols, count, position;
    int bingo[5][5] = {0};
    char temp;

    //Seed random number generator
    srand(time(0));

    //Print instructions
    printf("Welcome to the C Bingo Simulator!\n");
    printf("Press ENTER to continue...");
    getchar();
    printf("\n");

    //Generate random Bingo card
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if(j == 2 && i == 2){
                bingo[i][j] = 0;
                continue;
            }
            num = rand() % 15 + (15 * j) + 1;
            while(bingo[0][j] == num || bingo[1][j] == num || bingo[2][j] == num || bingo[3][j] == num || bingo[4][j] == num){
                num = rand() % 15 + (15 * j) + 1;
            }
            bingo[i][j] = num;
        }
    }

    //Print Bingo card
    printf("Your Bingo card:\n\n");
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            printf("%d\t", bingo[i][j]);
        }
        printf("\n\n");
    }

    //Play Bingo
    count = 0;
    while(count < 24){
        printf("Press ENTER to draw a number...");
        getchar();
        printf("\n");

        //Generate random number
        num = rand() % 75 + 1;
        printf("The number drawn is: %d\n", num);

        //Check if number is on Bingo card
        for(i = 0; i < 5; i++){
            for(j = 0; j < 5; j++){
                if(bingo[i][j] == num){
                    printf("The number %d is on your card!\n", num);
                    bingo[i][j] = 0; //Replace number with 0 to mark it as found
                    count++;
                }
            }
        }

        //Check if Bingo has been achieved
        if(bingo[0][0] == 0 && bingo[0][1] == 0 && bingo[0][2] == 0 && bingo[0][3] == 0 && bingo[0][4] == 0){
            printf("BINGO! You have won!\n");
            break;
        }
        if(bingo[1][0] == 0 && bingo[1][1] == 0 && bingo[1][2] == 0 && bingo[1][3] == 0 && bingo[1][4] == 0){
            printf("BINGO! You have won!\n");
            break;
        }
        if(bingo[2][0] == 0 && bingo[2][1] == 0 && bingo[2][3] == 0 && bingo[2][3] == 0 && bingo[2][4] == 0){
            printf("BINGO! You have won!\n");
            break;
        }
        if(bingo[3][0] == 0 && bingo[3][1] == 0 && bingo[3][2] == 0 && bingo[3][3] == 0 && bingo[3][4] == 0){
            printf("BINGO! You have won!\n");
            break;
        }
        if(bingo[4][0] == 0 && bingo[4][1] == 0 && bingo[4][2] == 0 && bingo[4][3] == 0 && bingo[4][4] == 0){
            printf("BINGO! You have won!\n");
            break;
        }
        if(bingo[0][0] == 0 && bingo[1][1] == 0 && bingo[2][2] == 0 && bingo[3][3] == 0 && bingo[4][4] == 0){
            printf("BINGO! You have won!\n");
            break;
        }
        if(bingo[0][4] == 0 && bingo[1][3] == 0 && bingo[2][2] == 0 && bingo[3][1] == 0 && bingo[4][0] == 0){
            printf("BINGO! You have won!\n");
            break;
        }
    }

    //Print Final Bingo card
    printf("\nFinal state of Bingo card:\n\n");
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            printf("%d\t", bingo[i][j]);
        }
        printf("\n\n");
    }

    printf("Thank you for playing C Bingo Simulator!\n");

    return 0;
}