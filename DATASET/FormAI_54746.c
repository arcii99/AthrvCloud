//FormAI DATASET v1.0 Category: Pattern printing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define ROWS 6
#define COLUMNS 11

void *printPattern(void *);
char pattern[ROWS][COLUMNS] = {{'*','*','*','*','*','*','*','*','*','*','*'},
                               {'*','*','*','*','*','*','*','*','*','*',' '},
                               {'*','*','*','*','*','*','*','*','*',' ',' '},
                               {'*','*','*','*','*','*','*','*',' ',' ',' '},
                               {'*','*','*','*','*','*','*',' ',' ',' ',' '},
                               {'*','*','*','*','*',' ',' ',' ',' ',' ',' '}};

int main(int argc, char *argv[]){
    int rc;
    pthread_t threads[ROWS];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for(int i=0; i<ROWS; i++){
        rc = pthread_create(&threads[i], &attr, printPattern, (void *)i);
        if(rc){
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    pthread_attr_destroy(&attr); 

    for(int i=0; i<ROWS; i++){
        rc = pthread_join(threads[i], NULL);
        if(rc){
            printf("ERROR; return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }

    pthread_exit(NULL);
}

void *printPattern(void *param){
    int row = (int)param;
    for(int i=0; i<COLUMNS; i++){
        usleep(50000);
        system("clear");
        for(int j=0; j<=row; j++){
            for(int k=0; k<COLUMNS; k++){
                printf("%c", pattern[j][k]);
            }
            printf("\n");
        }
    }
    pthread_exit(NULL);
}