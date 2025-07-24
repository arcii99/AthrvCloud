//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_PLAYERS 4

void *player_function(void *arg);

pthread_t threads[MAX_PLAYERS];

int main()
{
    int i;
    int player_ids[MAX_PLAYERS] = {1, 2, 3, 4};

    for (i = 0; i < MAX_PLAYERS; i++) 
    {
        int rc = pthread_create(&threads[i], NULL, player_function, (void*)(intptr_t)player_ids[i]);

        if (rc)
        {
            printf("Error creating thread %d!\n", i);
            exit(-1);
        } 
    }

    for (i = 0; i < MAX_PLAYERS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *player_function(void *arg)
{
    int player_id = (intptr_t)arg;

    printf("Player %d joined the game!\n", player_id);

    // Game loop
    while (1)
    {
        printf("Player %d's turn...\n", player_id);
        sleep(1);
    }

    return NULL;
}