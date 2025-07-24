//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int width=10, height=10, x=0,y=0,fruit_x,fruit_y,score=0,ch;
    int tail_x[100],tail_y[100],count_tail=0;
    time_t t;
    srand((unsigned) time(&t));
    fruit_x=rand() % width;
    fruit_y=rand() % height;
    while(1){
        system("clear"); //Clearing the screen in UNIX based operating systems
        for(int i=0;i<=width;i++){
            printf("#");
        }
        printf("\n");
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(i==y && j==x){
                    printf("O");
                }
                else if(i==fruit_y && j==fruit_x){
                    printf("*");
                }
                else{
                    int print=0;
                    for(int k=0;k<count_tail;k++){
                        if(tail_x[k]==j && tail_y[k]==i){
                            printf("o");
                            print=1;
                        }
                    }
                    if(print==0){
                        printf(" ");
                    }
                }
            }
            printf("\n");
        }
        for(int i=0;i<=width;i++){
            printf("#");
        }
        printf("\n");
        printf("Score: %d\n",score);
        printf("Use arrow keys to control the snake");
        ch=getchar();
        switch(ch){
            case 'A':
            case 'a':
                y--;
                break;
            
            case 'B':
            case 'b':
                y++;
                break;
            
            case 'C':
            case 'c':
                x++;
                break;
            
            case 'D':
            case 'd':
                x--;
                break;
            
            case 'X':
            case 'x':
                exit(0);
                break;
        }
        if(x<0 || x>width || y<0 || y>height){
            printf("You died because you hit the boundary\n");
            exit(0);
        }
        if(x==fruit_x && y==fruit_y){
            score++;
            tail_x[count_tail]=x;
            tail_y[count_tail++]=y;
            fruit_x=rand() % width;
            fruit_y=rand() % height;
        }
        for(int i=0;i<count_tail-1;i++){
            tail_x[i]=tail_x[i+1];
            tail_y[i]=tail_y[i+1];
        }
        tail_x[count_tail-1]=x;
        tail_y[count_tail-1]=y;
    }
    return 0;
}