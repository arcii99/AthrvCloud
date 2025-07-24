//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 5
#define COLS 5

void display(char c[ROWS][COLS]){
    int i,j;
    printf("\nB    I    N    G    O\n\n");
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            if(c[i][j] == '*')
                printf("| %c |", c[i][j]);
            else if(c[i][j] == '!')
                printf("| X |");
            else
                printf("| %c |", c[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

int check(char c[ROWS][COLS]){
    int i,j,row=0, col=0,count=0,dcount1=0, dcount2=0;
    for(i=0;i<ROWS;i++){
        col=0;
        row=0;
        for(j=0;j<COLS;j++){
            if(c[i][j] == '!')
                row++;
            if(c[j][i] == '!')
                col++;
        }
        if(row == 5 || col == 5)
            count++;
    }
    for(i=0;i<ROWS;i++){
         if(c[i][i] == '!')
            dcount1++;
         if(c[i][ROWS-i-1] == '!')
            dcount2++;
    }
    if(dcount1 == 5 || dcount2 == 5)
        count++;

    return count;
}

int main(){
    char bingo[ROWS][COLS] ={
                    {'B','I','N','G','O'},
                    {'*','*','*','*','*'},
                    {'*','*','*','*','*'},
                    {'*','*','*','*','*'},
                    {'*','*','*','*','*'}
                    };
    int num[25];
    int i,j,k;
    int count = 0;
    srand((unsigned)time(NULL));
    for(i=0;i<25;i++)
        num[i] = rand()%25 + 1;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            bingo[i][j] = num[count] + '0';
            count++;
     }
  }
  printf("\t\t  WELCOME TO POST-APOCALYPTIC BINGO\n");
  printf("\nRULES:\n 1. Get a full line (Horizontal or Vertical) or Diagonal match to get a BINGO\n 2. You can mark a number with '!' once it is called\n 3. Survive the apocalypse and win the game\n\n");
  printf("Press Enter to continue\n");
  getchar();
  display(bingo);
  while(1){
        int flag=0;
        int inp;
        printf("Enter a number between 1-25: ");
        scanf("%d",&inp);
        if(inp<1 || inp>25){
            printf("\nInvalid input\n");
            continue;
        }
        for(i=0;i<ROWS;i++){
            for(j=0;j<COLS;j++){
                if(bingo[i][j] == inp+48){
                    bingo[i][j] = '!';
                    flag=1;
                }
             }
         }
         if(flag==0){
            printf("\nNumber %d not found\n\n",inp);
            continue;
        } 
        else {
            printf("\nNumber %d marked successfully\n\n",inp);
            int checkBingo = check(bingo);
            display(bingo);
            if(checkBingo >= 1){
                printf("BINGO!! You survived the apocalypse\n\n");
                break;
            }
        }
    }
    return 0;
}