//FormAI DATASET v1.0 Category: Movie Rating System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int ratings[5] = {0}; // array to hold movie ratings

void* addRatings(void* arg) {
    int rating = *((int*) arg);
    ratings[rating-1]++; // increment the corresponding rating count
    return NULL;
}

int main() {
    pthread_t threads[10]; // an array of 10 thread IDs
    int num_threads = 0;

    printf("Welcome to the Movie Rating System!\n");
    printf("Please rate the movie on a scale of 1 to 5:\n");

    while (num_threads < 10) {
        int rating;
        printf("Thread %d: ", num_threads+1);
        scanf("%d", &rating);
        while (rating < 1 || rating > 5) { // only accept ratings between 1 and 5
            printf("Invalid rating. Please enter a number between 1 and 5: ");
            scanf("%d", &rating);
        }
        pthread_create(&threads[num_threads], NULL, addRatings, &rating); // create a new thread to add the rating
        num_threads++;
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL); // wait for all threads to complete
    }

    printf("Movie Ratings Summary:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d Stars: %d\n", i+1, ratings[i]); // print the rating counts
    }

    return 0;
}