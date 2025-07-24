//FormAI DATASET v1.0 Category: Task Scheduler ; Style: multiplayer
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_JOBS 10 // number of possible jobs
#define NUM_PLAYERS 4 // number of players in the game
#define MIN_TIME 1 // minimum execution time of a job (in seconds)
#define MAX_TIME 10 // maximum execution time of a job (in seconds)

int jobs[NUM_JOBS]; // list of possible jobs
int players[NUM_PLAYERS]; // list of players in the game
int job_counter = 0; // counter for the number of jobs executed

// Function to randomly shuffle an array
void shuffle(int arr[], int n) {
    for(int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Function to simulate a job
void execute_job(int job_id) {
    printf("Executing job %d...\n", job_id);
    sleep(jobs[job_id]);
    printf("Job %d completed! Execution time: %d seconds\n", job_id, jobs[job_id]);
    job_counter++;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the arrays
    for(int i = 0; i < NUM_JOBS; i++)
        jobs[i] = (rand() % (MAX_TIME - MIN_TIME + 1)) + MIN_TIME;

    for(int i = 0; i < NUM_PLAYERS; i++)
        players[i] = i + 1;

    // Shuffle the arrays
    shuffle(jobs, NUM_JOBS);
    shuffle(players, NUM_PLAYERS);

    // Main game loop
    int current_player = 0;
    while(job_counter < NUM_JOBS) {
        printf("It's player %d's turn...\n", players[current_player]);

        // Simulate the player selecting a job
        int selected_job = rand() % NUM_JOBS;
        while(jobs[selected_job] == 0)
            selected_job = rand() % NUM_JOBS;

        // Execute the job
        execute_job(selected_job);
        jobs[selected_job] = 0;

        // Move on to the next player
        current_player = (current_player + 1) % NUM_PLAYERS;
    }

    printf("All jobs completed!\n");

    return 0;
}