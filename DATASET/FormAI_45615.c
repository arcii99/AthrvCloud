//FormAI DATASET v1.0 Category: Table Game ; Style: multi-threaded
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int players[4];
int currentPlayer = 0;
int gameDone = 0;
pthread_mutex_t mutex;

void* playGame(void* playerID)
{
    int id = *(int*)playerID;

    while(!gameDone)
    {
        pthread_mutex_lock(&mutex);
        if(currentPlayer == id)
        {
            printf("Player %d: It's my turn!\n", id+1);
            players[id] += 1;
            if(players[id] >= 10)
            {
                printf("Player %d wins!\n", id+1);
                gameDone = 1;
            }
            currentPlayer = (currentPlayer + 1) % 4;
        }
        pthread_mutex_unlock(&mutex);
        usleep(100); // Sleep to give other threads a chance to run
    }

    return NULL;
}

int main()
{
    pthread_t threads[4];
    int playerIDs[4] = {0, 1, 2, 3};

    pthread_mutex_init(&mutex, NULL);
    for(int i = 0; i < 4; i++)
    {
        pthread_create(&threads[i], NULL, playGame, &playerIDs[i]);
    }

    for(int i = 0; i < 4; i++)
    {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}