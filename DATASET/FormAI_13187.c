//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include <pthread.h> 

// array of candidates
char candidates[50][50];
int num_candidates;

// array of votes
int votes[10000];

// mutex to synchronize vote counting
pthread_mutex_t count_mutex; 

// function to set up candidates
void setup_candidates() {
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    getchar();

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter candidate %d name: ", i+1);
        fgets(candidates[i], 50, stdin);
        candidates[i][strlen(candidates[i])-1] = '\0'; // remove newline character
    }
}

// function to display candidate list
void display_candidates() {
    printf("Candidate list:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i]);
    }
}

// function to vote
void *vote(void *vargp) {
    int *id = (int *)vargp;
    int candidate;

    printf("\nEnter candidate ID to vote for (1-%d): ", num_candidates);
    scanf("%d", &candidate);

    pthread_mutex_lock(&count_mutex); 
    votes[*id] = candidate-1; // store candidate number (0-indexed) in votes array
    printf("Vote successfully casted by voter %d for %s\n", *id+1, candidates[candidate-1]);
    pthread_mutex_unlock(&count_mutex);
}

// function to count votes
void count_votes() {
    int results[num_candidates];
    memset(results, 0, sizeof(results));

    for (int i = 0; i < 10000; i++) {
        results[votes[i]]++;
    }

    printf("Vote counting complete. Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i], results[i]);
    }
}

int main() {
    setup_candidates();
    display_candidates();

    pthread_t threads[10000];

    // create threads for voting
    for (int i = 0; i < 10000; i++) {
        pthread_create(&threads[i], NULL, vote, &i);
    }

    // wait for threads to complete
    for (int i = 0; i < 10000; i++) {
        pthread_join(threads[i], NULL);
    }

    count_votes();

    return 0;
}