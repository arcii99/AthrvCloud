//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>

// Global variables
int isRunning = 1;
pthread_mutex_t lock;

// Function prototypes
void *playerAction(void *arg);
void *ghostAction(void *arg);

int main() {
    pthread_t player, ghost;

    // Initialize random seed
    srand(time(NULL));
    
    pthread_mutex_init(&lock, NULL); // Initialize lock
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You have entered a spooky house at midnight...\n");
    printf("You hear strange noises and see shadows moving in the dark.\n");

    printf("\nInstructions:\n");
    printf("- Use 'w', 'a', 's', 'd' to move around the house.\n");
    printf("- Avoid the ghost! If it catches you, it's game over.\n");
    printf("- Press 'q' to quit the game.\n");
    printf("- Good luck!\n");
    
    // Create threads
    pthread_create(&player, NULL, playerAction, NULL);
    pthread_create(&ghost, NULL, ghostAction, NULL);

    // Wait for threads to finish
    pthread_join(player, NULL);
    pthread_join(ghost, NULL);

    pthread_mutex_destroy(&lock);
    
    return 0;
}

// Thread for player action
void *playerAction(void *arg)
{
    char input;
    int pos_x = 0;
    int pos_y = 0;

    while (isRunning) {
        input = getchar();
        fflush(stdin);

        pthread_mutex_lock(&lock);
        switch (input)
        {
        case 'w':
            pos_y++;
            printf("You move north.\n");
            break;
        case 'a':
            pos_x--;
            printf("You move west.\n");
            break;
        case 's':
            pos_y--;
            printf("You move south.\n");
            break;
        case 'd':
            pos_x++;
            printf("You move east.\n");
            break;
        case 'q':
            printf("You quit the game.\n");
            isRunning = 0;
            break;
        default:
            printf("Invalid input.\n");
            break;
        }
        pthread_mutex_unlock(&lock);

        usleep(50000); // Wait for 50ms
    }

    pthread_exit(NULL);
}

// Thread for ghost action
void *ghostAction(void *arg)
{
    int pos_x = rand() % 10;
    int pos_y = rand() % 10;

    while (isRunning) {

        pthread_mutex_lock(&lock);
        // Check if player and ghost are at same position
        if (pos_x == 0 && pos_y == 0) {
            printf("\nYou've been caught by the ghost! Game Over.\n");
            isRunning = 0;
            break;
        }

        // Move ghost randomly
        int move = rand() % 4; // 0 = north, 1 = west, 2 = south, 3 = east
        switch (move)
        {
        case 0:
            pos_y++;
            break;
        case 1:
            pos_x--;
            break;
        case 2:
            pos_y--;
            break;
        case 3:
            pos_x++;
            break;
        default:
            break;
        }
        pthread_mutex_unlock(&lock);

        // Wait for 500ms
        usleep(500000);
    }

    pthread_exit(NULL);
}