//FormAI DATASET v1.0 Category: Checkers Game ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
int board[8][8]={
    {0,2,0,2,0,2,0,2},
    {2,0,2,0,2,0,2,0},
    {0,2,0,2,0,2,0,2},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {1,0,1,0,1,0,1,0},
    {0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0},
};
int turn=1;
void display();
void possible_moves(int a[2], int *moves[12]);
int check_validity(int a[2], int b[2]);
int check_capture_or_not(int a[2]);

int main(){
    printf("\n\n Welcome to C Checkers Game!\n___________________________\n");
    display();
    while(1){
        int i, j, cap_present=0;
        int start[2], end[2];
        printf("Turn=%d\n", turn);
        if (turn==1){
            printf("White's Move.\n");
        }
        else{
            printf("Black's Move.\n");
        }
        printf("Enter the starting position(row, column): ");
        scanf("%d %d", &start[0], &start[1]);
        printf("Enter the ending position(row, column): ");
        scanf("%d %d", &end[0], &end[1]);
        if (check_validity(start, end)){
            board[end[0]][end[1]]=board[start[0]][start[1]];
            board[start[0]][start[1]]=0;
            display();
            if (check_capture_or_not(end)){
                cap_present=1;
                int* moves[12];
                possible_moves(end, moves);
                int temp[2], k=0;
                while(*(moves+k)){
                    k++;
                }
                if (k>1){
                    printf("Chained Capture Possible!\n");
                    for(i=0; i<k-1; i++){
                        printf("Moving from (%d,%d) to (%d,%d).\n", moves[i][0], moves[i][1], moves[i+1][0], moves[i+1][1]);
                        board[moves[i+1][0]][moves[i+1][1]]=board[moves[i][0]][moves[i][1]];
                        board[moves[i][0]][moves[i][1]]=0;
                        display();
                    }
                }
            }
            if (!cap_present){
                printf("\n\n");
                turn=((turn+1)%2);
            }
        }
        else{
            printf("Invalid Move! Try Again.\n");
        }
    }
    return 0;
}

void display(){
    int i, j;
    char piece;
    printf("\n |1|2|3|4|5|6|7|8|\n");
    printf("__________________\n");
    for (i=0; i<8; i++){
        printf("%d|", i+1);
        for (j=0; j<8; j++){
            if (board[i][j]==0){
                printf(" |");
            }
            else{
                if (board[i][j]==1){
                    piece='o';
                }
                else if (board[i][j]==2){
                    piece='x';
                }
                printf("%c|", piece);
            }
        }
        printf("%d\n", i+1);
    }
    printf("------------------\n");
    printf(" |1|2|3|4|5|6|7|8|\n\n\n");
}

int check_validity(int a[2], int b[2]){
    if (b[0]>7 || b[0]<0 || b[1]>7 || b[1]<0){
        return 0;
    }
    if (board[b[0]][b[1]]!=0){
        return 0;
    }
    if (board[a[0]][a[1]]==1 && b[0]>=a[0]){
        return 0;
    }
    if (board[a[0]][a[1]]==2 && b[0]<=a[0]){
        return 0;
    }
    if (abs(b[0]-a[0])==1 && abs(b[1]-a[1])==1){
        return 1;
    }
    if (abs(b[0]-a[0])==2 && abs(b[1]-a[1])==2){
        int x=(a[0]+b[0])/2;
        int y=(a[1]+b[1])/2;
        if (board[x][y]!=((turn+1)%2)+1){
            return 0;
        }
        board[x][y]=0;
        return 1;
    }
    return 0;
}


void possible_moves(int a[2], int *moves[12]){
    int i, j, k=0, temp[2];
    if (board[a[0]][a[1]]==1 || board[a[0]][a[1]]==2){
        for (i=-2; i<=2; i+=4){
            for (j=-2; j<=2; j+=4){
                temp[0]=a[0]+i;
                temp[1]=a[1]+j;
                if (check_validity(a, temp)){
                    *(moves+k)=(int*)malloc(2*sizeof(int));
                    *(moves+k)[0]=temp[0];
                    *(moves+k)[1]=temp[1];
                    k++;
                }
            }
        }
    }
    if (board[a[0]][a[1]]==1){
        if (check_validity(a, a)){ //in case no capture is possible, the function returns a single move which is (a[0],a[1])
            *(moves+k)=(int*)malloc(2*sizeof(int));
            *(moves+k)[0]=a[0];
            *(moves+k)[1]=a[1];
            k++;
        }
    }
    if (board[a[0]][a[1]]==2 || board[a[0]][a[1]]==3){
        for (i=-2; i<=2; i+=4){
            for (j=-2; j<=2; j+=4){
                for (int k=1; ; k++){
                    temp[0]=a[0]+k*i;
                    temp[1]=a[1]+k*j;
                    if (check_validity(a, temp)){
                        *(moves+k-1)=(int*)malloc(2*sizeof(int));
                        *(moves+k-1)[0]=temp[0];
                        *(moves+k-1)[1]=temp[1];
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    if (board[a[0]][a[1]]==2){
        if (check_validity(a, a)){
            *(moves+k)=(int*)malloc(2*sizeof(int));
            *(moves+k)[0]=a[0];
            *(moves+k)[1]=a[1];
            k++;
        }
    }   
    *(moves+k)=NULL; //add NULL pointer to terminate the array of pointers
    return;
}

int check_capture_or_not(int a[2]){
    int *temp[12];
    possible_moves(a, temp);
    if (*temp==NULL){
        return 0;
    }
    else{
        return 1;
    }
}