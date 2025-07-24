//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_OF_DISCS 3
#define NUM_OF_PEGS 3

int hanoi[NUM_OF_PEGS][NUM_OF_DISCS]={{1,2,3},{0,0,0},{0,0,0}};
pthread_mutex_t mutex[NUM_OF_PEGS];
pthread_t thread[NUM_OF_DISCS];

void print_hanoi(){
    printf("\n*** HANOI ***\n");
    for(int i=0;i<NUM_OF_PEGS;i++){
        printf("Peg %d: ",i+1);
        for(int j=0;j<NUM_OF_DISCS;j++){
            if(hanoi[i][j]!=0){
                printf("%d ",hanoi[i][j]);
            }
        }
        printf("\n");
    }
}

int check_win(){
    int count=0;
    for(int i=0;i<NUM_OF_DISCS;i++){
        if(hanoi[NUM_OF_PEGS-1][i]==i+1){
            count++;
        }
    }
    if(count==NUM_OF_DISCS){
        return 1;
    }
    return 0;
}

void* move_disc(void* arg){
    int disc=*(int *)arg;
    int from_peg=0, to_peg=0;
    for(int i=0;i<NUM_OF_PEGS;i++){
        if(hanoi[i][disc-1]!=0){
            from_peg=i;
            break;
        }
    }
    for(int i=0;i<NUM_OF_PEGS;i++){
        if(i!=from_peg && hanoi[i][NUM_OF_DISCS-1]==0){
            to_peg=i;
            break;
        }
    }
    while(1){
        usleep(1000000);
        pthread_mutex_lock(&mutex[from_peg]);
        if(hanoi[from_peg][disc-1]!=0){
            for(int i=0;i<NUM_OF_DISCS;i++){
                if(hanoi[to_peg][i]==0){
                    hanoi[to_peg][i]=hanoi[from_peg][disc-1];
                    hanoi[from_peg][disc-1]=0;
                    printf("Moved Disc %d from Peg %d to Peg %d\n",disc,from_peg+1,to_peg+1);
                    print_hanoi();
                    break;
                }
            }
        }
        pthread_mutex_unlock(&mutex[from_peg]);
        if(check_win()){
            printf("YOU WIN!\n");
            exit(0);
        }
    }
}

int main(){
    pthread_mutex_init(&mutex[0],NULL);
    pthread_mutex_init(&mutex[1],NULL);
    pthread_mutex_init(&mutex[2],NULL);
    printf("*** HANOI PROBLEM ***\n");
    print_hanoi();
    for(int i=0;i<NUM_OF_DISCS;i++){
        pthread_create(&thread[i],NULL,move_disc,&hanoi[0][i]);
    }
    for(int i=0;i<NUM_OF_DISCS;i++){
        pthread_join(thread[i],NULL);
    }
    return 0;
}